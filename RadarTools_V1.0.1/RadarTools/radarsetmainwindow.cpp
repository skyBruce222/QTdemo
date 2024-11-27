#include "radarsetmainwindow.h"
#include "ui_radarsetmainwindow.h"
#include "coordinateaxiswight.h"
#include <QRegularExpressionValidator>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QTranslator>
#include <QFile>
#include <math.h>
#include <QSettings>
#include <QTextCodec>
#include <QDir>
#include <QTextStream>

radarSetMainWindow::radarSetMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::radarSetMainWindow)
{
    ui->setupUi(this);
    initMainWindow();
    initCamera();
    actionEventHandle();
    CANEventHandle();
}

radarSetMainWindow::~radarSetMainWindow()
{
    if (canthread){
        canthread->stop();
        if (connectStates){
            canthread->reSetCAN();
            canthread->closeDevice();
        }
        canthread->wait();
        delete canthread;
        canthread = nullptr;
    }

    delete ui;
}


void radarSetMainWindow::initCamera(){
    cameras = QCameraInfo::availableCameras();//获取摄像头列表
    //qDebug()<<cameras.size();

    for(int i = 0;i<cameras.size();i++)
        ui->comboBox->addItem(cameras[i].description());//摄像头描述
}

void radarSetMainWindow::initMainWindow()
{
    this->setWindowTitle("Radar Tools V1.0");
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
    setWindowIcon(QIcon(":/img/dragonbool.jpg"));
    ui->menubar->setObjectName("menubar");
    ui->menubar->setStyleSheet("#menubar{background-color:#F0F0F0;}");
    //ui->centralwidget->setObjectName("radarMainWidget");
    //ui->centralwidget->setStyleSheet("#radarMainWidget{background-color:#d3d7d4;}");

    QSettings setting("./Setting.ini", QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QString lang = setting.value("login/language").toString();
    if (lang.isEmpty()){
        switchLanguage("中文");
    } else{
        switchLanguage(lang);
    }
    ui->menuObject->menuAction()->setVisible(false);
    ui->X_lineEdit->setValidator(new QIntValidator(this));//只允许输入纯数字形式
    ui->X_lineEdit->setText("10");//默认值为50
    ui->Y_lineEdit->setText("50");
    ui->Y_lineEdit->setValidator(new QIntValidator(this));
    ui->angle_lineEdit->setText("120");
    ui->angle_lineEdit->setValidator(new QIntValidator(this));
    xScale = ui->X_lineEdit->text().toInt();
    yScale = ui->Y_lineEdit->text().toInt();
    angle = ui->angle_lineEdit->text().toInt();
    //ui->groupBox->setStyleSheet("background-color:wihte;");
    //ui->CameraWidget->setStyleSheet("background-color:black;");
    ui->lineEdit_6->setPlaceholderText("0-7");
    setLED(ui->label_led, 0, 22);
    QSettings writeini("./SystemPara.ini", QSettings::IniFormat); // 打开ini文件
    writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
    QString xScale_s=writeini.value("Axis/xScale").toString();
    QString yScale_s=writeini.value("Axis/yScale").toString();
    QString angle_s=writeini.value("Axis/angle").toString();
    QString buad_sidx = writeini.value("baud/baudidx").toString();
    QString radarmodeidx=writeini.value("radarmode/modeidx").toString();
    QString cantypeidx=writeini.value("canType/canidx").toString();

    if (!xScale_s.isEmpty() && !yScale_s.isEmpty() && !angle_s.isEmpty()){
        xScale = xScale_s.toInt();
        yScale = yScale_s.toInt();
        angle = angle_s.toInt();
        ui->X_lineEdit->setText(xScale_s);
        ui->Y_lineEdit->setText(yScale_s);
        ui->angle_lineEdit->setText(angle_s);
        ui->widget_4->updateAxis(xScale,yScale,angle);
    }

    if (!buad_sidx.isEmpty()){
        ui->comboBox_5->setCurrentIndex(buad_sidx.toInt());
    }
    if (!radarmodeidx.isEmpty()){
        ui->comboBox_4->setCurrentIndex(radarmodeidx.toInt());
    }
    if (!cantypeidx.isEmpty()){
        ui->comboBox_6->setCurrentIndex(cantypeidx.toInt());
    }

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &radarSetMainWindow::updateTime);
    timer->start(1000);//1Sec update


    eventFilter = new cameraEventfilter(ui->comboBox, this);
    ui->comboBox->installEventFilter(eventFilter);

    connect(eventFilter, SIGNAL(comboBoxPopupShown()), this, SLOT(onComboBoxPopupShown()));//连接鼠标点击事件，实现点击comboBox刷新相机列表

    canthread = new CANThread();
    connect(canthread,&CANThread::getProtocolData,this,&radarSetMainWindow::onGetProtocolData);
}

