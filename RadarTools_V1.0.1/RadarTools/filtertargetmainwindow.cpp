#include "filtertargetmainwindow.h"
#include "ui_filtertargetmainwindow.h"
#include <QSettings>
#include <QTextCodec>

filterTargetMainWindow::filterTargetMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::filterTargetMainWindow)
{
    ui->setupUi(this);
    initFilterWindow();
}

filterTargetMainWindow::~filterTargetMainWindow()
{
    delete ui;
}

void filterTargetMainWindow::initFilterWindow(){
    setWindowTitle(tr("目标过滤"));
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

void filterTargetMainWindow::switchLanguageSlot(QString lang){
    switchLanguage(lang);
}

void filterTargetMainWindow::switchLanguage(QString lang){
    if (lang == "中文"){
        setWindowTitle(tr("目标过滤"));
        ui->label->setText("显示最大目标数目");
        ui->label_2->setText("可输出置信度区间");
        ui->label_6->setText("目标纵向距离区间");
        ui->label_9->setText("纵向靠近速度区间");
        ui->label_12->setText("纵向远离速度区间");
        ui->label_15->setText("探测目标面积区间");
        ui->label_18->setText("探测目标RCS区间 ");
        ui->label_21->setText("目标横向距离区间");
        ui->label_24->setText("从左至右速度区间");
        ui->label_27->setText("从右至左速度区间");
        ui->pushButton->setText("默认");
        ui->pushButton_2->setText("应用");
    } else {
        setWindowTitle(tr("Target Filter"));
        ui->label->setText("Target Max Num");
        ui->label_2->setText("Confidence Data");
        ui->label_6->setText("Longitudinal Dis");
        ui->label_9->setText("Longitudinal Vel");
        ui->label_12->setText("Longitudinal Sed");
        ui->label_15->setText("Det Target Area");
        ui->label_18->setText("Det Target Rcs ");
        ui->label_21->setText("Lateral Distance");
        ui->label_24->setText("Left to Right Sed");
        ui->label_27->setText("Right to Left Sed");
        ui->pushButton->setText("Default");
        ui->pushButton_2->setText("Save");
    }
}

void filterTargetMainWindow::on_pushButton_clicked()
{
    //set default parameters
}

void filterTargetMainWindow::on_pushButton_2_clicked()
{
    //save current parameters
}
