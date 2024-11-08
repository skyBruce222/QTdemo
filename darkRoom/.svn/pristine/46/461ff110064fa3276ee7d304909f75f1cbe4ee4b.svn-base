#include "controldlg.h"
#include "ui_controldlg.h"
#include <QRegExp>
#include <QApplication>
#include <QPainter>
#include <QDesktopWidget>
#include "Spcomm.h"
#include <QDebug>

controldlg::controldlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    setWindowFlag(Qt::FramelessWindowHint);

    initTitleBar();
}

void controldlg::initTitleBar()
{
    m_titleBar = new MyTitleBar(this);
    m_titleBar->move(0, 0);

    m_titleBar->setTitleIcon(":/img/mbit.ico");
    m_titleBar->setTitleContent(QStringLiteral(" 配置"));
    m_titleBar->setButtonType(MIN_BUTTON);
    m_titleBar->setBackgroundColor(65, 65, 65, false);

    connect(m_titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(m_titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

void controldlg::onButtonMinClicked()
{
    showMinimized();
}

void controldlg::onButtonRestoreClicked()
{
    QPoint windowPos;
    QSize windowSize;
    m_titleBar->getRestoreInfo(windowPos, windowSize);
    this->setGeometry(QRect(windowPos, windowSize));
}

void controldlg::onButtonMaxClicked()
{
    m_titleBar->saveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
    setGeometry(FactRect);
}

void controldlg::onButtonCloseClicked()
{
    close();
}

controldlg::~controldlg()
{
    delete ui;
}


void controldlg::availableportnameslot(QList<QString> ports)
{
    QString port;
    QRegExp rx(".*MOXA.*");
    foreach(port, ports)
    {
        if(rx.exactMatch(port))
        {
            if(port.contains("12"))
            {
                ui->comboBoxRotary->addItem(port);
                emit sinalRotaryAddPort(port);
            }
        }
        else
        {
            ui->comboBoxRadars->addItem(QString(port));
            emit sinalRadarsAddPort(port);
        }
    }
}

void controldlg::on_comboBoxRadars_currentIndexChanged(const QString &selected)
{
//    emit RadarSerialChanged(selected.mid(0, selected.indexOf("  ")), 115200, 8, 1, 0);

//    emit radar_reselect();
}

void controldlg::slotChangeBoxRotaryIndex(const QString &arg1)
{
    ui->comboBoxRotary->setCurrentText(arg1);
}

void controldlg::slotChangeBoxRadarsIndex(const QString &arg1)
{
    ui->comboBoxRadars->setCurrentText(arg1);
}

void controldlg::on_comboBoxRotary_currentIndexChanged(const QString &selected)
{
    qDebug() << "restart Rotary thread.";
    emit RotarySerialChanged(selected.mid(0, selected.indexOf("  ")), 38400, 8, 1, 0);

    emit rotary_reselect();
}

void controldlg::slotChangeComboType(const QString &arg1)
{
    ui->comboType->setCurrentText(arg1);
}

void controldlg::on_comboType_currentIndexChanged(const QString &selected)
{
    emit typechanged(selected);
}

void controldlg::on_buttonCw_clicked()
{
    emit action_cw(ui->lineedit_Speed->text().toFloat(), ui->lineedit_position->text().toFloat());
}

void controldlg::on_pushButton_Ccw_clicked()
{
    emit action_ccw(ui->lineedit_Speed->text().toFloat(), ui->lineedit_position->text().toFloat());
}

void controldlg::on_pushButton_lead_clicked()
{
    emit action_lead(ui->lineedit_Speed->text().toFloat(), ui->lineedit_position->text().toFloat());
}

void controldlg::on_pushButton_reset_clicked()
{
    emit action_reset();
}

void controldlg::on_pushButton_calibration_clicked()
{
    emit action_calibration(ui->lineedit_position->text().toFloat());
}


void controldlg::on_pushButton_stop_clicked()
{
    emit action_stop();
}

void controldlg::RotarySerialDataRechSlot(double val1, double val2, double val3)
{
    switch(ui->comboType->currentIndex())
    {
    case 0:
        ui->lcdNumber->display(val1);
        break;
    case 1:
        ui->lcdNumber->display(val2);
        break;
    case 2:
        ui->lcdNumber->display(val3);
        break;
    default:
        ui->lcdNumber->display(0);
        break;
    }
}


void controldlg::on_pushButton_refresh_clicked()
{
    availableportnameslot(SPComm::getAvailablePort());
}

void controldlg::on_pushButton_output_clicked()
{
    emit action_output_changed(true);
}

void controldlg::on_pushButton_noput_clicked()
{
    emit action_output_changed(false);
}

void controldlg::on_lineEdit_radarID_textChanged(const QString &arg1)
{
    emit radarid_changed(arg1);
}

void controldlg::on_lineEdit_precision_textChanged(const QString &arg1)
{
    emit precision_changed(arg1.toDouble());
}

void controldlg::on_checkBox_saveData_stateChanged(int checked)
{
    if(checked)
        emit save_state_changed(true);
    else {
        emit save_state_changed(false);
    }
}

void controldlg::on_lineEdit_distance_textChanged(const QString &arg1)
{
    emit distance_changed(arg1.toDouble());
}

void controldlg::slotChangeSpeed(const QString &arg1)
{
    ui->lineedit_Speed->setText(arg1);
}

void controldlg::slotChangePosition(const QString &arg1)
{
    ui->lineedit_position->setText(arg1);
}

void controldlg::on_lineedit_Speed_textChanged(const QString &arg1)
{
    emit speed_changed(arg1.toDouble());
}

void controldlg::send_uid_slot(QString uid)
{
    ui->lineEdit_radarID->setText(uid);
}

void controldlg::on_pushButton_uid_clicked()
{
    emit action_get_uid();
}