void radarSetMainWindow::CANEventHandle(){

    connect(this, &radarSetMainWindow::connectSucceedSig, &radarAreaWin,&radarAreaMainWindow::connectSucceedSlot);
    connect(&radarAreaWin,&radarAreaMainWindow::setAreaSig,this,&radarSetMainWindow::setAreaSlot);//配置雷达检测区域
    connect(&radarAreaWin,&radarAreaMainWindow::readAreaSig,this,&radarSetMainWindow::readAreaSlot);//读取区域
    connect(this,&radarSetMainWindow::radarAreaReturnSig,&radarAreaWin,&radarAreaMainWindow::radarDataRespond);//返回雷达数据至radarAreaWin 界面

    connect(this, &radarSetMainWindow::connectSucceedSig, &radarParasWin,&radarParasMainWindow::connectSucceedSlot);
    connect(&radarParasWin,&radarParasMainWindow::setParasSig,this,&radarSetMainWindow::setParasSlot);//配置雷达参数
    connect(&radarParasWin,&radarParasMainWindow::readParasSig,this,&radarSetMainWindow::readParasSlot);//读取参数
    connect(this,&radarSetMainWindow::radarParasReturnSig,&radarParasWin,&radarParasMainWindow::radarDataRespond);//返回雷达数据至radarparasWin 界面
}

void radarSetMainWindow::setAreaSlot(unsigned char * data, uint8_t len){

//    for (uint8_t i = 0; i < len; i++){
//          qDebug()<<QString::number(data[i],16);
//    }
     unsigned int msgId = ui->lineEdit_6->text().toUInt();
    if(canthread->sendData(QVariant(ui->comboBox_2->currentIndex()).toUInt(),//ch
                        (0x401+msgId*0x10),
                        0,
                        0,
                        data,len))
    {
        //ui->widget_4->updatePoints(0,0,0,0,0,0,0,0);//清除画布上的目标显示
        //ui->widget_4->updataArea(0,0,0,0);//清除画布上的雷达检测区域显示
        sendSetAreaOrder = true;
    }
}

void radarSetMainWindow::readAreaSlot(){
     //canthread->sendData();
     sendReadAreaOrder = true;
}

void radarSetMainWindow::setParasSlot(unsigned char *data, uint8_t len){

    for (uint8_t i = 0; i < len; i++){
          qDebug()<<QString::number(data[i],16);
    }
     unsigned int msgId = ui->lineEdit_6->text().toUInt();
    if(canthread->sendData(QVariant(ui->comboBox_2->currentIndex()).toUInt(),//ch
                        (0x200+msgId*0x10),
                        0,
                        0,
                        data,len))
    {
          sendSetParasOrder = true;
    }
}

void radarSetMainWindow::readParasSlot(){
    sendReadParasOrder = true;
}

void radarSetMainWindow::onComboBoxPopupShown(){
    ui->comboBox->clear();
    cameras = QCameraInfo::availableCameras();//获取摄像头列表
    for(int i = 0;i<cameras.size();i++)
        ui->comboBox->addItem(cameras[i].description());//摄像头描述
}


void radarSetMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void radarSetMainWindow::updateTime(){

    currentTime = QDateTime::currentDateTime();
    QString timeStr;

    if (languageSwitch){
        QLocale locale = QLocale::English;
        timeStr = QString(locale.toString(currentTime,QString("yyyy-MM-dd hh:mm:ss")));
    }else {
        QLocale locale = QLocale::Chinese;
        timeStr = QString(locale.toString(currentTime,QString("yyyy-MM-dd hh:mm:ss")));
    }

    ui->label_3->setText(timeStr);
}

