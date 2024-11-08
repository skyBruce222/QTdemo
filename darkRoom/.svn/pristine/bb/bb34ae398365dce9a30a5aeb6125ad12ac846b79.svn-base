#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QVector>
#include <QMap>
#include <QMutex>
#include "Spcomm.h"
#include "RotaryControlThread.h"
#include "RadarControlThread.h"
#include "controldlg.h"
#include "MyTitlebar.h"
#include <memory>

namespace Ui {
class MainWindow;
}

namespace QtCharts
{
    class QChart;
    class QLineSeries;
    class QValueAxis;
    class QScatterSeries;
}

class QFile;
class QTextStream;
class QSerialPort;
class QTimer;

struct RadarAvgData
{
    double      dbAngle;
    int         iPeak;
    double      dbLogPeak;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_O_triggered();

    void on_pushButtonDetect_clicked();

    void waitUtil(double target, int maxMilliSeconds = 60000);
    void waitUtil(int maxMilliSeconds = 60000);
    void detectProcess(double angle);

    void on_actionAbout_A_triggered();

private:
    Ui::MainWindow *ui;

    SPComm m_commRotary;
    SPComm m_commRadar;

    bool m_justic;
    RotaryControlThread m_rotarythread;
//    RadarControlThread m_radarthread;

    int xAxismax;
    int yAxismin;
    int yAxismax;

    controldlg *dialog;

    QMutex radar_mutex;

    volatile double m_curRotaryAngle;
    bool m_savedata;
    double m_speed;

    double m_angle;
    double m_pitching;
    double m_oritation;

    bool        m_bIsReadyDetect_max;    //发送转台转动到俯仰峰值最大位置
    bool        m_bIsDetect_max;         //转台转到俯仰峰值最大位置
    bool        m_bIsReadyDetect_AZ;    //发送转台转动到方位起始位置,测量开始
    bool        m_bIsDetect_AZ;         //转台转到测量方位起始位置完成，开始测量
    bool        m_bAngleTo0_1;
    //AngleType   m_typeScanRotary;      //峰值扫描转台转轴类型
    double      m_maxPeakAngle;        //俯仰最大峰值所在位置
    QString     m_reportFileName;
    double      m_rangY_start;
    double      m_rangY_end;
    double      m_rangY_avg_start;
    double      m_rangY_avg_end;
    double      m_channel_num;
    double      maxPeak;
    double      minPeak;
    double      minAvgPeak;
    double      maxAvgPeak;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries8;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries9;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries10;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries11;


    bool        m_bIsReadyDetect;    //发送转台转动到俯仰起始位置,测量开始
    bool        m_bIsPressDetect;    //发送停止测量，转台位置归零
    double      m_dbStartAngle;      //测量起始角度
    bool        m_bIsDetect;         //转台转到测量俯仰起始位置完成，开始测量
    bool        m_bAngleTo0;         //测量完成，转台位置归零
    QString     m_strStartDetectTime;
    double      m_dbEndAngle;
    double      m_dbAngleOfX;
    QVector<int>    m_vecPeak;
    QVector<double> m_vecLogPeak;
    QVector<RadarAvgData> m_vecAvgData;

    int         m_iMaxPeak;
    QString     m_strMaxPeak;
    double      m_dbMaxLogPeak;
    QString     m_strMaxLogPeak;
    double      m_dbMaxPeakAngle;
    QString     m_strMaxPeakAngle;
    double      m_db6Range;
    QString     m_str6Range;
    double      m_db12Range;
    QString     m_str12Range;
    double      m_db6Statrt;
    QString     m_str6Statrt;
    double      m_db12Statrt;
    QString     m_str12Statrt;
    double      m_db6End;
    QString     m_str6End;
    double      m_db12End;
    QString     m_str12End;
    double      m_db6Center;
    QString     m_str6Center;
    double      m_db12Center;
    QString     m_str12Center;

    std::shared_ptr<QFile>                  m_pFileLog;
    std::shared_ptr<QTextStream>            m_pTsLog;

    std::shared_ptr<QSerialPort>            m_pSerialRadar;
    std::shared_ptr<QTimer>                 m_pTimerReadRadarData;
    QString                                 m_strLine;
    QString                                 m_strTailData;

    AngleType   m_typeRotary;

    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries0;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries1;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries2;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries3;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries4;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries5;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries6;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeries7;
    std::shared_ptr<QtCharts::QLineSeries>  m_pLineSeriesAvg;
    std::shared_ptr<QtCharts::QChart>       m_pChart;
    std::shared_ptr<QtCharts::QChart>       m_pChartAvg;
    std::shared_ptr<QtCharts::QValueAxis>   m_pAxisX;
    std::shared_ptr<QtCharts::QValueAxis>   m_pAxisY;
    std::shared_ptr<QtCharts::QValueAxis>   m_pAxisXAvg;
    std::shared_ptr<QtCharts::QValueAxis>   m_pAxisYAvg;
    std::shared_ptr<QtCharts::QScatterSeries>   m_pScatterSeriesAvgTip;

signals:
    void RadarSerialChanged(const QString &portname, int baudrate, int databits, int stopbits, int parity);
    void RotarySerialChanged(const QString &portname, int baudrate, int databits, int stopbits, int parity);
    void typechanged(const QString& type);
    void getRotaryType(AngleType &type);
    void action_adjust();
    void action_output(bool output);
    void set_measures(QList<double> measures);
    void action_lead(float spd, float target);
    void action_write(bool write);
    void rename_file();

public slots:
    void checkopenslot(bool justic, const QString &port);

    void RotarySerialDataRechSlot(double val1, double val2, double val3);
    void wrongdetectoneslot();
    void wrongdetecttwoslot();
    void RadarSerialDataRechSlot2(int t_iAnt, int t_iRangeIdx, int t_iPeak);

    void radar_reselect_slot();
    void rotary_reselect_slot();

    void radar_adjust_fail_slot(const QString &msg);
    void radar_adjust_success_slot();

    void save_sate_changed_slot(bool save);

    void adjust_fail_slot(const QString &msg);
    void adjust_success_slot();
    void judge_qualified_slot(double val);
    void judge_disqualification(double val);
    void standard_distance_changed(double val);
	void speed_changed_slot(double val);

    void slotRotaryAddPort(const QString &t_qstrPort);
    void slotRadarsAddPort(const QString &t_qstrPort);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    void initTitleBar();
    void InitChart(void);

    void OpenRadarPort(void);// 打开雷达串口
    void ParseData(QString &t_strLine);
    void DealAvgMap(void);
    void on_BtnGenerateReport(void);  //zxy
    void saveHtmlToWord(QString &html);
    void saveHtmlToWord1(QString &html);
    void StartRotarythread(void);
    void StopRotarythread(void);

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

    void on_pushButton_refresh_clicked();

    void on_comboBoxRotary_currentIndexChanged(const QString &arg1);

    void on_comboType_currentIndexChanged(const QString &arg1);

    void on_lineedit_Speed_textChanged(const QString &arg1);

    void on_comboBoxRadars_currentIndexChanged(const QString &arg1);

    void ReceiveRadarInfo(void);

    void on_BtnGenerateReport_clicked();

protected:
    MyTitleBar* m_titleBar;
};

#endif // MAINWINDOW_H
