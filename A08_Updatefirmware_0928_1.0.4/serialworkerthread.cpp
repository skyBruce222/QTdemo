#include "serialworkerthread.h"
#include<QList>

#include<QDebug>
#include<QString>
#include <QElapsedTimer>

#include <QDateTime>
#include<QCoreApplication>
#include <QThread>
#include <QtEndian>
static int k=0;

//static int sizefirmware=0;
//uint16_t sendeachbinsize=64;  //每包数据大小；

// int sizefirmware=0;
uint16_t sendeachbinsize=240;  //每包数据大小； 128ok



uint8_t crc8_table[256] = {
0x93,0x98,0xE4,0x46,0xEB,0xBA,0x04,0x4C,
0xFA,0x40,0xB8,0x96,0x0E,0xB2,0xB7,0xC0,
0x0C,0x32,0x9B,0x80,0xFF,0x30,0x7F,0x9D,
0xB3,0x81,0x58,0xE7,0xF1,0x19,0x7E,0xB6,
0xCD,0xF7,0xB4,0xCB,0xBC,0x5C,0xD6,0x09,
0x20,0x0A,0xE0,0x37,0x51,0x67,0x24,0x95,
0xE1,0x62,0xF8,0x5E,0x38,0x15,0x54,0x77,
0x63,0x57,0x6D,0xE9,0x89,0x76,0xBE,0x41,
0x5D,0xF9,0xB1,0x4D,0x6C,0x53,0x9C,0xA2,
0x23,0xC4,0x8E,0xC8,0x05,0x42,0x61,0x71,
0xC5,0x00,0x18,0x6F,0x5F,0xFB,0x7B,0x11,
0x65,0x2D,0x8C,0xED,0x14,0xAB,0x88,0xD5,
0xD9,0xC2,0x36,0x34,0x7C,0x5B,0x3C,0xF6,
0x48,0x0B,0xEE,0x02,0x83,0x79,0x17,0xE6,
0xA8,0x78,0xF5,0xD3,0x4E,0x50,0x52,0x91,
0xD8,0xC6,0x22,0xEC,0x3B,0xE5,0x3F,0x86,
0x06,0xCF,0x2B,0x2F,0x3D,0x59,0x1C,0x87,
0xEF,0x4F,0x10,0xD2,0x7D,0xDA,0x72,0xA0,
0x9F,0xDE,0x6B,0x75,0x56,0xBD,0xC7,0xC1,
0x70,0x1D,0x25,0x92,0xA5,0x31,0xE2,0xD7,
0xD0,0x9A,0xAF,0xA9,0xC9,0x97,0x08,0x33,
0x5A,0x99,0xC3,0x16,0x84,0x82,0x8A,0xF3,
0x4A,0xCE,0xDB,0x29,0x0F,0xAE,0x6E,0xE3,
0x8B,0x07,0x3A,0x74,0x47,0xB0,0xBB,0xB5,
0x7A,0xA9,0x2C,0xD4,0x03,0x3E,0x1A,0xA7,
0x27,0x64,0x06,0xBF,0x56,0x73,0x1E,0xFE,
0x49,0x01,0x39,0x28,0xF4,0x26,0xDF,0xDD,
0x44,0x0D,0x21,0xF2,0x85,0xB9,0xEA,0x4B,
0xDC,0x6A,0xCA,0xAC,0x12,0xFC,0x2E,0x2A,
0xA3,0xF0,0x66,0xE8,0x60,0x45,0xA1,0x8D,
0x68,0x35,0xFD,0x8F,0x9E,0x1F,0x13,0xD1,
0xAD,0x69,0xCC,0xA4,0x94,0x90,0x1B,0x43,
};
Serialworkerthread::Serialworkerthread(QObject *parent) : QObject(parent)
{
    QList<QSerialPortInfo> serialInfopList = QSerialPortInfo::availablePorts();
    if(!serialInfopList.empty())
    {
        for(auto portInfo : serialInfopList)
        {
            m_portList.insert(portInfo.portName(), portInfo);
        }
    }
    stopflag=0;bootLoaderFlag=0;softresetflag=0;erasureflashflag=0;updatetestflag=0;binsizeflag=0;sendeachbinflag=0;resendeachbinflag=0;sendeachbinendflag=0;sendbinupdateflag=0;
    verread=1;
    cliread=0;
    sizefirmware=0;
}
//void Worker::startPort(const QString &portName)
//void Serialworkerthread::startPort(QString portName)
//{
//   qDebug() << "打开串口"<<portName;
//    QSerialPortInfo portInfo = m_portList[portName];
//    m_port = new QSerialPort(portInfo);
//    m_port->open(QIODevice::ReadWrite);//读写方式打开
//    m_port->setBaudRate(115200);//波特率
//    m_port->setDataBits(QSerialPort::Data8);//数据位
//    m_port->setParity(QSerialPort::NoParity);//奇偶校验
//    m_port->setStopBits(QSerialPort::OneStop);//停止位
//    m_port->setFlowControl(QSerialPort::NoFlowControl);//控制位
//    timer = new QTimer; //定时扫描和更新串口
//     qDebug() << ("open port success");