void radarSetMainWindow::actionEventHandle(){
    connect(ui->actions, &QAction::triggered, this, &radarSetMainWindow::openRadarSetWindow);
    connect(ui->actionq, &QAction::triggered, this, &radarSetMainWindow::openRadarAreaSetWindow);
    connect(ui->actionx, &QAction::triggered, this, &radarSetMainWindow::openRadarToolSysSetWindow);
    connect(ui->actions_2, &QAction::triggered, this, &radarSetMainWindow::openSysSaveDataWindow);
    connect(ui->actionw, &QAction::triggered, this, &radarSetMainWindow::openTextSetWindow);
    connect(ui->actionm, &QAction::triggered, this, &radarSetMainWindow::openTargetTypeWindow);
    connect(ui->actiong, &QAction::triggered, this, &radarSetMainWindow::openFilterTargetWindow);
    connect(ui->actionp, &QAction::triggered, this, &radarSetMainWindow::openCollisionAreaWindow);
    connect(ui->actionen, &QAction::triggered, this, [this](){
        QSettings writeini("./Setting.ini", QSettings::IniFormat); // 打开ini文件
        writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
        writeini.setValue("login/language", "English"); // 写ini文件时记录为false
        switchLanguage("English");
        emit setSwitchLanguageSig("English");
    });
    connect(ui->actionCH, &QAction::triggered, this, [this](){
        QSettings writeini("./Setting.ini", QSettings::IniFormat); // 打开ini文件
        writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
        writeini.setValue("login/language", "中文"); // 写ini文件时记录为false
        switchLanguage("中文");
        emit setSwitchLanguageSig("中文");
    });

    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &toolSetWin, &radarToolSysSetMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &saveDataWin, &saveDataMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &textSetWin, &textSetMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &radarAreaWin, &radarAreaMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &radarParasWin, &radarParasMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &filterTargetWin, &filterTargetMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &collisionAreaWin, &collisionAreaMainWindow::switchLanguageSlot);
    connect(this, &radarSetMainWindow::setSwitchLanguageSigForChild, &targetTypeWin, &targetTypeMainWindow::switchLanguageSlot);

    connect(&textSetWin,&textSetMainWindow::textTypeSig,this,&radarSetMainWindow::textTypeSlot);
    connect(&saveDataWin,&saveDataMainWindow::saveDataSig,this,&radarSetMainWindow::saveDataSlot);

    connect(this,&radarSetMainWindow::writeDataSig,this,&radarSetMainWindow::writeDataSlot);
}

void radarSetMainWindow::writeDataSlot(
        unsigned int num, unsigned int *targetID, unsigned int *sate,
        float *target_x, float *target_y, float *target_v,
        float *target_RCS, float *R, float *targetAngle){

    if (!filePath.isEmpty()){
        QFile file(filePath);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out.setCodec("UTF-8");
            out<<"time:"<<currentTime.toString("hh:mm:ss.zzz")<<endl;
            for(unsigned int i = 0; i < num; i++){
                out<<" ID:"<<QString("%1").arg(targetID[i],3, 10,QLatin1Char('0'))<<" "<<\
                     " x:"<<QString::number(target_x[i],'f',2)<<"m "<<\
                     " y:"<<QString::number(target_y[i],'f',2)<<"m ";
                if (VelocityFlag){
                   out<<" v:"<<QString::number(target_v[i],'f',2)<<"m/s ";
                }
                if (RCSFlag){
                   out<<" Rcs:"<<QString::number(target_RCS[i],'f',2);
                }
                if (RangeFlag){
                   out<<" R:"<<QString::number(R[i],'f',2)<<"m ";
                }
                if (AngleFlag){
                   out<<" angle:"<<QString::number(targetAngle[i],'f',2)<<"°";
                }
                if (SateFlag){
                    out<<" sate:"<<sate[i];
                }
                out << endl;
            }
            file.close();
        } else {
            qDebug() << "Failed to open file for writing:" << filePath;
        }
    }
}

void radarSetMainWindow::saveDataSlot(QString path, QString line){
    qDebug()<<path<<line;
    QDateTime currentTime_s;
    QString folderName = "Radar_data";
    currentTime_s = QDateTime::currentDateTime();
    QString timeStr = currentTime_s.toString("yyyy-MM-dd hh-mm-ss");
    QString fileName = timeStr + ".txt";
    filePath = QDir(path).filePath(folderName + "/" + fileName);

    QDir dir(path);
    if (!dir.exists(folderName)) {
        if (!dir.mkpath(folderName)) {
            if(languageSwitch){
                QMessageBox::information(this,"System Prompts","Failed to create folder Radar_data!");
            }else {
                QMessageBox::information(this,"提示","文件夹Radar_data创建失败！");
            }

            qDebug() << "Failed to create folder:" << folderName;
            return ;
        }
    }
}

