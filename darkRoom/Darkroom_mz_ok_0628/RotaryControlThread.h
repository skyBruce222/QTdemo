#ifndef DisplayControlThread_H
#define DisplayControlThread_H

#include "BaseControlThread.h"
#include "RemoteDoc.h"

const QString DownType = QObject::tr("下方位轴");
const QString PitchingType = QObject::tr("俯仰轴");
const QString RollType = QObject::tr("上方位横滚");

class RotaryControlThread : public BaseControlThread
{
	Q_OBJECT

protected:
	void run();

private:
	RotaryRemoteDoc doc;
	signed int readdatareturn;
    AngleType m_type = AT_Az;


public slots:
	void action_cw_slot(float spd, float target);
	void action_ccw_slot(float spd, float target);
	void action_stop_slot();
	void action_reset_slot();
	void action_lead_slot(float spd, float target);
	void action_calibration(float target);

	void typechangedslot(int type);
	void typechangedslot(const QString& type);

    void getRotaryTypeslot(AngleType &type);

signals:
	void SendBytes(QByteArray data);
	void SendString(QString PortMessageString);
	void SendInt(int PortMessageInt);
	void SendDouble(double data);
	void SerialDataReach(double val1, double val2, double val3);
};

#endif // DisplayControlThread_H