//    connect(m_port, &QSerialPort::readyRead,this,&Serialworkerthread::Serial_Read,Qt::AutoConnection);

//    connect(this,SIGNAL(senddatabin(int)),SLOT(senddatabinSlot(int)));
//    Sleep(1000);

//    Sleep(1000);
//}

void Serialworkerthread::startPort(QString portName,int baudrate)
{
    qDebug() << "打开串口"<< portName;
    QSerialPortInfo portInfo = m_portList[portName];
    //qDebug()<<portInfo;
    m_port = new QSerialPort(portInfo);
    m_port->open(QIODevice::ReadWrite);//读写方式打开
//    m_port->setBaudRate(115200);//波特率
    m_port->setBaudRate(baudrate);//波特率
    m_port->setDataBits(QSerialPort::Data8);//数据位
    m_port->setParity(QSerialPort::NoParity);//奇偶校验
    m_port->setStopBits(QSerialPort::OneStop);//停止位
    m_port->setFlowControl(QSerialPort::NoFlowControl);//控制位
    //timer = new QTimer; //定时扫描和更新串口
 //    qDebug() << ("open port success");

    connect(m_port, &QSerialPort::readyRead,this,&Serialworkerthread::Serial_Read,Qt::AutoConnection);

    connect(this,SIGNAL(senddatabin(int)),SLOT(senddatabinSlot(int)));
    m_port->clear();
    m_port->close();
    Sleep(1000);

//    Sleep(1000);
}

//void Worker::sendMessage( const QString &message)
//{
//    if (m_port)
//    {
//        int ret = m_port->write(message);
//        qDebug() << ("send message. ") << ret << "bytes";
//    }
//}
void Serialworkerthread::write_serial_data( QByteArray str)
{
//    qDebug() << "进入写串口";
    if (m_port)
    {
         m_port->write(str);
        // qDebug() << "串口发送:"<< str.toHex();
//         Sleep(20);
         Sleep(1);

    }
}
void Serialworkerthread::close_serial()
{
    qDebug() << "关闭串口";
    if (m_port)
    {
        m_port->clear();
        m_port->close();
    //     qDebug() << "close serial" ;
    }
}
void Serialworkerthread::open_serial(int baudrate)
{
    qDebug() << "打开串口";
    if (m_port)
    {
        if(!m_port->isOpen())
        {
            m_port->open(QIODevice::ReadWrite);//读写方式打开
        //    m_port->setBaudRate(115200);//波特率
            m_port->setBaudRate(baudrate);
            m_port->setDataBits(QSerialPort::Data8);//数据位
            m_port->setParity(QSerialPort::NoParity);//奇偶校验
            m_port->setStopBits(QSerialPort::OneStop);//停止位
            m_port->setFlowControl(QSerialPort::NoFlowControl);//控制位
        }

    }
//    QSerialPortInfo portInfo = m_portList[portName];
//    m_port = new QSerialPort(portInfo);

}