void radarSetMainWindow::textTypeSlot(bool Angle,bool Range,bool Velocity,bool RCS,bool Sate, bool Class){
    //qDebug()<<Angle<<Range<<Velocity<<RCS<<Sate<<Class;
    AngleFlag = Angle;
    RangeFlag = Range;
    VelocityFlag = Velocity;
    RCSFlag = RCS;
    SateFlag = Sate;
    ClassFlag = Class;
}

void radarSetMainWindow::switchLanguage(const QString &lang){
    if (lang == "中文"){
        ui->menu_2->setTitle(tr("雷达设置"));
        ui->actions->setText(tr("参数配置"));
        ui->actionq->setText("区域设置");
        ui->menu->setTitle(tr("系统配置"));
        ui->actionx->setText(tr("修改密码"));
        ui->actions_2->setText(tr("数据保存"));
        ui->actionw->setText(tr("文本配置"));
        ui->menuObject->setTitle(tr("Object模式"));
        ui->actionm->setText(tr("目标类型"));
        ui->actiong->setText(tr("过滤参数"));
        ui->actionp->setText(tr("碰撞参数"));
        ui->menu_4->setTitle(tr("语言"));
        ui->actionCH->setText(tr("中文"));
        ui->X_label->setText(tr("X轴范围(m)"));
        ui->Y_label->setText(tr("Y轴范围(m)"));
        ui->angle_label->setText(tr("角度范围"));
        ui->setAPPDispalyPushButton->setText(tr("应用"));
        ui->groupBox->setTitle(tr("相      机"));
        if (ui->pushButton_3->text() != tr("Open") && ui->pushButton_3->text() != tr("开启视频"))
            ui->pushButton_3->setText(tr("关闭视频"));
        else
            ui->pushButton_3->setText(tr("开启视频"));

        if (ui->pushButton_2->text() != tr("Display Info") && ui->pushButton_2->text() != tr("显示信息"))
            ui->pushButton_2->setText(tr("关闭显示"));
        else
            ui->pushButton_2->setText(tr("显示信息"));
        if ( ui->pushButton->text() != tr("录制视频") &&  ui->pushButton->text() != tr("Record"))
            ui->pushButton->setText(tr("停止录制"));
        else
            ui->pushButton->setText(tr("录制视频"));
        ui->groupBox_2->setTitle(tr("雷      达"));
        ui->label_8->setText(tr("雷达型号："));
        ui->label->setText(tr("连接状态"));
        ui->label_9->setText(tr("传输速率："));
        ui->label_10->setText(tr("雷达模式："));
        ui->label_11->setText(tr("雷达编号："));
        if (ui->pushButton_5->text() != tr("Connect") && ui->pushButton_5->text() != tr("连接设备"))
            ui->pushButton_5->setText(tr("断开连接"));
        else
            ui->pushButton_5->setText(tr("连接设备"));
        ui->label_12->setText(tr("CAN型号："));
        ui->label_13->setText(tr("通道"));
        ui->comboBox_6->setCurrentIndex(0);
        ui->comboBox_6->setItemText(0,"创芯科技");
        languageSwitch = false;
    } else {
        ui->menu_2->setTitle(tr("Radar Set"));
        ui->actions->setText(tr("Paras Set"));
        ui->actionq->setText("Area Set");
        ui->menu->setTitle(tr("System Set"));
        ui->actionx->setText(tr("Change Password"));
        ui->actions_2->setText(tr("Data Save"));
        ui->actionw->setText(tr("Text Configuration"));
        ui->menuObject->setTitle(tr("Object Mode"));
        ui->actionm->setText(tr("Target Type"));
        ui->actiong->setText(tr("Filter Paras"));
        ui->actionp->setText(tr("Collision Paras"));
        ui->menu_4->setTitle(tr("Language"));
        ui->actionCH->setText(tr("中文"));
        ui->X_label->setText(tr("XAxis(m)"));
        ui->Y_label->setText(tr("YAxis(m)"));
        ui->angle_label->setText(tr("Angle"));
        ui->setAPPDispalyPushButton->setText(tr("Save"));
        ui->groupBox->setTitle(tr("Camera"));
        if (ui->pushButton_3->text() != tr("Open") && ui->pushButton_3->text() != tr("开启视频"))
            ui->pushButton_3->setText(tr("Close"));
        else
            ui->pushButton_3->setText(tr("Open"));
        if ( ui->pushButton->text() != tr("录制视频") &&  ui->pushButton->text() != tr("Record"))
            ui->pushButton->setText(tr("Stop"));
        else
            ui->pushButton->setText(tr("Record"));

        if (ui->pushButton_2->text() != tr("Display Info") && ui->pushButton_2->text() != tr("显示信息"))
            ui->pushButton_2->setText(tr("Turn Off"));
        else
            ui->pushButton_2->setText(tr("Display Info"));
        ui->groupBox_2->setTitle(tr("Radar"));
        ui->label_8->setText(tr("Radar Type:"));
        ui->label->setText(tr("State"));
        ui->label_9->setText(tr("Baud   Rate:"));
        ui->label_10->setText(tr("Radar Mode:"));
        ui->label_11->setText(tr("Radar Num :"));
        if (ui->pushButton_5->text() != tr("Connect") && ui->pushButton_5->text() != tr("连接设备"))
            ui->pushButton_5->setText(tr("Disconnect"));
        else
            ui->pushButton_5->setText(tr("Connect"));
        ui->label_12->setText(tr("CAN   Type:"));
        ui->label_13->setText(tr("Channel"));
        ui->comboBox_6->setItemText(0,"CHUANGXIN TEC");
        languageSwitch = true;
    }
    setSwitchLanguageSigForChild(lang);
}

