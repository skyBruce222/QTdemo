#ifndef SERIALWORKERTHREAD_H
#define SERIALWORKERTHREAD_H

//#include <QObject>

//class Serialworkerthread : public QObject
//{
//    Q_OBJECT
//public:
//    explicit Serialworkerthread(QObject *parent = nullptr);

//signals:

//public slots:
//};

#include <QObject>
#include <QSerialPort>
#include<QHash>
#include<QSerialPortInfo>
#include <QTimer>
class Serialworkerthread : public QObject
{
    Q_OBJECT
public:
    explicit Serialworkerthread(QObject *parent = nullptr);
//    void startPort(const QString &portName);
//    void startPort(QString);
    void startPort(QString,int);
    void Sleep(int msec);
//    void firmbinupdate();
    uint8_t crc8(const QByteArray &data, int32_t len);
    uint8_t checkSum(const QByteArray &data, int32_t len);

    float   parseValueFloat(QByteArray data,  int valuePos, int valueSize);
    quint32 parseValueUint32(QByteArray data, int valuePos, int valueSize);
    quint16 parseValueUint16(QByteArray data, int valuePos, int valueSize);
    qint16  parseValueInt16(QByteArray data, int valuePos, int valueSize);

    //字符串转16进制
     QByteArray QString2Hex(QString str);
      //字符转16进制
     char ConvertHexChar(char ch);
     uint8_t stopflag,bootLoaderFlag,softresetflag,erasureflashflag,updatetestflag,binsizeflag,sendeachbinflag,resendeachbinflag,sendeachbinendflag,sendbinupdateflag;
      uint8_t ack_response_flag, first_status_response_flag, status_response_flag, version_response_flag, ack_response_error_flag;
      bool verread,cliread;
      int sizefirmware;
      QString framecount_string;
       QString temp1,temp2;
      QByteArray firmwarebin;


signals:
    void senddata(QByteArray data);//向主线程发送接收到的串口数据
    void sendvar(QString data);//向主线程发送版本号
    void sendprogressdlgupdatesignals(int data);//向主线程发送接收到的串口数据
    void sendStatusSignal(QString status);
    void senddatabin(int x);
    void sendcli(QString data);//向主线程发送雷达参数
//    void sendburnstatus(QString data);
private:
    QHash<QString, QSerialPortInfo> m_portList;
    QSerialPort *m_port;
    QTimer *timer;
    QByteArray dataBuffer;
    QByteArray dataBufferrevsave;

    void uart_break(void);
    void get_status_command(void);
    void ping_command(void);
    void get_version_command(void);
    void erase_command(void);
    void open_command(int binSize);
    void write_to_flash_command(int frameCnt);
    void close_command(void);

    void sensorstop(void);// 停止雷达
    void softreset(void);// 重启
    void softresetF9(void);// 重启
    void updatemode(int);// 进入升级模式
    void updatetest(void);//升级测试
    void updateerasuse(void);// 擦除FLASH
    void sendbinsize(int);//发送固件大小
    void sendbindate(int framecount);
    void updatebin(void);
    void sendserialcmd(QByteArray);
    void hexdataParse(QByteArray);
    void checkparams();//参数校验
    void readvar();
    void readcli(void);

public slots:
    void Serial_Read();
    void write_serial_data(QByteArray str);
    void close_serial();
    void open_serial(int);
//    void open_serial();
    void display();
    void firmbinupdateslot(QByteArray firmbindata,int baudrate);
    void senddatabinSlot(int x);
    void readclislot();
//    void changebaudrateslot(int);  //修改波特率

//    void Init();
};

#endif // SERIALWORKERTHREAD_H