void Serialworkerthread::Serial_Read()
{


//    temp = m_port->readAll().toHex();
//    qDebug() <<"串口数据十六进制："<<temp;
        QString tempserialdata;
        QByteArray temp;

        tempserialdata = m_port->readAll().toHex();
             temp=tempserialdata.toLatin1();

             hexdataParse(temp);
}

void Serialworkerthread::hexdataParse(QByteArray t_strLine)
{
   // QDateTime timeCur;

    dataBuffer = dataBuffer.append(t_strLine);
   // timeCur = QDateTime::currentDateTime();//获取系统现在的时间
   // qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口接收到" << dataBuffer ;

    if(dataBuffer.contains("0004cc00cc"))
    {
        ack_response_flag = 1;
    }
    else if(dataBuffer.contains("00034040"))
    {
        status_response_flag = 1;
    }
    else if(dataBuffer.contains("00030000"))
    {
        first_status_response_flag = 1;
    }
    else if(dataBuffer.contains("0004cc00cc000e"))
    {
        version_response_flag = 1;
    }
    else if(dataBuffer.contains("0004cc00cc"))
    {
        ack_response_error_flag = 1;
    }
    dataBuffer.clear();//清理接收缓存

}
void Serialworkerthread::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void Serialworkerthread::display()
{

    qDebug() <<"串口线程ID："<<QThread::currentThread()<<"次数"<<k;;
    k++;
}
void Serialworkerthread::sendserialcmd(QByteArray data)
{
//    emit sendtoserial(data);
    write_serial_data(data);

}

