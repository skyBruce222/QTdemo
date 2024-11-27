#ifndef RADARSETMAINWINDOW_H
#define RADARSETMAINWINDOW_H

#include <QMainWindow>
#include "coordinateaxiswight.h"
#include "radarparasmainwindow.h"
#include "radarareamainwindow.h"
#include "radartoolsyssetmainwindow.h"
#include "savedatamainwindow.h"
#include "textsetmainwindow.h"
#include "targettypemainwindow.h"
#include "filtertargetmainwindow.h"
#include "collisionareamainwindow.h"
#include "cameraeventfilter.h"
#include "canthread.h"

#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QCameraInfo>
#include <QVideoWidget>
#include <QLabel>
#include <QFile>
#include <QDateTime>

namespace Ui {
class radarSetMainWindow;
}

class radarSetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit radarSetMainWindow(QWidget *parent = nullptr);
    ~radarSetMainWindow();

public slots:
    void switchLanguageSlot(QString lang);

    void setAreaSlot(unsigned char * data, uint8_t len);

    void readAreaSlot();

    void setParasSlot(unsigned char * data, uint8_t len);

    void readParasSlot();

private slots:

    void on_setAPPDispalyPushButton_clicked();

    void openRadarSetWindow();

    void openRadarAreaSetWindow();

    void openRadarToolSysSetWindow();

    void openSysSaveDataWindow();

    void openTextSetWindow();

    void openTargetTypeWindow();

    void openFilterTargetWindow();

    void openCollisionAreaWindow();

    void updateTime();

    void closeSetWindow();

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void onComboBoxPopupShown();

    void onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel);

    void on_pushButton_2_clicked();

    void textTypeSlot(bool,bool,bool,bool,bool,bool);

    void saveDataSlot(QString,QString);

    void writeDataSlot(unsigned int,unsigned int *, unsigned int *,float *, float *, float *, float *, float *, float *);

private:
    Ui::radarSetMainWindow *ui;
    radarParasMainWindow radarParasWin;
    radarAreaMainWindow radarAreaWin;
    radarToolSysSetMainWindow toolSetWin;
    saveDataMainWindow saveDataWin;
    textSetMainWindow textSetWin;
    targetTypeMainWindow targetTypeWin;
    filterTargetMainWindow filterTargetWin;
    collisionAreaMainWindow collisionAreaWin;
    cameraEventfilter *eventFilter;

    QCamera *curCamera=Q_NULLPTR;//
    QList<QCameraInfo> cameras;//可用相机列表

    QCameraImageCapture *imageCapture; //抓图
    QMediaRecorder* mediaRecorder = Q_NULLPTR;//录像
    QDateTime currentTime;
    CANThread *canthread;
    int xScale = 0,yScale = 0,angle = 0;
    bool connectStates = false;
    bool languageSwitch = false;
    float x[96],y[96],vel[96],RCS_A[96],Range[96],targetAngle[96];
    unsigned int  ID[96],targetSate[96];
    unsigned int targetNum = 0;
    bool switchTargetInfo = false;
    bool AngleFlag = true,RangeFlag=true,VelocityFlag=true,RCSFlag=true,SateFlag=true,ClassFlag = true;//写入数据类型标志
    QString filePath;

    bool sendSetAreaOrder = false;

    bool sendReadAreaOrder = false;

    bool sendSetParasOrder = false;

    bool sendReadParasOrder = false;

    short int maxNumTarget, radarID, p1_long, p1_lat, p2_long, p2_lat;

    unsigned char radarID_paraswin, radarOutMode, radarBaud;

    void initMainWindow();

    void actionEventHandle();

    void initCamera();

    void CANEventHandle();

    void setLED(QLabel* label, int color, int size);

    void switchLanguage(const QString &lang);

    void changeControlStates(bool states);

signals:
    void closeSetWindowSig();
    void setSwitchLanguageSig(QString lang);
    void setSwitchLanguageSigForChild(QString lang);
    void writeDataSig(unsigned int,unsigned int *, unsigned int *,float *, float *, float *, float *, float *, float *);
    void connectSucceedSig(bool);
    void radarAreaReturnSig(short int, short int, short int, short int, short int, short int);
    void radarParasReturnSig(unsigned char, unsigned char, unsigned char);
};

#endif // RADARSETMAINWINDOW_H
