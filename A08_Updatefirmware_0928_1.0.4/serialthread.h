#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>



class SerialThread : public QThread
{
    Q_OBJECT

public:
    SerialThread(QString port, long baud);


    void Sleep(int msec);
    QByteArray tempsrc;
protected:





signals:

    void senddata(QByteArray data);//向主线程发送接收到的串口数据
    void signalemit(QByteArray);

public slots:

    void read_serial_data();//读取串口数据

    void close_mthread_serial();//关闭
    void write_serial_data(QByteArray str);

private:


    QSerialPort *serial;
    QString myport;
    long myBaud;
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明

    float data;
     void run();
};

#endif // SERIALTHREAD_H

