#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QTranslator>
#include <QFile>
#include <QSettings>
#include <QTextCodec>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
    actionEventHandle();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initMainWindow()
{
    setWindowTitle(tr("Radar Tools V1.0"));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(this->width(),this->height());//禁止放大
    //ui->centralwidget->setObjectName("mainWidget");
    //ui->centralwidget->setStyleSheet("background-color:#d3d7d4;");//设置背景色
    //ui->centralwidget->setStyleSheet("#mainWidget{background-color:#d3d7d4;}");
    ui->passwordLineEdit->setValidator(new QIntValidator(this));//确保输入密码为纯数字形式
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);//采用密码形式显示
    ui->passwordLineEdit->setStyleSheet("width:200px;");
    ui->rememberPasswordCheckBox->setCheckState(Qt::Checked);//默认勾选记住密码

    setWindowIcon(QIcon(":/img/dragonbool.jpg"));

    QSettings setting("./Setting.ini", QSettings::IniFormat);  //QSettings能记录一些程序中的信息，下次再打开时可以读取出来
    setting.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式，因为我这里有中文，读和写的时候都要保持一致
    QString isremember = setting.value("login/isremember").toString(); // 是否选择了记住密码
    QString name = QString::fromUtf8(setting.value("login/username").toByteArray()); // 账号
    QString lock = setting.value("login/password").toString(); // 密码
    if (!name.isEmpty())
        ui->usernameLineEdit->setText(name); // 显示上一次登录的账号名
    QString lang = setting.value("login/language").toString();
    if (lang.isEmpty()){
        switchLanguage("中文");
        ui->usernameLineEdit->setPlaceholderText("用户名");
        ui->passwordLineEdit->setPlaceholderText("请输入1至6位数字");
    } else{
        switchLanguage(lang);
        if (lang == "中文"){
            ui->usernameLineEdit->setPlaceholderText("用户名");
            ui->passwordLineEdit->setPlaceholderText("请输入1至6位数字");
        }else{
            ui->usernameLineEdit->setPlaceholderText("Uset name");
            ui->passwordLineEdit->setPlaceholderText("Enter 1 to 6 digits");
        }
    }

    if (isremember == "true") // 记住密码
    {
        ui->passwordLineEdit->setText(lock); // 密码写在密码输入框
        ui->rememberPasswordCheckBox->setChecked(true); // 记住密码那里打√
        rememberPasswd = true; // 记住密码
    }
    else
    {
        ui->rememberPasswordCheckBox->setChecked(false); // 记住密码那里不打√
        rememberPasswd = false; // 不记住密码
    }

    connect(this,&MainWindow::switchLanguageSig, &radarSetWin, &radarSetMainWindow::switchLanguageSlot);
    connect(&radarSetWin,&radarSetMainWindow::setSwitchLanguageSig, this, &MainWindow::switchLanguageSlot);
}

void MainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void MainWindow::actionEventHandle(){
    connect(ui->actionen, &QAction::triggered, this, [this](){
        QSettings writeini("./Setting.ini", QSettings::IniFormat); // 打开ini文件
        writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
        writeini.setValue("login/language", "English"); // 写ini文件时记录为false
        switchLanguage("English");
        emit switchLanguageSig("English");
    });
    connect(ui->actionch, &QAction::triggered, this, [this](){
        QSettings writeini("./Setting.ini", QSettings::IniFormat); // 打开ini文件
        writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
        writeini.setValue("login/language", "中文"); // 写ini文件时记录为false
        switchLanguage("中文");
        emit switchLanguageSig("中文");
    });
}

void MainWindow::switchLanguage(const QString &lang){
    if (lang == "中文"){
        languageSwitch = false;
        ui->menu->setTitle(tr("语言"));
        ui->actionch->setText(tr("中文"));
        ui->usernameLabel->setText(tr("用户名"));
        ui->passwordLabel->setText(tr("密  码"));
        ui->rememberPasswordCheckBox->setText(tr("记住密码"));
        ui->loginPushButton->setText(tr("登录"));
    } else {
        languageSwitch = true;
        ui->menu->setTitle(tr("Language"));
        ui->actionch->setText(tr("中文"));
        ui->usernameLabel->setText(tr("Username"));
        ui->passwordLabel->setText(tr("Password"));
        ui->rememberPasswordCheckBox->setText(tr("Remember Password"));
        ui->loginPushButton->setText(tr("Login"));
    }
}