void radarSetMainWindow::openRadarSetWindow(){
    radarParasWin.setWindowModality(Qt::ApplicationModal);//阻塞当前窗口，不允许操作其他窗口
    radarParasWin.show();//显示窗口
}

void radarSetMainWindow::openRadarAreaSetWindow(){
    radarAreaWin.setWindowModality(Qt::ApplicationModal);//阻塞当前窗口，不允许操作其他窗口
    radarAreaWin.show();//显示窗口
}

void radarSetMainWindow::openRadarToolSysSetWindow(){
    toolSetWin.setWindowModality(Qt::ApplicationModal);
    toolSetWin.show();
    connect(&toolSetWin,&radarToolSysSetMainWindow::closeSysWin,this,&radarSetMainWindow::closeSetWindow);
}

void radarSetMainWindow::closeSetWindow(){
    emit closeSetWindowSig();
    this->close();
}

void radarSetMainWindow::openSysSaveDataWindow(){
    saveDataWin.setWindowModality(Qt::ApplicationModal);
    saveDataWin.show();
}

void radarSetMainWindow::openTextSetWindow(){
    textSetWin.setWindowModality(Qt::ApplicationModal);
    textSetWin.show();
}

void radarSetMainWindow::openTargetTypeWindow(){
    targetTypeWin.setWindowModality(Qt::ApplicationModal);
    targetTypeWin.show();
}

void radarSetMainWindow::openFilterTargetWindow(){
    filterTargetWin.setWindowModality(Qt::ApplicationModal);
    filterTargetWin.show();
}

void radarSetMainWindow::openCollisionAreaWindow(){
    collisionAreaWin.setWindowModality(Qt::ApplicationModal);
    collisionAreaWin.show();
}

void radarSetMainWindow::on_setAPPDispalyPushButton_clicked()
{
    xScale = ui->X_lineEdit->text().toInt();
    yScale = ui->Y_lineEdit->text().toInt();
    angle = ui->angle_lineEdit->text().toInt();
    if (yScale > 60){
        if (languageSwitch){
            QMessageBox::information(this,tr("System Prompts"),tr("The input Y-axis range is too large"));
        }else{
            QMessageBox::information(this,tr("提示"),tr("输入Y轴范围过大"));
        }
        return;
    }
    if (xScale > 40){
        if (languageSwitch){
             QMessageBox::information(this,tr("System Prompts"),tr("The input X-axis range is too large"));
        }else{
             QMessageBox::information(this,tr("提示"),tr("输入X轴范围过大"));
        }
        return;
    }
    if (angle > 180){
        if (languageSwitch){
             QMessageBox::information(this,tr("System Prompts"),tr("The input angle range is too large"));
        }else{
             QMessageBox::information(this,tr("提示"),tr("输入角度范围过大"));
        }
         return;
    }
    QSettings writeini("./SystemPara.ini", QSettings::IniFormat); // 打开ini文件
    writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
    writeini.setValue("Axis/xScale", xScale); // 把xScale写入ini文件
    writeini.setValue("Axis/yScale", yScale); // 把yScale写入ini文件
    writeini.setValue("Axis/angle", angle); // 把angle写入ini文件
    ui->widget_4->updateAxis(xScale,yScale,angle);
}


void radarSetMainWindow::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Cluster"){
        ui->menuObject->menuAction()->setVisible(false);
    } else if (arg1 == "Object"){
        ui->menuObject->menuAction()->setVisible(false);
    } else {
        ui->menuObject->menuAction()->setVisible(false);
    }
}

