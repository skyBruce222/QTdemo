﻿#include "mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtMath>
#include <QThread>
#include <QtCharts/QValueAxis>
#include <QStringList>
#include <QtGlobal>
#include <QEventLoop>
#include <QTimer>
#include <QApplication>
#include <QPainter>
#include <QFile>
#include <QtMath>
#include <QElapsedTimer>
#include <QSharedPointer>
#include <QDateTime>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QDesktopServices>
#include <QBuffer>

extern double StandR;
extern double ErrorDelta;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(this->width(), this->height());
    ui->label_logo->installEventFilter(this);
//    statusBar()->hide();

    ui->BtnGenerateReport->hide();
    ui->comboType->hide();
    ui->lineedit_StartAngle->hide();
    ui->lineedit_EndAngle->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_8->hide();

    initTitleBar();
    dialog = new controldlg(this);

    connect(dialog, SIGNAL(RotarySerialChanged(QString,int,int,int,int)), &m_rotarythread, SLOT(serialChangedslot(QString,int,int,int,int)));
    connect(this, SIGNAL(RotarySerialChanged(QString,int,int,int,int)), &m_rotarythread, SLOT(serialChangedslot(QString,int,int,int,int)));
//    connect(dialog, &controldlg::RadarSerialChanged, &m_radarthread, &BaseControlThread::serialChangedslot);
//    connect(this, &MainWindow::RadarSerialChanged, &m_radarthread, &BaseControlThread::serialChangedslot);

    connect(&m_rotarythread, SIGNAL(checkopen(bool, QString)), this, SLOT(checkopenslot(bool, QString)));
//    connect(&m_radarthread, SIGNAL(checkopen(bool, QString)), this, SLOT(checkopenslot(bool, QString)));
    connect(&m_rotarythread, SIGNAL(wrongdetectone()), this, SLOT(wrongdetectoneslot()));
    connect(&m_rotarythread, SIGNAL(wrongdetecttwo()), this, SLOT(wrongdetecttwoslot()));
//    connect(&m_radarthread, SIGNAL(wrongdetectone()), this, SLOT(wrongdetectoneslot()));
//    connect(&m_radarthread, SIGNAL(wrongdetecttwo()), this, SLOT(wrongdetecttwoslot()));

    connect(dialog, SIGNAL(availableportdetect()), &m_rotarythread, SLOT(availableportdetectslot()));

    connect(&m_rotarythread, SIGNAL(SerialDataReach(double,double,double)), this, SLOT(RotarySerialDataRechSlot(double,double,double)));
//    connect(&m_rotarythread, SIGNAL(SerialDataReach(double,double,double)), dialog, SLOT(RotarySerialDataRechSlot(double,double,double)));

//    connect(&m_radarthread, &RadarControlThread::signalDataDeal, this, &MainWindow::RadarSerialDataRechSlot2);

    connect(dialog, SIGNAL(typechanged(QString)), &m_rotarythread, SLOT(typechangedslot(QString)));
    connect(this, SIGNAL(typechanged(QString)), &m_rotarythread, SLOT(typechangedslot(QString)));
    connect(this,SIGNAL(getRotaryType(AngleType &)),&m_rotarythread,SLOT(getRotaryTypeslot(AngleType &)));
    connect(dialog, SIGNAL(action_cw(float, float)), &m_rotarythread, SLOT(action_cw_slot(float,float)));
    connect(dialog, SIGNAL(action_ccw(float, float)), &m_rotarythread, SLOT(action_ccw_slot(float,float)));
    connect(dialog, SIGNAL(action_stop()), &m_rotarythread, SLOT(action_stop_slot()));
    connect(dialog, SIGNAL(action_reset()), &m_rotarythread, SLOT(action_reset_slot()));

    connect(dialog, SIGNAL(rotary_reselect()), this, SLOT(rotary_reselect_slot()));
    connect(dialog, SIGNAL(radar_reselect()), this, SLOT(radar_reselect_slot()));

//    connect(this, SIGNAL(action_adjust()), &m_radarthread, SLOT(action_adjust_slot()));
//    connect(this, SIGNAL(action_output(bool)), &m_radarthread, SLOT(action_output_slot(bool)));
    connect(this, SIGNAL(action_lead(float,float)), &m_rotarythread, SLOT(action_lead_slot(float, float)));

    connect(dialog, SIGNAL(save_state_changed(bool)), this, SLOT(save_sate_changed_slot(bool)));
//    connect(dialog, SIGNAL(action_output_changed(bool)), &m_radarthread, SLOT(action_output_slot(bool)));
    connect(dialog, SIGNAL(action_lead(float,float)), &m_rotarythread, SLOT(action_lead_slot(float,float)));

//    connect(&m_radarthread, SIGNAL(adjust_fail(QString)), this, SLOT(radar_adjust_fail_slot(QString)));
//    connect(&m_radarthread, SIGNAL(adjust_success()), this, SLOT(radar_adjust_success_slot()));

    connect(dialog, SIGNAL(distance_changed(double)), this, SLOT(standard_distance_changed(double)));
	connect(dialog, SIGNAL(speed_changed(double)), this, SLOT(speed_changed_slot(double)));

//    connect(dialog, SIGNAL(action_get_uid()), &m_radarthread, SLOT(action_get_uid_slot()));
//    connect(&m_radarthread, SIGNAL(send_uid(QString)), dialog, SLOT(send_uid_slot(QString)));

    connect(dialog, &controldlg::sinalRotaryAddPort,this, &MainWindow::slotRotaryAddPort);
    connect(dialog, &controldlg::sinalRadarsAddPort,this, &MainWindow::slotRadarsAddPort);

    //emit typechanged(DownType);   //释放信号改变转台转动类型,默认为水平转动
    emit typechanged(PitchingType);     //zxy

    m_speed = 1.0;
    m_angle = 0.0;
    m_oritation = 0.0;
    m_pitching = 0.0;
    m_savedata = false;

    /*峰值扫描初始化 zxy*/
    //m_typeScanRotary = AT_El;
    m_maxPeakAngle = 0.0;
    m_bIsReadyDetect_max = false;    //发送转台转动到俯仰峰值最大位置
    m_bIsDetect_max = false;         //转台转到俯仰峰值最大位置
    m_bIsReadyDetect_AZ = false;    //发送转台转动到方位起始位置,测量开始
    m_bIsDetect_AZ = false;         //转台转到测量方位起始位置完成，开始测量
    m_bAngleTo0_1 = false;

    m_bIsPressDetect = false;
    m_bIsReadyDetect = false;
    m_dbStartAngle = 0.0;
    m_bIsDetect = false;
    m_bAngleTo0 = false;
    m_strStartDetectTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    m_dbEndAngle = 0.0;

    m_iMaxPeak = 0;
    m_strMaxPeak.setNum(m_iMaxPeak);
    m_dbMaxLogPeak = 0.0;
    m_strMaxLogPeak.setNum(m_dbMaxLogPeak);
    m_dbMaxPeakAngle = 0.0;
    m_strMaxPeakAngle.setNum(m_dbMaxPeakAngle);

    m_db6Range = 0.0;
    m_str6Range.setNum(m_db6Range);
    m_db12Range = 0.0;
    m_str12Range.setNum(m_db12Range);

    m_db6Statrt = 0.0;
    m_str6Statrt.setNum(m_db6Statrt);
    m_db12Statrt = 0.0;
    m_str12Statrt.setNum(m_db12Statrt);

    m_db6End = 0.0;
    m_str6End.setNum(m_db6End);
    m_db12End = 0.0;
    m_str12End.setNum(m_db12End);

    m_db6Center = 0.0;
    m_str6Center.setNum(m_db6Center);
    m_db12Center = 0.0;
    m_str12Center.setNum(m_db12Center);

    m_pFileLog = std::make_shared<QFile>();
    m_pTsLog = std::make_shared<QTextStream>();

    m_pSerialRadar = std::make_shared<QSerialPort>();

    // 如果串口已经打开了, 关闭
    if(m_pSerialRadar->isOpen())
    {
        m_pSerialRadar->clear();
        m_pSerialRadar->close();
    }

    m_pTimerReadRadarData = std::make_shared<QTimer>();
    connect(m_pTimerReadRadarData.get(), &QTimer::timeout, this, &MainWindow::ReceiveRadarInfo);  //定时接收雷达数据 100ms

   // m_typeRotary = AT_Az;    //zxy
    m_typeRotary = AT_El;

    m_channel_num = 3;

    ui->comboBox_azimuth->addItem("±60°");
    ui->comboBox_azimuth->addItem("±90°");


    InitChart();

    on_pushButton_refresh_clicked();
}

