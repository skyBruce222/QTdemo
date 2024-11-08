#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "serialgetevent.h"
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void onComboBoxPopupShown_1();

    void onComboBoxPopupShown_2();

private:
    Ui::MainWindow *ui;

    //初始化widget1与widget2为Qchart界面
    QChart  chart1,chart2;
    QValueAxis  axisX,axisXAvg;
    QValueAxis  axisY,axisYAvg;
    QLineSeries lineSeries1;
    QLineSeries lineSeries2;
    QLineSeries lineSeries3;
    QLineSeries lineSeries4;
    QLineSeries lineSeries5;
    QLineSeries lineSeries6;
    QLineSeries lineSeries7;
    QLineSeries lineSeries8;
    QLineSeries lineSeries9;
    QLineSeries lineSeries10;
    QLineSeries lineSeries11;
    QLineSeries lineSeries12;
    QLineSeries lineSeriesAvg;
    QScatterSeries lineSeriesAvgTip;

    //combobox下拉刷新串口
    serialGetEvent *eventFilter;
    serialGetEvent *eventFilter2;

    //串口列表
    QStringList PortStringList;

    void initMainWindow();
    void initCharts();
};
#endif // MAINWINDOW_H
