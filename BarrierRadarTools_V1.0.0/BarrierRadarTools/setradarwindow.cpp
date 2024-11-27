#include "setradarwindow.h"
#include "ui_setradarwindow.h"
#include <QDebug>
#include <QRegularExpression>
#include <QRegExp>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include <QFile>

setRadarWindow::setRadarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setRadarWindow)
{
    ui->setupUi(this);
    initSetRadarWindow();
}

setRadarWindow::~setRadarWindow()
{
    if (serialPort){
        serialPort->close();
        delete serialPort;
        serialPort = nullptr;
    }
    delete ui;
}

void setRadarWindow::initSetRadarWindow(){

    setWindowTitle(tr("Radar Tools V1.0"));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(this->width(),this->height());//禁止放大
    setLED(ui->label_led, 0, 22);

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &setRadarWindow::updateTime);
    timer->start(1000);//1Sec update

    serialPort = new QSerialPort(this);

    connect(serialPort,&QSerialPort::readyRead,this,&setRadarWindow::SerialReadDataSlot);
    connect(serialPort,&QSerialPort::errorOccurred,this,&setRadarWindow::handleSerialError);

    connect(this, &setRadarWindow::sendRodDirectionSig, this, &setRadarWindow::sendRodDirectionSlot);
    connect(this, &setRadarWindow::sendRodDirectionSetSig, this, &setRadarWindow::sendRodDirectionSetSlot);
    connect(this, &setRadarWindow::displayAllPointsSig, this, &setRadarWindow::displayAllPointsSlot);
    connect(this, &setRadarWindow::stateChangeSig, this, &setRadarWindow::stateChangeSlot);
    connect(this, &setRadarWindow::upgradeFwSig, this, &setRadarWindow::upgradeFwSlot);
}

/**
 *  @b Description
 *  @n
 *      CRC8
 *
 *  @retval
 *      CRC.
 */
uint8_t setRadarWindow::crc8(uint8_t* pbuf, int32_t len)
{
     uint8_t* data = pbuf;
     uint8_t crc = 0;
     while ( len-- )
     crc = crc8_table[crc^*(data++)];
     return crc;
}


