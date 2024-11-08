#include "Spcomm.h"
#include <QDebug>
#include <QTime>
#include <QCoreApplication>
#include <QByteArray>

void SPComm::setPortName(const QString &name)
{
    m_portName = name;
}

QString SPComm::portName() const
{
    return m_portName;
}

void SPComm::setBaudRate(int baudRate)
{
    m_BaudRate = baudRate;
}

void SPComm::setParity(int parity)
{
    m_parity = parity;
}

void SPComm::setDatabits(int bits)
{
    m_databits = bits;
}

void SPComm::setStopbits(int bits)
{
    m_stopbits = bits;
}

bool SPComm::isOpen() const
{
    if(m_serialPort->isOpen())
        return true;
    return false;
}

bool SPComm::open()
{
    m_serialPort->setPortName(m_portName);
    bool t_bRet = m_serialPort->open(QIODevice::ReadWrite);
    if (!t_bRet)
    {
        qDebug() << m_portName <<" 打开失败! ";
        return false;
    }

    m_serialPort->setBaudRate(m_BaudRate);
//    m_serialPort->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);//设置波特率和读写方向
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
//    m_serialPort->setReadBufferSize(MAX_SERIAL_READ_BUFFER_SIZE);

//    bool t_bRet = m_serialPort->open(QSerialPort::ReadWrite);
    qDebug() << "m_portName:" << m_portName << ", m_BaudRate:" << m_BaudRate << ", t_bRet" << t_bRet;

    return t_bRet;
}

void SPComm::close()
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }
}

bool SPComm::clear()
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        this->close();
        return this->open();
    }
    return false;
}

int SPComm::readData(char *buffer, int count, int timeout)
{
    int len = 0;
    forever
    {
        int n = m_serialPort->read(&buffer[len], count-len);
        if(n == -1)
            return -1;
        else if(n==0 && m_serialPort->waitForReadyRead(timeout))
        {
            return -2;
        }
        else
        {
            len += n;
            if(count == len)
                break;
        }
    }
    return len;
}

int SPComm::readAllBytes(QByteArray &result, int timeout)
{
    result = m_serialPort->readAll();
//    if(result.size() == 0)
//        if(m_serialPort->waitForReadyRead(timeout))
//            return -2;
    return result.size();
}

int SPComm::readAllLines(QByteArray &result, int timeout)
{
//    QMutexLocker locker(&m_readMutex);
//	result.clear();

//    if (m_serialPort->isReadable())
//    {
//        result.append(m_serialPort->readAll());
//        if (result.trimmed().size() > 1)
//        {
//            return result.size();
//        }
//        else
//        {
//            return 0;
//        }
//    }

    result = m_serialPort->readAll();
    if (result.trimmed().size() > 1)
    {
        return result.size();
    }
    else
    {
        return 0;
    }
}

QByteArray SPComm::readLine()
{
    return m_serialPort->readLine();
}

int SPComm::writeData(const char *data, int size)
{
    int i;
    //char dataBuf[16];
    //char sendBuf[128];
    //memset(sendBuf,0,128);

    qDebug() << "writeData:" << data << ", size:" << size;
    for(i=0;i<size;i++)
    {
        //sprintf(dataBuf,"%x",*(data+i));
        qDebug()<<"Hex:"<<QString("%1").arg(*(data+i),8,16,QLatin1Char('0')).toUpper();
    }

    int len = 0;
//    char end[] = {'\0'};
//    m_serialPort->write(end, 1);
    forever
    {
        int n = m_serialPort->write(data+len, size-len);
        if(n == -1)
            return -1;
        else
        {
            len += n;
            if(size == len)
                break;
        }
    }
    return len;
}

QString SPComm::writeDataForResponse(const char *data, int size, const QString &target, int waitfor)
{
    m_serialPort->write(data, size);
    QByteArray result;
    QString resultStr = "";
    int count = 0;
    QStringList allTarget = target.split('|');
    forever
    {
        readAllBytes(result, 100);
        resultStr += result;
        QString tmp;
        foreach(tmp, allTarget)
        {
            if(resultStr.contains(tmp))
                return QString("Done");
        }
        sleep(2);
        count++;
        if((waitfor > 0) && (count*10 > waitfor))
            break;
    }
    return resultStr;
}

SPComm::SPComm(QObject *parent):QObject (parent)
{
    m_serialPort = new QSerialPort();
    m_BaudRate = 38400;
    m_portName = "";
    m_databits = QSerialPort::Data8;
    m_parity   = QSerialPort::NoParity;
    m_stopbits = QSerialPort::OneStop;
}

SPComm::~SPComm()
{
    if (m_serialPort){
        delete m_serialPort;
        m_serialPort = nullptr;
    }
}

QList<QString> SPComm::getAvailablePort()
{
    QList<QString> result;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
//        qDebug() << "Name:" << info.portName()
//                 << "Description:" << info.description()
//                 << "Manufacturer:" <<info.manufacturer()
//                 << "Serial Number:" << info.serialNumber()
//                 << "System Location:" <<info.systemLocation();
        result.append(info.portName() + "  " + info.description());
    }
    return result;
}

void SPComm::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
