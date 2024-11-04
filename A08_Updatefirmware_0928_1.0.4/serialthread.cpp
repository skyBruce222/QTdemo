#include "serialthread.h"
#include "mainwindow.h"
#include <QElapsedTimer>
#include <QTimer>
#include <QDateTime>
#include<QCoreApplication>

SerialThread::SerialThread(QString port, long baud)
{
     isStop = false;
    myport = port;
    myBaud = baud;
    tempsrc=0;

}
void SerialThread::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void SerialThread::run()

{
            qDebug() <<"start run";
            serial = new QSerialPort();
            serial->setPortName(myport);
            qDebug() <<myport<< "SerialThread thread ID:" << QThread::currentThreadId() << '\n' ;

            serial->open(QIODevice::ReadWrite);//读写方式打开

            serial->setBaudRate(myBaud);//波特率

            serial->setDataBits(QSerialPort::Data8);//数据位

            serial->setParity(QSerialPort::NoParity);//奇偶校验

            serial->setStopBits(QSerialPort::OneStop);//停止位

            serial->setFlowControl(QSerialPort::NoFlowControl);//控制位
            connect(serial, SIGNAL(readyRead()), this, SLOT(read_serial_data()), Qt::AutoConnection);//有数据就读
//            connect(this, SIGNAL(signalemit(QByteArray)), this, SLOT(write_serial_data(QByteArray)), Qt::DirectConnection);
//            connect(serial, SIGNAL(signalemit(QByteArray)), this, SLOT(write_serial_data(QByteArray)), Qt::AutoConnection);//有数据就读
//            connect(serial, SIGNAL(readyRead()), this, SLOT(read_serial_data()), Qt::AutoConnection);//有数据就读
//            QByteArray temp;
//            qDebug() <<"write11123341:";
            exec();
//            qDebug() <<"write111:";
            while (1)
            {
//                    if(!tempsrc.isNull())
//                    {
//                        qDebug() <<"writetempsrc:"<<tempsrc;
//                        this->serial->write(tempsrc);
//                        Sleep(100);
//                    }
                if(isStop)
                    {
                        if(serial->isOpen())
                        {
                            this->serial->clear();
                            qDebug() <<"关闭串口"<<endl;
                            serial->close();//关闭子线程
                            serial->deleteLater();
                        }
                         return;
                    }
                Sleep(100);
               qDebug() <<"write1:";

            }






//             connect(serial, SIGNAL(readyRead()), this, SLOT(read_serial_data()), Qt::AutoConnection);//有数据就读


}

void SerialThread::read_serial_data()
{

        QByteArray temp;
//       temp = serial->readAll().toHex();//每串数据为9个字节
        temp = serial->readAll();
//        qDebug() <<"串口数据："<<temp;
        emit senddata(temp);//发送数据给主线程
}

void SerialThread::close_mthread_serial()

{
    isStop = true;
    qDebug() <<"关闭串口"<<endl;


}
void SerialThread::write_serial_data(QByteArray str)
{
    qDebug() <<"write:"<<str;

//    tempsrc=str;
//    qDebug() <<"write:"<<tempsrc.isNull();
     serial->write(str);

    Sleep(10);
//    serial->write("\n");
}

