#include "collisionareamainwindow.h"
#include "ui_collisionareamainwindow.h"
#include <QSettings>
#include <QTextCodec>

collisionAreaMainWindow::collisionAreaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::collisionAreaMainWindow)
{
    ui->setupUi(this);
    initCollisionAreaWindow();
}

collisionAreaMainWindow::~collisionAreaMainWindow()
{
    delete ui;
}


void collisionAreaMainWindow::initCollisionAreaWindow(){
    setWindowTitle(tr("碰撞区域（非汽车用途设计）"));
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

void collisionAreaMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void collisionAreaMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        setWindowTitle(tr("碰撞区域（非汽车用途设计）"));
        ui->pushButton->setText("清除区域");
        ui->pushButton_2->setText("应用");

    } else {
        setWindowTitle(tr("Collision Area Setting(Non Automobile Use Design)"));
        ui->pushButton->setText("Clear Area");
        ui->pushButton_2->setText("Save");
    }
}

void collisionAreaMainWindow::on_pushButton_clicked()
{
    //
}

void collisionAreaMainWindow::on_pushButton_2_clicked()
{
    //set collDetRegCfg
    //0x402
}
