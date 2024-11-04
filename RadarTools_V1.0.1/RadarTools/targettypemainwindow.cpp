#include "targettypemainwindow.h"
#include "ui_targettypemainwindow.h"
#include <QTextCodec>
#include <QSettings>

targetTypeMainWindow::targetTypeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::targetTypeMainWindow)
{
    ui->setupUi(this);
    initTargetTypeWindow();
}

targetTypeMainWindow::~targetTypeMainWindow()
{
    delete ui;
}

void targetTypeMainWindow::initTargetTypeWindow(){
    setWindowTitle(tr("目标汇总"));
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
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

void targetTypeMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void targetTypeMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        setWindowTitle(tr("目标汇总"));
        ui->groupBox->setTitle("目标状态");
        ui->groupBox_2->setTitle("目标类型（仅参考）");
        ui->pushButton->setText("应用");
    } else {
        setWindowTitle(tr("Objective Summary"));
        ui->groupBox->setTitle("Target State");
        ui->groupBox_2->setTitle("Target Type(Refernce Only)");
        ui->pushButton->setText("Save");
    }
}

void targetTypeMainWindow::on_pushButton_clicked()
{
    //un know
}
