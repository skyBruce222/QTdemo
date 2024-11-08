#include "BaseControlThread.h"

BaseControlThread::BaseControlThread()
{
}

BaseControlThread::~BaseControlThread()
{

}

void BaseControlThread::run()
{
    comm.setPortName(portName);
    comm.setBaudRate(baudRate);
    emit checkopen(comm.open(), portName);
}

void BaseControlThread::stop()
{
    comm.close();
    requestInterruption();
}

void BaseControlThread::serialChangedslot(const QString &name, int rate, int databits, int stopbits, int Parity)
{
    bool haveRestart = false;
    if(portName != name)
    {
        portName = name;
        haveRestart = true;
    }
    if(baudRate != rate)
    {
        baudRate = rate;
        haveRestart = true;
    }
    if(dataBits != databits)
    {
        dataBits = databits;
        haveRestart = true;
    }
    if(stopBits != stopbits)
    {
        stopBits = stopbits;
        haveRestart = true;
    }
    if(parity != Parity)
    {
        parity = Parity;
        haveRestart = true;
    }

//    if(haveRestart)
//    {
//        this->stop();
//        this->terminate();
//        this->wait();
//        this->start();
//    }

}

void BaseControlThread::availableportdetectslot()
{
    emit availableportnames(comm.getAvailablePort());
}
