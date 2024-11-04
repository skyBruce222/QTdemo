#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QDataStream>
#include <QDebug>
#include <QFileInfo>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <QStringList>
#include <QElapsedTimer>
#include <QDateTime>
#include <QtEndian>
#include <QSettings>
static QString binfilename ;
QStringList displayString; //读入加载的配置
QFile file;
QByteArray firmbindata; //存储bin文件数据
QStringList PortStringList; //保存当前可用的串口号
QTimer *timer;
long baudrate=115200;
static int sizefirmware=0;
uint16_t sendeachbinsize1=240;  //每包数据大小；
QString clistring;
//static QByteArray firmwarebin;

#define BAUDRATE   115200U

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pause_pushButton->setDisabled(true);
    //QTimer* time;
//    ui->run_pushButton->setDisabled(false);
//    ui->run_pushButton->setDisabled(true);
//    ui->run_pushButton->setEnabled(false);
  //  qDebug() <<QThread::currentThread();
    // timer = new QTimer; //定时扫描和更新串口
    // connect(timer,&QTimer::timeout,this,&MainWindow::showValidPort);//实时更新端口号
    // timer->start(1000); //每1000ms定时检测串口状态
    serialRead = new QSerialPort(this);

    ui->label_burnState->setText("PASS");
    ui->label_burnState->setAlignment(Qt::AlignCenter);
    ui->label_burnState->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");

    ui->label_burnState_2->setText("FAIL");
    ui->label_burnState_2->setAlignment(Qt::AlignCenter);
    ui->label_burnState_2->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");

    ui->label_burnState_3->setText("RUN");
    ui->label_burnState_3->setAlignment(Qt::AlignCenter);
    ui->label_burnState_3->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");

    statusDisplayInit(); //各路串口烧录状态显示，状态包括：FAIL/PASS等

//     ui->label_burnState->setColor(QPalette::Window, Qt::white);
//     setLED(ui->label_led1, 0, 16);

     OpenRadarPort();
     mthread = new QThread(this);
     mthread2 = new QThread(this);
     mthread3 = new QThread(this);
     mthread4 = new QThread(this);
     mthread5 = new QThread(this);
     mthread6 = new QThread(this);
     mthread7 = new QThread(this);
     mthread8 = new QThread(this);

     mSerial_worker = new Serialworkerthread;
     mSerial_worker2 = new Serialworkerthread;
     mSerial_worker3 = new Serialworkerthread;
     mSerial_worker4 = new Serialworkerthread;
     mSerial_worker5 = new Serialworkerthread;
     mSerial_worker6 = new Serialworkerthread;
     mSerial_worker7 = new Serialworkerthread;
     mSerial_worker8 = new Serialworkerthread;

     mSerial_worker->moveToThread(mthread);
     mSerial_worker2->moveToThread(mthread2);
     mSerial_worker3->moveToThread(mthread3);
     mSerial_worker4->moveToThread(mthread4);
     mSerial_worker5->moveToThread(mthread5);
     mSerial_worker6->moveToThread(mthread6);
     mSerial_worker7->moveToThread(mthread7);
     mSerial_worker8->moveToThread(mthread8);