void radarSetMainWindow::changeControlStates(bool states){

    ui->comboBox_2->setEnabled(states);
    ui->comboBox_6->setEnabled(states);
    ui->comboBox_3->setEnabled(states);
    ui->comboBox_5->setEnabled(states);
    ui->comboBox_4->setEnabled(states);
    ui->lineEdit_6->setEnabled(states);
    //ui->menu_2->menuAction()->setVisible(states);
}

void radarSetMainWindow::on_pushButton_5_clicked()
{
    //init CAN connect radar
    if (ui->comboBox_6->currentText() == tr("创芯科技") || ui->comboBox_6->currentText() == tr("CHUANGXIN TEC")){
        if (connectStates == false){
            UINT baundRate = 0;
            if(ui->comboBox_5->currentText().indexOf("Kbps") != -1)
                baundRate = ui->comboBox_5->currentText().remove("Kbps").toUInt();
            else
                baundRate = QVariant(ui->comboBox_5->currentText().remove("Mbps").toFloat()).toUInt()*1000;

            //qDebug()<<baundRate;
            bool dev = canthread->openDevice(4,//QVariant(ui->comboBox->currentIndex()).toUInt(),
                                          0,//设备索引,可能需要修改
                                          baundRate);
            if (dev == true){
                if(canthread->initCAN()){
                    if (canthread->startCAN()){
                        if(languageSwitch){
                            ui->pushButton_5->setText("Disconnect");
                        } else {
                            ui->pushButton_5->setText("断开连接");
                        }
                        QSettings writeini("./SystemPara.ini", QSettings::IniFormat); // 打开ini文件
                        writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
                        writeini.setValue("baud/baudidx", ui->comboBox_5->currentIndex()); // 把xScale写入ini文件
                        writeini.setValue("radarmode/modeidx", ui->comboBox_4->currentIndex()); // mode
                        writeini.setValue("canType/canidx", ui->comboBox_6->currentIndex()); // can
                        changeControlStates(false);
                        connectStates = true;
                        emit connectSucceedSig(connectStates);
                        setLED(ui->label_led, 2, 22);//绿色
                        canthread->start();
                    } else {
                        if (languageSwitch){
                             QMessageBox::warning(this,tr("Warn"),tr("CAN boot failed!"));
                        }else{
                            QMessageBox::warning(this,tr("警告"),tr("CAN启动失败！"));
                        }
                    }
                } else {
                    if (languageSwitch){
                        QMessageBox::warning(this,tr("Warn"),tr("CAN initialization failed!"));
                    }else{
                        QMessageBox::warning(this,tr("警告"),tr("CAN初始化失败！"));
                    }
                }

            } else
                if (languageSwitch){
                    QMessageBox::warning(this,tr("Warn"),tr("CAN device turned on failed!"));
                }else{
                    QMessageBox::warning(this,tr("警告"),tr("CAN设备打开失败！"));
                }
        } else {
            if(languageSwitch){
                ui->pushButton_2->setText("Dispaly Info");
                ui->pushButton_5->setText("Connect");
            } else {
                ui->pushButton_2->setText("显示信息");
                ui->pushButton_5->setText(tr("连接设备"));
            }
            switchTargetInfo = false;
            changeControlStates(true);
            connectStates = false;
            emit connectSucceedSig(connectStates);
            filePath.clear();
            setLED(ui->label_led, 0, 22);//灰色
            ui->widget_4->updatePoints(0,0,0,0,0,0,0,0);//清除画布上的目标显示
            ui->widget_4->updataArea(0,0,0,0);//清除画布上的雷达检测区域显示
            canthread->stop();
            canthread->reSetCAN();
            canthread->closeDevice();
        }
    } else {
        qDebug()<< ui->comboBox_6->currentText();
    }
}