void MainWindow::on_loginPushButton_clicked()
{
       QString textname = ui->usernameLineEdit->text(); // 获得输入的账号
       QString textpassword = ui->passwordLineEdit->text(); // 获得输入的密码

       //QFile fileInfo("./Setting.ini");
       QSettings setting("./Setting.ini", QSettings::IniFormat); // 打开ini文件
       setting.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
       QString isremember = setting.value("login/isremember").toString(); // 是否选择了记住密码
       QString name = QString::fromUtf8(setting.value("login/username").toByteArray()); // 账号
       QString lock = setting.value("login/password").toString(); // 密码
       QString language = setting.value("login/language").toString(); // 是否选择了记住密码
       if (name.isEmpty()||lock.isEmpty()){
           if (textname.isEmpty() || textpassword.isEmpty()){
               if(languageSwitch){
                   QMessageBox::information(this,"System Prompts","please registered username and password!");
               }else {
                   QMessageBox::information(this,"提示","请注册账号密码！");
               }
               return;
           }
           if (name.isEmpty()){
               setting.setValue("login/username", textname); // 把账号写入ini文件
           }
           if (lock.isEmpty()){
               setting.setValue("login/password", textpassword); // 把账号写入ini文件
           }
           if (language.isEmpty()){
                setting.setValue("login/language", "中文"); // 把账号写入ini文件
           }
           setting.setValue("login_name/admin",textpassword);
           return ;
       }

       QStringList nameLockList = setting.childGroups(); // 获得ini文件的所有组
       //qDebug()<<nameLockList[1];
       setting.beginGroup(nameLockList[1]); // 选择账号密码那组
       bool islogin = false; // 用来查验账号密码是否正确

       foreach(QString key, setting.childKeys()) // 遍历账号密码那组
       {
           //qDebug()<<"key"<<key<<"name"<<QString::fromUtf8(setting.value(key).toByteArray());
           if ((key == textname) && (QString::fromUtf8(setting.value(key).toByteArray()) == textpassword)) // 查验输入的账号密码和文件里的账号密码是否有对应的
           {
               islogin = true; // 如果遍历到有就改变标志位并退出
               break;
           }
       }

       if (islogin) // 说明账号密码正确
       {
           QSettings writeini("./Setting.ini", QSettings::IniFormat); // 打开ini文件
           writeini.setIniCodec(QTextCodec::codecForName("UTF-8")); // 设置编码格式
           if (rememberPasswd) // 选择保存密码
           {
               writeini.setValue("login/isremember", "true"); // 写ini文件时记录为true
           }
           else // 不保存密码
           {
               writeini.setValue("login/isremember", "false"); // 写ini文件时记录为false
           }
           writeini.setValue("login/username", textname); // 把账号写入ini文件
           writeini.setValue("login/password", textpassword); // 把密码写入ini文件
           radarSetWin.show();
           this->hide();
           connect(&radarSetWin,&radarSetMainWindow::closeSetWindowSig,this,&MainWindow::showMainwindow);
       }
       else // 账号密码跟ini文件对不上
       {
           // 消息提示登录失败
           if (languageSwitch){
               QMessageBox::information(this, tr("System Prompts"), tr("your account or password is incorrect, please log in again"));
           } else {
               QMessageBox::information(this, tr("提示"), tr("账号或密码有误，请重新登录"));
           }
       }
}

void MainWindow::showMainwindow(){
    this->show();
}

void MainWindow::on_rememberPasswordCheckBox_clicked()
{
    if (ui->rememberPasswordCheckBox->isChecked()){
        rememberPasswd = true;
    } else {
        rememberPasswd = false;
        ui->passwordLineEdit->clear();
    }
}
