#include "textsetmainwindow.h"
#include "ui_textsetmainwindow.h"
#include <QDebug>
#include <QTextCodec>
#include <QSettings>


textSetMainWindow::textSetMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::textSetMainWindow)
{
    ui->setupUi(this);
    initTextSetWindow();
}

textSetMainWindow::~textSetMainWindow()
{
    delete ui;
}

void textSetMainWindow::initTextSetWindow(){
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
    setWindowTitle(tr("保存文本类型配置"));
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

void textSetMainWindow::on_pushButton_clicked()
{
    bool Angle = false,Range = false,Velocity = false ,RCS = false,Sate = false, Class = false;
    //
    if (ui->checkBox->isChecked()){
        Angle = true;
    }
    if (ui->checkBox_2->isChecked()){
        Range = true;
    }
    if (ui->checkBox_3->isChecked()){
        Velocity = true;
    }
    if (ui->checkBox_4->isChecked()){
        RCS = true;
    }
    if (ui->checkBox_5->isChecked()){
        Sate = true;
    }
    if (ui->checkBox_6->isChecked()){
        Class = true;
    }
    emit textTypeSig(Angle,Range,Velocity,RCS,Sate,Class);
    this->close();
}

void textSetMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void textSetMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        setWindowTitle(tr("保存文本类型配置"));
        ui->pushButton->setText("应用");
    } else {
        setWindowTitle(tr("Save the text type configuration"));
        ui->pushButton->setText("Save");
    }
}
