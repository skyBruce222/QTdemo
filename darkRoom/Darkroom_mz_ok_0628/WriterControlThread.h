#ifndef WRITERCONTROLTHREAD_H
#define WRITERCONTROLTHREAD_H

#include <QThread>
#include <QMutex>
#include <QmutexLocker>
#include <QString>
#include "FileManager.h"

const double Precision  = 0.15;

const double PassLevel = 0.8;

class WriterControlThread : public QThread
{
    Q_OBJECT
public:
    WriterControlThread();
    ~WriterControlThread();

    void setSavePath(QString filePath);
    void setSaveFlag(bool toSave);

    void run();
    void stop();
private:
    void analyseDistance(double angle);
    double analyseMSE(double angle);
    void analyseRMSE(double angle);
    void storedata(double angle, double delta, double x, double y);

private:
    FileManager writer;
    double _x, _y, _val, _lastVal, _z;
    bool saveflag;
    QList<double> analyseList;
    QList<double> analyseListX;
    QList<double> analyseListY;
    QList<double> measures;
    QMutex mutex;
    QString _radarID;

public:
    QString path;

public slots:
    void data_reach_slot(double x, double y, double z);
    void data_reach_slot(double val);
    void set_measures_slot(QList<double> measurelist);
    void action_write_slot(bool write);

    void precision_changed_slot(double pricision);
    void radarid_changed_slot(const QString &id);

    void rename_file_slot();

signals:
    void judge_qualified(double val);
    void judge_disqualification(double val);

};

#endif // WRITERCONTROLTHREAD_H
