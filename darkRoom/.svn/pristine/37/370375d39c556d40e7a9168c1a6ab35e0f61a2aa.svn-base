#include "WriterControlThread.h"
#include <QTime>
#include <QtMath>
#include <QDebug>

double StandR = 6.0;
double ErrorDelta = 1e-1;

WriterControlThread::WriterControlThread()
{
    _x = 0; _y = 0; _val = 0;
    saveflag = false;
    _radarID = "";
}

WriterControlThread::~WriterControlThread()
{
}

void WriterControlThread::setSaveFlag(bool toSave)
{
    saveflag = toSave;
}

void WriterControlThread::setSavePath(QString filePath)
{
    path = filePath;
}

void WriterControlThread::data_reach_slot(double x, double y, double z)
{
    _x = x; _y = y; _z = z;
}

void WriterControlThread::data_reach_slot(double val)
{
    _val = val;
}

void WriterControlThread::run()
{
    forever
    {
        if(saveflag)
        {
            QMutexLocker locker(&mutex);
            QString data = QString::number(_z) + "," + QString::number(_x, 'g', 2) + "," + QString::number(_y, 'g', 2) + "," + QString::number(_val, 'g', 2) + ",";
            double standY = qCos(qDegreesToRadians(_val))*StandR;
            double measureDelta = qAbs(_y-standY);
            double standX = qSin(qDegreesToRadians(_val))*StandR;
            double measureDeltaX = qAbs(_x-standX);
            data += QString::number(standX, 'g', 2) + "," + QString::number(measureDeltaX, 'g', 2)  + "," + QString::number(standY, 'g', 2) + "," + QString::number(measureDelta, 'g', 2);
            storedata(_val, measureDelta, _x, _y);
            if((analyseListY.size() > 0) && (qAbs(_val -_lastVal) > Precision))
            {
                analyseMSE(_lastVal);
               //writer.append(",,,,,,,,MSE_Y:" + QString::number(analyseMSE(_lastVal), 'g', 2));
            }
            _lastVal = _val;
            writer.append(data);
        }
        msleep(100);
    }
}

void WriterControlThread::stop()
{
    saveflag = false;
    writer.close();
}

void WriterControlThread::storedata(double angle, double delta, double x, double y)
{
    double val;
    foreach(val, measures)
    {
        if(qAbs(val-angle) < Precision)
        {
            analyseList<<delta;
            analyseListX<<x;
            analyseListY<<y;
        }
    }
}

void WriterControlThread::analyseDistance(double val)
{
    if(analyseList.size() > 0)
    {
        int count = 0;
        double tmp = 0;
        foreach(tmp, analyseList)
        {
            if(tmp < ErrorDelta)
                count++;
        }
        double result = (double)count/analyseList.size();
        qDebug()<<"======================analyse======"<<val<<"==="<<result;
        if(result > PassLevel)
            emit judge_qualified(val);
        else
            emit judge_disqualification(val);
        analyseList.clear();
        analyseListX.clear();
        analyseListY.clear();
    }
}

double WriterControlThread::analyseMSE(double angle)
{
    if(analyseListY.size() > 0)
    {
        double standard = StandR*qCos(qDegreesToRadians(angle));
        double val = 0.0;
        double mse = 0.0;
        foreach(val, analyseListY)
        {
            mse += (val-standard)*(val-standard);
        }
        mse = mse/analyseListY.size();
        qDebug()<<"======================analyseMSE======"<<angle<<"==="<<mse;
        if(mse < ErrorDelta)
            emit judge_qualified(angle);
        else
            emit judge_disqualification(angle);
        analyseList.clear();
        analyseListX.clear();
        analyseListY.clear();
        return mse;
    }
}

void WriterControlThread::analyseRMSE(double angle)
{
    if(analyseListY.size() > 0)
    {
        double standard = StandR*qCos(qDegreesToRadians(angle));
        double val = 0.0;
        double rmse = 0.0;
        foreach(val, analyseListY)
        {
            rmse += (val-standard)*(val-standard);
        }
        rmse = qSqrt(rmse/analyseListY.size());
        qDebug()<<"======================analyseMSE======"<<angle<<"==="<<rmse;
        if(rmse < ErrorDelta)
            emit judge_qualified(angle);
        else
            emit judge_disqualification(angle);
        analyseList.clear();
        analyseListX.clear();
        analyseListY.clear();
    }
}

void WriterControlThread::action_write_slot(bool write)
{
    if(write)
        writer.setFileName(path, tr("wave_intensity, measure_x, measure_y, angle, theory_x,  measure_x_error, theory_y, measure_y_error"));
    saveflag = write;
}

void WriterControlThread::set_measures_slot(QList<double> measurelist)
{
    measures = measurelist;
    analyseList.clear();
    analyseListX.clear();
    analyseListY.clear();
    _lastVal = -45.0;
}

void WriterControlThread::precision_changed_slot(double pricision)
{
    ErrorDelta = pricision;
}

void WriterControlThread::radarid_changed_slot(const QString &id)
{
    _radarID = id;
    path = QTime::currentTime().toString(id + "  HH_mm_ss.CSV");
}

void WriterControlThread::rename_file_slot()
{
    path = QTime::currentTime().toString(_radarID + "  HH_mm_ss.CSV");
    writer.setFileName(path, tr("wave_intensity, measure_x, measure_y, angle, theory_x, measure_x_error, theory_y,  measure_y_error"));
}