/* 固件升级函数*/
void Serialworkerthread::firmbinupdateslot(QByteArray firmbindata,int baudrate)
{
    Sleep(200);
    verread=1;
    cliread=0;
    sizefirmware=0;
    stopflag=0;bootLoaderFlag=0;softresetflag=0;erasureflashflag=0;
    updatetestflag=0;binsizeflag=0;sendeachbinflag=0;
    resendeachbinflag=0;sendeachbinendflag=0;sendbinupdateflag=0;
    ack_response_flag = 0; first_status_response_flag = 0; status_response_flag = 0; version_response_flag = 0;
    dataBuffer.clear();
    uint32_t fileTotalSize = 0;
    QDateTime timeCur;
    uint32_t burnStartTime = 0, burnEndTime = 0, burnTotalTime = 0;

    emit sendStatusSignal("RUN");
    fileTotalSize = firmbindata.size()/2;
  //  qDebug()<<"固件字节数"<<fileTotalSize;
    if((firmbindata.size()/2)%sendeachbinsize==0)
    {
        sizefirmware=(firmbindata.size()/2)/sendeachbinsize;
    }
    else
    {
        sizefirmware=(firmbindata.size()/2)/sendeachbinsize+1;
    }
    firmwarebin=firmbindata;
   // qDebug()<<"固件包数"<<sizefirmware;   //10793
    int frameCnt=0;
   // qDebug()<<"进入升级过程";

    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    burnStartTime = timeCur.toTime_t(); qDebug() << "burnStartTime:" << burnStartTime << endl;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("打开串口，开始烧录");
    close_serial();  open_serial(110); // 切换波特率到110


    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug()<<"timeCur"<<timeCur;
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送串口中断" ;
    uart_break();
    Sleep(500);

    close_serial(); open_serial(115200); // 切换波特率到115200bps


   // timeCur = QDateTime::currentDateTime();//获取系统现在的时间
   // qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "获取雷达状态" ;
    get_status_command();

    Sleep(2);
    uint16_t returncount = 0;
    while(first_status_response_flag != 1)
    {
        Sleep(2);
        returncount++;
        //get_status_command();
        if(returncount == 2500)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    first_status_response_flag = 0;


    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送PING命令" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送PING命令");
    ping_command();
    Sleep(2);
    returncount = 0;
    while(ack_response_flag != 1)
    {
        Sleep(2);
        //ping_command();
        returncount++;
        if(returncount == 2500)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    ack_response_flag = 0;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送PING命令成功" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送PING命令成功");


    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "读取版本信息" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("读取版本信息");
    get_version_command();
    Sleep(2);
    returncount = 0;
    while(ack_response_flag != 1)
    {
        Sleep(2);
        //get_version_command();
        returncount++;
        if(returncount == 2500)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    ack_response_flag = 0;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "读取版本信息成功" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("读取版本信息成功");


    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "擦除Flash" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("擦除Flash");
    erase_command();
    Sleep(100);
    returncount = 0;
    while(ack_response_flag != 1)
    {
        Sleep(100);
        returncount++;
        //erase_command();
        if(returncount == 400)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    ack_response_flag = 0;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "擦除Flash成功" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("擦除Flash成功");


    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送打开文件命令" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送打开文件命令");
    open_command(fileTotalSize);
    Sleep(100);
    returncount = 0;
    while(ack_response_flag != 1)
    {
        Sleep(100);
        //open_command(fileTotalSize);
        returncount++;
        if(returncount == 100)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    ack_response_flag = 0;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送打开文件命令成功" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送打开文件命令成功");



    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送固件内容..." ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送固件内容[" + tr("%1").arg(fileTotalSize) + "]...");
    while(frameCnt < sizefirmware)
    {
        get_status_command();
        //Sleep(1);
        uint16_t returncount = 0;
        while(status_response_flag != 1)
        {
            Sleep(1);
            //get_status_command();
            returncount++;
            if(returncount == 5000)
            {
                timeCur = QDateTime::currentDateTime();//获取系统现在的时间
               // qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
                emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
                emit sendStatusSignal("FAIL");
                close_serial();
                return;
            }
        }
        status_response_flag = 0;

        write_to_flash_command(frameCnt);
        //Sleep(1);
        returncount = 0;
        while(ack_response_flag != 1)
        {
            Sleep(1);
            //write_to_flash_command(frameCnt);
            returncount++;
            if(returncount == 5000)
            {
                timeCur = QDateTime::currentDateTime();//获取系统现在的时间
               // qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
                emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
                emit sendStatusSignal("FAIL");
                close_serial();
                return;
            }
        }
        ack_response_flag = 0;
        if((frameCnt % 10) == 0)
        {
            emit sendprogressdlgupdatesignals(frameCnt);
        }
        frameCnt++;
    }
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送固件内容完成" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送固件内容完成");

   // timeCur = QDateTime::currentDateTime();//获取系统现在的时间
   // qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "获取雷达状态" ;
    get_status_command();
    Sleep(10);
    returncount = 0;
    while(status_response_flag != 1)
    {
        Sleep(10);
        returncount++;
        //qDebug() << "第八步：获取雷达状态,重发次数:" << returncount;
        //get_status_command();
        if(returncount == 500)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    status_response_flag = 0;



    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送关闭命令" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送关闭命令");
    close_command();
    Sleep(10);
    returncount = 0;
    while(ack_response_flag != 1)
    {
        Sleep(10);
        returncount++;
       // qDebug() << "第九步：发送关闭命令,重发次数:" << returncount;
        //close_command();
        if(returncount == 500)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    ack_response_flag = 0;
    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "发送关闭命令成功" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("发送关闭命令成功");


   // timeCur = QDateTime::currentDateTime();//获取系统现在的时间
   // qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "获取雷达状态" ;
    get_status_command();
    Sleep(10);
    returncount = 0;
    while(status_response_flag != 1)
    {
        Sleep(10);
        returncount++;
        //get_status_command();
        if(returncount == 500)
        {
            timeCur = QDateTime::currentDateTime();//获取系统现在的时间
            qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "串口通信超时" ;
            emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("串口通信超时");
            emit sendStatusSignal("FAIL");
            close_serial();
            return;
        }
    }
    status_response_flag = 0;
    emit sendprogressdlgupdatesignals(sizefirmware);

    timeCur = QDateTime::currentDateTime();//获取系统现在的时间
    burnEndTime = timeCur.toTime_t(); qDebug() << "burnEndTime:" << burnEndTime << endl;
    burnTotalTime = burnEndTime - burnStartTime;
    qDebug() << timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz").toUtf8().data() << "烧录成功，请断电重启。" ;
    emit sendvar(timeCur.toString("yyyy-MM-dd hh:mm:ss.zzz  ")); emit sendvar("烧录成功，请断电重启。[总耗时：" + QString::number(burnTotalTime) + "s]");
    emit sendStatusSignal("PASS");
    close_serial();

    return;
}