void setRadarWindow::upgradeFwSlot(){

    QString cmd_SR = "SR\r\n";
    QByteArray upgrade_test = "55aaff00f000000072aa55";//test
    QByteArray upgrade_erase = "55aaff00f1000000f3aa55";//erase
    QByteArray upgrade_sendSize;//发送文件大小
    QByteArray upgrade_sendData;//发送文件内容
    QByteArray upgrade_checkSum;//= "55aaff00fd000800047006007b0e4f023daa55";//校验和读取
    QByteArray upgrade_upgrade = "55aaff00f80000000caa55";//更新
    QByteArray upgrade_SR_2 = "55aaff00f9000000ffaa55";//重启

    QString validData;
    QByteArray temp;
    uint16_t fillInLen = 0;

    switch (upgrade_step) {
        case SET_BOOT_MODE:
            sendDataBySerialPort(cmd_SR,false);
            upgrade_step = SR;

        break;
        case SR:
            Delay_MSec_Suspend(30);
            sendDataBySerialPort(upgrade_test,true);
            upgrade_step = TEST;

        break;
        case TEST:
            Delay_MSec_Suspend(30);
            sendDataBySerialPort(upgrade_erase, true);
            upgrade_step = ERASE;

        break;
        case ERASE://不是擦除，是发送包总数
            Delay_MSec_Suspend(30);
            upgrade_sendSize.clear();
            upgrade_sendSize.append("55aaff00f2000400");
            upgrade_sendSize.append(QString::number(sizefirmware&0xff,16).toLatin1());
            upgrade_sendSize.append(QString::number((sizefirmware>>8)&0xff,16).toLatin1());
            upgrade_sendSize.append("0000ffaa55");
            sendDataBySerialPort(upgrade_sendSize,true);
            upgrade_step = SEND_FILE_SIZE;
        break;
        case SEND_FILE_SIZE://发送完了包号之后发送数据内容
            Delay_MSec_Suspend(30);
            upgrade_sendData.clear();
            validData.clear();
            upgrade_sendData.append("55aaff00f3004400");
            upgrade_sendData.append(QString("%1").arg((framecount&0xff),2,16,QLatin1Char('0')));
            upgrade_sendData.append(QString("%1").arg(((framecount>>8)&0xff),2,16,QLatin1Char('0')));
            upgrade_sendData.append(QString("%1").arg(((framecount>>16)&0xff),2,16,QLatin1Char('0')));
            upgrade_sendData.append(QString("%1").arg(((framecount>>24)&0xff),2,16,QLatin1Char('0')));
            validData = firmbindata.mid((framecount*64)*2,64*2);
            temp.clear();
            temp = QByteArray::fromHex(validData.toLatin1());
            for (int idx = 0; idx < temp.length(); idx ++){
                checkSum += static_cast<unsigned char>(temp[idx]);
            }
            if (validData.size() < 64*2){//最后一包
                fillInLen = validData.size()/2;
                for(int i = 0; i< (64 - fillInLen); i++){
                    validData.append("ff");//不够的全填FF
                }
            }
            upgrade_sendData.append(validData);
            upgrade_sendData.append("ffaa55");
            //qDebug()<< framecount;
            sendDataBySerialPort(upgrade_sendData,true);
            upgrade_step = SEND_FILE;

        break;

        case SEND_FILE:
            Delay_MSec_Suspend(30);
            //qDebug()<<"read check sum";
            upgrade_checkSum.clear();
            upgrade_checkSum.append("55aaff00fd000800");
            upgrade_checkSum.append(QString("%1").arg(((firmbindata.size()/2)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg((((firmbindata.size()/2) >> 8)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg((((firmbindata.size()/2) >> 16)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg((((firmbindata.size()/2) >> 24)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg((checkSum&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg(((checkSum >> 8)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg(((checkSum >> 16)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append(QString("%1").arg(((checkSum >> 24)&0xff),2,16,QLatin1Char('0')));
            upgrade_checkSum.append("ffaa55");
            sendDataBySerialPort(upgrade_checkSum,true);
            upgrade_step = CHECKSUM;
        break;

        case CHECKSUM:
            Delay_MSec_Suspend(30);
            sendDataBySerialPort(upgrade_upgrade,true);
            upgrade_step = UPGRADE;
        break;

        case UPGRADE:
            Delay_MSec_Suspend(30);
            sendDataBySerialPort(upgrade_SR_2,true);
            upgrade_step = SR_2;
        break;

        default:

        break;
    }
}

void setRadarWindow::sendRodDirectionSlot(){
    //qDebug()<<"in sendRodDirectionSlot";
    QString readParas;
    if (ui->comboBox->currentText() == "直杆"){
         readParas = "ReadCLI rodDirection 0\r\n";
    } else {
         readParas = "ReadCLI rodDirection\r\n";
    }

    Delay_MSec_Suspend(30);
    sendDataBySerialPort(readParas,false);
}

void setRadarWindow::sendRodDirectionSetSlot(){
    //qDebug()<<"in sendRodDirectionSlot";
    QString readParas;
    if (ui->comboBox->currentText() == "直杆"){
        if (ui->comboBox_2->currentText() == "左"){
            readParas = "WriteCLI rodDirection 0 1\r\n";
        } else if(ui->comboBox_2->currentText() == "右"){
            readParas = "WriteCLI rodDirection 0 2\r\n";
        } else {
            readParas = "WriteCLI rodDirection 0 0\r\n";
        }
    } else {
        if (ui->comboBox_2->currentText() == "左"){
            readParas = "WriteCLI rodDirection 0\r\n";
        } else if (ui->comboBox_2->currentText() == "右"){
            readParas = "WriteCLI rodDirection 1\r\n";
        } else {
            QMessageBox::information(this,"提示","杆件方向设置错误！");
        }
    }

    Delay_MSec_Suspend(30);
    sendDataBySerialPort(readParas,false);
}

void setRadarWindow::displayAllPointsSlot(){
    QString cmd = "55aaff001301010001ffaa55";
    Delay_MSec_Suspend(30);
    hexSendFlag = true;
    sendDataBySerialPort(cmd,true);
}

void setRadarWindow::Delay_MSec_Suspend(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer );
}

void setRadarWindow::stateChangeSlot(bool states){
    //qDebug()<<states;
    if (states){
        if (ledLightCnt < 255){
            ledLightCnt ++;
        }
       ledDownCnt = 0;
    } else {
        if (ledDownCnt < 255){
            ledDownCnt ++;
        }
       ledLightCnt = 0;
    }

    if (ledLightCnt >= 2){
        setLED(ui->label_led,2,22);
    }
    if (ledDownCnt >= 15){
      setLED(ui->label_led,0,22);
    }
}

void setRadarWindow::upgradeProcess(QByteArray data){
    uint16_t dataLen = 0;
    //uint16_t Func = 0;
    QByteArray checkSumTemp;
    //uint32_t csum = 0;

    switch (upgrade_step) {
        case SET_BOOT_MODE:
            if (data.contains("Done\n")){
                emit upgradeFwSig();
            }
        break;

        case SR:
            if (data.contains("Enter bootloader hex mode -> \n")){
                emit upgradeFwSig();
            }
        break;

        case TEST:
            if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) == 0x00f0){
                emit upgradeFwSig();
                sendCmdCnt = 0;
            } else {
                sendCmdCnt++;
            }
            if (sendCmdCnt >= 3){
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","升级测试失败！");
                return ;
            }

        break;

        case ERASE:

             if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) == 0x00f1){
                 emit upgradeFwSig();
             }else {
                 sendCmdCnt++;
             }
             if (sendCmdCnt >= 3){
                 upgrade_step = SET_BOOT_MODE;
                 checkSum = 0;
                 framecount = 0;
                 sendCmdCnt = 0;
                 upgradeFw = false;
                 setUIcontrol(!upgradeFw);
                 ui->progressBar->setValue(0);
                 QMessageBox::information(this,"提示","擦除失败！");
                 return ;
             }
        break;

        case SEND_FILE_SIZE:
            if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) == 0x00f2){
                emit upgradeFwSig();
            }else {
                sendCmdCnt++;
            }

            if (sendCmdCnt >= 3){
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","文件大小发送失败！");
                return ;
            }

        break;

        case SEND_FILE://这里其实是解析SEND_FILE的返回值
            //qDebug()<<frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) << sendCmdCnt;
            if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) != 0x00f3){
                upgrade_step = SEND_FILE_SIZE;
                sendCmdCnt ++;
            } else {
                framecount++;
                ui->progressBar->setValue(framecount);
                sendCmdCnt = 0;
                if (framecount < sizefirmware){
                    upgrade_step = SEND_FILE_SIZE;
                }else {
                    upgrade_step = SEND_FILE;
                }

            }

            if (sendCmdCnt >= 3){
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","固件发送失败！");
                return ;
            }

            emit upgradeFwSig();
        break;

        case CHECKSUM:
            //qDebug()<<frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) << sendCmdCnt;
            if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) != 0x00fd){
                sendCmdCnt ++;
            } else {
                sendCmdCnt = 0;
                emit upgradeFwSig();
            }

            if (sendCmdCnt >= 3){
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","校验失败！");
            }

        break;

        case UPGRADE:
            //qDebug()<<frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) << sendCmdCnt;
            if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) != 0x00f8){
                sendCmdCnt ++;
            } else {
                sendCmdCnt = 0;
                emit upgradeFwSig();
            }
            if (sendCmdCnt >= 3){
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","更新失败！");
            }

        break;

        case SR_2:
            //qDebug()<<frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) << sendCmdCnt;
            if (frame_format_analysis(QByteArray::fromHex(data.toHex()),&dataLen) != 0x00f9){
                sendCmdCnt ++;
            } else {
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","升级成功！");
            }

            if (sendCmdCnt >= 3){
                upgrade_step = SET_BOOT_MODE;
                checkSum = 0;
                framecount = 0;
                sendCmdCnt = 0;
                upgradeFw = false;
                setUIcontrol(!upgradeFw);
                ui->progressBar->setValue(0);
                QMessageBox::information(this,"提示","更新失败！");
            }

        break;

        default:

        break;
    }
}

uint16_t setRadarWindow::frame_format_analysis(QByteArray data, uint16_t *dataLen){

    if (static_cast<unsigned char>(data[0]) != 0x55 && static_cast<unsigned char>(data[1]) != 0xaa){
        return 1;
        if (static_cast<unsigned char>(data[data.length() - 2]) != 0xaa && static_cast<unsigned char>(data[data.length() - 1]) != 0x55){
             return 1;
        }
    }

    if (static_cast<unsigned char>(data[2]) != 0x00 || static_cast<unsigned char>(data[3]) != 0x00){
        return 1;
    }

    uint16_t funC = static_cast<unsigned char>(data[4]) | (static_cast<unsigned char>(data[5]) << 8);
    *dataLen = static_cast<unsigned char>(data[6]) | (static_cast<unsigned char>(data[7]) << 8);

    return funC;
}

void setRadarWindow::SerialReadDataSlot(){

    QByteArray readData = serialPort->readAll();
    //qDebug()<<readData;
    if (upgradeFw){
        timeOutCnt = 0;
        upgradeProcess(readData);
        return ;
    } else {
        setParasProcess(readData);
    }
}

void setRadarWindow::handleSerialError(QSerialPort::SerialPortError error){
    //qDebug()<<error;
    if (error == QSerialPort::PermissionError){
        this->hide();
        emit reConnectSerialSig();
    }
}

void setRadarWindow::setParasProcess(QByteArray readData){
    if (hexSendFlag){
        QByteArray temp = QByteArray::fromHex(readData.toHex());

        if (static_cast<unsigned char>(temp[0]) == 0x55 && static_cast<unsigned char>(temp[1]) == 0xaa){
            if (static_cast<unsigned char>(temp[temp.length() - 2]) == 0xaa && static_cast<unsigned char>(temp[temp.length() - 1]) == 0x55){
                //qDebug()<<"标准帧";

                uint16_t funC = static_cast<unsigned char>(temp[4]) | static_cast<unsigned char>(temp[5]) << 8;
                uint16_t dataLen = static_cast<unsigned char>(temp[6]) | static_cast<unsigned char>(temp[7]) << 8;
                if (funC == 0x0116 && dataLen == 0x08){
                     pIndex[pIdx] = static_cast<unsigned char>(temp[8]);
                     uint16_t x = ((static_cast<unsigned char>(temp[11])&0x0f)<<8 | static_cast<unsigned char>(temp[9]));
                     uint16_t y = ((static_cast<unsigned char>(temp[11])&0xf0)<<4 | static_cast<unsigned char>(temp[10]));
                     p_x[pIdx] = (x/4.0-128)/20.0;
                     p_y[pIdx] = y/80.0;
                     p_v[pIdx] = (static_cast<unsigned char>(temp[12]) - 128)*0.4/0.46;
                     p_p[pIdx] = ((static_cast<unsigned char>(temp[14]) << 8)|static_cast<unsigned char>(temp[13]));
                     p_area[pIdx] = (static_cast<unsigned char>(temp[15]) & 0x80) >> 7;
                     p_thr[pIdx] = (static_cast<unsigned char>(temp[15]) & 0x40) >> 6;
                     p_t[pIdx] = (static_cast<unsigned char>(temp[15]) & 0x01);
                     if ( p_t[pIdx] == 1){
                        states = true;
                     }
                     pIdx++;
                } else if (funC == 0x0119 && dataLen == 0x08){
                    emit stateChangeSig(states);
                    states = false;
                    ui->widget_2->updatePoints(pIndex,p_x,p_y,p_v,p_p,p_area,p_thr,p_t,pIdx,displayInfo,disVel);
                    memset((void *)pIndex,0,sizeof(pIndex));
                    memset((void *)p_x,0,sizeof(p_x));
                    memset((void *)p_y,0,sizeof(p_y));
                    memset((void *)p_v,0,sizeof(p_v));
                    memset((void *)p_p,0,sizeof(p_p));
                    memset((void *)p_area,0,sizeof(p_area));
                    memset((void *)p_thr,0,sizeof(p_thr));
                    memset((void *)p_t,0,sizeof(p_t));
                    pIdx = 0;
                }
            }
        }
    } else{
        if (sendReadParasCmdFlag){
            if (readData.contains("Done\n")){
                sendReadParasCmdFlag = false;
                emit sendRodDirectionSig();
            }
        }

        if (sendSetParasCmdFlag){
            if (readData.contains("Done\n")){
                sendSetParasCmdFlag = false;
                emit sendRodDirectionSetSig();
            }
        }

        if (displayAllTargetCmdFlag){
            if (readData.contains("Done\n")){
                displayAllTargetCmdFlag = false;
                emit displayAllPointsSig();
            }
        }

        if (readData.contains("setFilterPara")){
              //qDebug()<<"setFilterPara";
              QRegularExpression re("(-?\\d+\\.?\\d*)"); // 匹配整数或小数
              QRegularExpressionMatchIterator i = re.globalMatch(readData);
              QList<double> numbers;
              while (i.hasNext()) {
                  QRegularExpressionMatch match = i.next();
                  bool ok;
                  double number = match.captured().toDouble(&ok);
                  if (ok) {
                      numbers.append(number);
                  }
              }
             if (numbers.length() >= 11){
                 ui->lineEdit->setText(QString::number(numbers[5]/10,'f',1));//bottom
                 ui->lineEdit_2->setText(QString::number(numbers[3]/10));
                 ui->lineEdit_3->setText(QString::number(numbers[2]/10));
                 ui->lineEdit_4->setText(QString::number(numbers[6]/10));
                 if (numbers[8] == 0){
                     ui->comboBox->setCurrentIndex(0);
                     rodType = 0;
                 } else if (numbers[8] == 1){
                     ui->comboBox->setCurrentIndex(1);
                     rodType = 1;
                 } else {
                     ui->comboBox->setCurrentIndex(2);
                     rodType = 2;
                 }

                 if (numbers[9] == 0){
                     ui->comboBox_3->setCurrentIndex(1);
                 } else {
                     ui->comboBox_3->setCurrentIndex(0);
                 }

                 if (numbers[10] == 1){
                     ui->comboBox_4->setCurrentIndex(0);
                 } else {
                     ui->comboBox_4->setCurrentIndex(1);
                 }
                 ui->widget_2->updateArea(numbers[5]/10,numbers[3]/10,numbers[2]/10,numbers[6]/10);
             } else {
                 QMessageBox::warning(this, "错误", "获取setFilterPara参数失败");
             }
        }

        if (rodType == 0){
            if (readData.contains("StraightRodDirection")){
                QRegularExpression re("(-?\\d+\\.?\\d*)"); // 匹配整数或小数
                QRegularExpressionMatchIterator i = re.globalMatch(readData);
                QList<double> numbers;
                while (i.hasNext()) {
                    QRegularExpressionMatch match = i.next();
                    bool ok;
                    double number = match.captured().toDouble(&ok);
                    if (ok) {
                        numbers.append(number);
                    }
                }
                if (numbers.length() > 0){
                    if (numbers[0] == 0){
                        ui->comboBox_2->setCurrentIndex(2);
                    } else if (numbers[0] == 1) {
                        ui->comboBox_2->setCurrentIndex(0);
                    } else {
                        ui->comboBox_2->setCurrentIndex(1);
                    }
                } else {
                     QMessageBox::warning(this, "错误", "获取StraightRodDirection参数失败");
                }
            }
        }else {
            if (readData.contains("rodDirection")){
                QRegularExpression re("(-?\\d+\\.?\\d*)"); // 匹配整数或小数
                QRegularExpressionMatchIterator i = re.globalMatch(readData);
                QList<double> numbers;
                while (i.hasNext()) {
                    QRegularExpressionMatch match = i.next();
                    bool ok;
                    double number = match.captured().toDouble(&ok);
                    if (ok) {
                        numbers.append(number);
                    }
                }
                if (numbers.length() > 0){
                    if (numbers[0] == 0){
                        ui->comboBox_2->setCurrentIndex(0);
                    } else {
                        ui->comboBox_2->setCurrentIndex(1);
                    }
                } else {
                    QMessageBox::warning(this, "错误", "获取rodDirection参数失败");
                }
            }
        }
    }
}

QString setRadarWindow::chardata(const QString &hexString,const int &i) //取出字节
{
     QString Chars = hexString.mid(i * 2,2);
     return Chars;
}

void setRadarWindow::serialNameSlot(QString portName, int baudRate){
    //qDebug()<<portName;
    gPortName = portName;
    gBaudRate = baudRate;
    serialPort->setPortName(gPortName);
    serialPort->close();
    if (serialPort->open(QIODevice::ReadWrite)){
        serialPort->setBaudRate(gBaudRate);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
    }
}

void setRadarWindow::sendDataBySerialPort(QString data, bool hexSend){
    if (hexSend){
       //qDebug()<<QByteArray::fromHex(data.toLatin1());
       serialPort->write(QByteArray::fromHex(data.toLatin1()));
    } else {
       serialPort->write(data.toLatin1());
    }
}

void setRadarWindow::setLED(QLabel* label, int color, int size)
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

void setRadarWindow::updateTime(){

    currentTime = QDateTime::currentDateTime();
    QString timeStr;

    QLocale locale = QLocale::English;
    timeStr = QString(locale.toString(currentTime,QString("yyyy-MM-dd hh:mm:ss")));

    ui->label_10->setText(timeStr);

    if (upgradeFw){
        if (timeOutCnt < 65530){
            timeOutCnt++;
        }
        //qDebug()<<timeOutCnt;
        if (timeOutCnt == 10){
            QString text;
            text.append(QString::number(upgrade_step));
            text.append("升级通信失败！");
            timeOutCnt = 0;
            ui->progressBar->setRange(0,sizefirmware);
            ui->progressBar->setValue(0);
            upgrade_step = SET_BOOT_MODE;
            checkSum = 0;
            framecount = 0;
            sendCmdCnt = 0;
            upgradeFw = false;
            setUIcontrol(!upgradeFw);
            QMessageBox::information(this,"提示",text);
        }
    }
}

//学习
void setRadarWindow::on_pushButton_4_clicked()
{
    QString readParas = "clioutput 4\r\n";
    sendDataBySerialPort(readParas,false);
    hexSendFlag = false;
    setLED(ui->label_led,0,22);
    qDebug()<<serialPort;
}

//读雷达参数
void setRadarWindow::on_pushButton_2_clicked()
{
    QString readParas = "ReadCLI setFilterPara\r\n";
    sendDataBySerialPort(readParas,false);
    sendReadParasCmdFlag = true;
    hexSendFlag =false;
    ui->widget_2->updatePoints(nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,0,false,false);
    setLED(ui->label_led,0,22);
}

//重启
void setRadarWindow::on_pushButton_3_clicked()
{
    QString readParas = "SR\r\n";
    sendDataBySerialPort(readParas,false);
    hexSendFlag = false;
    ui->widget_2->updatePoints(nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,0,false,false);
    setLED(ui->label_led,0,22);
}

//配置参数
void setRadarWindow::on_pushButton_clicked()
{
    QString readParas = "WriteCLI setFilterPara 0 0 ";
    readParas = readParas + QString::number(ui->lineEdit_3->text().toDouble()*10) + " ";
    readParas = readParas + QString::number(ui->lineEdit_2->text().toDouble()*10) + " ";
    readParas = readParas + "3 ";
    readParas = readParas + QString::number(ui->lineEdit->text().toDouble()*10)+" ";
    readParas = readParas + QString::number(ui->lineEdit_4->text().toDouble()*10)+" ";
    readParas = readParas + "64 ";
    if (ui->comboBox->currentText() == "直杆"){
        readParas = readParas + "0 ";
    } else if(ui->comboBox->currentText() == "栅栏"){
        readParas = readParas + "1 ";
    } else {
        readParas = readParas + "2 ";
    }

    if (ui->comboBox_3->currentText() == "否"){
        readParas = readParas + "0 ";
    } else{
        readParas = readParas + "2 ";
    }

    if (ui->comboBox_4->currentText() == "关"){
        readParas = readParas + "0 ";
    } else{
        readParas = readParas + "1 ";
    }
    readParas = readParas + "\r\n";
    //qDebug()<<readParas;
    sendDataBySerialPort(readParas,false);
    sendSetParasCmdFlag = true;
    hexSendFlag = false;
    ui->widget_2->updatePoints(nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,0,false,false);
    setLED(ui->label_led,0,22);
}

//显示所有目标
void setRadarWindow::on_pushButton_5_clicked()
{
    if (!hexSendFlag){
        QString cmd = "clioutput 21\r\n";
        sendDataBySerialPort(cmd,false);
        displayAllTargetCmdFlag = true;
    }
}

//
void setRadarWindow::on_pushButton_6_clicked()
{
    //QString cmd = "clioutput 22\r\n";
    //sendDataBySerialPort(cmd,false);
    //hexSendFlag = false;
    if(ui->pushButton_6->text() == "显示速度"){
        disVel = true;
        ui->pushButton_6->setText("关闭显示");
    } else {
        disVel = false;
        ui->pushButton_6->setText("显示速度");
    }
}

//停止显示
void setRadarWindow::on_pushButton_9_clicked()
{
    QString cmd = "clioutput 0\r\n";
    sendDataBySerialPort(cmd,false);
    hexSendFlag = false;
    ui->widget_2->updatePoints(nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,0,false,false);
    setLED(ui->label_led,0,22);
}

void setRadarWindow::on_pushButton_10_clicked()
{
    if (ui->pushButton_10->text() == "显示坐标"){
        displayInfo = true;
        ui->pushButton_10->setText("取消坐标");
    } else {
        displayInfo = false;
        ui->pushButton_10->setText("显示坐标");
    }
}

//获取固件路径
void setRadarWindow::on_pushButton_8_clicked()
{
    QDateTime timeCur;

    //binfilename = QFileDialog::getOpenFileName(this, QString("选择文件"), QString("/"),QString("TEXT(*.bin)"));
   // qDebug()<<binfilename;
    QSettings setting("./Setting.ini", QSettings::IniFormat);  //QSettings能记录一些程序中的信息，下次再打开时可以读取出来
    QString lastPath = setting.value("LastFilePath").toString();  //获取上次的打开路径
    qDebug()<<"lastPath"<<lastPath;
    //获取文件的路径
    QString filePath = QFileDialog::getOpenFileName(this, tr("打开文件"), lastPath, QString("TEXT(*bin)"));//从上次的路径处打开
    qDebug()<< filePath;

    if(!filePath.isEmpty())
    {
        setting.setValue("LastFilePath",filePath);  //记录路径到QSetting中保存
    }
    ui->lineEdit_5->setText(filePath);
    binfilename = filePath;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "固件路径：" << filePath.toUtf8().data() ;
//    ui->run_pushButton->setEnabled(true);
}

//升级
void setRadarWindow::on_pushButton_7_clicked()
{
    ui->widget_2->updatePoints(nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,0,false,false);
    setLED(ui->label_led,0,22);
    /* 获取固件内容 */
    file.setFileName(binfilename);
    if(!file.open(QIODevice::ReadOnly))
    {
       qDebug() << " Could not open the file for reading";
       QMessageBox::information(this, "提示", "固件选择错误，请选择正确的固件！", QMessageBox::Cancel);
       return;
    }
    firmbindata=file.readAll().toHex();
    //qDebug()<<firmbindata.toHex();
    file.close();
    qDebug()<<firmbindata.size()/2;
    if((firmbindata.size()/2)%sendeachbinsize1==0)
    {
       sizefirmware=(firmbindata.size()/2)/sendeachbinsize1;
       qDebug()<<sizefirmware;
    }
    else
    {
       sizefirmware=(firmbindata.size()/2)/sendeachbinsize1+1;
       qDebug()<<sizefirmware;
    }
    ui->progressBar->setRange(0,sizefirmware);
    ui->progressBar->setValue(0);
    QString cmd = "WriteCLI bootLoaderFlag 1\r\n";
    sendDataBySerialPort(cmd,false);
    upgrade_step = SET_BOOT_MODE;
    checkSum = 0;
    framecount = 0;
    sendCmdCnt = 0;
    upgradeFw = true;
    setUIcontrol(!upgradeFw);
}


void setRadarWindow::setUIcontrol(bool states){
    ui->pushButton->setEnabled(states);
    ui->pushButton_2->setEnabled(states);
    ui->pushButton_3->setEnabled(states);
    ui->pushButton_4->setEnabled(states);
    ui->pushButton_5->setEnabled(states);
    ui->pushButton_6->setEnabled(states);
    ui->pushButton_9->setEnabled(states);
    ui->pushButton_10->setEnabled(states);
}
