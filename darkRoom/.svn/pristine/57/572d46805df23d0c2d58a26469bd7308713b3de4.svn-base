#include "RotaryControlThread.h"
#include "Communicate.h"

AngleType GetSelectedAxis(int type)
{
    AngleType angle;
    switch(type)
    {
//    case 0:
//        //12米前后位移
//        angle = AT_X;
//        break;
//    case 1:
//        //左右位移
//        angle = AT_Y;
//        break;
//    case 2:
//        //上下位移;
//        angle = AT_Z;
//        break;
    case 0:
        //下方位轴;
        angle = AT_Az;
        break;
    case 1:
        //俯仰轴;
        angle = AT_El;
        break;
    case 2:
        //上方位横滚;
        angle = AT_Pol;
        break;
    }
    return angle;
}

/*获取状态速度基数*/
float GetSelectedAxisSpeedUnit(int type)
{
    float unit = 0.0;
    switch(type)
    {
    case 0:
//        unit = 0.02;
//        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        unit = 10;
        break;
    }
    return unit;
}

/*轮询读取转台串口数据，获取转台位置*/
void RotaryControlThread::run()
{
    BaseControlThread::run();

    while(!isInterruptionRequested())  //判断有无结束线程请求
    {
        if(comm.isOpen())
        {
            QByteArray result;
            readdatareturn = comm.readAllBytes(result, 100);
            if(readdatareturn > 0)
            {
                Communicate::ReceiveData(&doc, result.data(), readdatareturn, GetSelectedAxis(m_type));  //根据转台串口数据解析转台角度
//                emit SendDouble(doc.GetAngle(m_type));
                emit SerialDataReach(doc.GetAngle(AT_Az),doc.GetAngle(AT_El), doc.GetAngle(AT_Pol));  //释放角度更新信号
            }
            comm.sleep(60);
        }else
        {
            break;
        }
        msleep(60);
    }
}

/*设置转台速度*/
void RotaryControlThread::action_cw_slot(float spd, float target)
{
    float speed = GetSelectedAxisSpeedUnit(m_type)*spd;
    doc.MakeCommand(m_type, EXE_Cw, speed+0.5, 0);
    comm.writeData((char*)doc.m_writeBuffer, G_WriteBufferLength);
}

/*设置转台速度*/
void RotaryControlThread::action_ccw_slot(float spd, float target)
{
    float speed = GetSelectedAxisSpeedUnit(m_type)*spd;
    doc.MakeCommand(m_type, EXE_Ccw, speed+0.5, 0);
    comm.writeData((char*)doc.m_writeBuffer, G_WriteBufferLength);
}

void RotaryControlThread::action_stop_slot()
{
    doc.MakeCommand(m_type, EXE_Stop, 0, 0);
    comm.writeData((char *)doc.m_writeBuffer, G_WriteBufferLength);
}

void RotaryControlThread::action_reset_slot()
{
    doc.MakeCommand(m_type, EXE_RESET, 0, 0);
    comm.writeData((char *)doc.m_writeBuffer, G_WriteBufferLength);
}

/*发送位置到转台控制转台转动*/
void RotaryControlThread::action_lead_slot(float spd, float target)
{
    float speed = GetSelectedAxisSpeedUnit(m_type)*spd;
    doc.MakeCommand(m_type, EXE_Lead, speed+0.5, target);
    comm.writeData((char*)doc.m_writeBuffer, G_WriteBufferLength);
}

/*转台校准*/
void RotaryControlThread::action_calibration(float target)
{
    doc.MakeCommand(m_type, EXE_Calibration, 0, target);
    comm.writeData((char *)doc.m_writeBuffer, G_WriteBufferLength);
}

void RotaryControlThread::typechangedslot(int type)
{
    m_type = GetSelectedAxis(type);
}

/*改变操作转台转轴类型函数*/
void RotaryControlThread::typechangedslot(const QString &type)
{
    qDebug() << "RotaryControlThread::typechangedslot:" << type;
    if(type == DownType)
    {
        m_type = AT_Az;
    }
    else if(type == PitchingType)
    {
        m_type = AT_El;
    }
    else if(type == RollType)
    {
        m_type = AT_Pol;
    }

    qDebug() << "RotaryControlThread::typechangedslot m_type:" << m_type;
}

void RotaryControlThread::getRotaryTypeslot(AngleType &type)
{
    type = m_type;
}