void MainWindow::InitChart(void)
{
    ui->tabWidget->setTabText(0, QStringLiteral("8通道曲线图"));
    ui->tabWidget->setTabText(1, QStringLiteral("平均后曲线图"));
    ui->tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{ border: 1px solid white;}QTabBar::tab{ background-color: rgb(85, 85, 85);border-bottom-color: #C2C7CB; border-top-left-radius: 4px;     border-top-right-radius: 4px;     min-width: 60px;     padding: 2px; }QTabBar::tab:selected{    background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #626262,stop:1 #545454);}QTabBar::tab:!selected{    margin-top:5px;}"));

    QPen t_penLine;
    t_penLine.setWidth(1);

    m_pLineSeries0 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::red);
    m_pLineSeries0->setPen(t_penLine);
    m_pLineSeries0->setName("Ant0");

    m_pLineSeries1 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::green);
    m_pLineSeries1->setPen(t_penLine);
    m_pLineSeries1->setName("Ant1");

    m_pLineSeries2 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::blue);
    m_pLineSeries2->setPen(t_penLine);
    m_pLineSeries2->setName("Ant2");

    m_pLineSeries3 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::yellow);
    m_pLineSeries3->setPen(t_penLine);
    m_pLineSeries3->setName("Ant3");

    m_pLineSeries4 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::darkRed);
    m_pLineSeries4->setPen(t_penLine);
    m_pLineSeries4->setName("Ant4");

    m_pLineSeries5 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::darkGreen);
    m_pLineSeries5->setPen(t_penLine);
    m_pLineSeries5->setName("Ant5");

    m_pLineSeries6 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::darkBlue);
    m_pLineSeries6->setPen(t_penLine);
    m_pLineSeries6->setName("Ant6");

    m_pLineSeries7 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::darkYellow);
    m_pLineSeries7->setPen(t_penLine);
    m_pLineSeries7->setName("Ant7");

    m_pLineSeries8 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::magenta);
    m_pLineSeries8->setPen(t_penLine);
    m_pLineSeries8->setName("Ant8");

    m_pLineSeries9 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::darkMagenta);
    m_pLineSeries9->setPen(t_penLine);
    m_pLineSeries9->setName("Ant9");

    m_pLineSeries10 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::cyan);
    m_pLineSeries10->setPen(t_penLine);
    m_pLineSeries10->setName("Ant10");

    m_pLineSeries11 = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::darkCyan);
    m_pLineSeries11->setPen(t_penLine);
    m_pLineSeries11->setName("Ant11");

    m_pAxisX = std::make_shared<QtCharts::QValueAxis>();
    m_pAxisY = std::make_shared<QtCharts::QValueAxis>();

    maxPeak = -10000;
    minPeak = 10000;
    minAvgPeak = 10000;
    maxAvgPeak = -10000;

    m_rangY_start = 40;
    m_rangY_end = 90;
    m_pAxisY->setRange(m_rangY_start, m_rangY_end);
    m_pAxisX->setRange(-180.0, -60.0);
    m_pAxisX->setLabelsColor(Qt::white);
    m_pAxisY->setLabelsColor(Qt::white);
    m_pAxisY->setTitleText(QStringLiteral("单位db"));
    m_pAxisY->setTitleBrush(Qt::white);
    m_pAxisX->setTickCount(13);
    m_pAxisX->setMinorTickCount(9);
    m_pAxisY->setTickCount(6);
    m_pAxisY->setMinorTickCount(9);

    m_pChart = std::make_shared<QtCharts::QChart>();
    m_pChart->legend()->setAlignment(Qt::AlignRight);
    m_pChart->addSeries(m_pLineSeries0.get());
    m_pChart->addSeries(m_pLineSeries1.get());
    m_pChart->addSeries(m_pLineSeries2.get());
    m_pChart->addSeries(m_pLineSeries3.get());
    m_pChart->addSeries(m_pLineSeries4.get());
    m_pChart->addSeries(m_pLineSeries5.get());
    m_pChart->addSeries(m_pLineSeries6.get());
    m_pChart->addSeries(m_pLineSeries7.get());

    m_pChart->setBackgroundVisible(false);
    m_pChart->legend()->setLabelColor(Qt::white);

//    m_pChart->addSeries(m_pLineSeries8.get());

    m_pChart->addAxis(m_pAxisX.get(), Qt::AlignBottom);
    m_pChart->addAxis(m_pAxisY.get(), Qt::AlignLeft);
    m_pLineSeries0->attachAxis(m_pAxisX.get());
    m_pLineSeries0->attachAxis(m_pAxisY.get());
    m_pLineSeries1->attachAxis(m_pAxisX.get());
    m_pLineSeries1->attachAxis(m_pAxisY.get());
    m_pLineSeries2->attachAxis(m_pAxisX.get());
    m_pLineSeries2->attachAxis(m_pAxisY.get());
    m_pLineSeries3->attachAxis(m_pAxisX.get());
    m_pLineSeries3->attachAxis(m_pAxisY.get());
    m_pLineSeries4->attachAxis(m_pAxisX.get());
    m_pLineSeries4->attachAxis(m_pAxisY.get());
    m_pLineSeries5->attachAxis(m_pAxisX.get());
    m_pLineSeries5->attachAxis(m_pAxisY.get());
    m_pLineSeries6->attachAxis(m_pAxisX.get());
    m_pLineSeries6->attachAxis(m_pAxisY.get());
    m_pLineSeries7->attachAxis(m_pAxisX.get());
    m_pLineSeries7->attachAxis(m_pAxisY.get());

    ui->tab->setChart(m_pChart.get());
    ui->tab->setRenderHint(QPainter::Antialiasing);

    m_pLineSeriesAvg = std::make_shared<QtCharts::QLineSeries>();
    t_penLine.setColor(Qt::red);
    m_pLineSeriesAvg->setPen(t_penLine);
    m_pLineSeriesAvg->setName("Avg");

    m_pAxisXAvg = std::make_shared<QtCharts::QValueAxis>();
    m_pAxisYAvg = std::make_shared<QtCharts::QValueAxis>();

    m_rangY_avg_start = 40;
    m_rangY_avg_end = 90;
    m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
    m_pAxisXAvg->setRange(-180.0, -60.0);
    m_pAxisXAvg->setLabelsColor(Qt::white);
    m_pAxisYAvg->setLabelsColor(Qt::white);
    m_pAxisYAvg->setTitleText(QStringLiteral("单位db"));
    m_pAxisYAvg->setTitleBrush(Qt::white);
    m_pAxisYAvg->setTickCount(6);     //设置多少格
    m_pAxisYAvg->setMinorTickCount(9); //设置每格小刻度线的数目
    m_pAxisXAvg->setTickCount(13);
    m_pAxisXAvg->setMinorTickCount(9);

    m_pChartAvg = std::make_shared<QtCharts::QChart>();
    m_pChartAvg->legend()->setAlignment(Qt::AlignRight);
    m_pChartAvg->addSeries(m_pLineSeriesAvg.get());
    m_pChartAvg->setBackgroundVisible(false);
    m_pChartAvg->legend()->setLabelColor(Qt::white);

    m_pChartAvg->addAxis(m_pAxisXAvg.get(), Qt::AlignBottom);
    m_pChartAvg->addAxis(m_pAxisYAvg.get(), Qt::AlignLeft);
    m_pLineSeriesAvg->attachAxis(m_pAxisXAvg.get());
    m_pLineSeriesAvg->attachAxis(m_pAxisYAvg.get());

    m_pScatterSeriesAvgTip = std::make_shared<QtCharts::QScatterSeries>();
    m_pChartAvg->addSeries(m_pScatterSeriesAvgTip.get());
    m_pScatterSeriesAvgTip->setMarkerSize(10);     // 设置散点大小
    m_pScatterSeriesAvgTip->attachAxis(m_pAxisXAvg.get());
    m_pScatterSeriesAvgTip->attachAxis(m_pAxisYAvg.get());
    m_pScatterSeriesAvgTip->setPointLabelsVisible(true);
    m_pScatterSeriesAvgTip->setPointLabelsColor(Qt::green);
    QFont t_FontLab;
    t_FontLab.setPointSize(16);
    m_pScatterSeriesAvgTip->setPointLabelsFont(t_FontLab);
    m_pScatterSeriesAvgTip->setName("Tip");
    t_penLine.setColor(Qt::green);
    m_pScatterSeriesAvgTip->setPen(t_penLine);

    ui->tab_2->setChart(m_pChartAvg.get());
    ui->tab_2->setRenderHint(QPainter::Antialiasing);
}

/*雷达串口数据接收*/
void MainWindow::ReceiveRadarInfo(void)
{
    if (!m_pSerialRadar->isReadable())
    {
        return;
    }

    QString t_strRadarData = m_pSerialRadar->readAll();
    if (t_strRadarData.length() < 1)
    {
        return;
    }

    QStringList data = t_strRadarData.split('\n');
    bool t_bIsHead = true;
    int t_iSize = data.size();
    int t_iIndex = 1;
    for (auto t_strLine : data)
    {
        m_strLine = t_strLine;
        if (m_strLine.length() > 0
            && "Done" != m_strLine)
        {
            if (t_bIsHead)
            {
                if (m_strLine.startsWith("Ant"))
                {
                    if (m_strTailData.startsWith("Ant"))
                    {
                        ParseData(m_strTailData);
                    }
                    ParseData(m_strLine);
                }
                else
                {
                    if (m_strTailData.startsWith("Ant"))
                    {
                        m_strTailData.append(m_strLine);
                        ParseData(m_strTailData);
                    }
                }
                m_strTailData = "";
                t_bIsHead = false;
            }
            else if (!t_bIsHead && t_iIndex != t_iSize)
            {
                ParseData(m_strLine);
            }

            if (t_iIndex == t_iSize
                    && m_strLine.startsWith("Ant"))
            {
                m_strTailData = m_strLine;
            }
            ++t_iIndex;
        }
    }
}

