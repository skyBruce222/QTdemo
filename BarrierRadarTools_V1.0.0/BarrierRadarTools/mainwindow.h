#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "serialgetevent.h"
#include "setradarwindow.h"
#include <QTime>
#include <QTimer>

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
    void onComboBoxPopupShown();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void SerialReadDataSlot();

    void updateTime();

    void showMainWindow();

private:
    Ui::MainWindow *ui;

    //combobox下拉刷新串口
    serialGetEvent *eventFilter;
    //串口列表
    QStringList PortStringList;

    setRadarWindow setRadarWin;

    QSerialPort *serialPort;//定义串口指针
    //bool connectRadar = false;
    uint16_t timeOutCnt = 0;
    bool connectRadarClick = false;
    void initWindow();
signals:
    void serialPortNameSig(QString, int);
};
#endif // MAINWINDOW_H
