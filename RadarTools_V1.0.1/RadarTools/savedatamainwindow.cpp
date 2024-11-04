#include "savedatamainwindow.h"
#include "ui_savedatamainwindow.h"
#include <QIntValidator>
#include <QFileDialog>
#include <QDebug>
#include <QTextCodec>
#include <QSettings>
#include <QMessageBox>

saveDataMainWindow::saveDataMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::saveDataMainWindow)
{
    ui->setupUi(this);
    initSaveWindow();
}

saveDataMainWindow::~saveDataMainWindow()
{
    delete ui;
}


void saveDataMainWindow::initSaveWindow(){
    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    this->setFixedSize(this->width(),this->height());//禁止放大
    setWindowTitle(tr("数据保存"));
    setWindowIcon(QIcon(":/img/dragonbool.jpg"));

    ui->lineEdit->setValidator(new QIntValidator(this));//只允许输入纯数字形式

    QSettings setting("./Setting.ini", QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QString lang = setting.value("login/language").toString();
    if (lang.isEmpty()){
        switchLanguage("中文");
    } else{
        switchLanguage(lang);
    }
}

void saveDataMainWindow::on_pushButton_clicked()
{
    //configuretion save data path
    QString filepath = QFileDialog::getExistingDirectory(this,"./");
    //qDebug()<<filepath;
    ui->lineEdit_2->setText(filepath);
}

void saveDataMainWindow::on_pushButton_2_clicked()
{
    //config this path
    if (!ui->lineEdit_2->text().isEmpty()){
       emit saveDataSig(ui->lineEdit_2->text(),ui->lineEdit->text());
       this->close();
    }else {
        if (languageSwt)
            QMessageBox::information(this,"提示","请选择正确的保存路径！");
        else
            QMessageBox::information(this,"System Prompts","Please select the correct save path!");
    }
}

void saveDataMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void saveDataMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
       languageSwt = true;
       setWindowTitle(tr("数据保存"));
       ui->label->setText("文件行数");
       ui->checkBox->setText("保存数据");
       ui->label_2->setText("文件路径");
       ui->pushButton->setText("更改");
       ui->pushButton_2->setText("保存");
    } else {
       languageSwt = false;
       setWindowTitle(tr("Data Save"));
       ui->label->setText("File Lines");
       ui->checkBox->setText("Save Data");
       ui->label_2->setText("File Path");
       ui->pushButton->setText("Change");
       ui->pushButton_2->setText("Save");
    }
}