void radarSetMainWindow::onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel){
    //qDebug()<<"CH"<<channel;
    uint8_t index = 0;
    bool updataAreaFlag = false;
    unsigned int msgId = ui->lineEdit_6->text().toUInt();

    targetNum = 0;
    memset((void *)x, 0, sizeof(x));
    memset((void *)y, 0, sizeof(y));
    memset((void *)ID, 0, sizeof(ID));//雷达目标ID号
    memset((void *)vel, 0, sizeof(vel));
    memset((void *)Range, 0, sizeof(Range));
    memset((void *)targetAngle, 0, sizeof(targetAngle));
    memset((void *)targetSate, 0, sizeof(targetSate));

    if (channel){
        //NOP
    }

    for(unsigned int i = 0;i < dwRel;i ++)
    {
        if (vci[i].ID == (0x60A + msgId*0x10)){
            targetNum = vci[i].Data[0];
            //qDebug()<<"num"<<targetNum;
        }

        if(vci[i].ID == (0x60B + msgId*0x10)){
//            qDebug()<<(vci[i].Data[1]*32 + (vci[i].Data[2]>>3))*0.2-500;//y
//            qDebug()<<((vci[i].Data[2]&0x07)*256 + vci[i].Data[3])*0.2 - 204.6;//x
//            qDebug()<<(vci[i].Data[4]*4+(vci[i].Data[5]>>6))*0.25-128;//vy
//            qDebug()<<((vci[i].Data[5]&0x3f)*8+(vci[i].Data[6]>>5))*0.25-64;//vx
//            qDebug()<<(vci[i].Data[6]&0x07);//Sate 0静止 1运动
//            qDebug()<<vci[i].Data[7]*0.5-64;//RCS
            float vx = ((vci[i].Data[5]&0x3f)*8+(vci[i].Data[6]>>5))*0.25-64;
            float vy = (vci[i].Data[4]*4+(vci[i].Data[5]>>6))*0.25-128;
            ID[index] = vci[i].Data[0];
            y[index] = (vci[i].Data[1]*32 + (vci[i].Data[2]>>3))*0.2-500;
            x[index] = ((vci[i].Data[2]&0x07)*256 + vci[i].Data[3])*0.2 - 204.6;
            Range[index] = sqrt(x[index]*x[index]+y[index]*y[index]);
            if (Range[index] != 0.0)
                targetAngle[index] = atan(x[index]/y[index])*180/3.1415926;
            vel[index] = sqrt(vx*vx + vy*vy)*3.6;
            RCS_A[index] = vci[i].Data[7]*0.5-64;
            targetSate[index] = (vci[i].Data[6]&0x07);
            index = (index + 1) % 64;//防止非法越界
        }

        if (vci[i].ID == (0x201 + msgId*0x10)){//雷达状态信息
            //qDebug()<<vci[i].Data[4]<<vci[i].Data[5]<<vci[i].Data[6];
            radarID_paraswin = (unsigned char)(vci[i].Data[4]&0x07);
            radarOutMode = (unsigned char)((vci[i].Data[5]&0x0c)>>2);
            radarBaud = (unsigned char)((vci[i].Data[6]&0xe0)>>5);
        }

        if (vci[i].ID == (0x700 + msgId*0x10)){//心跳
//            qDebug()<<QString::number(vci[i].ID,16);
//            for(int j = 0;j < vci[i].DataLen;j ++){
//                qDebug()<< QString("%1 ").arg(vci[i].Data[j],2,16,QChar('0')).toUpper();
//            }
        }

        if (vci[i].ID == (0x402 + msgId*0x10)){//碰撞区域信息
            maxNumTarget = vci[i].Data[0]&0x3f;
            radarID = ((vci[i].Data[0]&0xC0)>>6);
            p1_long= ((vci[i].Data[1]&0xff)<<5)+((vci[i].Data[2]&0xfc)>>3);
            p1_lat = ((vci[i].Data[2]&0x07)<<8)+(vci[i].Data[3]&0xff);
            p2_long = ((vci[i].Data[4]&0xff)<<5)+((vci[i].Data[5]&0xfc)>>3);
            p2_lat = ((vci[i].Data[5]&0x07)<<8)+(vci[i].Data[6]&0xff);
            updataAreaFlag = true;
        }

    }
    //qDebug()<<"--------------------------";
    if (index == targetNum){//确保数据是全的
        emit writeDataSig(targetNum,ID,targetSate,x,y,vel,RCS_A,Range,targetAngle);
        ui->widget_4->updatePoints(x,y,vel,Range,targetAngle,ID,targetNum,switchTargetInfo);
    } else {
        emit writeDataSig(index,ID,targetSate,x,y,vel,RCS_A,Range,targetAngle);
        ui->widget_4->updatePoints(x,y,vel,Range,targetAngle,ID,index,switchTargetInfo);
    }

    if (updataAreaFlag == true){
        ui->widget_4->updataArea(p1_long,p1_lat,p2_long,p2_lat);
    }

    if (sendReadAreaOrder){
         emit radarAreaReturnSig(maxNumTarget,radarID,p1_long,p1_lat,p2_long,p2_lat);
        sendReadAreaOrder = false;
    }

    if (sendReadParasOrder){
        emit radarParasReturnSig(radarID_paraswin,radarOutMode,radarBaud);
        sendReadParasOrder = false;
    }

}

