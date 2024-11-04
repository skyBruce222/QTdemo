#include "radarareamainwindow.h"
#include "ui_radarareamainwindow.h"
#include <QSettings>
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>

radarAreaMainWindow::radarAreaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::radarAreaMainWindow)
{
    ui->setupUi(this);
    initAreaWin();
}

radarAreaMainWindow::~radarAreaMainWindow()
{
    delete ui;
}

void radarAreaMainWindow::initAreaWin(){
    setWindowTitle(tr("区域设置"));
    setWindowIcon(QIcon(":/img/dragonbool.jpg"));
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
    ui->lineEdit->setValidator(new QIntValidator(this));//只允许输入纯数字形式
    ui->lineEdit_2->setValidator(new QIntValidator(this));//只允许输入纯数字形式
    ui->lineEdit_3->setValidator(new QIntValidator(this));//只允许输入纯数字形式
    ui->lineEdit_4->setValidator(new QIntValidator(this));//只允许输入纯数字形式
    ui->lineEdit_5->setValidator(new QIntValidator(this));//只允许输入纯数字形式

    QSettings setting("./Setting.ini", QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QString lang = setting.value("login/language").toString();
    if (lang.isEmpty()){
        switchLanguage("中文");
    } else{
        switchLanguage(lang);
    }
}

void radarAreaMainWindow::on_pushButton_clicked()
{
    //read radar parameters
    //0x201
    if (connectFlag){
        unsigned char data[8];
        memset((void *)data,0,sizeof(data));
        emit readAreaSig();
    } else {
        if (languageFlag)
            QMessageBox::information(this,"提示","请先连接设备！");
        else
            QMessageBox::information(this,"System Prompt","Please connect your device first!");
    }
}

void radarAreaMainWindow::radarDataRespond(
        short int maxNum, short int ID, short int p1_long,
        short int p1_lat, short int p2_long, short int p2_lat){
    qDebug()<<ID;
    float p1_l = (p1_long/5.0 - 500);
    float p1_l2 = (p1_lat/5.0 - 204.6);
    float p2_l = (p2_long/5.0 -500);
    float p2_l2 = (p2_lat/5.0 - 204.6);

    ui->lineEdit_3->setText(QString::number(p1_l));
    ui->lineEdit->setText(QString::number(p1_l2));
    ui->lineEdit_4->setText(QString::number(p2_l));
    ui->lineEdit_2->setText(QString::number(p2_l2));
    ui->lineEdit_5->setText(QString::number(maxNum));
}

void radarAreaMainWindow::connectSucceedSlot(bool flag){
    connectFlag = flag;
}

void radarAreaMainWindow::on_pushButton_2_clicked()
{
    //set radar parameters
    //0x401
    unsigned char data[8];
    memset((void *)data, 0, sizeof(data));
    if (connectFlag){
        if (ui->comboBox->currentText() == tr("Active") && ui->comboBox_2->currentText() == tr("Active")){
            float p1_latf = ((ui->lineEdit->text().toFloat()+204.6)*5);
            float p1_longf = ((ui->lineEdit_3->text().toFloat()+500)*5);
            float p2_latf = ((ui->lineEdit_2->text().toFloat()+204.6)*5);
            float p2_longf = ((ui->lineEdit_4->text().toFloat()+500)*5);
            unsigned int maxNum = ui->lineEdit_5->text().toUInt();
            short int p1_lat = (short int )p1_latf;
            short int p1_long = (short int )p1_longf;
            short int p2_lat = (short int )p2_latf;
            short int p2_long = (short int )p2_longf;
            data[0] = (unsigned char)maxNum;
            data[1] = 0x01;
            data[2] = ((p1_long&0xfe0)>>5);
            data[3] = ((p1_long&0x1f)<<3)+((p1_lat&0x700)>>8);
            data[4] = (p1_lat&0xff);
            data[5] = ((p2_long&0xfe0)>>5);
            data[6] = ((p2_long&0x1f)<<3)+((p2_lat&0x700)>>8);
            data[7] = (p2_lat&0xff);
            qDebug()<<p1_latf<<p2_latf<<p2_longf<<p1_longf;
            if (p2_longf>p1_longf && p1_latf>p2_latf){
                emit setAreaSig(data,8);
            }
            else{
                if (languageFlag)
                    QMessageBox::information(this,"提示","区域设置错误！");
                else
                    QMessageBox::information(this,"System Prompt","radar Area set paras error!");
            }

        }else {
            this->close();
        }
    } else {
        if (languageFlag)
            QMessageBox::information(this,"提示","请先连接设备！");
        else
            QMessageBox::information(this,"System Prompt","Please connect your device first!");
    }
}

void radarAreaMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void radarAreaMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        setWindowTitle(tr("区域设置"));
        ui->label->setText("区域使能");
        ui->label_2->setText("坐标使能");
        ui->label_7->setText("最大目标输出个数");
        ui->pushButton->setText("读取");
        ui->pushButton_2->setText("应用");
        languageFlag = true;
    } else {
        setWindowTitle(tr("Area Set"));
        ui->label->setText("Zone");
        ui->label_2->setText("Axis");
        ui->label_7->setText("MaxOuptutNum");
        ui->pushButton->setText("Read");
        ui->pushButton_2->setText("Save");
        languageFlag = false;
    }
}
