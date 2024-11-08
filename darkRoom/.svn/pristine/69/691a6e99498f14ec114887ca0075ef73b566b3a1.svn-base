#ifndef RADARCONTROLTHREAD_H
#define RADARCONTROLTHREAD_H

#include "BaseControlThread.h"
//#include "RemoteDoc.h"

class RadarControlThread : public BaseControlThread
{
    Q_OBJECT

public:
    RadarControlThread(void);
    void run();

public slots:
    void action_adjust_slot();
    void action_restart_slot();
    void action_output_slot(bool out);
    void action_get_uid_slot();

signals:
    void SendString(QString msg);
    void SerialDataReach(double x, double y, double z);
    void adjust_fail(const QString &msg);
    void adjust_success();

    void send_uid(QString uid);

    void signalDataDeal(int t_iAnt, int t_iPeak);

private:
    void ParseData(QString &t_strLine);

    //    RadarRemoteDoc doc;
        signed int readdatareturn;

    volatile bool   m_bStartGetData;
    QString         m_strTailData;
    QString         m_strLine;
};

#endif // RADARCONTROLTHREAD_H
