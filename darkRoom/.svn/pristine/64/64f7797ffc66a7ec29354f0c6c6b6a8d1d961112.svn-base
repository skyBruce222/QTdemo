#ifndef CONTROLDLG_H
#define CONTROLDLG_H

#include <QDialog>
#include "MyTitlebar.h"

namespace Ui {
class Dialog;
}

class controldlg : public QDialog
{
    Q_OBJECT

public:
    explicit controldlg(QWidget *parent = nullptr);
    ~controldlg();

public slots:
    void availableportnameslot(QList<QString> ports);
    void RotarySerialDataRechSlot(double val1, double val2, double val3);
    void send_uid_slot(QString uid);

    void slotChangeBoxRotaryIndex(const QString &arg1);
    void slotChangeBoxRadarsIndex(const QString &arg1);
    void slotChangeComboType(const QString &arg1);
    void slotChangeSpeed(const QString &arg1);
    void slotChangePosition(const QString &arg1);

signals:
    void action_cw(float spd, float target);
    void action_ccw(float spd, float target);
    void action_stop();
    void action_reset();
    void action_lead(float spd, float target);
    void action_calibration(float target);
    void typechanged(const QString& type);

    void radar_reselect();
    void rotary_reselect();
    void RadarSerialChanged(const QString &portname, int baudrate, int databits, int stopbits, int parity);
    void RotarySerialChanged(const QString &portname, int baudrate, int databits, int stopbits, int parity);

    void availableportdetect();

    void save_state_changed(bool tosave);
    void precision_changed(double pricision);
    void radarid_changed(const QString &id);
    void action_output_changed(bool output);
    void distance_changed(double distance);
    void speed_changed(double speed);

    void action_get_uid();

    void sinalRotaryAddPort(const QString &t_qstrPort);
    void sinalRadarsAddPort(const QString &t_qstrPort);

public slots:
    void on_comboBoxRadars_currentIndexChanged(const QString &selected);

    void on_comboBoxRotary_currentIndexChanged(const QString &selected);

    void on_comboType_currentIndexChanged(const QString &arg1);

    void on_buttonCw_clicked();

    void on_pushButton_Ccw_clicked();

    void on_pushButton_lead_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_calibration_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_refresh_clicked();

private:
    void initTitleBar();

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

    void on_pushButton_output_clicked();

    void on_pushButton_noput_clicked();

    void on_lineEdit_radarID_textChanged(const QString &arg1);

    void on_lineEdit_precision_textChanged(const QString &arg1);

    void on_checkBox_saveData_stateChanged(int checked);

    void on_lineEdit_distance_textChanged(const QString &arg1);

    void on_lineedit_Speed_textChanged(const QString &arg1);

    void on_pushButton_uid_clicked();

protected:
    MyTitleBar* m_titleBar;

private:
    Ui::Dialog *ui;
};

#endif // CONTROLDLG_H