/*雷达串口数据解析*/
void MainWindow::ParseData(QString &t_strLine)
{
//    qDebug() << "uartData:" << t_strLine;
    t_strLine = t_strLine.trimmed();
    if (!t_strLine.startsWith("Ant"))
    {
        return;
    }

    bool t_bRet = false;

    QString t_strAnt = t_strLine.left(t_strLine.indexOf(','));
    t_strAnt = t_strAnt.mid(3);
    int t_iAnt = t_strAnt.toInt(&t_bRet);

    QString t_strRangeIdx = t_strLine.mid(t_strLine.indexOf("rangeIdx, ") + 10);
    t_strRangeIdx = t_strRangeIdx.left(t_strRangeIdx.indexOf(','));
    int t_iRangeIdx = t_strRangeIdx.toInt(&t_bRet);

    QString t_strPeak = t_strLine.mid(t_strLine.indexOf("Peak:") + 5 );
    int t_iPeak = t_strPeak.toInt(&t_bRet);

//    qDebug() << "uartData:" << t_iAnt << t_iRangeIdx << t_iPeak;
//    qDebug() << t_iAnt << ", " << t_iPeak;

    if (t_bRet && (m_bIsDetect || m_bIsDetect_AZ))
    {
        RadarSerialDataRechSlot2(t_iAnt, t_iRangeIdx, t_iPeak);  //将雷达数据画图
    }
    else
    {
        if(t_bRet)
        {
            if(m_channel_num < t_iAnt)
            {
                m_channel_num = t_iAnt;
                qDebug() << "m_channel_num:" << m_channel_num;
                if(m_channel_num == 11)
                {
                    ui->tabWidget->setTabText(0, QStringLiteral("12通道曲线图"));

                    m_pChart->addSeries(m_pLineSeries8.get());
                    m_pChart->addSeries(m_pLineSeries9.get());
                    m_pChart->addSeries(m_pLineSeries10.get());
                    m_pChart->addSeries(m_pLineSeries11.get());

                    m_pChart->legend()->setLabelColor(Qt::black);
                    m_pChart->legend()->setLabelColor(Qt::white);

                    m_pLineSeries8->attachAxis(m_pAxisX.get());
                    m_pLineSeries8->attachAxis(m_pAxisY.get());

                    m_pLineSeries9->attachAxis(m_pAxisX.get());
                    m_pLineSeries9->attachAxis(m_pAxisY.get());

                    m_pLineSeries10->attachAxis(m_pAxisX.get());
                    m_pLineSeries10->attachAxis(m_pAxisY.get());

                    m_pLineSeries11->attachAxis(m_pAxisX.get());
                    m_pLineSeries11->attachAxis(m_pAxisY.get());

                    ui->tab->setChart(m_pChart.get());
                }
            }
        }
    }
}

void MainWindow::OpenRadarPort(void)
{
    // 设置串口名字
    QString t_strRadarName = ui->comboBoxRadars->currentText();
    t_strRadarName = t_strRadarName.mid(0, t_strRadarName.indexOf("  "));
    qDebug() << "RadarName:" << t_strRadarName;
    m_pSerialRadar->setPortName(t_strRadarName);

    if(!m_pSerialRadar->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
    {
        qDebug() << t_strRadarName << " is open failed!";
        return;
    }

    QString t_strRadarBaudRate = ui->lineedit_RadarBaudRate->text();
    t_strRadarBaudRate = t_strRadarBaudRate.trimmed();  //字符串修饰,剔除开头结尾空白字符  (simplified:剔除空白字符)
    qDebug() << "RadarBaudRate:" << t_strRadarBaudRate.toInt();
    m_pSerialRadar->setBaudRate(t_strRadarBaudRate.toInt());
//    m_pSerialRadar->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections); //设置波特率和读写方向
    m_pSerialRadar->setDataBits(QSerialPort::Data8);     //数据位为8位
    m_pSerialRadar->setFlowControl(QSerialPort::NoFlowControl);  //无流控制
    m_pSerialRadar->setParity(QSerialPort::NoParity);    //无校验位
    m_pSerialRadar->setStopBits(QSerialPort::OneStop);   //一位停止位
}

void MainWindow::initTitleBar()
{
    m_titleBar = new MyTitleBar(this);
    m_titleBar->move(0, 0);

    //m_titleBar->setTitleIcon(":/img/mbit.ico");
    m_titleBar->setTitleContent(QStringLiteral(" 暗室转台雷达检测系统2.0.0.2"));
    m_titleBar->setButtonType(MIN_BUTTON);
    m_titleBar->setBackgroundColor(65, 65, 65);

    connect(m_titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(m_titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

void MainWindow::onButtonMinClicked()
{
    showMinimized();
}

void MainWindow::onButtonRestoreClicked()
{
    QPoint windowPos;
    QSize windowSize;
    m_titleBar->getRestoreInfo(windowPos, windowSize);
    this->setGeometry(QRect(windowPos, windowSize));
}

void MainWindow::onButtonMaxClicked()
{
    m_titleBar->saveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
    setGeometry(FactRect);
}

void MainWindow::onButtonCloseClicked()
{
    close();
}

MainWindow::~MainWindow()
{
    m_rotarythread.stop();

    m_rotarythread.terminate();

    m_rotarythread.wait();

    delete dialog;
    delete ui;
}

void MainWindow::radar_reselect_slot()
{
    m_pLineSeries0->clear();
    m_pLineSeries1->clear();
    m_pLineSeries2->clear();
    m_pLineSeries3->clear();
    m_pLineSeries4->clear();
    m_pLineSeries5->clear();
    m_pLineSeries6->clear();
    m_pLineSeries7->clear();
    m_pLineSeries8->clear();
    m_pLineSeries9->clear();
    m_pLineSeries10->clear();
    m_pLineSeries11->clear();
    m_pLineSeriesAvg->clear();
    m_pScatterSeriesAvgTip->clear();

    m_pAxisX->setRange(-180.0, -60.0);
    m_pAxisXAvg->setRange(-180.0, -60.0);

    m_vecAvgData.clear();
}

void MainWindow::rotary_reselect_slot()
{
}

void MainWindow::checkopenslot(bool justic, const QString &port)
{
    if(!justic)
        QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("串口[") + port + QStringLiteral("]打开失败"));
}

void MainWindow::wrongdetectoneslot()
{

}

void MainWindow::wrongdetecttwoslot()
{

}

/*转台串口数据刷新释放信号控制槽函数*/
void MainWindow::RotarySerialDataRechSlot(double val1, double val2, double val3)
{
    double t_dbEnd = 0.0;

    if (AT_Az == m_typeRotary)
    {
        m_curRotaryAngle = val1;
        t_dbEnd = 0.15;
    }
    else if(AT_El == m_typeRotary)
    {
        m_curRotaryAngle = val2;
        t_dbEnd = 0.2;
    }
    else if(AT_Pol == m_typeRotary)
    {
        m_curRotaryAngle = val3;
        t_dbEnd = 0.2;
    }

    QString t_strAngle;
    t_strAngle.setNum(m_curRotaryAngle);
    ui->label_7->setText(t_strAngle);

    if (m_bIsReadyDetect)
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - m_dbStartAngle);
        if (t_dbMinus < t_dbEnd)
        {
            qDebug() << "t_dbMinus:" << t_dbMinus << QStringLiteral("，已经转到俯仰开始角度");  //zxy
            m_bIsReadyDetect = false;
            m_bIsDetect = true;
            m_strStartDetectTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");

            if (m_pFileLog->isOpen())
            {
                m_pFileLog->close();
            }
            QString t_strRecordPath = QCoreApplication::applicationDirPath();
            t_strRecordPath.append("/Record");
            QDir dir;
            if (!dir.exists(t_strRecordPath))
            {
                dir.mkpath(t_strRecordPath);
            }
            t_strRecordPath.append("/").append(m_strStartDetectTime).append("_俯仰").append(".txt");  //zxy
            m_pFileLog->setFileName(t_strRecordPath);
            if (m_pFileLog->open(QIODevice::WriteOnly))
            {
                m_pTsLog->setDevice(m_pFileLog.get());
            }
            else
            {
                qCritical() << " Open file is failed, path:" << t_strRecordPath;
            }

            radar_reselect_slot();  //雷达显示数据刷新清零
//            OpenRadarPort();  //打开雷达串口
//            std::string t_strCmd = "clioutput 31\r\n";
//            m_pSerialRadar->write(t_strCmd.c_str(), t_strCmd.length());
//            m_pTimerReadRadarData->start(100); //雷达串口开始接接收 100ms定时接收

            QString t_strRadarData = m_pSerialRadar->readAll();


            emit action_lead(m_speed, m_dbEndAngle);   //发布控制转台运转信号
            qDebug() << "m_speed:" << m_speed;
            ui->label_in_status->setText(QStringLiteral("正在从俯仰开始角度转动到俯仰结束角度"));   //zxy
        }
    }

    if (m_bIsDetect)
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - m_dbEndAngle);
        if (t_dbMinus < t_dbEnd)
        {
            qDebug() << "t_dbMinus:" << t_dbMinus << QStringLiteral("，已经转到俯仰结束角度");  //zxy

            m_bIsDetect = false;

//            ui->label_in_status->setText(QStringLiteral("测量结束"));
//            ui->pushButtonDetect->setText(QStringLiteral("开始测量"));
//            m_bIsPressDetect = false;


            DealAvgMap();  //测量完成之后均值计算、特殊点显示
            m_pTimerReadRadarData->stop();
            m_pFileLog->close(); //zxy

//            std::string t_strCmd = "clioutput 1\r\n";
//            m_pSerialRadar->write(t_strCmd.c_str(), t_strCmd.length());
//            if(m_pSerialRadar->isOpen())
//            {
//                m_pSerialRadar->clear();
//                m_pSerialRadar->close();
//            }

//            emit action_lead(15.0, 0.0);   //转台位置归零
//            m_bAngleTo0 = true;
//            ui->label_in_status->setText(QStringLiteral("恢复转台到0度"));

            if(m_maxPeakAngle > 0)
            {
                m_maxPeakAngle += 0.11;
            }

            if(m_maxPeakAngle  < 0)
            {
                m_maxPeakAngle -= 0.11;
            }

            emit action_lead(15.0, m_maxPeakAngle);   //转台转到俯仰peak最大角度 zxy
            m_bIsDetect_max = true;  //zxy
            ui->label_in_status->setText(QStringLiteral("正在转动到俯仰能量最大角度"));  //zxy

        }
    }

    if(m_bIsDetect_max) //zxy
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - m_maxPeakAngle);
        if (t_dbMinus < t_dbEnd)
        {
            qDebug() << "t_dbMinus:" << t_dbMinus << QStringLiteral("，俯仰能量最大角度");

//            m_dbStartAngle = -60.0;
            if(ui->comboBox_azimuth->currentText() == "±60°")
            {
                m_dbStartAngle = -60.0;
                m_dbStartAngle -= 0.11;

                m_dbEndAngle = 60;
                m_dbEndAngle += 0.11;
            }

            if(ui->comboBox_azimuth->currentText() == "±90°")
            {
                m_dbStartAngle = -90.0;
                m_dbStartAngle -= 0.11;

                m_dbEndAngle = 90;
                m_dbEndAngle += 0.11;
            }

            m_dbAngleOfX = qAbs(m_dbEndAngle) + qAbs(m_dbStartAngle);

            m_typeRotary = AT_Az;
            emit typechanged(DownType);

            while(1)
            {
                AngleType rotaryType;
                emit getRotaryType(rotaryType);

                QThread::msleep(20);
                if(rotaryType == m_typeRotary)
                {
                    break;
                }
            }

            emit action_lead(15.0, m_dbStartAngle);
            ui->label_in_status->setText(QStringLiteral("正在转动到水平开始角度"));  //zxy
            m_bIsDetect_max = false;
            m_bIsReadyDetect_AZ = true;
        }
    }

    if(m_bIsReadyDetect_AZ) //zxy
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - m_dbStartAngle);
        if (t_dbMinus < t_dbEnd)
        {
            if (m_pFileLog->isOpen())
            {
                m_pFileLog->close();
            }
            QString t_strRecordPath = QCoreApplication::applicationDirPath();
            t_strRecordPath.append("/Record");
            QDir dir;
            if (!dir.exists(t_strRecordPath))
            {
                dir.mkpath(t_strRecordPath);
            }
            t_strRecordPath.append("/").append(m_strStartDetectTime).append("_方位").append(".txt");
            m_pFileLog->setFileName(t_strRecordPath);
            if (m_pFileLog->open(QIODevice::WriteOnly))
            {
                m_pTsLog->setDevice(m_pFileLog.get());
            }
            else
            {
                qCritical() << " Open file is failed, path:" << t_strRecordPath;
            }


            QString t_strRadarData = m_pSerialRadar->readAll();
            radar_reselect_slot();  //雷达显示数据刷新清零
            m_pTimerReadRadarData->start(100); //雷达串口开始接接收 100ms定时接收

            emit action_lead(m_speed, m_dbEndAngle);   //发布控制转台运转信号
            qDebug() << "m_speed:" << m_speed;
            ui->label_in_status->setText(QStringLiteral("正在从水平开始角度转动到水平结束角度"));

            m_bIsReadyDetect_AZ = false;
            m_bIsDetect_AZ = true;
        }
    }

    if(m_bIsDetect_AZ)  //zxy
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - m_dbEndAngle);
        if (t_dbMinus < t_dbEnd)
        {
            qDebug() << "t_dbMinus:" << t_dbMinus << QStringLiteral("，已经转到方位结束角度");  //zxy

            m_bIsDetect_AZ = false;
            ui->label_in_status->setText(QStringLiteral("测量结束"));
            ui->pushButtonDetect->setText(QStringLiteral("开始测量"));
            m_bIsPressDetect = false;


            std::string t_strCmd = "clioutput 1\r\n";
            m_pSerialRadar->write(t_strCmd.c_str(), t_strCmd.length());
            if(m_pSerialRadar->isOpen())
            {
                m_pSerialRadar->clear();
                m_pSerialRadar->close();
            }

            DealAvgMap();  //测量完成之后均值计算、特殊点显示
            m_pTimerReadRadarData->stop();
            m_pFileLog->close(); //zxy

            m_channel_num = 3;
            emit action_lead(15.0, 0.0);   //转台位置归零
            m_bAngleTo0 = true;
            ui->label_in_status->setText(QStringLiteral("恢复转台到0度"));
            //rotary_actionReset();
        }
    }

    if (m_bAngleTo0)
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - 0.0);
        if (t_dbMinus < t_dbEnd)
        {

//            qDebug() << "t_dbMinus:" << t_dbMinus << QStringLiteral("，已经恢复到0度");
            m_bAngleTo0 = false;
            m_bAngleTo0_1 = true;

            if(m_typeRotary == AT_Az)
            {

                m_typeRotary = AT_El;

                emit typechanged(PitchingType);

                while(1)
                {
                    AngleType rotaryType;
                    emit getRotaryType(rotaryType);

                    QThread::msleep(20);
                    if(rotaryType == m_typeRotary)
                    {
                        break;
                    }
                }

                emit action_lead(15.0, 0.0);
            }
            else
            {
                m_typeRotary = AT_Az;

                emit typechanged(DownType);

                while(1)
                {
                    AngleType rotaryType;
                    emit getRotaryType(rotaryType);

                    QThread::msleep(20);
                    if(rotaryType == m_typeRotary)
                    {
                        break;
                    }
                }

                emit action_lead(15.0, 0.0);
            }
        }
    }

    if (m_bAngleTo0)
    {
        double t_dbMinus = qAbs(m_curRotaryAngle - 0.0);
        if (t_dbMinus < t_dbEnd)
        {
            qDebug() << "t_dbMinus:" << t_dbMinus << QStringLiteral("，已经恢复到0度");
            m_bAngleTo0_1 = false;
            ui->label_in_status->setText(QStringLiteral("转台已经恢复到0度"));
            StopRotarythread();
        }
    }