//     connect(this,SIGNAL(mySignal(int)),SLOT(mySlot(int)));
//     connect(this,SIGNAL(senddatabin(int)),SLOT(senddatabinSlot(int)));
     QObject::connect(mthread,  &QThread::finished, mSerial_worker, &QObject::deleteLater);       // 清理线程
     QObject::connect(mthread2, &QThread::finished, mSerial_worker2, &QObject::deleteLater);      // 清理线程
     QObject::connect(mthread3, &QThread::finished, mSerial_worker3, &QObject::deleteLater);      // 清理线程
     QObject::connect(mthread4, &QThread::finished, mSerial_worker4, &QObject::deleteLater);      // 清理线程
     QObject::connect(mthread5, &QThread::finished, mSerial_worker5, &QObject::deleteLater);      // 清理线程
     QObject::connect(mthread6, &QThread::finished, mSerial_worker6, &QObject::deleteLater);      // 清理线程
     QObject::connect(mthread7, &QThread::finished, mSerial_worker7, &QObject::deleteLater);      // 清理线程
     QObject::connect(mthread8, &QThread::finished, mSerial_worker8, &QObject::deleteLater);      // 清理线程

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker,SLOT(write_serial_data(QByteArray)),Qt::AutoConnection); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker,SLOT(close_serial()),Qt::AutoConnection); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker,SLOT(open_serial()),Qt::AutoConnection); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数
//     QObject::connect(this, SIGNAL(changebaudrate(int)),mSerial_worker,SLOT(readclislot(int)),Qt::AutoConnection); //修改波特率

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker2,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker2,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker2,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker2,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker2,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker3,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker3,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker3,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker3,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker3,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker4,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker4,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker4,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker4,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker4,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker5,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker5,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker5,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker5,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker5,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker6,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker6,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker6,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker6,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker6,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker7,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker7,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker7,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker7,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker7,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

     QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker8,SLOT(write_serial_data(QByteArray))); //连接发送函数
     QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker8,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
     QObject::connect(this, SIGNAL(closeserial()),mSerial_worker8,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker8,SLOT(open_serial())); //连接打开串口
     QObject::connect(this, SIGNAL(readcli()),mSerial_worker8,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


     QObject::connect(mSerial_worker, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker, SIGNAL(sendvar(QString)),this,SLOT(on_showvar(QString)),Qt::AutoConnection); //次线程向主线程发送数据版本信息
     QObject::connect(mSerial_worker, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker2, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli2(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker2, SIGNAL(sendvar(QString)),this,SLOT(on_showvar2(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker2, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot2(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker2, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_2(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker3, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli3(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker3, SIGNAL(sendvar(QString)),this,SLOT(on_showvar3(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker3, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot3(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker3, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_3(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker4, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli4(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker4, SIGNAL(sendvar(QString)),this,SLOT(on_showvar4(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker4, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot4(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker4, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_4(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker5, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli5(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker5, SIGNAL(sendvar(QString)),this,SLOT(on_showvar5(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker5, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot5(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker5, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_5(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker6, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli6(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker6, SIGNAL(sendvar(QString)),this,SLOT(on_showvar6(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker6, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot6(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker6, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_6(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker7, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli7(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker7, SIGNAL(sendvar(QString)),this,SLOT(on_showvar7(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker7, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot7(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker7, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_7(QString)),Qt::AutoConnection);//显示烧录状态

     QObject::connect(mSerial_worker8, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli8(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
     QObject::connect(mSerial_worker8, SIGNAL(sendvar(QString)),this,SLOT(on_showvar8(QString)),Qt::AutoConnection); //次线程向主线程发送数据
     QObject::connect(mSerial_worker8, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot8(int)),Qt::AutoConnection);//显示升级进度
     QObject::connect(mSerial_worker8, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_8(QString)),Qt::AutoConnection);//显示烧录状态


     connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
     int portbaudrate = 115200;

      /*connect(mthread, &QThread::started, [=](){
          // QString portName = ui->uartnum_lineedit->text();
          QString portName = ui->comboBox_uartNumber->currentText();
          mSerial_worker->startPort(portName,portbaudrate);
             });*/
     connect(mthread, &QThread::started, [=](){
               // QString portName = ui->uartnum_lineedit->text();
               QString portName = ui->comboBox_uartNumber->currentText();
               mSerial_worker->startPort(portName,portbaudrate);
                  });
      connect(mthread2, &QThread::started, [=](){
         // QString portName2 = ui->uartnum_lineedit_2->text();
          QString portName2 = ui->comboBox_uartNumber_2->currentText();
          mSerial_worker2->startPort(portName2,portbaudrate);
             });
      connect(mthread3, &QThread::started, [=](){
         // QString portName3 = ui->uartnum_lineedit_3->text();
          QString portName3 = ui->comboBox_uartNumber_3->currentText();
          mSerial_worker3->startPort(portName3,portbaudrate);
             });
      connect(mthread4, &QThread::started, [=](){
          // QString portName4 = ui->uartnum_lineedit_4->text();
          QString portName4 = ui->comboBox_uartNumber_4->currentText();
          mSerial_worker4->startPort(portName4,portbaudrate);
             });
      connect(mthread5, &QThread::started, [=](){
         // QString portName5 = ui->uartnum_lineedit_5->text();
          QString portName5 = ui->comboBox_uartNumber_5->currentText();
          mSerial_worker5->startPort(portName5,portbaudrate);
             });
      connect(mthread6, &QThread::started, [=](){
         // QString portName6 = ui->uartnum_lineedit_6->text();
          QString portName6 = ui->comboBox_uartNumber_6->currentText();
          mSerial_worker6->startPort(portName6,portbaudrate);
             });
      connect(mthread7, &QThread::started, [=](){
         // QString portName7 = ui->uartnum_lineedit_7->text();
          QString portName7 = ui->comboBox_uartNumber_7->currentText();
          mSerial_worker7->startPort(portName7,portbaudrate);
             });
      connect(mthread8, &QThread::started, [=](){
         // QString portName8 = ui->uartnum_lineedit_8->text();
          QString portName8 = ui->comboBox_uartNumber_8->currentText();
          mSerial_worker8->startPort(portName8,portbaudrate);
             });

      qDebug()<<"识别到串口个数"<< PortStringList.size();

      /* 启动进程 */
      switch(PortStringList.size())
      {
       case 0:qDebug()<<"无有用串口";break;
       case 1:qDebug()<<"开启1个串口线程";
              mthread->start();
              Sleep(100);
               break;
      case 2:qDebug()<<"开启2个串口线程";
              mthread->start();
              mthread2->start();
              Sleep(100);

              break;
      case 3:qDebug()<<"开启3个串口线程";
              mthread->start();
              mthread2->start();
              mthread3->start();
              Sleep(100);
              break;
      case 4:qDebug()<<"开启4个串口线程";
              mthread->start();
              mthread2->start();
              mthread3->start();
              mthread4->start();
              Sleep(100);
              break;
      case 5:qDebug()<<"开启5个串口线程";
              mthread->start();
              mthread2->start();
              mthread3->start();
              mthread4->start();
              mthread5->start();
              Sleep(100);
              break;
      case 6:qDebug()<<"开启6个串口线程";
              mthread->start();
              mthread2->start();
              mthread3->start();
              mthread4->start();
              mthread5->start();
              mthread6->start();
              Sleep(100);
              break;
      case 7:qDebug()<<"开启7个串口线程";
              mthread->start();
              mthread2->start();
              mthread3->start();
              mthread4->start();
              mthread5->start();
              mthread6->start();
              mthread7->start();
              Sleep(100);
              break;
      case 8:qDebug()<<"开启8个串口线程";
              mthread->start();
              mthread2->start();
              mthread3->start();
              mthread4->start();
              mthread5->start();
              mthread6->start();
              mthread7->start();
              mthread8->start();
              Sleep(100);
              break;
      }

      /*time = new QTimer(this);
      connect(time, &QTimer::timeout, this, &MainWindow::updataSerailPort);
      time->start(3000);*/

}
void MainWindow::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
MainWindow::~MainWindow()
{
    mthread->quit();
    mthread->wait();
    mthread->deleteLater();
    mthread2->quit();
    mthread2->wait();
    mthread2->deleteLater();
    mthread3->quit();
    mthread3->wait();
    mthread3->deleteLater();
    mthread4->quit();
    mthread4->wait();
    mthread4->deleteLater();
    mthread5->quit();
    mthread5->wait();
    mthread5->deleteLater();
    mthread6->quit();
    mthread6->wait();
    mthread6->deleteLater();
    mthread7->quit();
    mthread7->wait();
    mthread7->deleteLater();
    mthread8->quit();
    mthread8->wait();
    mthread8->deleteLater();
    delete ui;

}
//选择固件文件
void MainWindow::on_openbin_pushButton_clicked()
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
    ui->firmwarename_lineEdit->setText(filePath);
    binfilename = filePath;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "固件路径：" << filePath.toUtf8().data() ;
//    ui->run_pushButton->setEnabled(true);
}

//更新并检测串口函数实现
void MainWindow::showValidPort()
{
    QStringList newPortStringList;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        newPortStringList += info.portName();
    if(newPortStringList.size() != PortStringList.size())
    {
        PortStringList = newPortStringList;
//        ui->comboBoxRadars->clear();
//        ui->comboBoxRadars->addItems(portStringList);
        OpenRadarPort();
    }
}

void MainWindow::uart_thread_close(void)
{
    switch(PortStringList.size())
    {
        case 0:qDebug()<<"无可用串口，无需关闭串口线程";break;
        case 1:qDebug()<<"1有用串口，关闭1个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            break;
        case 2:qDebug()<<"2有用串口，关闭2个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            break;
        case 3:qDebug()<<"3有用串口，关闭3个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
            break;
        case 4:qDebug()<<"4有用串口，关闭4个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
            mthread4->quit(); mthread4->wait(); mthread4->deleteLater();
            break;
        case 5:qDebug()<<"5有用串口，关闭5个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
            mthread4->quit(); mthread4->wait(); mthread4->deleteLater();
            mthread5->quit(); mthread5->wait(); mthread5->deleteLater();
            break;
        case 6:qDebug()<<"6有用串口，关闭6个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
            mthread4->quit(); mthread4->wait(); mthread4->deleteLater();
            mthread5->quit(); mthread5->wait(); mthread5->deleteLater();
            mthread6->quit(); mthread6->wait(); mthread6->deleteLater();
            break;
        case 7:qDebug()<<"7有用串口，关闭7个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
            mthread4->quit(); mthread4->wait(); mthread4->deleteLater();
            mthread5->quit(); mthread5->wait(); mthread5->deleteLater();
            mthread6->quit(); mthread6->wait(); mthread6->deleteLater();
            mthread7->quit(); mthread7->wait(); mthread7->deleteLater();
            break;
        case 8:qDebug()<<"8有用串口，关闭8个串口线程";
            mthread->quit(); mthread->wait(); mthread->deleteLater();
            mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
            mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
            mthread4->quit(); mthread4->wait(); mthread4->deleteLater();
            mthread5->quit(); mthread5->wait(); mthread5->deleteLater();
            mthread6->quit(); mthread6->wait(); mthread6->deleteLater();
            mthread7->quit(); mthread7->wait(); mthread7->deleteLater();
            mthread8->quit(); mthread8->wait(); mthread8->deleteLater();
            break;
    }
}


void MainWindow::OpenRadarPort(void)
{
    // 设置串口名字
//    ui->comboBoxRadars->clear();
//    ui->rateBox->clear();
    ui->comboBox_uartNumber->clear();
    ui->comboBox_uartNumber_2->clear();
    ui->comboBox_uartNumber_3->clear();
    ui->comboBox_uartNumber_4->clear();
    ui->comboBox_uartNumber_5->clear();
    ui->comboBox_uartNumber_6->clear();
    ui->comboBox_uartNumber_7->clear();
    ui->comboBox_uartNumber_8->clear();

    PortStringList.clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug()<<"Name:"<<info.portName();
        qDebug()<<"Description:"<<info.description();
        qDebug()<<"Manufacturer:"<<info.manufacturer();

        //这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            //将串口号添加到cmb
//            ui->uartnum_lineedit->setText(info.portName());
              PortStringList += info.portName();
              qDebug()<<"串口名称:"<<info.portName();
            serial.close();
        }
    }
    qDebug()<<"有用串口个数:"<<PortStringList.size();


    switch(PortStringList.size())
    {
        case 0:qDebug()<<"无有用串口";break;
        case 1:qDebug()<<"1有用串口";
           /* ui->uartnum_lineedit->setText(PortStringList.at(0));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            break;
        case 2:qDebug()<<"2有用串口";
           /* ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            break;
        case 3:qDebug()<<"3有用串口";
           /* ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            ui->uartnum_lineedit_3->setText(PortStringList.at(2));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            ui->comboBox_uartNumber_3->addItems(PortStringList); ui->comboBox_uartNumber_3->setCurrentIndex(2);
            break;
        case 4:qDebug()<<"4有用串口";
           /* ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            ui->uartnum_lineedit_3->setText(PortStringList.at(2));
            ui->uartnum_lineedit_4->setText(PortStringList.at(3));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            ui->comboBox_uartNumber_3->addItems(PortStringList); ui->comboBox_uartNumber_3->setCurrentIndex(2);
            ui->comboBox_uartNumber_4->addItems(PortStringList); ui->comboBox_uartNumber_4->setCurrentIndex(3);
            break;
        case 5:qDebug()<<"5有用串口";
           /* ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            ui->uartnum_lineedit_3->setText(PortStringList.at(2));
            ui->uartnum_lineedit_4->setText(PortStringList.at(3));
            ui->uartnum_lineedit_5->setText(PortStringList.at(4));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            ui->comboBox_uartNumber_3->addItems(PortStringList); ui->comboBox_uartNumber_3->setCurrentIndex(2);
            ui->comboBox_uartNumber_4->addItems(PortStringList); ui->comboBox_uartNumber_4->setCurrentIndex(3);
            ui->comboBox_uartNumber_5->addItems(PortStringList); ui->comboBox_uartNumber_5->setCurrentIndex(4);

            break;
        case 6:qDebug()<<"6有用串口";
           /* ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            ui->uartnum_lineedit_3->setText(PortStringList.at(2));
            ui->uartnum_lineedit_4->setText(PortStringList.at(3));
            ui->uartnum_lineedit_5->setText(PortStringList.at(4));
            ui->uartnum_lineedit_6->setText(PortStringList.at(5));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            ui->comboBox_uartNumber_3->addItems(PortStringList); ui->comboBox_uartNumber_3->setCurrentIndex(2);
            ui->comboBox_uartNumber_4->addItems(PortStringList); ui->comboBox_uartNumber_4->setCurrentIndex(3);
            ui->comboBox_uartNumber_5->addItems(PortStringList); ui->comboBox_uartNumber_5->setCurrentIndex(4);
            ui->comboBox_uartNumber_6->addItems(PortStringList); ui->comboBox_uartNumber_6->setCurrentIndex(5);
            break;
        case 7:qDebug()<<"7有用串口";
          /*  ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            ui->uartnum_lineedit_3->setText(PortStringList.at(2));
            ui->uartnum_lineedit_4->setText(PortStringList.at(3));
            ui->uartnum_lineedit_5->setText(PortStringList.at(4));
            ui->uartnum_lineedit_6->setText(PortStringList.at(5));
            ui->uartnum_lineedit_7->setText(PortStringList.at(6));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            ui->comboBox_uartNumber_3->addItems(PortStringList); ui->comboBox_uartNumber_3->setCurrentIndex(2);
            ui->comboBox_uartNumber_4->addItems(PortStringList); ui->comboBox_uartNumber_4->setCurrentIndex(3);
            ui->comboBox_uartNumber_5->addItems(PortStringList); ui->comboBox_uartNumber_5->setCurrentIndex(4);
            ui->comboBox_uartNumber_6->addItems(PortStringList); ui->comboBox_uartNumber_6->setCurrentIndex(5);
            ui->comboBox_uartNumber_7->addItems(PortStringList); ui->comboBox_uartNumber_7->setCurrentIndex(6);
            break;
        case 8:qDebug()<<"8有用串口";
          /*  ui->uartnum_lineedit->setText(PortStringList.at(0));
            ui->uartnum_lineedit_2->setText(PortStringList.at(1));
            ui->uartnum_lineedit_3->setText(PortStringList.at(2));
            ui->uartnum_lineedit_4->setText(PortStringList.at(3));
            ui->uartnum_lineedit_5->setText(PortStringList.at(4));
            ui->uartnum_lineedit_6->setText(PortStringList.at(5));
            ui->uartnum_lineedit_7->setText(PortStringList.at(6));
            ui->uartnum_lineedit_8->setText(PortStringList.at(7));
            */
            ui->comboBox_uartNumber->addItems(PortStringList); ui->comboBox_uartNumber->setCurrentIndex(0);
            ui->comboBox_uartNumber_2->addItems(PortStringList); ui->comboBox_uartNumber_2->setCurrentIndex(1);
            ui->comboBox_uartNumber_3->addItems(PortStringList); ui->comboBox_uartNumber_3->setCurrentIndex(2);
            ui->comboBox_uartNumber_4->addItems(PortStringList); ui->comboBox_uartNumber_4->setCurrentIndex(3);
            ui->comboBox_uartNumber_5->addItems(PortStringList); ui->comboBox_uartNumber_5->setCurrentIndex(4);
            ui->comboBox_uartNumber_6->addItems(PortStringList); ui->comboBox_uartNumber_6->setCurrentIndex(5);
            ui->comboBox_uartNumber_7->addItems(PortStringList); ui->comboBox_uartNumber_7->setCurrentIndex(6);
            ui->comboBox_uartNumber_8->addItems(PortStringList); ui->comboBox_uartNumber_8->setCurrentIndex(7);
            break;
    }



//    for(int i = 0; i< PortStringList.size();i++)
//        {
//            ui->uartnum_lineedit->setText(PortStringList.at(i));
//        }
       QStringList baudList;   //波特率
    // 波特率    //波特率默认选择下拉第三项：9600
       baudList<<"9600"<<"115200"<<"921600";
//       ui->rateBox->addItems(baudList);
//       ui->rateBox->setCurrentIndex(1);

}
//连接雷达串口，开启串口线程
void MainWindow::on_run_pushButton_clicked()
{
//   qDebug()<<"识别到串口个数"<< PortStringList.size();
   //ui->pause_pushButton->setEnabled(true);
//   ui->run_pushButton->setDisabled(true);


    qDebug()<<"点击烧录信号"<< PortStringList.size();

    ui->textBrowser_burnStatus->clear();
    ui->textBrowser_burnStatus_2->clear();
    ui->textBrowser_burnStatus_3->clear();
    ui->textBrowser_burnStatus_4->clear();
    ui->textBrowser_burnStatus_5->clear();
    ui->textBrowser_burnStatus_6->clear();
    ui->textBrowser_burnStatus_7->clear();
    ui->textBrowser_burnStatus_8->clear();

    ui->update_progressBar->reset();
    ui->update_progressBar_2->reset();
    ui->update_progressBar_3->reset();
    ui->update_progressBar_4->reset();
    ui->update_progressBar_5->reset();
    ui->update_progressBar_6->reset();
    ui->update_progressBar_7->reset();
    ui->update_progressBar_8->reset();


 /* 获取固件内容 */
    file.setFileName(binfilename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << " Could not open the file for reading";
        QMessageBox::information(this, "提示", "固件选择错误，请选择正确的固件！", QMessageBox::Cancel);
        return;
    }
    firmbindata=file.readAll().toHex();
    file.close();
    if((firmbindata.size()/2)%sendeachbinsize1==0)
    {
        sizefirmware=(firmbindata.size()/2)/sendeachbinsize1;
    }
    else
    {
        sizefirmware=(firmbindata.size()/2)/sendeachbinsize1+1;
    }

    /* 启动进程 */
    int portbaudrate1 = 115200;
    switch(PortStringList.size())
    {
     case 0:qDebug()<<"无有用串口";break;
     case 1:qDebug()<<"开启1个串口线程";
          //  mthread->start();
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
//            emit readcli();
             break;
    case 2:qDebug()<<"开启2个串口线程";
           // mthread->start();
           // mthread2->start();
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
           firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;
    case 3:qDebug()<<"开启3个串口线程";
            //mthread->start();
            //mthread2->start();
            //mthread3->start();
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
            ui->update_progressBar_3->setMinimum(0); ui->update_progressBar_3->setMaximum(sizefirmware);
           firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;
    case 4:qDebug()<<"开启4个串口线程";
            //mthread->start();
            //mthread2->start();
            //mthread3->start();
            //mthread4->start();
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
            ui->update_progressBar_3->setMinimum(0); ui->update_progressBar_3->setMaximum(sizefirmware);
            ui->update_progressBar_4->setMinimum(0); ui->update_progressBar_4->setMaximum(sizefirmware);
           firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;
    case 5:qDebug()<<"开启5个串口线程";
            //mthread->start();
            //mthread2->start();
            //mthread3->start();
            //mthread4->start();
            //mthread5->start();
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
            ui->update_progressBar_3->setMinimum(0); ui->update_progressBar_3->setMaximum(sizefirmware);
            ui->update_progressBar_4->setMinimum(0); ui->update_progressBar_4->setMaximum(sizefirmware);
            ui->update_progressBar_5->setMinimum(0); ui->update_progressBar_5->setMaximum(sizefirmware);
           firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;
    case 6:qDebug()<<"开启6个串口线程";
            //mthread->start();
            //mthread2->start();
            //mthread3->start();
            //mthread4->start();
            //mthread5->start();
            //mthread6->start();
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
            ui->update_progressBar_3->setMinimum(0); ui->update_progressBar_3->setMaximum(sizefirmware);
            ui->update_progressBar_4->setMinimum(0); ui->update_progressBar_4->setMaximum(sizefirmware);
            ui->update_progressBar_5->setMinimum(0); ui->update_progressBar_5->setMaximum(sizefirmware);
            ui->update_progressBar_6->setMinimum(0); ui->update_progressBar_6->setMaximum(sizefirmware);
            firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;
    case 7:qDebug()<<"开启7个串口线程";
           /* mthread->start();
            mthread2->start();
            mthread3->start();
            mthread4->start();
            mthread5->start();
            mthread6->start();
            mthread7->start();*/
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
            ui->update_progressBar_3->setMinimum(0); ui->update_progressBar_3->setMaximum(sizefirmware);
            ui->update_progressBar_4->setMinimum(0); ui->update_progressBar_4->setMaximum(sizefirmware);
            ui->update_progressBar_5->setMinimum(0); ui->update_progressBar_5->setMaximum(sizefirmware);
            ui->update_progressBar_6->setMinimum(0); ui->update_progressBar_6->setMaximum(sizefirmware);
            ui->update_progressBar_7->setMinimum(0); ui->update_progressBar_7->setMaximum(sizefirmware);
            firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;
    case 8:qDebug()<<"开启8个串口线程";
           /* mthread->start();
            mthread2->start();
            mthread3->start();
            mthread4->start();
            mthread5->start();
            mthread6->start();
            mthread7->start();
            mthread8->start();*/
            Sleep(100);
            ui->update_progressBar->setMinimum(0); ui->update_progressBar->setMaximum(sizefirmware);
            ui->update_progressBar_2->setMinimum(0); ui->update_progressBar_2->setMaximum(sizefirmware);
            ui->update_progressBar_3->setMinimum(0); ui->update_progressBar_3->setMaximum(sizefirmware);
            ui->update_progressBar_4->setMinimum(0); ui->update_progressBar_4->setMaximum(sizefirmware);
            ui->update_progressBar_5->setMinimum(0); ui->update_progressBar_5->setMaximum(sizefirmware);
            ui->update_progressBar_6->setMinimum(0); ui->update_progressBar_6->setMaximum(sizefirmware);
            ui->update_progressBar_7->setMinimum(0); ui->update_progressBar_7->setMaximum(sizefirmware);
            ui->update_progressBar_8->setMinimum(0); ui->update_progressBar_8->setMaximum(sizefirmware);
            firmupdatesignals(firmbindata,portbaudrate1);//binfilename为固件内容
            break;

    }


}


/* 刷新  */
/*
void MainWindow::on_pause_pushButton_clicked()
{
    Sleep(100);
//    qDebug()<<"close serial";
//    emit closeserial();

    ui->update_progressBar->setValue(0);
    ui->update_progressBar_2->setValue(0);
    ui->update_progressBar_3->setValue(0);
    ui->update_progressBar_4->setValue(0);
    ui->update_progressBar_5->setValue(0);
    ui->update_progressBar_6->setValue(0);
    ui->update_progressBar_7->setValue(0);
    ui->update_progressBar_8->setValue(0);

    ui->pause_pushButton->setDisabled(true);
//    ui->run_pushButton->setDisabled(false);
}
*/

/* 文本框发送  */
void MainWindow::on_send_pushButton_clicked()
{
//    qDebug() <<"发送:";
//     QByteArray data = ui->write_textEdit->toPlainText().toUtf8();



}
/* 发送串口命令  */
void MainWindow::sendserialcmd(QByteArray data)
{
    emit sendtoserial(data);
}



/* 参数校验  */
void MainWindow::checkparams()
{

}
/* 显示版本  */
void MainWindow::on_showvar(QString ver)
{
   // ui->devicestate_lineedit->setText(ver);
    ui->textBrowser_burnStatus->append(ver);

}
void MainWindow::on_showvar2(QString ver)
{
    ui->textBrowser_burnStatus_2->append(ver);
}
void MainWindow::on_showvar3(QString ver)
{
    ui->textBrowser_burnStatus_3->append(ver);
}

void MainWindow::on_showvar4(QString ver)
{
    ui->textBrowser_burnStatus_4->append(ver);
}
void MainWindow::on_showvar5(QString ver)
{
    ui->textBrowser_burnStatus_5->append(ver);
}
void MainWindow::on_showvar6(QString ver)
{
    ui->textBrowser_burnStatus_6->append(ver);
}

void MainWindow::on_showvar7(QString ver)
{
    ui->textBrowser_burnStatus_7->append(ver);
}
void MainWindow::on_showvar8(QString ver)
{
    ui->textBrowser_burnStatus_8->append(ver);
}




/* 显示升级进度  */
void MainWindow::on_showprogressslot(int process)
{
    ui->update_progressBar->setValue(process);
}
void MainWindow::on_showprogressslot2(int process)
{
    ui->update_progressBar_2->setValue(process);
}
void MainWindow::on_showprogressslot3(int process)
{
    ui->update_progressBar_3->setValue(process);
}
void MainWindow::on_showprogressslot4(int process)
{
    ui->update_progressBar_4->setValue(process);
}
void MainWindow::on_showprogressslot5(int process)
{
    ui->update_progressBar_5->setValue(process);
}
void MainWindow::on_showprogressslot6(int process)
{
    ui->update_progressBar_6->setValue(process);
}
void MainWindow::on_showprogressslot7(int process)
{
    ui->update_progressBar_7->setValue(process);
}
void MainWindow::on_showprogressslot8(int process)
{
    ui->update_progressBar_8->setValue(process);
}

/* 显示烧录状态： FAIL/PASS */
void MainWindow::on_showBurnStatus(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState->setText("PASS");
        ui->label_burnState->setAlignment(Qt::AlignCenter);
        ui->label_burnState->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState->setText("FAIL");
        ui->label_burnState->setAlignment(Qt::AlignCenter);
        ui->label_burnState->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState->setText("RUN");
        ui->label_burnState->setAlignment(Qt::AlignCenter);
        ui->label_burnState->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState->setText("");
        ui->label_burnState->setAlignment(Qt::AlignCenter);
        ui->label_burnState->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_2(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_2->setText("PASS");
        ui->label_burnState_2->setAlignment(Qt::AlignCenter);
        ui->label_burnState_2->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_2->setText("FAIL");
        ui->label_burnState_2->setAlignment(Qt::AlignCenter);
        ui->label_burnState_2->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_2->setText("RUN");
        ui->label_burnState_2->setAlignment(Qt::AlignCenter);
        ui->label_burnState_2->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_2->setText("");
        ui->label_burnState_2->setAlignment(Qt::AlignCenter);
        ui->label_burnState_2->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_3(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_3->setText("PASS");
        ui->label_burnState_3->setAlignment(Qt::AlignCenter);
        ui->label_burnState_3->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_3->setText("FAIL");
        ui->label_burnState_3->setAlignment(Qt::AlignCenter);
        ui->label_burnState_3->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_3->setText("RUN");
        ui->label_burnState_3->setAlignment(Qt::AlignCenter);
        ui->label_burnState_3->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_3->setText("");
        ui->label_burnState_3->setAlignment(Qt::AlignCenter);
        ui->label_burnState_3->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_4(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_4->setText("PASS");
        ui->label_burnState_4->setAlignment(Qt::AlignCenter);
        ui->label_burnState_4->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_4->setText("FAIL");
        ui->label_burnState_4->setAlignment(Qt::AlignCenter);
        ui->label_burnState_4->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_4->setText("RUN");
        ui->label_burnState_4->setAlignment(Qt::AlignCenter);
        ui->label_burnState_4->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_4->setText("");
        ui->label_burnState_4->setAlignment(Qt::AlignCenter);
        ui->label_burnState_4->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_5(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_5->setText("PASS");
        ui->label_burnState_5->setAlignment(Qt::AlignCenter);
        ui->label_burnState_5->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_5->setText("FAIL");
        ui->label_burnState_5->setAlignment(Qt::AlignCenter);
        ui->label_burnState_5->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_5->setText("RUN");
        ui->label_burnState_5->setAlignment(Qt::AlignCenter);
        ui->label_burnState_5->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_5->setText("");
        ui->label_burnState_5->setAlignment(Qt::AlignCenter);
        ui->label_burnState_5->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_6(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_6->setText("PASS");
        ui->label_burnState_6->setAlignment(Qt::AlignCenter);
        ui->label_burnState_6->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_6->setText("FAIL");
        ui->label_burnState_6->setAlignment(Qt::AlignCenter);
        ui->label_burnState_6->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_6->setText("RUN");
        ui->label_burnState_6->setAlignment(Qt::AlignCenter);
        ui->label_burnState_6->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_6->setText("");
        ui->label_burnState_6->setAlignment(Qt::AlignCenter);
        ui->label_burnState_6->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_7(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_7->setText("PASS");
        ui->label_burnState_7->setAlignment(Qt::AlignCenter);
        ui->label_burnState_7->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_7->setText("FAIL");
        ui->label_burnState_7->setAlignment(Qt::AlignCenter);
        ui->label_burnState_7->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_7->setText("RUN");
        ui->label_burnState_7->setAlignment(Qt::AlignCenter);
        ui->label_burnState_7->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_7->setText("");
        ui->label_burnState_7->setAlignment(Qt::AlignCenter);
        ui->label_burnState_7->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}

void MainWindow::on_showBurnStatus_8(QString status)
{
    if (status == "PASS")
    {
        ui->label_burnState_8->setText("PASS");
        ui->label_burnState_8->setAlignment(Qt::AlignCenter);
        ui->label_burnState_8->setStyleSheet("background-color:rgb(0,255,0);font-size:20px;color:black");
    }
    else if(status == "FAIL")
    {
        ui->label_burnState_8->setText("FAIL");
        ui->label_burnState_8->setAlignment(Qt::AlignCenter);
        ui->label_burnState_8->setStyleSheet("background-color:rgb(255,0,0);font-size:20px;color:black");
    }
    else if (status == "RUN")
    {
        ui->label_burnState_8->setText("RUN");
        ui->label_burnState_8->setAlignment(Qt::AlignCenter);
        ui->label_burnState_8->setStyleSheet("background-color:rgb(255,255,0);font-size:20px;color:black");
    }
    else if (status == "EMPTY")
    {
        ui->label_burnState_8->setText("");
        ui->label_burnState_8->setAlignment(Qt::AlignCenter);
        ui->label_burnState_8->setStyleSheet("background-color:transparent;font-size:20px;color:black");
    }
}


void MainWindow::statusDisplayInit(void)
{
    on_showBurnStatus("EMPTY");
    on_showBurnStatus_2("EMPTY");
    on_showBurnStatus_3("EMPTY");
    on_showBurnStatus_4("EMPTY");
    on_showBurnStatus_5("EMPTY");
    on_showBurnStatus_6("EMPTY");
    on_showBurnStatus_7("EMPTY");
    on_showBurnStatus_8("EMPTY");
}


/*  修改串口波特率 */
//void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
//{
////int portbaudrate1 = ui->comboBox->currentText().toInt();
////    int portbaudrate1 = arg1.toInt();
////    emit changebaudrate(portbaudrate1);
//}




void MainWindow::on_pushButton_updateUart_clicked()
{
    uart_thread_close();
    OpenRadarPort();
    statusDisplayInit();

    mthread = new QThread(this);
    mthread2 = new QThread(this);
    mthread3 = new QThread(this);
    mthread4 = new QThread(this);
    mthread5 = new QThread(this);
    mthread6 = new QThread(this);
    mthread7 = new QThread(this);
    mthread8 = new QThread(this);

    mSerial_worker = new Serialworkerthread;
    mSerial_worker2 = new Serialworkerthread;
    mSerial_worker3 = new Serialworkerthread;
    mSerial_worker4 = new Serialworkerthread;
    mSerial_worker5 = new Serialworkerthread;
    mSerial_worker6 = new Serialworkerthread;
    mSerial_worker7 = new Serialworkerthread;
    mSerial_worker8 = new Serialworkerthread;

    mSerial_worker->moveToThread(mthread);
    mSerial_worker2->moveToThread(mthread2);
    mSerial_worker3->moveToThread(mthread3);
    mSerial_worker4->moveToThread(mthread4);
    mSerial_worker5->moveToThread(mthread5);
    mSerial_worker6->moveToThread(mthread6);
    mSerial_worker7->moveToThread(mthread7);
    mSerial_worker8->moveToThread(mthread8);

//     connect(this,SIGNAL(mySignal(int)),SLOT(mySlot(int)));
//     connect(this,SIGNAL(senddatabin(int)),SLOT(senddatabinSlot(int)));
    QObject::connect(mthread,  &QThread::finished, mSerial_worker, &QObject::deleteLater);       // 清理线程
    QObject::connect(mthread2, &QThread::finished, mSerial_worker2, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread3, &QThread::finished, mSerial_worker3, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread4, &QThread::finished, mSerial_worker4, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread5, &QThread::finished, mSerial_worker5, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread6, &QThread::finished, mSerial_worker6, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread7, &QThread::finished, mSerial_worker7, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread8, &QThread::finished, mSerial_worker8, &QObject::deleteLater);      // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker,SLOT(write_serial_data(QByteArray)),Qt::AutoConnection); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker,SLOT(close_serial()),Qt::AutoConnection); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker,SLOT(open_serial()),Qt::AutoConnection); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数
//     QObject::connect(this, SIGNAL(changebaudrate(int)),mSerial_worker,SLOT(readclislot(int)),Qt::AutoConnection); //修改波特率

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker2,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker2,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker2,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker2,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker2,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker3,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker3,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker3,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker3,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker3,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker4,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker4,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker4,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker4,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker4,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker5,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker5,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker5,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker5,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker5,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker6,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker6,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker6,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker6,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker6,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker7,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker7,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker7,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker7,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker7,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker8,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker8,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker8,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker8,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker8,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker, SIGNAL(sendvar(QString)),this,SLOT(on_showvar(QString)),Qt::AutoConnection); //次线程向主线程发送数据版本信息
    QObject::connect(mSerial_worker, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker2, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli2(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker2, SIGNAL(sendvar(QString)),this,SLOT(on_showvar2(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker2, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot2(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker2, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_2(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker3, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli3(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker3, SIGNAL(sendvar(QString)),this,SLOT(on_showvar3(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker3, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot3(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker3, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_3(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker4, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli4(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker4, SIGNAL(sendvar(QString)),this,SLOT(on_showvar4(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker4, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot4(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker4, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_4(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker5, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli5(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker5, SIGNAL(sendvar(QString)),this,SLOT(on_showvar5(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker5, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot5(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker5, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_5(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker6, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli6(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker6, SIGNAL(sendvar(QString)),this,SLOT(on_showvar6(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker6, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot6(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker6, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_6(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker7, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli7(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker7, SIGNAL(sendvar(QString)),this,SLOT(on_showvar7(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker7, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot7(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker7, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_7(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker8, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli8(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker8, SIGNAL(sendvar(QString)),this,SLOT(on_showvar8(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker8, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot8(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker8, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_8(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

     connect(mthread, &QThread::started, [=](){
         // QString portName = ui->uartnum_lineedit->text();
         QString portName = ui->comboBox_uartNumber->currentText();
         mSerial_worker->startPort(portName,portbaudrate);
            });
     connect(mthread2, &QThread::started, [=](){
        // QString portName2 = ui->uartnum_lineedit_2->text();
         QString portName2 = ui->comboBox_uartNumber_2->currentText();
         mSerial_worker2->startPort(portName2,portbaudrate);
            });
     connect(mthread3, &QThread::started, [=](){
        // QString portName3 = ui->uartnum_lineedit_3->text();
         QString portName3 = ui->comboBox_uartNumber_3->currentText();
         mSerial_worker3->startPort(portName3,portbaudrate);
            });
     connect(mthread4, &QThread::started, [=](){
         // QString portName4 = ui->uartnum_lineedit_4->text();
         QString portName4 = ui->comboBox_uartNumber_4->currentText();
         mSerial_worker4->startPort(portName4,portbaudrate);
            });
     connect(mthread5, &QThread::started, [=](){
        // QString portName5 = ui->uartnum_lineedit_5->text();
         QString portName5 = ui->comboBox_uartNumber_5->currentText();
         mSerial_worker5->startPort(portName5,portbaudrate);
            });
     connect(mthread6, &QThread::started, [=](){
        // QString portName6 = ui->uartnum_lineedit_6->text();
         QString portName6 = ui->comboBox_uartNumber_6->currentText();
         mSerial_worker6->startPort(portName6,portbaudrate);
            });
     connect(mthread7, &QThread::started, [=](){
        // QString portName7 = ui->uartnum_lineedit_7->text();
         QString portName7 = ui->comboBox_uartNumber_7->currentText();
         mSerial_worker7->startPort(portName7,portbaudrate);
            });
     connect(mthread8, &QThread::started, [=](){
        // QString portName8 = ui->uartnum_lineedit_8->text();
         QString portName8 = ui->comboBox_uartNumber_8->currentText();
         mSerial_worker8->startPort(portName8,portbaudrate);
            });

     qDebug()<<"识别到串口个数"<< PortStringList.size();

     /* 启动进程 */
     switch(PortStringList.size())
     {
      case 0:qDebug()<<"无有用串口";break;
      case 1:qDebug()<<"开启1个串口线程";
             mthread->start();
             Sleep(100);
              break;
     case 2:qDebug()<<"开启2个串口线程";
             mthread->start();
             mthread2->start();
             Sleep(100);

             break;
     case 3:qDebug()<<"开启3个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             Sleep(100);
             break;
     case 4:qDebug()<<"开启4个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             Sleep(100);
             break;
     case 5:qDebug()<<"开启5个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             Sleep(100);
             break;
     case 6:qDebug()<<"开启6个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             mthread6->start();
             Sleep(100);
             break;
     case 7:qDebug()<<"开启7个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             mthread6->start();
             mthread7->start();
             Sleep(100);
             break;
     case 8:qDebug()<<"开启8个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             mthread6->start();
             mthread7->start();
             mthread8->start();
             Sleep(100);
             break;
     }
}

void MainWindow::comboxClickTrigger(QString portNum)
{
//    uart_thread_close();
    mthread->quit(); mthread->wait(); mthread->deleteLater();
    //OpenRadarPort();
    //statusDisplayInit();
    on_showBurnStatus("EMPTY");

    mthread = new QThread(this);

    mSerial_worker = new Serialworkerthread;

    mSerial_worker->moveToThread(mthread);

    QObject::connect(mthread,  &QThread::finished, mSerial_worker, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker,SLOT(write_serial_data(QByteArray)),Qt::AutoConnection); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker,SLOT(close_serial()),Qt::AutoConnection); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker, SIGNAL(sendvar(QString)),this,SLOT(on_showvar(QString)),Qt::AutoConnection); //次线程向主线程发送数据版本信息
    QObject::connect(mSerial_worker, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

     connect(mthread, &QThread::started, [=](){
         // QString portName = ui->uartnum_lineedit->text();
         QString portName = portNum;
         mSerial_worker->startPort(portName,portbaudrate);
            });

    mthread->start();
}

void MainWindow::comboxClickTrigger2(QString portNum)
{
    mthread2->quit(); mthread2->wait(); mthread2->deleteLater();
    on_showBurnStatus_2("EMPTY");

    mthread2 = new QThread(this);

    mSerial_worker2 = new Serialworkerthread;

    mSerial_worker2->moveToThread(mthread2);

    QObject::connect(mthread2,  &QThread::finished, mSerial_worker2, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker2,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker2,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker2,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker2,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker2, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli2(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker2, SIGNAL(sendvar(QString)),this,SLOT(on_showvar2(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker2, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot2(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker2, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_2(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread2, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName2 = portNum;
        mSerial_worker2->startPort(portName2,portbaudrate);
           });

    mthread2->start();
}
void MainWindow::comboxClickTrigger3(QString portNum)
{
    mthread3->quit(); mthread3->wait(); mthread3->deleteLater();
    on_showBurnStatus_3("EMPTY");

    mthread3 = new QThread(this);

    mSerial_worker3 = new Serialworkerthread;

    mSerial_worker3->moveToThread(mthread3);

    QObject::connect(mthread3,  &QThread::finished, mSerial_worker3, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker3,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker3,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker3,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker3,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker3, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli3(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker3, SIGNAL(sendvar(QString)),this,SLOT(on_showvar3(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker3, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot3(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker3, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_3(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread3, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName3 = portNum;
        mSerial_worker3->startPort(portName3,portbaudrate);
           });

    mthread3->start();
}


void MainWindow::comboxClickTrigger4(QString portNum)
{
    mthread4->quit(); mthread4->wait(); mthread4->deleteLater();
    on_showBurnStatus_4("EMPTY");

    mthread4 = new QThread(this);

    mSerial_worker4 = new Serialworkerthread;

    mSerial_worker4->moveToThread(mthread4);

    QObject::connect(mthread4,  &QThread::finished, mSerial_worker4, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker4,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker4,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker4,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()), mSerial_worker4,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker4, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli4(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker4, SIGNAL(sendvar(QString)),this,SLOT(on_showvar4(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker4, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot4(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker4, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_4(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread4, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName4 = portNum;
        mSerial_worker4->startPort(portName4,portbaudrate);
           });

    mthread4->start();
}

void MainWindow::comboxClickTrigger5(QString portNum)
{
    mthread5->quit(); mthread5->wait(); mthread5->deleteLater();
    on_showBurnStatus_5("EMPTY");

    mthread5 = new QThread(this);

    mSerial_worker5 = new Serialworkerthread;

    mSerial_worker5->moveToThread(mthread5);

    QObject::connect(mthread5,  &QThread::finished, mSerial_worker5, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker5,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker5,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker5,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()), mSerial_worker5,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker5, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli5(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker5, SIGNAL(sendvar(QString)),this,SLOT(on_showvar5(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker5, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot5(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker5, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_5(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread5, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName5 = portNum;
        mSerial_worker5->startPort(portName5,portbaudrate);
           });

    mthread5->start();
}

void MainWindow::comboxClickTrigger6(QString portNum)
{
    mthread6->quit(); mthread6->wait(); mthread6->deleteLater();
    on_showBurnStatus_6("EMPTY");

    mthread6 = new QThread(this);

    mSerial_worker6 = new Serialworkerthread;

    mSerial_worker6->moveToThread(mthread6);

    QObject::connect(mthread6,  &QThread::finished, mSerial_worker6, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker6,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker6,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker6,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()), mSerial_worker6,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker6, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli6(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker6, SIGNAL(sendvar(QString)),this,SLOT(on_showvar6(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker6, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot6(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker6, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_6(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread6, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName6 = portNum;
        mSerial_worker6->startPort(portName6,portbaudrate);
           });

    mthread6->start();
}

void MainWindow::comboxClickTrigger7(QString portNum)
{
    mthread7->quit(); mthread7->wait(); mthread7->deleteLater();
    on_showBurnStatus_7("EMPTY");

    mthread7 = new QThread(this);

    mSerial_worker7 = new Serialworkerthread;

    mSerial_worker7->moveToThread(mthread7);

    QObject::connect(mthread7,  &QThread::finished, mSerial_worker7, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker7,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker7,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker7,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()), mSerial_worker7,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker7, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli7(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker7, SIGNAL(sendvar(QString)),this,SLOT(on_showvar7(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker7, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot7(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker7, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_7(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread7, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName7 = portNum;
        mSerial_worker7->startPort(portName7,portbaudrate);
           });

    mthread7->start();
}

void MainWindow::comboxClickTrigger8(QString portNum)
{
    mthread8->quit(); mthread8->wait(); mthread8->deleteLater();
    on_showBurnStatus_8("EMPTY");

    mthread8 = new QThread(this);

    mSerial_worker8 = new Serialworkerthread;

    mSerial_worker8->moveToThread(mthread8);

    QObject::connect(mthread8,  &QThread::finished, mSerial_worker8, &QObject::deleteLater);       // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker8,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker8,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker8,SLOT(close_serial())); //连接关闭串口
    QObject::connect(this, SIGNAL(readcli()), mSerial_worker8,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker8, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli8(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker8, SIGNAL(sendvar(QString)),this,SLOT(on_showvar8(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker8, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot8(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker8, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_8(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

    connect(mthread8, &QThread::started, [=](){
       // QString portName2 = ui->uartnum_lineedit_2->text();
        QString portName8 = portNum;
        mSerial_worker8->startPort(portName8,portbaudrate);
           });

    mthread8->start();
}

void MainWindow::on_comboBox_uartNumber_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    //int portbaudrate = BAUDRATE;
    QString portName;

    portName.clear();
    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
           //qDebug() << com_buf;
           portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger(portName);
}

void MainWindow::on_comboBox_uartNumber_2_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger2(portName);
}

void MainWindow::on_comboBox_uartNumber_3_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger3(portName);
}

void MainWindow::on_comboBox_uartNumber_4_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger4(portName);
}

void MainWindow::on_comboBox_uartNumber_5_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger5(portName);
}

void MainWindow::on_comboBox_uartNumber_6_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger6(portName);
}

void MainWindow::on_comboBox_uartNumber_7_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger7(portName);
}

void MainWindow::on_comboBox_uartNumber_8_activated(const QString &arg1)
{
    //qDebug()<<arg1;
    QString  com_buf;
    QString portName;

    this->serialRead->close();
    //遍历查询端口号并显示在comboBox控件上。
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        com_buf = info.portName();
        if(arg1 == com_buf)
        {
             portName = com_buf;
        }
    }
    qDebug() << portName;
    comboxClickTrigger8(portName);
}

void MainWindow::updataSerailPort()
{
    uart_thread_close();
    OpenRadarPort();
    statusDisplayInit();

    mthread = new QThread(this);
    mthread2 = new QThread(this);
    mthread3 = new QThread(this);
    mthread4 = new QThread(this);
    mthread5 = new QThread(this);
    mthread6 = new QThread(this);
    mthread7 = new QThread(this);
    mthread8 = new QThread(this);

    mSerial_worker = new Serialworkerthread;
    mSerial_worker2 = new Serialworkerthread;
    mSerial_worker3 = new Serialworkerthread;
    mSerial_worker4 = new Serialworkerthread;
    mSerial_worker5 = new Serialworkerthread;
    mSerial_worker6 = new Serialworkerthread;
    mSerial_worker7 = new Serialworkerthread;
    mSerial_worker8 = new Serialworkerthread;

    mSerial_worker->moveToThread(mthread);
    mSerial_worker2->moveToThread(mthread2);
    mSerial_worker3->moveToThread(mthread3);
    mSerial_worker4->moveToThread(mthread4);
    mSerial_worker5->moveToThread(mthread5);
    mSerial_worker6->moveToThread(mthread6);
    mSerial_worker7->moveToThread(mthread7);
    mSerial_worker8->moveToThread(mthread8);

//     connect(this,SIGNAL(mySignal(int)),SLOT(mySlot(int)));
//     connect(this,SIGNAL(senddatabin(int)),SLOT(senddatabinSlot(int)));
    QObject::connect(mthread,  &QThread::finished, mSerial_worker, &QObject::deleteLater);       // 清理线程
    QObject::connect(mthread2, &QThread::finished, mSerial_worker2, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread3, &QThread::finished, mSerial_worker3, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread4, &QThread::finished, mSerial_worker4, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread5, &QThread::finished, mSerial_worker5, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread6, &QThread::finished, mSerial_worker6, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread7, &QThread::finished, mSerial_worker7, &QObject::deleteLater);      // 清理线程
    QObject::connect(mthread8, &QThread::finished, mSerial_worker8, &QObject::deleteLater);      // 清理线程

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker,SLOT(write_serial_data(QByteArray)),Qt::AutoConnection); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker,SLOT(close_serial()),Qt::AutoConnection); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker,SLOT(open_serial()),Qt::AutoConnection); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数
//     QObject::connect(this, SIGNAL(changebaudrate(int)),mSerial_worker,SLOT(readclislot(int)),Qt::AutoConnection); //修改波特率

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker2,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker2,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker2,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker2,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker2,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker3,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker3,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker3,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker3,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker3,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker4,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker4,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker4,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker4,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker4,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker5,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker5,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker5,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker5,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker5,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker6,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker6,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker6,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker6,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker6,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker7,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker7,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker7,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker7,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker7,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数

    QObject::connect(this, SIGNAL(sendtoserial(QByteArray)),mSerial_worker8,SLOT(write_serial_data(QByteArray))); //连接发送函数
    QObject::connect(this, SIGNAL(firmupdatesignals(QByteArray,int)),mSerial_worker8,SLOT(firmbinupdateslot(QByteArray,int)),Qt::AutoConnection);//启动升级
    QObject::connect(this, SIGNAL(closeserial()),mSerial_worker8,SLOT(close_serial())); //连接关闭串口
//     QObject::connect(this, SIGNAL(openserial()),mSerial_worker8,SLOT(open_serial())); //连接打开串口
    QObject::connect(this, SIGNAL(readcli()),mSerial_worker8,SLOT(readclislot()),Qt::AutoConnection); //连接读取配置参数


    QObject::connect(mSerial_worker, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker, SIGNAL(sendvar(QString)),this,SLOT(on_showvar(QString)),Qt::AutoConnection); //次线程向主线程发送数据版本信息
    QObject::connect(mSerial_worker, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker2, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli2(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker2, SIGNAL(sendvar(QString)),this,SLOT(on_showvar2(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker2, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot2(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker2, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_2(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker3, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli3(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker3, SIGNAL(sendvar(QString)),this,SLOT(on_showvar3(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker3, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot3(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker3, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_3(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker4, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli4(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker4, SIGNAL(sendvar(QString)),this,SLOT(on_showvar4(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker4, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot4(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker4, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_4(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker5, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli5(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker5, SIGNAL(sendvar(QString)),this,SLOT(on_showvar5(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker5, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot5(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker5, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_5(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker6, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli6(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker6, SIGNAL(sendvar(QString)),this,SLOT(on_showvar6(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker6, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot6(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker6, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_6(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker7, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli7(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker7, SIGNAL(sendvar(QString)),this,SLOT(on_showvar7(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker7, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot7(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker7, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_7(QString)),Qt::AutoConnection);//显示烧录状态

    QObject::connect(mSerial_worker8, SIGNAL(sendcli(QString)),this,SLOT(on_comparisoncli8(QString)),Qt::AutoConnection); //次线程向主线程发送雷达参数数据
    QObject::connect(mSerial_worker8, SIGNAL(sendvar(QString)),this,SLOT(on_showvar8(QString)),Qt::AutoConnection); //次线程向主线程发送数据
    QObject::connect(mSerial_worker8, SIGNAL(sendprogressdlgupdatesignals(int)),this,SLOT(on_showprogressslot8(int)),Qt::AutoConnection);//显示升级进度
    QObject::connect(mSerial_worker8, SIGNAL(sendStatusSignal(QString)),this,SLOT(on_showBurnStatus_8(QString)),Qt::AutoConnection);//显示烧录状态


    connect(ui->textBrowser_burnStatus, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));

//     int portbaudrate = ui->comboBox->currentText().toInt();
    int portbaudrate = 115200;

     connect(mthread, &QThread::started, [=](){
         // QString portName = ui->uartnum_lineedit->text();
         QString portName = ui->comboBox_uartNumber->currentText();
         mSerial_worker->startPort(portName,portbaudrate);
            });
     connect(mthread2, &QThread::started, [=](){
        // QString portName2 = ui->uartnum_lineedit_2->text();
         QString portName2 = ui->comboBox_uartNumber_2->currentText();
         mSerial_worker2->startPort(portName2,portbaudrate);
            });
     connect(mthread3, &QThread::started, [=](){
        // QString portName3 = ui->uartnum_lineedit_3->text();
         QString portName3 = ui->comboBox_uartNumber_3->currentText();
         mSerial_worker3->startPort(portName3,portbaudrate);
            });
     connect(mthread4, &QThread::started, [=](){
         // QString portName4 = ui->uartnum_lineedit_4->text();
         QString portName4 = ui->comboBox_uartNumber_4->currentText();
         mSerial_worker4->startPort(portName4,portbaudrate);
            });
     connect(mthread5, &QThread::started, [=](){
        // QString portName5 = ui->uartnum_lineedit_5->text();
         QString portName5 = ui->comboBox_uartNumber_5->currentText();
         mSerial_worker5->startPort(portName5,portbaudrate);
            });
     connect(mthread6, &QThread::started, [=](){
        // QString portName6 = ui->uartnum_lineedit_6->text();
         QString portName6 = ui->comboBox_uartNumber_6->currentText();
         mSerial_worker6->startPort(portName6,portbaudrate);
            });
     connect(mthread7, &QThread::started, [=](){
        // QString portName7 = ui->uartnum_lineedit_7->text();
         QString portName7 = ui->comboBox_uartNumber_7->currentText();
         mSerial_worker7->startPort(portName7,portbaudrate);
            });
     connect(mthread8, &QThread::started, [=](){
        // QString portName8 = ui->uartnum_lineedit_8->text();
         QString portName8 = ui->comboBox_uartNumber_8->currentText();
         mSerial_worker8->startPort(portName8,portbaudrate);
            });

     qDebug()<<"识别到串口个数"<< PortStringList.size();

     /* 启动进程 */
     switch(PortStringList.size())
     {
      case 0:qDebug()<<"无有用串口";break;
      case 1:qDebug()<<"开启1个串口线程";
             mthread->start();
             Sleep(100);
              break;
     case 2:qDebug()<<"开启2个串口线程";
             mthread->start();
             mthread2->start();
             Sleep(100);

             break;
     case 3:qDebug()<<"开启3个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             Sleep(100);
             break;
     case 4:qDebug()<<"开启4个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             Sleep(100);
             break;
     case 5:qDebug()<<"开启5个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             Sleep(100);
             break;
     case 6:qDebug()<<"开启6个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             mthread6->start();
             Sleep(100);
             break;
     case 7:qDebug()<<"开启7个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             mthread6->start();
             mthread7->start();
             Sleep(100);
             break;
     case 8:qDebug()<<"开启8个串口线程";
             mthread->start();
             mthread2->start();
             mthread3->start();
             mthread4->start();
             mthread5->start();
             mthread6->start();
             mthread7->start();
             mthread8->start();
             Sleep(100);
             break;
     }
}