void radarSetMainWindow::setLED(QLabel* label, int color, int size)
{
    // 将label中的文字清空
    label->clear();
    // 先设置矩形大小
    // 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
    // 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
    QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
    QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
    QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
    QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
    // 再设置边界形状及边框
    QString border_radius = QString("border-radius: %1px;").arg(size/2);    // 边框是圆角，半径为size/2
    QString border = QString("border:1px solid black;");                    // 边框为1px黑色
    // 最后设置背景颜色
    QString background = "background-color:";
    switch (color) {
    case 0:
        // 灰色
        background += "rgb(190,190,190)";
        break;
    case 1:
        // 红色
        background += "rgb(255,0,0)";
        break;
    case 2:
        // 绿色
        background += "rgb(0,255,0)";
        break;
    case 3:
        // 黄色
        background += "rgb(255,255,0)";
        break;
    default:
        break;
    }

    const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
    label->setStyleSheet(SheetStyle);
}


void radarSetMainWindow::on_pushButton_3_clicked()
{
    //connect camera
    if (ui->comboBox->currentIndex() >= 0){
        if (languageSwitch){
            if (ui->pushButton_3->text() == tr("Open")){
                curCamera = new QCamera(cameras[ui->comboBox->currentIndex()],this);//新建QCamera
                curCamera->setViewfinder(ui->CameraWidget);
                curCamera->start();

                ui->pushButton_3->setText(tr("Close"));
            } else {
                curCamera->stop();
                //ui->CameraWidget->clearFocus();
                ui->pushButton_3->setText(tr("Open"));
            }
        } else {
            if (ui->pushButton_3->text() == tr("开启视频")){
                curCamera = new QCamera(cameras[ui->comboBox->currentIndex()],this);//新建QCamera
                curCamera->setViewfinder(ui->CameraWidget);
                curCamera->start();

                ui->pushButton_3->setText(tr("关闭视频"));
            } else {
                curCamera->stop();
                //ui->CameraWidget->clearFocus();
                ui->pushButton_3->setText(tr("开启视频"));
            }
        }
    } else {
        if (languageSwitch){
            QMessageBox::information(this,tr("System Prompts"),tr("Not find Camera!"));
        }else {
             QMessageBox::information(this,tr("提示"),tr("未发现摄像头！"));
        }
    }
}

void radarSetMainWindow::on_pushButton_clicked()
{
    //Record a video
    if (curCamera != Q_NULLPTR){
        if (languageSwitch){
            if (ui->pushButton->text() == "Record"){
                mediaRecorder = new QMediaRecorder(curCamera, this);
                //qDebug()<<mediaRecorder->isMuted();
                if (mediaRecorder->isMuted())
                {
                    ui->pushButton->setText("Stop");
                    mediaRecorder->record();
                }
            } else {
                ui->pushButton->setText("Record");
                mediaRecorder->stop();
            }
        }else {
            if (ui->pushButton->text() == "录制视频"){
                mediaRecorder = new QMediaRecorder(curCamera, this);
                //qDebug()<<mediaRecorder->isMuted();
                if (mediaRecorder->isMuted())
                {
                    ui->pushButton->setText("停止录制");
                    mediaRecorder->record();
                }
            } else {
                ui->pushButton->setText("录制视频");
                mediaRecorder->stop();
            }
        }
    }
}

void radarSetMainWindow::on_pushButton_2_clicked()
{
    if (connectStates){
        if(languageSwitch){
            if (ui->pushButton_2->text() == tr("显示信息") || ui->pushButton_2->text() == tr("Dispaly Info")){
                ui->pushButton_2->setText("Turn Off");
                switchTargetInfo = true;
            } else {
                ui->pushButton_2->setText("Dispaly Info");
                switchTargetInfo = false;
            }
        } else {
            if (ui->pushButton_2->text() == tr("显示信息") || ui->pushButton_2->text() == tr("Dispaly Info")){
                ui->pushButton_2->setText("关闭显示");
                switchTargetInfo = true;
            } else {
                ui->pushButton_2->setText("显示信息");
                switchTargetInfo = false;
            }
        }
    } else {
        if (languageSwitch){
            QMessageBox::information(this,tr("System Prompts"),tr("Please connect equipment!"));
        }else {
             QMessageBox::information(this,tr("提示"),tr("请先连接设备！"));
        }
    }
}