void Serialworkerthread::uart_break(void)
{
    QString UART_BREAK = "00";
    QByteArray  UART_BREAK_cmd = QString2Hex(UART_BREAK);
    sendserialcmd(UART_BREAK_cmd);
}

void Serialworkerthread::get_status_command(void)
{
    QByteArray data;

    QString sync = "aa";
    QString length = "0003";
    QString sum = "23";
    QString command = "23";

    data.append(sync);
    data.append(length);
    data.append(sum);
    data.append(command);
    data = QString2Hex(data);
    sendserialcmd(data);
}

void Serialworkerthread::ping_command(void)
{
    QByteArray data;

    QString sync = "aa";
    QString length = "0003";
    QString sum = "20";
    QString command = "20";

    data.append(sync);
    data.append(length);
    data.append(sum);
    data.append(command);
    data = QString2Hex(data);
    sendserialcmd(data);
}

void Serialworkerthread::get_version_command(void)
{
    QByteArray data;

    QString sync = "aa";
    QString length = "0003";
    QString sum = "2f";
    QString command = "2f";

    data.append(sync);
    data.append(length);
    data.append(sum);
    data.append(command);
    data = QString2Hex(data);
    sendserialcmd(data);
}

void Serialworkerthread::erase_command(void)
{
    QByteArray data;

    QString sync = "aa";
    QString length = "0003";
    QString sum = "28";
    QString command = "28";

    data.append(sync);
    data.append(length);
    data.append(sum);
    data.append(command);
    data = QString2Hex(data);
    sendserialcmd(data);
}


void Serialworkerthread::open_command(int binSize)
{
    uint8_t sum;
    QByteArray payload, payloadHex;
    QByteArray data;

    QString sync = "aa";
    QString length = "0013";
    QString command = "21";
    QString fileSize = QString("%1").arg(binSize, 4*2, 16, QChar('0')); //将10进制转为16进制字符串；
    // qDebug()<< "fileSize:" << fileSize;
    QString fileType = "00000002";
    QString reserved = "0000000600000000";

    payload.append(command);
    payload.append(fileSize);
    payload.append(fileType);
    payload.append(reserved);
    payloadHex = QString2Hex(payload);
    //qDebug()<< "payloadHex:" << payload;
    sum = checkSum(payloadHex, payloadHex.size());
    QString sumHex = QString("%1").arg(sum, 1*2, 16, QChar('0')); //将10进制转为16进制字符串；

    data.append(sync);
    data.append(length);
    data.append(sumHex);
    data.append(payload);
    data = QString2Hex(data);
    sendserialcmd(data);
}


void Serialworkerthread::write_to_flash_command(int frameCnt)
{
    uint8_t sum;
    int len;
    QByteArray payload, payloadAndCommand, payloadHex;
    QByteArray data;
    QByteArray valid_data;
    QString length;

    QString sync = "aa";
    QString command = "24";

    if((frameCnt+1)*sendeachbinsize*2 <= firmwarebin.size())
    {
        length = "00f3";
        payload = firmwarebin.mid(frameCnt*sendeachbinsize*2, sendeachbinsize*2);
       // qDebug()<<"包次："<< frameCnt+1;
    }
    /* 最后一个数据包判断 */
    else
    {
        len = firmwarebin.size()/2 - frameCnt*sendeachbinsize + 3;
        length = QString("%1").arg(len, 2*2, 16, QChar('0')); //将10进制转为16进制字符串；
        payload = firmwarebin.mid((frameCnt*sendeachbinsize)*2, firmwarebin.size()-frameCnt*sendeachbinsize*2);
       // qDebug()<<"包次："<< frameCnt+1;

    }
    payloadAndCommand.append(command);
    payloadAndCommand.append(payload);

    payloadHex = QString2Hex(payloadAndCommand);
    // qDebug()<< "payloadHex.size():" << payloadHex.size();
    sum = checkSum(payloadHex, payloadHex.size());
    // qDebug()<< "sum:" << sum;
    QString sumHex = QString("%1").arg(sum, 1*2, 16, QChar('0')); //将10进制转为16进制字符串；
    // qDebug()<< "sumHex:" << sumHex;

    data.append(sync);
    data.append(length);
    data.append(sumHex);
    data.append(command);
    data.append(payload);
    data = QString2Hex(data);
    sendserialcmd(data);
}

