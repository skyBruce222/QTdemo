#ifndef SPCOMM_H
#define SPCOMM_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QMutexLocker>


const int MAX_SERIAL_READ_BUFFER_SIZE = 4096;
class SPComm: public QObject
{
    Q_OBJECT
public:
    explicit SPComm(QObject *parent = 0);
    ~SPComm();

    bool isOpen() const;

    void setPortName(const QString &name);
    QString portName() const;

    void setBaudRate(int baudRate);
    int baudRate() const;

    virtual bool open();
    virtual void close();
    virtual bool clear();

    int readData(char *buffer, int count, int timeout = 1000);
    int readAllBytes(QByteArray &result, int timeout);
    int readAllLines(QByteArray &result, int timeout);
    QByteArray readLine();
    int writeData(const char *data, int size);
    QString writeDataForResponse(const char *data, int size, const QString &target="", int waitforMs=-1);
    int write(char ch);

    void setParity(int parity);
    void setStopbits(int bits);
    void setDatabits(int bits);

    static QList<QString> getAvailablePort();
    void sleep(unsigned int msec);

protected:
    QString m_portName;
    int m_BaudRate;
    int m_parity;
    int m_stopbits;
    int m_databits;
    QSerialPort *m_serialPort;
    QMutex m_readMutex;

signals:

public slots:

};

#endif // SPCOMM_H
