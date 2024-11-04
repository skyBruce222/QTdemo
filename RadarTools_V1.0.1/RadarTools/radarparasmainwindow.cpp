#include "radarparasmainwindow.h"
#include "ui_radarparasmainwindow.h"
#include <QSettings>
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>

radarParasMainWindow::radarParasMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::radarParasMainWindow)
{
    ui->setupUi(this);
    initRadarParasWindow();
}

radarParasMainWindow::~radarParasMainWindow()
{
    delete ui;
}

void radarParasMainWindow::initRadarParasWindow(){
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
    setWindowTitle(tr("雷达参数设置"));
    setWindowIcon(QIcon(":/img/dragonbool.jpg"));

    QSettings setting("./Setting.ini", QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QString lang = setting.value("login/language").toString();
    if (lang.isEmpty()){
        switchLanguage("中文");
    } else{
        switchLanguage(lang);
    }
}

void radarParasMainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("0");
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_6->setChecked(false);
    ui->comboBox->setCurrentIndex(1);
    ui->comboBox_5->setCurrentIndex(-1);
}

void radarParasMainWindow::on_pushButton_3_clicked()
{
    //read radar parameters
    if (connectFlag){
        emit readParasSig();
    } else {
        if (languageFlag)
            QMessageBox::information(this,"提示","请先连接设备！");
        else
            QMessageBox::information(this,"System Prompt","Please connect your device first!");
    }
}

void radarParasMainWindow::on_pushButton_2_clicked()
{
    //set radar parameters
    if (connectFlag){
        unsigned char data[8];
        data[0] = 0xff;
        data[1] = 0x00;
        data[2] = 0x02;
        data[3] = 0x00;
        data[4] = (ui->lineEdit->text().toUInt()&0x07);
        data[5] = 0x00;
        data[6] = 0x00;
        data[7] = 0x10;
        if (ui->comboBox_5->currentText() == "250Kbps"){
            data[7] = 0x30;
        } else if (ui->comboBox_5->currentText() == "500Kbps"){
            data[7] = 0x10;
        } else {
            data[7] = 0x50;
        }

        emit setParasSig(data,8);
    } else {
        if (languageFlag)
            QMessageBox::information(this,"提示","请先连接设备！");
        else
            QMessageBox::information(this,"System Prompt","Please connect your device first!");
    }
}

void radarParasMainWindow::radarDataRespond(unsigned char id, unsigned char mode, unsigned char baud){
    qDebug()<<id<<mode<<baud;
}

void radarParasMainWindow::connectSucceedSlot(bool flag){
    connectFlag = flag;
}

void radarParasMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void radarParasMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        setWindowTitle(tr("雷达参数设置"));
        ui->checkBox->setText("雷 达  ID");
        ui->checkBox_2->setText("雷达模式");
        ui->checkBox_6->setText("波 特 率");
        ui->pushButton->setText("默认");
        ui->pushButton_2->setText("应用");
        ui->pushButton_3->setText("读取");
        languageFlag = true;
    } else {
        setWindowTitle(tr("Radar Paras Set"));
        ui->checkBox->setText("Radar ID");
        ui->checkBox_2->setText("Radar Mode");
        ui->checkBox_6->setText("Baudrate");
        ui->pushButton->setText("Default");
        ui->pushButton_2->setText("Save");
        ui->pushButton_3->setText("Read");
        languageFlag = false;
    }
}