void Serialworkerthread::close_command(void)
{
    QByteArray data;

    QString sync = "aa";
    QString length = "0007";
    QString sum = "28";
    QString command = "22";
    QString fileType = "00000006";

    data.append(sync);
    data.append(length);
    data.append(sum);
    data.append(command);
    data.append(fileType);
    data = QString2Hex(data);
    sendserialcmd(data);
}



/*......................................................................................*/
/* 读版本号 */
void Serialworkerthread::readvar(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="0200";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
}

void Serialworkerthread::sensorstop(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="0300";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}
/** 重启雷达 **/

void Serialworkerthread::softreset(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="0500";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}
void Serialworkerthread::softresetF9(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="F900";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}

/** 进入升级 0009**/
void Serialworkerthread::updatemode(int baudrate)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="0800";
    QString length="0100";
    QString usedata="01";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    /*  判断升级波特率 */
    if(baudrate==115200)
        usedata="01";
    else if(baudrate==57600)
        usedata="02";
    else if(baudrate==38400)
        usedata="03";
    else if(baudrate==19200)
        usedata="04";
    else if(baudrate==256000)
        usedata="05";
    else if(baudrate==512000)
        usedata="06";
    else if(baudrate==921600)
        usedata="07";
    else
        usedata="01";
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
    data.append(usedata);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}

/** 测试指令00F0 **/
void Serialworkerthread::updatetest(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="F000";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}

/** 擦除指令00F1 **/
void Serialworkerthread::updateerasuse(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="F100";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}
/** 发送固件大小00F2 **/
void Serialworkerthread::sendbinsize(int numberpack)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="F200";
    QString length="0400";
//    int binsize=binlength;
    qDebug()<< "numberpack:"<<numberpack;   //690692
//    qDebug()<< "numbin:"<<binlength/64+1;  //5397
    QString binsize1 =QString("%1").arg(numberpack, 4*2, 16, QChar('0')); //将大小转为16进制字符串；
//    qDebug()<< "binsize:"<<binsize1;
    QString binsize=binsize1.mid(6,2)+binsize1.mid(4,2)+binsize1.mid(2,2)+binsize1.mid(0,2);
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
    data.append(binsize);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
//    hexcmd(data);
}



void Serialworkerthread::senddatabinSlot(int framecount)   //10972
{
    uint8_t crc;
     QString length;
     QByteArray valid_data;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="F300";
    QString framecountstring =QString("%1").arg(framecount, 4*2, 16, QChar('0')); //将大小转为16进制字符串；
    framecount_string=framecountstring.mid(6,2)+framecountstring.mid(4,2)+framecountstring.mid(2,2)+framecountstring.mid(0,2);
//    qDebug()<<"包次："<< framecount<<"固件大小："<<firmwarebin.size()<<"每包大小："<<sendeachbinsize;
    if((framecount+1)*sendeachbinsize*2<=firmwarebin.size())
    {
        valid_data=firmwarebin.mid((framecount*sendeachbinsize)*2,sendeachbinsize*2);
//        qDebug()<<"包次："<< framecount<<"内容："<<valid_data;
        int lengtheachbin=sendeachbinsize+4;
        QString binsize1 =QString("%1").arg(lengtheachbin, 2*2, 16, QChar('0')); //将大小转为16进制字符串；
         length=binsize1.mid(2,2)+binsize1.mid(0,2);
    }
    /* 最后一个数据包判断 */
    else
    {
        valid_data=firmwarebin.mid((framecount*sendeachbinsize)*2,firmwarebin.size()-framecount*sendeachbinsize*2);
        QByteArray test;
        for(int i=0;i<sendeachbinsize-(firmwarebin.size()/2-framecount*sendeachbinsize);i++)
        {
            test.append("00");
        }
        int lengtheachbin=sendeachbinsize+4;
        valid_data.append(test);
        QString binsize1 =QString("%1").arg(lengtheachbin, 2*2, 16, QChar('0')); //将大小转为16进制字符串；
         length=binsize1.mid(2,2)+binsize1.mid(0,2);
    }

    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
    data.append(framecount_string);
    data.append(valid_data);
    data = QString2Hex(data);
    crc=crc8(data,data.size());
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);