//    QString t_qstrNum;
//    if(m_angle != val1)
//    {
////        ui->angleDashBoard->setValue(((qreal)(val1+90.0)/180.0)*100.0);
//        t_qstrNum.setNum(((qreal)(val1+90.0)/180.0)*100.0, 'g', 2);
//        ui->label_7->setText(t_qstrNum);
//    }
//    if(m_pitching != val2)
//    {
////        ui->pitchingDashBoard->setValue(((qreal)(val2+90.0)/180)*100);
//        t_qstrNum.setNum(((qreal)(val2+90.0)/180)*100, 'g', 2);
//        ui->label_8->setText(t_qstrNum);
//    }
//    if(m_oritation != val3)
//    {
////        ui->oritationDashBoard->setValue(((qreal)(val3+90.0)/180.0)*100.0);
//        t_qstrNum.setNum(((qreal)(val3+90.0)/180.0)*100.0, 'g', 2);
//        ui->label_9->setText(t_qstrNum);
//    }
}


/*雷达数据解析完后连同转台数据一起图像显示*/
void MainWindow::RadarSerialDataRechSlot2(int t_iAnt, int t_iRangeIdx, int t_iPeak)
{
    *m_pTsLog << "Ant:" << t_iAnt << ", RangeIdx:" << t_iRangeIdx << ", Peak:" << t_iPeak
              << ", RotaryAngle:" << m_curRotaryAngle << "\r\n";

    m_pTsLog->flush();
    m_pFileLog->flush();

    static bool t_bIsFirst = true;

    if (t_bIsFirst)
    {
        if (0 != t_iAnt)
        {
            return;
        }
        t_bIsFirst = false;
    }

    static int t_iOldAnt = -1;
    static double t_dbOldAngle = 0.0;

    if (t_iOldAnt == t_iAnt
            && qAbs(t_dbOldAngle - m_curRotaryAngle) < 0.1)
    {
        return;
    }

    t_iOldAnt = t_iAnt;
    t_dbOldAngle = m_curRotaryAngle;

    m_pAxisX->setRange(m_curRotaryAngle - m_dbAngleOfX, m_curRotaryAngle);
    m_vecPeak.push_back(t_iPeak);

    double tempPeak = t_iPeak + 0.01;
//    double t_dbLog2 = 10 * log10(t_iPeak * t_iPeak);
    double t_dbLog2 = 10 * log10(tempPeak * tempPeak);

    if(t_dbLog2 > maxPeak)
    {
        maxPeak = t_dbLog2;
    }
    if(t_dbLog2 < minPeak)
    {
        minPeak = t_dbLog2;
    }

    if(minPeak < m_rangY_start)
    {
         if(maxPeak - minPeak <= 40)
         {
             m_rangY_start = minPeak - 10;
             m_rangY_end = m_rangY_start + 50;
         }
         else
         {
             m_rangY_start = minPeak - 5;
             m_rangY_end = maxPeak + 5;
         }

         m_pAxisY->setRange(m_rangY_start, m_rangY_end);
    }
    if(maxPeak > m_rangY_end)
    {
        if(maxPeak - minPeak <= 40)
        {
            m_rangY_start = minPeak - 10;
            m_rangY_end = m_rangY_start + 50;
        }
        else
        {
            m_rangY_start = minPeak - 5;
            m_rangY_end = maxPeak + 5;
        }

        m_pAxisY->setRange(m_rangY_start, m_rangY_end);
    }

    m_vecLogPeak.push_back(t_dbLog2);
    switch(t_iAnt)
    {
        case 0:
        {
            m_pLineSeries0->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 1:
        {
            m_pLineSeries1->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 2:
        {
            m_pLineSeries2->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 3:
        {
            m_pLineSeries3->append(m_curRotaryAngle, t_dbLog2);

            if (4 == m_vecLogPeak.size() && m_channel_num == 3)
            {
                double t_dbSum = 0;
                for (auto t_dbItem : m_vecLogPeak)
                {
                    t_dbSum += t_dbItem;
                }
                double t_dbAvg = t_dbSum / 4;
                m_pAxisXAvg->setRange(m_curRotaryAngle - m_dbAngleOfX, m_curRotaryAngle);
                m_pLineSeriesAvg->append(m_curRotaryAngle, t_dbAvg);  //合通道平均值显示

                if(t_dbAvg > maxAvgPeak)
                {
                    maxAvgPeak = t_dbAvg;
                }
                if(t_dbAvg < minAvgPeak)
                {
                    minAvgPeak = t_dbAvg;
                }

                if(minAvgPeak < m_rangY_avg_start)
                {
                     if(maxAvgPeak - minAvgPeak <= 40)
                     {
                         m_rangY_avg_start = minAvgPeak - 10;
                         m_rangY_avg_end = m_rangY_avg_start + 50;
                     }
                     else
                     {
                         m_rangY_avg_start = minAvgPeak - 5;
                         m_rangY_avg_end = maxAvgPeak + 5;
                     }

                     m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
                }

                if(maxAvgPeak > m_rangY_avg_end)
                {
                    if(maxAvgPeak - minAvgPeak <= 40)
                    {
                        m_rangY_avg_start = minAvgPeak - 10;
                        m_rangY_avg_end = m_rangY_avg_start + 50;
                    }
                    else
                    {
                        m_rangY_avg_start = minAvgPeak - 5;
                        m_rangY_avg_end = maxAvgPeak + 5;
                    }

                    m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
                }

                RadarAvgData t_RadarAvgData;
                t_RadarAvgData.dbAngle = m_curRotaryAngle;
                t_RadarAvgData.dbLogPeak = t_dbAvg;
                m_vecAvgData.push_back(t_RadarAvgData);

                m_vecLogPeak.clear();
            }


            if (4 == m_vecPeak.size() && m_channel_num == 3)
            {
                int t_iSum = 0;
                for (auto t_iItem : m_vecPeak)
                {
                    t_iSum += t_iItem;
                }
                int t_iAvg = t_iSum / 4;

                m_vecAvgData[m_vecAvgData.size() - 1].iPeak = t_iAvg;

                m_vecPeak.clear();
            }

            break;
        }
        case 4:
        {
            m_pLineSeries4->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 5:
        {
            m_pLineSeries5->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 6:
        {
            m_pLineSeries6->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 7:
        {
            m_pLineSeries7->append(m_curRotaryAngle, t_dbLog2);

            if (8 == m_vecLogPeak.size() && m_channel_num == 7)
            {
                double t_dbSum = 0;
                for (auto t_dbItem : m_vecLogPeak)
                {
                    t_dbSum += t_dbItem;
                }
                double t_dbAvg = t_dbSum / 8;
                m_pAxisXAvg->setRange(m_curRotaryAngle - m_dbAngleOfX, m_curRotaryAngle);
                m_pLineSeriesAvg->append(m_curRotaryAngle, t_dbAvg);  //合通道平均值显示

                if(t_dbAvg > maxAvgPeak)
                {
                    maxAvgPeak = t_dbAvg;
                }
                if(t_dbAvg < minAvgPeak)
                {
                    minAvgPeak = t_dbAvg;
                }

                if(minAvgPeak < m_rangY_avg_start)
                {
                     if(maxAvgPeak - minAvgPeak <= 40)
                     {
                         m_rangY_avg_start = minAvgPeak - 10;
                         m_rangY_avg_end = m_rangY_avg_start + 50;
                     }
                     else
                     {
                         m_rangY_avg_start = minAvgPeak - 5;
                         m_rangY_avg_end = maxAvgPeak + 5;
                     }

                     m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
                }

                if(maxAvgPeak > m_rangY_avg_end)
                {
                    if(maxAvgPeak - minAvgPeak <= 40)
                    {
                        m_rangY_avg_start = minAvgPeak - 10;
                        m_rangY_avg_end = m_rangY_avg_start + 50;
                    }
                    else
                    {
                        m_rangY_avg_start = minAvgPeak - 5;
                        m_rangY_avg_end = maxAvgPeak + 5;
                    }

                    m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
                }

                RadarAvgData t_RadarAvgData;
                t_RadarAvgData.dbAngle = m_curRotaryAngle;
                t_RadarAvgData.dbLogPeak = t_dbAvg;
                m_vecAvgData.push_back(t_RadarAvgData);

                m_vecLogPeak.clear();
            }


            if (8 == m_vecPeak.size() && m_channel_num == 7)
            {
                int t_iSum = 0;
                for (auto t_iItem : m_vecPeak)
                {
                    t_iSum += t_iItem;
                }
                int t_iAvg = t_iSum / 8;

                m_vecAvgData[m_vecAvgData.size() - 1].iPeak = t_iAvg;

                m_vecPeak.clear();
            }

            break;
        }
        case 8:
        {
            m_pLineSeries8->append(m_curRotaryAngle, t_dbLog2);

            break;
        }
        case 9:
        {
            m_pLineSeries9->append(m_curRotaryAngle, t_dbLog2);

            break;
        }

        case 10:
        {
            m_pLineSeries10->append(m_curRotaryAngle, t_dbLog2);

            break;
        }

        case 11:
        {
            m_pLineSeries11->append(m_curRotaryAngle, t_dbLog2);

            if (12 == m_vecLogPeak.size() && m_channel_num == 11)
            {
                double t_dbSum = 0;
                for (auto t_dbItem : m_vecLogPeak)
                {
                    t_dbSum += t_dbItem;
                }
                double t_dbAvg = t_dbSum / 12;
                m_pAxisXAvg->setRange(m_curRotaryAngle - m_dbAngleOfX, m_curRotaryAngle);
                m_pLineSeriesAvg->append(m_curRotaryAngle, t_dbAvg);  //合通道平均值显示

                if(t_dbAvg > maxAvgPeak)
                {
                    maxAvgPeak = t_dbAvg;
                }
                if(t_dbAvg < minAvgPeak)
                {
                    minAvgPeak = t_dbAvg;
                }

                if(minAvgPeak < m_rangY_avg_start)
                {
                     if(maxAvgPeak - minAvgPeak <= 40)
                     {
                         m_rangY_avg_start = minAvgPeak - 10;
                         m_rangY_avg_end = m_rangY_avg_start + 50;
                     }
                     else
                     {
                         m_rangY_avg_start = minAvgPeak - 5;
                         m_rangY_avg_end = maxAvgPeak + 5;
                     }

                     m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
                }

                if(maxAvgPeak > m_rangY_avg_end)
                {
                    if(maxAvgPeak - minAvgPeak <= 40)
                    {
                        m_rangY_avg_start = minAvgPeak - 10;
                        m_rangY_avg_end = m_rangY_avg_start + 50;
                    }
                    else
                    {
                        m_rangY_avg_start = minAvgPeak - 5;
                        m_rangY_avg_end = maxAvgPeak + 5;
                    }

                    m_pAxisYAvg->setRange(m_rangY_avg_start, m_rangY_avg_end);
                }

                RadarAvgData t_RadarAvgData;
                t_RadarAvgData.dbAngle = m_curRotaryAngle;
                t_RadarAvgData.dbLogPeak = t_dbAvg;
                m_vecAvgData.push_back(t_RadarAvgData);

                m_vecLogPeak.clear();
            }

            if (12 == m_vecPeak.size() && m_channel_num == 11)
            {
                int t_iSum = 0;
                for (auto t_iItem : m_vecPeak)
                {
                    t_iSum += t_iItem;
                }
                int t_iAvg = t_iSum / 12;

                m_vecAvgData[m_vecAvgData.size() - 1].iPeak = t_iAvg;

                m_vecPeak.clear();
            }

            break;
        }
    }

    if(m_vecLogPeak.size() > (m_channel_num + 1))
    {
        m_vecLogPeak.clear();
    }

    if(m_vecPeak.size() > (m_channel_num + 1))
    {
         m_vecPeak.clear();
    }
}


/*测量完成之后计算*/
void MainWindow::DealAvgMap(void)
{
    m_iMaxPeak = 0;
    m_dbMaxPeakAngle = 0.0;

    int t_iIndex = 0;
    int t_iMaxIndex = 0;
    for (; t_iIndex < m_vecAvgData.size(); ++t_iIndex)
    {
        if (m_vecAvgData[t_iIndex].iPeak > m_iMaxPeak)
        {
            m_iMaxPeak = m_vecAvgData[t_iIndex].iPeak;
            m_dbMaxLogPeak = m_vecAvgData[t_iIndex].dbLogPeak;
            m_dbMaxPeakAngle = m_vecAvgData[t_iIndex].dbAngle;
            t_iMaxIndex = t_iIndex;
        }
    }
    m_maxPeakAngle = m_dbMaxPeakAngle;   //zxy
    if(fabs(m_maxPeakAngle) > 10)
    {
        m_maxPeakAngle = 0;
    }

    m_strMaxPeakAngle.setNum(m_dbMaxPeakAngle);
    ui->label_CenterAngle->setText(m_strMaxPeakAngle);

    m_strMaxPeak.setNum(m_iMaxPeak);
    m_strMaxLogPeak.setNum(m_dbMaxLogPeak, 'f', 2);
    ui->label_18->setText(m_strMaxPeak + "(" + m_strMaxLogPeak + ")");

    m_db6Statrt = m_dbStartAngle;
    double t_db6StatrtLogPeak = 0.0;
    m_db6End = m_dbEndAngle;
    double t_db6EndLogPeak = 0.0;
    m_db12Statrt = m_dbStartAngle;
    double t_db12StatrtLogPeak = 0.0;
    m_db12End = m_dbEndAngle;
    double t_db12EndLogPeak = 0.0;
    bool t_bIsFind6 = false;
    bool t_bIsFind12 = false;
    double t_db6Peak = m_dbMaxLogPeak - 6;
    double t_db12Peak = m_dbMaxLogPeak - 12;
//    qDebug() << "6Peak:" << t_i6Peak << ", 12Peak:" << t_i12Peak;

    for (int i = t_iMaxIndex; i > 0; --i)
    {
        if (!t_bIsFind6)
        {
            if (m_vecAvgData[i].dbLogPeak < t_db6Peak
                    && m_vecAvgData[i].dbAngle < m_dbMaxPeakAngle)
            {
                m_db6Statrt = m_vecAvgData[i].dbAngle;
                t_db6StatrtLogPeak = m_vecAvgData[i].dbLogPeak;
                t_bIsFind6 = true;
            }
        }

        if (t_bIsFind6 && !t_bIsFind12)
        {
            if (m_vecAvgData[i].dbLogPeak <= t_db12Peak
                    && m_vecAvgData[i].dbAngle < m_dbMaxPeakAngle)
            {
                m_db12Statrt = m_vecAvgData[i].dbAngle;
                t_db12StatrtLogPeak = m_vecAvgData[i].dbLogPeak;
                t_bIsFind12 = true;
                break;
            }
        }
    }

    m_str6Statrt.setNum(m_db6Statrt);
    if (!t_bIsFind12)
    {
        m_db12Statrt = m_dbStartAngle + 0.11;
        t_db12StatrtLogPeak = m_vecAvgData[0].dbLogPeak;
    }
    m_str12Statrt.setNum(m_db12Statrt);
    ui->label_27->setText(m_str6Statrt);
    ui->label_34->setText(m_str12Statrt);

    t_bIsFind6 = false;
    t_bIsFind12 = false;
    for (int i = t_iMaxIndex; i < t_iIndex; ++i)
    {
        if (!t_bIsFind6)
        {
            if (m_vecAvgData[i].dbLogPeak < t_db6Peak
                    && m_vecAvgData[i].dbAngle > m_dbMaxPeakAngle)
            {
                m_db6End = m_vecAvgData[i].dbAngle;
                t_db6EndLogPeak = m_vecAvgData[i].dbLogPeak;
                t_bIsFind6 = true;
            }
        }

        if (t_bIsFind6 && !t_bIsFind12)
        {
            if (m_vecAvgData[i].dbLogPeak <= t_db12Peak
                    && m_vecAvgData[i].dbAngle > m_dbMaxPeakAngle)
            {
                m_db12End = m_vecAvgData[i].dbAngle;
                t_db12EndLogPeak = m_vecAvgData[i].dbLogPeak;
                t_bIsFind12 = true;
                break;
            }
        }
    }

    m_str6End.setNum(m_db6End);
    if (!t_bIsFind12)
    {
        m_db12End = m_dbEndAngle - 0.11;
        t_db12EndLogPeak = m_vecAvgData[m_vecAvgData.size() - 1].dbLogPeak;
    }
    m_str12End.setNum(m_db12End);
    ui->label_30->setText(m_str6End);
    ui->label_35->setText(m_str12End);

    m_db6Range = m_db6End - m_db6Statrt;
    m_str6Range.setNum(m_db6Range);
    ui->label_16->setText(m_str6Range);

    m_db6Center = (m_db6Statrt + m_db6End) / 2;
    m_str6Center.setNum(m_db6Center);

    m_db12Range = m_db12End - m_db12Statrt;
    m_str12Range.setNum(m_db12Range);
    ui->label_20->setText(m_str12Range);

    m_db12Center = (m_db12Statrt + m_db12End) / 2;
    m_str12Center.setNum(m_db12Center);

    QString t_strTest;
    t_strTest.setNum(t_db12StatrtLogPeak, 'f', 2);
    m_pScatterSeriesAvgTip->append(m_db12Statrt, t_strTest.toDouble());
    t_strTest.setNum(t_db6StatrtLogPeak, 'f', 2);
    m_pScatterSeriesAvgTip->append(m_db6Statrt, t_strTest.toDouble());
    t_strTest.setNum(m_dbMaxLogPeak, 'f', 2);
    m_pScatterSeriesAvgTip->append(m_dbMaxPeakAngle, t_strTest.toDouble());
    t_strTest.setNum(t_db6EndLogPeak, 'f', 2);
    m_pScatterSeriesAvgTip->append(m_db6End, t_strTest.toDouble());
    t_strTest.setNum(t_db12EndLogPeak, 'f', 2);
    m_pScatterSeriesAvgTip->append(m_db12End, t_strTest.toDouble());

    /*自动生成报告*/
    on_BtnGenerateReport();
}

void MainWindow::on_BtnGenerateReport(void)
{
    if(m_typeRotary == AT_El)
    {
//        QString t_strDefalut;
//        t_strDefalut = m_strStartDetectTime;

//        t_strDefalut.append(".html");

//        m_reportFileName = QFileDialog::getSaveFileName(this, tr("Save File"), t_strDefalut, tr("Web(*.html)"));
//        if (m_reportFileName.length() < 1)
//        {
//            return;
//        }
//        qDebug() << "save path:" << m_reportFileName;

        m_reportFileName = QCoreApplication::applicationDirPath();
        m_reportFileName.append("/Record");
        QDir dir;
        if (!dir.exists(m_reportFileName))
        {
            dir.mkpath(m_reportFileName);
        }
        m_reportFileName.append("/").append(m_strStartDetectTime).append(".html");  //zxy


        QString html;
        saveHtmlToWord(html);
        QFile outFile(m_reportFileName);
        outFile.open(QIODevice::WriteOnly | QIODevice::Append );
        QTextStream ts(&outFile);
        ts << html;
        outFile.close();
    }
    else
    {
         QString html;
         saveHtmlToWord1(html);
         QFile outFile(m_reportFileName);
         outFile.open(QIODevice::WriteOnly | QIODevice::Append );
         QTextStream ts(&outFile);
         ts << html;
         outFile.close();
        QDesktopServices::openUrl(m_reportFileName);
    }

}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(qobject_cast<QLabel*>(obj) == ui->label_logo && event->type() == QEvent::MouseButtonDblClick)
    {
        if(dialog == NULL)
            dialog = new  controldlg(this) ;
        dialog->show();
		return true;
    }
	return false;
}

void MainWindow::on_action_O_triggered()
{
    if(dialog == NULL)
        dialog = new controldlg(this);
    dialog->show();
}

//void MainWindow::on_pushButtonDetect_clicked()
//{
//    ui->label_in_status->setText(QStringLiteral("正在进行雷达校准"));
//    //set radar output false
//    emit action_output(false);
//    //adjust
//    emit action_adjust();
//    //data after adjust
//    emit action_output(true);
//}

/*开始测量按键槽函数*/
void MainWindow::on_pushButtonDetect_clicked()
{
//    qDebug() << "Enter MainWindow::on_pushButtonDetect_clicked";

    if (m_bIsReadyDetect || m_bIsDetect_max || m_bIsReadyDetect_AZ)
    {
        QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("正在转动到起始角度，请等待！"));
        return;
    }
    if (m_bIsPressDetect)
    {
        m_pTimerReadRadarData->stop();
        std::string t_strCmd = "clioutput 1\r\n";
        m_pSerialRadar->write(t_strCmd.c_str(), t_strCmd.length());
        if(m_pSerialRadar->isOpen())
        {
            m_pSerialRadar->clear();
            m_pSerialRadar->close();
        }

        m_bIsReadyDetect = false;
        m_bIsDetect = false;
        emit action_lead(15.0, 0.0);   //转台位置归零
        m_bAngleTo0 = true;
        ui->pushButtonDetect->setText(QStringLiteral("开始测量"));
        m_bIsPressDetect = false;
        return;
    }

    StopRotarythread();
    StartRotarythread();  //启动转台线程，线程定时读取转台位置，释放转台数据更新信号

    OpenRadarPort();  //打开雷达串口
    std::string t_strCmd = "clioutput 31\r\n";
    m_pSerialRadar->write(t_strCmd.c_str(), t_strCmd.length());
    m_pTimerReadRadarData->start(100); //雷达串口开始接接收 100ms定时接收

    ui->pushButtonDetect->setText(QStringLiteral("停止测量"));
    m_bIsPressDetect = true;

    ui->label_CenterAngle->setText("0.0");
    ui->label_18->setText("0.0");
    ui->label_16->setText("0.0");
    ui->label_20->setText("0.0");
    ui->label_27->setText("0.0");
    ui->label_34->setText("0.0");
    ui->label_30->setText("0.0");
    ui->label_35->setText("0.0");

    m_bIsReadyDetect = true;
    QString t_strReadyDetectAngle = "-45.0";  // zxy ui->lineedit_StartAngle->text();
    m_dbStartAngle = t_strReadyDetectAngle.toDouble();
    m_dbStartAngle -= 0.11;
    qDebug() << "StartAngle: " << m_dbStartAngle;
    ui->label_in_status->setText(QStringLiteral("正在转动到俯仰开始角度"));  //zxy

    QString t_strEndAngle = "45.0"; //zxy  ui->lineedit_EndAngle->text();
    m_dbEndAngle = t_strEndAngle.toDouble();
    m_dbEndAngle += 0.11;
    qDebug() << "EndAngle:" << m_dbEndAngle;

    m_dbAngleOfX = qAbs(t_strEndAngle.toDouble()) + qAbs(t_strReadyDetectAngle.toDouble());
    qDebug() << "AngleOfX:" << m_dbAngleOfX;

//    if (m_dbAngleOfX < 1)
//    {
//        QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("起始角度和结束角度设置错误！"));
//        return;
//    }

    m_typeRotary = AT_El;

    emit typechanged(PitchingType);

    while(1)
    {
        AngleType rotaryType;
        emit getRotaryType(rotaryType);

        QThread::msleep(20);
        if(rotaryType == m_typeRotary)
        {
            break;
        }
    }

    emit action_lead(15.0, m_dbStartAngle); //将转台转到测量起始位置（水平或俯仰）

//    qDebug() << "End MainWindow::on_pushButtonDetect_clicked";

}

/*启动转台线程*/
void MainWindow::StartRotarythread(void)
{
    m_rotarythread.start();
}

void MainWindow::StopRotarythread(void)
{
	m_bIsReadyDetect = false;
    m_rotarythread.stop();
    m_rotarythread.terminate();
    m_rotarythread.wait();
}

void MainWindow::radar_adjust_fail_slot(const QString &msg)
{
    ui->label_in_status->setStyleSheet("background-color:red");
    ui->label_in_status->setText(QStringLiteral("雷达校准失败：") + msg);
}

void MainWindow::radar_adjust_success_slot()
{
    ui->label_in_status->setStyleSheet("background-color:rgb(0,170,0)");
    ui->label_in_status->setText(QStringLiteral("雷达校准成功"));
}

void MainWindow::waitUtil(double target, int maxMilliSeconds)
{
//	QElapsedTimer et;
//	et.start();
//    while ((qAbs(m_curRotaryAngle-target)>0.15) && (maxMilliSeconds == -1 || et.elapsed() < maxMilliSeconds) && this->isVisible())
//	{
//        QApplication::processEvents(QEventLoop::AllEvents, 100);
//	}

    Q_UNUSED(maxMilliSeconds);
    while (qAbs(m_curRotaryAngle-target)>0.15)
    {
        QApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::waitUtil(int maxMilliSeconds)
{
    QElapsedTimer et;
    et.start();
    while(et.elapsed() < maxMilliSeconds)
    {
        QApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::detectProcess(double angle)
{
    //set rotary to the second postition
    if(m_curRotaryAngle != angle)
    {
        emit action_lead(m_speed, angle);  //发送信号让转台变换位置
        waitUtil(angle, -1);
    }
    waitUtil(1000);
    //start save data
//    if(m_savedata)
//        emit action_write(true);
//    m_paintRadar = true;
    //wait for 2 seconds
//    waitUtil(2000);
    //stop save data
//    if(m_savedata)
//        emit action_write(false);
//    m_paintRadar = false;
}

void MainWindow::on_actionAbout_A_triggered()
{
    QMessageBox *info = new QMessageBox(this);
    info->setText(QStringLiteral("AIPR@Microbrain.com.cn"));
    info->setWindowTitle(QStringLiteral("关于"));
    //info->setIconPixmap(QPixmap(":/img/Mbit_Logo.png").scaled(QSize(300,150), Qt::KeepAspectRatio));
    info->exec();
}

void MainWindow::save_sate_changed_slot(bool save)
{
    m_savedata = save;
}

void MainWindow::adjust_fail_slot(const QString &msg)
{
    ui->label_in_status->setText(msg);
    ui->label_in_status->setStyleSheet("background-color:red");
}

void MainWindow::adjust_success_slot()
{
    ui->label_in_status->setText(QStringLiteral("measureRangeBiasAndRxChanPhase 成功"));
    ui->label_in_status->setStyleSheet("background-color:rgb(0,170,0)");
}

void MainWindow::judge_qualified_slot(double angle)
{
    ui->label_in_status->setText(QStringLiteral("检测角度 ") + QString::number(angle) + QStringLiteral(" 通过"));
    ui->label_in_status->setStyleSheet("background-color:rgb(0,170,0)");
}

void MainWindow::judge_disqualification(double angle)
{
    ui->label_in_status->setText(QStringLiteral("检测角度 ") + QString::number(angle) + QStringLiteral(" 未通过"));
    ui->label_in_status->setStyleSheet("background-color:red");
}

void MainWindow::standard_distance_changed(double val)
{
    StandR = val;
}

void MainWindow::speed_changed_slot(double val)
{
    m_speed = val;
}

void MainWindow::on_pushButton_refresh_clicked()
{
    ui->label_in_status->setText(QStringLiteral("正在刷新串口"));
//    ui->label_in_status->setMinimumSize(ui->label_in_status->sizeHint());
    dialog->on_pushButton_refresh_clicked();
    ui->label_in_status->setText(QStringLiteral("刷新串口完成"));
}

void MainWindow::slotRotaryAddPort(const QString &t_qstrPort)
{
    ui->comboBoxRotary->addItem(t_qstrPort);
}

/*函数重载 当值变动时自动调用*/
void MainWindow::on_comboBoxRotary_currentIndexChanged(const QString &arg1)
{
    dialog->slotChangeBoxRotaryIndex(arg1);
}

/*函数重载 当值变动时自动调用*/
void MainWindow::slotRadarsAddPort(const QString &t_qstrPort)
{
    ui->comboBoxRadars->addItem(t_qstrPort);
}

/*函数重载 当值变动时自动调用*/
void MainWindow::on_comboBoxRadars_currentIndexChanged(const QString &arg1)
{
    dialog->slotChangeBoxRadarsIndex(arg1);
}

/*函数重载 当值变动时自动调用*/
void MainWindow::on_comboType_currentIndexChanged(const QString &arg1)
{
    if(arg1 == DownType)
    {
//        m_typeRotary = AT_Az;
//        ui->lineedit_StartAngle->setText("-60.0");
//        ui->lineedit_EndAngle->setText("60.0");
    }
    else if(arg1 == PitchingType)
    {
//        m_typeRotary = AT_El;
//        ui->lineedit_StartAngle->setText("-45.0");
//        ui->lineedit_EndAngle->setText("45.0");
    }
    else if(arg1 == RollType)
    {
//        m_typeRotary = AT_Pol;
    }

//    qDebug() << "m_typeRotary: " << m_typeRotary;

//    emit typechanged(arg1);
//    dialog->slotChangeComboType(arg1);
}

void MainWindow::on_lineedit_Speed_textChanged(const QString &arg1)
{
    dialog->slotChangeSpeed(arg1);
}

void MainWindow::on_BtnGenerateReport_clicked()  //zxy
{

//    if(m_typeRotary == AT_El)
//    {
//        QString t_strDefalut;
//        t_strDefalut = m_strStartDetectTime;

//        t_strDefalut.append(".html");

//        QString m_reportFileName = QFileDialog::getSaveFileName(this, tr("Save File"), t_strDefalut, tr("Web(*.html)"));
//        if (m_reportFileName.length() < 1)
//        {
//            return;
//        }
//        qDebug() << "save path:" << m_reportFileName;

//        QString html;
//        saveHtmlToWord(html);
//        QFile outFile(m_reportFileName);
//        outFile.open(QIODevice::WriteOnly | QIODevice::Append );
//        QTextStream ts(&outFile);
//        ts << html;
//    }
//    else
//    {
//         QString html;
//         saveHtmlToWord1(html);
//         QFile outFile(m_reportFileName);
//         QTextStream ts(&outFile);
//         ts << html;
//        QDesktopServices::openUrl(m_reportFileName);
//    }
}

void MainWindow::saveHtmlToWord(QString &html) //zxy
{
    QString t_strTitle = QStringLiteral("雷达转台测试报告");
    QString t_strP1 = QStringLiteral("测试时间：");
    QString t_strP2 = QStringLiteral("雷达类型版本：");

    QString t_strP3 = " ";

    if(m_channel_num == 3)
    {
        t_strP3 = QStringLiteral("俯仰4通道曲线图");
    }

    if(m_channel_num == 7)
    {
        t_strP3 = QStringLiteral("俯仰8通道曲线图");
    }

    if(m_channel_num == 11)
    {
        t_strP3 = QStringLiteral("俯仰12通道曲线图");
    }

    QString t_strP4 = QStringLiteral("俯仰平均值曲线图");
    QString t_strP4_2 = QStringLiteral("俯仰平均值统计图");

    QString t_strP5 = QStringLiteral("俯仰-6dB角度范围");
    QString t_strP6 = QStringLiteral("俯仰-6dB起始角度");
    QString t_strP7 = QStringLiteral("俯仰-6dB结束角度");
    QString t_strP8 = QStringLiteral("俯仰-6dB中心角度");
    QString t_strP9 = QStringLiteral("俯仰-12dB角度范围");
    QString t_strP10 = QStringLiteral("俯仰-12dB起始角度");
    QString t_strP11 = QStringLiteral("俯仰-12dB结束角度");
    QString t_strP12 = QStringLiteral("俯仰-12dB中心角度");
    QString t_strP13 = QStringLiteral("俯仰最大值中心角度");
    QString t_strP14 = QStringLiteral("俯仰最大能量值");

    html += "<html>";
    html += "<head>";
    html += "<head>";
    html += "<body style=\"bgcolor:white\">";
    html += "<h1 style=\"background-color:white\" align=\"center\">";
    html += t_strTitle;
    html += "</h1>";
    html += "<hr>";

    // 测试时间
    html += "<p>";
    html += t_strP1;
    html += m_strStartDetectTime;
    html += "</p>";

    // 雷达类型版本
    html += "<p>";
    html += t_strP2;
    html += ui->label_13->text();
    html += "</p>";

    // 8通道曲线图
    QPixmap pixmap = ui->tab->grab();
    pixmap.save("a1.png");
    QImage img1("a1.png");
    QByteArray ba;
    QBuffer buf(&ba);
    buf.open(QIODevice::WriteOnly);
    img1.save(&buf, "png");
//    qDebug() <<  ba.toBase64();
//    QByteArray ba2 = ba.toBase64();
//    QString b64str = QString::fromLatin1(ba2);
    html += "<p align=\"center\">";
    html += t_strP3;
    html += "</p>";
    html += "<p align=\"center\">";
    html += "<img src=\"data:image/png;base64,";
    html += ba.toBase64();
    html += "\" height=\"658\" width=\"999\">";
    html += "</p>";
    buf.close();

    // 平均值曲线图
    pixmap = ui->tab_2->grab();
    pixmap.save("a2.png");
    QImage img2("a2.png");
    ba.clear();
    buf.open(QIODevice::WriteOnly);
    img2.save(&buf, "png");
    html += "<p align=\"center\">";
    html += t_strP4;
    html += "</p>";
    html += "<p align=\"center\">";
    html += "<img src=\"data:image/png;base64,";
    html += ba.toBase64();
    html += "\" height=\"658\" width=\"999\">";
    html += "</p>";
    buf.close();

    // 平均值统计
    pixmap = ui->widget->grab();
    pixmap.save("a3.png");
    QImage img3("a3.png");
    ba.clear();
    buf.open(QIODevice::WriteOnly);
    img3.save(&buf, "png");
    html += "<p align=\"center\">";
    html += t_strP4_2;
    html += "</p>";
    html += "<p align=\"center\">";
    html += "<img src=\"data:image/png;base64,";
    html += ba.toBase64();
    html += "\">";
    html += "</p>";
    buf.close();

    html += "<table border=\"1\">";
    html += "<tr>";

    html += "<th>";
    html += t_strP5;
    html += "</th>";
    html += "<th>";
    html += t_strP6;
    html += "</th>";
    html += "<th>";
    html += t_strP7;
    html += "</th>";
    html += "<th>";
    html += t_strP8;
    html += "</th>";
    html += "<th>";
    html += t_strP9;
    html += "</th>";
    html += "<th>";
    html += t_strP10;
    html += "</th>";
    html += "<th>";
    html += t_strP11;
    html += "</th>";
    html += "<th>";
    html += t_strP12;
    html += "</th>";
    html += "<th>";
    html += t_strP13;
    html += "</th>";
    html += "<th>";
    html += t_strP14;
    html += "</th>";

    html += "</tr>";

    html += "<tr>";

    html += "<td align='center'>";
    html += m_str6Range;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str6Statrt;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str6End;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str6Center;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12Range;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12Statrt;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12End;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12Center;
    html += "</td>";

    html += "<td align='center'>";
    html += m_strMaxPeakAngle;
    html += "</td>";

    html += "<td align='center'>";
//    html += m_strMaxPeak + "(" + m_strMaxLogPeak + ")";
    html += m_strMaxLogPeak;
    html += "</td>";

    html += "</tr>";
    html += "</table>";

    html += "<hr>";
    html += "</body>";
    html += "</html>";
}

void MainWindow::saveHtmlToWord1(QString &html)  //zxy
{
    QString t_strTitle = QStringLiteral("雷达转台测试报告");
    QString t_strP1 = QStringLiteral("测试时间：");
    QString t_strP2 = QStringLiteral("雷达类型版本：");

    QString t_strP3 = " ";

    if(m_channel_num == 3)
    {
        t_strP3 = QStringLiteral("水平4通道曲线图");
    }

    if(m_channel_num == 7)
    {
        t_strP3 = QStringLiteral("水平8通道曲线图");
    }

    if(m_channel_num == 11)
    {
        t_strP3 = QStringLiteral("水平12通道曲线图");
    }

//    QString t_strP3 = QStringLiteral("水平8通道曲线图");
    QString t_strP4 = QStringLiteral("水平平均值曲线图");
    QString t_strP4_2 = QStringLiteral("水平平均值统计图");

    QString t_strP5 = QStringLiteral("水平-6dB角度范围");
    QString t_strP6 = QStringLiteral("水平-6dB起始角度");
    QString t_strP7 = QStringLiteral("水平-6dB结束角度");
    QString t_strP8 = QStringLiteral("水平-6dB中心角度");
    QString t_strP9 = QStringLiteral("水平-12dB角度范围");
    QString t_strP10 = QStringLiteral("水平-12dB起始角度");
    QString t_strP11 = QStringLiteral("水平-12dB结束角度");
    QString t_strP12 = QStringLiteral("水平-12dB中心角度");
    QString t_strP13 = QStringLiteral("水平最大值中心角度");
    QString t_strP14 = QStringLiteral("水平最大能量值");

    html += "<html>";
    html += "<head>";
    html += "<head>";
    html += "<body style=\"bgcolor:white\">";
    html += "<h1 style=\"background-color:white\" align=\"center\">";
    html += t_strTitle;
    html += "</h1>";
    html += "<hr>";

    // 测试时间
    html += "<p>";
    html += t_strP1;
    html += m_strStartDetectTime;
    html += "</p>";

    // 雷达类型版本
    html += "<p>";
    html += t_strP2;
    html += ui->label_13->text();
    html += "</p>";

    // 8通道曲线图
    QPixmap pixmap = ui->tab->grab();
    pixmap.save("a1.png");
    QImage img1("a1.png");
    QByteArray ba;
    QBuffer buf(&ba);
    buf.open(QIODevice::WriteOnly);
    img1.save(&buf, "png");
//    qDebug() <<  ba.toBase64();
//    QByteArray ba2 = ba.toBase64();
//    QString b64str = QString::fromLatin1(ba2);
    html += "<p align=\"center\">";
    html += t_strP3;
    html += "</p>";
    html += "<p align=\"center\">";
    html += "<img src=\"data:image/png;base64,";
    html += ba.toBase64();
    html += "\" height=\"658\" width=\"999\">";
    html += "</p>";
    buf.close();

    // 平均值曲线图
    pixmap = ui->tab_2->grab();
    pixmap.save("a2.png");
    QImage img2("a2.png");
    ba.clear();
    buf.open(QIODevice::WriteOnly);
    img2.save(&buf, "png");
    html += "<p align=\"center\">";
    html += t_strP4;
    html += "</p>";
    html += "<p align=\"center\">";
    html += "<img src=\"data:image/png;base64,";
    html += ba.toBase64();
    html += "\" height=\"658\" width=\"999\">";
    html += "</p>";
    buf.close();

    // 平均值统计
    pixmap = ui->widget->grab();
    pixmap.save("a3.png");
    QImage img3("a3.png");
    ba.clear();
    buf.open(QIODevice::WriteOnly);
    img3.save(&buf, "png");
    html += "<p align=\"center\">";
    html += t_strP4_2;
    html += "</p>";
    html += "<p align=\"center\">";
    html += "<img src=\"data:image/png;base64,";
    html += ba.toBase64();
    html += "\">";
    html += "</p>";
    buf.close();

    html += "<table border=\"1\">";
    html += "<tr>";

    html += "<th>";
    html += t_strP5;
    html += "</th>";
    html += "<th>";
    html += t_strP6;
    html += "</th>";
    html += "<th>";
    html += t_strP7;
    html += "</th>";
    html += "<th>";
    html += t_strP8;
    html += "</th>";
    html += "<th>";
    html += t_strP9;
    html += "</th>";
    html += "<th>";
    html += t_strP10;
    html += "</th>";
    html += "<th>";
    html += t_strP11;
    html += "</th>";
    html += "<th>";
    html += t_strP12;
    html += "</th>";
    html += "<th>";
    html += t_strP13;
    html += "</th>";
    html += "<th>";
    html += t_strP14;
    html += "</th>";

    html += "</tr>";

    html += "<tr>";

    html += "<td align='center'>";
    html += m_str6Range;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str6Statrt;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str6End;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str6Center;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12Range;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12Statrt;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12End;
    html += "</td>";

    html += "<td align='center'>";
    html += m_str12Center;
    html += "</td>";

    html += "<td align='center'>";
    html += m_strMaxPeakAngle;
    html += "</td>";

    html += "<td align='center'>";
//    html += m_strMaxPeak + "(" + m_strMaxLogPeak + ")";
    html += m_strMaxLogPeak;
    html += "</td>";

    html += "</tr>";
    html += "</table>";

    html += "<hr>";
    html += "</body>";
    html += "</html>";
}
