#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "serialthread.h"
#include "serialworkerthread.h"
#include <memory>
#include <QProgressDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}
class QSerialPort;
class SerialThread;
class QProgressDialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Sleep(int msec);
    void firmbinupdate();
    uint8_t crc8(const QByteArray &data, int32_t len);
    float   parseValueFloat(QByteArray data,  int valuePos, int valueSize);
    quint32 parseValueUint32(QByteArray data, int valuePos, int valueSize);
    quint16 parseValueUint16(QByteArray data, int valuePos, int valueSize);
    qint16  parseValueInt16(QByteArray data, int valuePos, int valueSize);

    //字符串转16进制
     QByteArray QString2Hex(QString str);
      //字符转16进制
     char ConvertHexChar(char ch);
     QProgressDialog  *progressdlgupdate;
//     void hexcmd(QByteArray hexdata);

private slots:
    void on_openbin_pushButton_clicked();
    void showValidPort();

    void on_run_pushButton_clicked();

   // void on_pause_pushButton_clicked();



    void on_send_pushButton_clicked();


//    void mySlot(int x);

    void on_showvar(QString);
    void on_showvar2(QString);
    void on_showvar3(QString);
    void on_showvar4(QString);
    void on_showvar5(QString);
    void on_showvar6(QString);
    void on_showvar7(QString);
    void on_showvar8(QString);
    void on_showprogressslot(int);
    void on_showprogressslot2(int);
    void on_showprogressslot3(int);
    void on_showprogressslot4(int);
    void on_showprogressslot5(int);
    void on_showprogressslot6(int);
    void on_showprogressslot7(int);
    void on_showprogressslot8(int);

    void on_showBurnStatus(QString);
    void on_showBurnStatus_2(QString);
    void on_showBurnStatus_3(QString);
    void on_showBurnStatus_4(QString);
    void on_showBurnStatus_5(QString);
    void on_showBurnStatus_6(QString);
    void on_showBurnStatus_7(QString);
    void on_showBurnStatus_8(QString);

//    void on_comboBox_currentTextChanged(const QString &arg1);


    void on_pushButton_updateUart_clicked();

    //void on_comboBox_uartNumber_activated(const QString &arg1);

    void on_comboBox_uartNumber_activated(const QString &arg1);

    void on_comboBox_uartNumber_2_activated(const QString &arg1);

    void on_comboBox_uartNumber_3_activated(const QString &arg1);

    void on_comboBox_uartNumber_4_activated(const QString &arg1);

    void on_comboBox_uartNumber_5_activated(const QString &arg1);

    void on_comboBox_uartNumber_6_activated(const QString &arg1);

    void on_comboBox_uartNumber_7_activated(const QString &arg1);

    void on_comboBox_uartNumber_8_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *serialRead;
    QByteArray dataBuffer;
    QByteArray dataBufferrevsave, dataBufferrevsave2,dataBufferrevsave3,dataBufferrevsave4,dataBufferrevsave5,dataBufferrevsave6,dataBufferrevsave7,dataBufferrevsave8;
//    SerialThread *mthread,*mthread2;
//    ,*mthread3,*mthread4,*mthread5,*mthread6,*mthread7,*mthread8;
    void OpenRadarPort(void);// 打开雷达串口
    QThread *mthread,*mthread2,*mthread3,*mthread4,*mthread5,*mthread6,*mthread7,*mthread8;
    Serialworkerthread *mSerial_worker,*mSerial_worker2,*mSerial_worker3,*mSerial_worker4,*mSerial_worker5,*mSerial_worker6,*mSerial_worker7,*mSerial_worker8;

    void uart_thread_close(void); //关闭串口线程

    void sensorstop(void);// 停止雷达
    void softreset(void);// 重启
    void softresetF9(void);// 重启
    void updatemode(void);// 进入升级模式
    void updatetest(void);//升级测试
    void updateerasuse(void);// 擦除FLASH
    void sendbinsize(int);//发送固件大小
    void sendbindate(int framecount);
    void updatebin(void);
    void sendserialcmd(QByteArray);
    void hexdataParse(QByteArray);
    void checkparams();//参数校验
    void readvar();
    void setLED(QLabel* label, int color, int size);
    void statusDisplayInit(void);
    void updataSerailPort();

    void comboxClickTrigger(QString portNum);
    void comboxClickTrigger2(QString portNum);
    void comboxClickTrigger3(QString portNum);
    void comboxClickTrigger4(QString portNum);
    void comboxClickTrigger5(QString portNum);
    void comboxClickTrigger6(QString portNum);
    void comboxClickTrigger7(QString portNum);
    void comboxClickTrigger8(QString portNum);
signals:
    void close_serial();
    void write_serial(QByteArray);
    void sendtoserial(QByteArray);
    void firmupdatesignals(QByteArray,int);
    void closeserial();
    void openserial();
//    changebaudrate(int);
    void readcli();
//     void mySignal(int x);
//    void senddatabin(int x);

};

#endif // MAINWINDOW_H