//    hexcmd(data);
}


/** 更新固件00F8 **/
void Serialworkerthread::updatebin(void)
{
    uint8_t crc;
    QString head="5555";
    QString orientation="00";
    QString error="00";
    QString fc="F800";
    QString length="0000";
    QString tail0="AA";
    QString tail1="AA";
    QByteArray data;
    data.append(head);
    data.append(orientation);
    data.append(error);
    data.append(fc);
    data.append(length);
//    qDebug()<< data;
    data = QString2Hex(data);
    crc=crc8(data,data.size());
//    qDebug()<< crc;
//    qDebug()<<QString::number(crc,16);
    data.append(crc);
    data.append(tail0.toInt(0,16));
    data.append(tail1.toInt(0,16));
    sendserialcmd(data);
}

/** 读取雷达参数 **/
//void Serialworkerthread::readcli(void)
//{
//    sendserialcmd("ReadCLI all\n");
//    Sleep(100);
//    cliread=1;
//}
void Serialworkerthread::readclislot()
{
    dataBuffer.clear();
     cliread=1;
    sendserialcmd("ReadCLI all\n");
    Sleep(300);

}

//void Serialworkerthread::changebaudrateslot(int baudrate)
//{
////    dataBuffer.clear();
//////     cliread=1;
////    sendserialcmd("ReadCLI all\n");
////    Sleep(300);

//}

float  Serialworkerthread::parseValueFloat(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos,valueSize);
    QString strParseData = parseData;
    quint32 temp_int = strParseData.toUInt(&ok,16);
    temp_int =  qToBigEndian(temp_int);        // Convert to Big-Endian
    float parseValueOut;
    parseValueOut = *reinterpret_cast<float*>(&temp_int); // cast to Float
    return parseValueOut;
}

quint32  Serialworkerthread::parseValueUint32(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos, valueSize);
    QString strParseData = parseData;
    quint32 tempInt32 = strParseData.toUInt(&ok,16);
    quint32 parseValueOut =  qToBigEndian(tempInt32);        // Convert to Big-Endian
    return parseValueOut;
}

quint16 Serialworkerthread::parseValueUint16(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos, valueSize);
    QString strParseData = parseData;
    quint16 parseValueOut = strParseData.toInt(&ok,16);
    parseValueOut =  qToBigEndian(parseValueOut);        // Convert to Big-Endian
    return parseValueOut;
}

qint16  Serialworkerthread::parseValueInt16(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos, valueSize);
    QString strParseData = parseData;
    qint16 parseValueOut = strParseData.toInt(&ok,16);
    parseValueOut =  qToBigEndian(parseValueOut);        // Convert to Big-Endian
    return parseValueOut;
}

//字符串转16进制
QByteArray Serialworkerthread::QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();

    senddata.resize(len/2);
    char lstr,hstr;

    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}
//字符转16进制
char Serialworkerthread::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

/* 校验  */
uint8_t Serialworkerthread::crc8(const QByteArray &data, int32_t len)
{
    uint8_t buf ;
    uint8_t crc = 0;
    for(auto i = 0;i<len-2;i++)
//    for(auto i = 0;i<len-2;i++)
    {
        buf = data.at(i+2) ^crc;
        crc = crc8_table[buf];
//        qDebug()<<crc8;
    }
    return crc;

}

/* 校验  */
uint8_t Serialworkerthread::checkSum(const QByteArray &data, int32_t len)
{
    uint8_t sum = 0;
    //qDebug()<< "data:" << data;
    for(auto i = 0;i<len;i++)
    {
        sum = sum + data.at(i);
        //qDebug()<<"sum:"<<sum;
    }
    return sum;

}



