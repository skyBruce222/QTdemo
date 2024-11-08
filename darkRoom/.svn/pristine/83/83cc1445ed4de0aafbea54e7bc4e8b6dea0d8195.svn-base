#ifndef BASECONTROLTHREAD_H
#define BASECONTROLTHREAD_H

#include <QThread>
#include <QString>
#include <QDebug>
#include "Spcomm.h"

class BaseControlThread : public QThread
{
    Q_OBJECT
public:
    BaseControlThread();
    virtual ~BaseControlThread();
    virtual void stop();

protected:
    virtual void run();

protected:
    QString portName;
    int baudRate;
    int dataBits;
    int stopBits;
    int parity;

    SPComm comm;

public slots:
    void serialChangedslot(const QString &portname, int rate, int databits, int stopbits, int parity);
    void availableportdetectslot();

signals:
    void checkopen(bool justic, const QString &port);
    void wrongdetectone();
    void wrongdetecttwo();
    void availableportnames(QList<QString> ports);

};

#endif // BASECONTROLTHREAD_H
