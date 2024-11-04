#include "radartoolsyssetmainwindow.h"
#include "ui_radartoolsyssetmainwindow.h"
#include <QIntValidator>
#include <QTextCodec>
#include <QSettings>
#include <QMessageBox>
#include <QDebug>

radarToolSysSetMainWindow::radarToolSysSetMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::radarToolSysSetMainWindow)
{
    ui->setupUi(this);
    iniToolSysSetWindow();

}

radarToolSysSetMainWindow::~radarToolSysSetMainWindow()
{
    delete ui;
}


void radarToolSysSetMainWindow::iniToolSysSetWindow(){
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
    setWindowTitle(tr("修改系统密码"));
    setWindowIcon(QIcon(":/img/dragonbool.jpg"));

    ui->lineEdit->setEchoMode(QLineEdit::Password);//采用密码形式显示
    ui->lineEdit->setValidator(new QIntValidator(this));//确保输入密码为纯数字形式
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);//采用密码形式显示
    ui->lineEdit_2->setValidator(new QIntValidator(this));//确保输入密码为纯数字形式
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);//采用密码形式显示
    ui->lineEdit_3->setValidator(new QIntValidator(this));//确保输入密码为纯数字形式


    QSettings setting("./Setting.ini", QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QString lang = setting.value("login/language").toString();
    if (lang.isEmpty()){
        switchLanguage("中文");
    } else{
        switchLanguage(lang);
    }
}

void radarToolSysSetMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void radarToolSysSetMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        ui->label->setText("当前密码");
        ui->label_2->setText("修改密码");
        ui->label_3->setText("确认密码");
        ui->pushButton->setText("修改");
        setWindowTitle(tr("修改系统密码"));
        languageSwitch = false;
    } else {
        ui->label->setText("Current password");
        ui->label_2->setText("Change Password");
        ui->label_3->setText("Confirm Password");
        ui->pushButton->setText("Save");
        setWindowTitle(tr("Change the system password"));
        languageSwitch = true;
    }
}


void radarToolSysSetMainWindow::on_pushButton_clicked()
{
    QString passwd = ui->lineEdit->text();
    QSettings setting("./Setting.ini", QSettings::IniFormat); // 打开ini文件
    setting.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
    QStringList nameLockList = setting.childGroups(); // 获得ini文件的所有组
    //qDebug()<<nameLockList[1];
    setting.beginGroup(nameLockList[0]); // 选择账号密码那组
    bool islogin = false; // 用来查验账号密码是否正确

    foreach(QString key, setting.childKeys()) // 遍历账号密码那组
    {
        if ((QString::fromUtf8(setting.value(key).toByteArray()) == passwd)) // 查验输入的账号密码和文件里的账号密码是否有对应的
        {
            islogin = true; // 如果遍历到有就改变标志位并退出
            break;
        }
    }

    if (islogin){
        if (ui->lineEdit_2->text() == ui->lineEdit_3->text()){
             QSettings writeini("./Setting.ini", QSettings::IniFormat); // 打开ini文件
             writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
             writeini.setValue("login/username", "admin"); // 把账号写入ini文件
             writeini.setValue("login/password", ui->lineEdit_2->text()); // 把密码写入ini文件
             writeini.setValue("login_name/admin",ui->lineEdit_2->text());
             if (languageSwitch){
                  QMessageBox::information(this, tr("System Prompts"), tr("The modification was successful"));
             } else {
                  QMessageBox::information(this, tr("提示"), tr("修改成功"));
             }

             emit closeSysWin();
             this->close();
        }
        else {
            if (languageSwitch){
                 QMessageBox::information(this, tr("System Prompts"), tr("The password is not the same twice, please re-enter it"));
            } else {
                QMessageBox::information(this, tr("提示"), tr("两次密码不一样，请重新输入"));
            }
        }
    } else {
        if (languageSwitch){
             QMessageBox::information(this, tr("System Prompts"), tr("The current password is incorrect"));
        } else {
            QMessageBox::information(this, tr("提示"), tr("当前密码不正确"));
        }
    }
}
