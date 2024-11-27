#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
}

MainWindow::~MainWindow()
{
    if (serialPort){
        serialPort->close();
        delete serialPort;
        serialPort = nullptr;
    }
    delete ui;
}

void MainWindow::initWindow(){
    setWindowTitle(tr("Radar Tools V1.0"));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(this->width(),this->height());//禁止放大
    eventFilter = new serialGetEvent(ui->comboBox, this);
    ui->comboBox->installEventFilter(eventFilter);
    connect(eventFilter, SIGNAL(comboBoxPopupShown()), this, SLOT(onComboBoxPopupShown()));//连接鼠标点击事件，实现点击串口列表刷新

    serialPort = new QSerialPort(this);

    connect(serialPort,&QSerialPort::readyRead,this,&MainWindow::SerialReadDataSlot);
    connect(this,&MainWindow::serialPortNameSig,&setRadarWin,&setRadarWindow::serialNameSlot);
    connect(&setRadarWin,&setRadarWindow::reConnectSerialSig,this,&MainWindow::showMainWindow);

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);//1Sec update

}

void MainWindow::showMainWindow(){
    this->show();
}

void MainWindow::updateTime(){

    if (connectRadarClick){
        if (timeOutCnt < 65530)
        {
            timeOutCnt++;
        }
        qDebug()<<timeOutCnt;
        if (timeOutCnt == 3){
           connectRadarClick = false;
           QMessageBox::information(this,"提示","连接雷达超时！");
        }
    }
}

void MainWindow::SerialReadDataSlot(){
    QByteArray readData = serialPort->readAll();
    timeOutCnt = 0;
    connectRadarClick = false;
    //qDebug()<<readData;
    if (readData.contains("IPR")){
        serialPort->clear();
        serialPort->close();
        this->hide();
        setRadarWin.show();
        emit serialPortNameSig(ui->comboBox->currentText(),ui->comboBox_2->currentText().toInt());
    }
}

void MainWindow::onComboBoxPopupShown(){

    ui->comboBox->clear();
    PortStringList.clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
//        qDebug()<<"Name:"<<info.portName();
//        qDebug()<<"Description:"<<info.description();
//        qDebug()<<"Manufacturer:"<<info.manufacturer();

        //这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            //将串口号添加到cmb
            PortStringList += info.portName();
            serial.close();
        }
    }
    ui->comboBox->addItems(PortStringList);
}

void MainWindow::on_pushButton_clicked(){
    connectRadarClick = true;
    if (ui->comboBox->currentText().isEmpty()){
        QMessageBox::information(this,"提示","请先选择雷达串口！");
    }else{
        serialPort->setPortName(ui->comboBox->currentText());
        serialPort->close();
        if (serialPort->open(QIODevice::ReadWrite)){
            serialPort->setBaudRate(ui->comboBox_2->currentText().toInt());
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setFlowControl(QSerialPort::NoFlowControl);
            QString  sendData;
            sendData.clear();
            sendData = "ver.\r\n";
            //qDebug()<<sendData;
            serialPort->write(sendData.toLatin1());
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
