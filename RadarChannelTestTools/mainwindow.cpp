#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
    initCharts();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow(){

    QPalette palette;
    //设置主窗口背景颜色
    palette.setColor(QPalette::Window,QColor(190, 190, 190));

    this->setPalette(palette);

    setWindowTitle("雷达通道测试");
    setFixedSize(this->width(), this->height());
    ui->pushButton_2->setEnabled(false);

    eventFilter = new serialGetEvent(ui->comboBox, this);
    ui->comboBox->installEventFilter(eventFilter);
    connect(eventFilter, SIGNAL(comboBoxPopupShown()), this, SLOT(onComboBoxPopupShown_1()));//连接鼠标点击事件，实现点击串口列表刷新

    eventFilter2 = new serialGetEvent(ui->comboBox_2, this);
    ui->comboBox_2->installEventFilter(eventFilter2);
    connect(eventFilter2, SIGNAL(comboBoxPopupShown()), this, SLOT(onComboBoxPopupShown_2()));//连接鼠标点击事件，实现点击串口列表刷新
}

void MainWindow::initCharts(){
    QPen t_penLine;
    t_penLine.setWidth(1);

    //axisX.setTitleText(QStringLiteral("单位 °"));
    //t_penLine.setColor(Qt::color0);
    //axisX.setGridLinePen(t_penLine);
    axisX.setTickCount(13);
    axisX.setMinorTickCount(4);
    axisX.setRange(-180,-60);
    //axisY.setGridLinePen(t_penLine);
    axisY.setTitleText(QStringLiteral("单位 db"));
    axisY.setTickCount(9);
    axisY.setMinorTickCount(4);
    axisY.setRange(10,90);

    chart1.addAxis(&axisX,Qt::AlignBottom);
    chart1.addAxis(&axisY, Qt::AlignLeft);

    chart1.addSeries(&lineSeries1);
    t_penLine.setColor(Qt::red);
    lineSeries1.setPen(t_penLine);
    lineSeries1.setName("Ant1");
    lineSeries1.attachAxis(&axisX);
    lineSeries1.attachAxis(&axisY);

    chart1.addSeries(&lineSeries2);
    t_penLine.setColor(Qt::green);
    lineSeries2.setPen(t_penLine);
    lineSeries2.setName("Ant2");
    lineSeries2.attachAxis(&axisX);
    lineSeries2.attachAxis(&axisY);

    chart1.addSeries(&lineSeries3);
    t_penLine.setColor(Qt::blue);
    lineSeries3.setPen(t_penLine);
    lineSeries3.setName("Ant3");
    lineSeries3.attachAxis(&axisX);
    lineSeries3.attachAxis(&axisY);

    chart1.addSeries(&lineSeries4);
    t_penLine.setColor(Qt::yellow);
    lineSeries4.setPen(t_penLine);
    lineSeries4.setName("Ant4");
    lineSeries4.attachAxis(&axisX);
    lineSeries4.attachAxis(&axisY);

    chart1.addSeries(&lineSeries5);
    t_penLine.setColor(Qt::darkRed);
    lineSeries5.setPen(t_penLine);
    lineSeries5.setName("Ant5");
    lineSeries5.attachAxis(&axisX);
    lineSeries5.attachAxis(&axisY);

    chart1.addSeries(&lineSeries6);
    t_penLine.setColor(Qt::darkGreen);
    lineSeries6.setPen(t_penLine);
    lineSeries6.setName("Ant6");
    lineSeries6.attachAxis(&axisX);
    lineSeries6.attachAxis(&axisY);

    chart1.addSeries(&lineSeries7);
    t_penLine.setColor(Qt::darkBlue);
    lineSeries7.setPen(t_penLine);
    lineSeries7.setName("Ant7");
    lineSeries7.attachAxis(&axisX);
    lineSeries7.attachAxis(&axisY);

    chart1.addSeries(&lineSeries8);
    t_penLine.setColor(Qt::darkYellow);
    lineSeries8.setPen(t_penLine);
    lineSeries8.setName("Ant8");
    lineSeries8.attachAxis(&axisX);
    lineSeries8.attachAxis(&axisY);

    chart1.legend()->setAlignment(Qt::AlignRight);
    //chart1.setBackgroundVisible(false);
    chart1.setBackgroundBrush(Qt::lightGray);
    ui->tab_1->setChart(&chart1);
    ui->tab_1->setRenderHint(QPainter::Antialiasing);

    //axisXAvg.setTitleText(QStringLiteral("单位 °"));
    axisXAvg.setTickCount(13);
    axisXAvg.setMinorTickCount(4);
    axisXAvg.setRange(-180,-60);
    axisYAvg.setTitleText(QStringLiteral("单位 db"));
    axisYAvg.setTickCount(9);
    axisYAvg.setMinorTickCount(4);
    axisYAvg.setRange(10,90);

    chart2.addAxis(&axisXAvg,Qt::AlignBottom);
    chart2.addAxis(&axisYAvg, Qt::AlignLeft);

    chart2.addSeries(&lineSeriesAvg);
    t_penLine.setColor(Qt::red);
    lineSeriesAvg.setPen(t_penLine);
    lineSeriesAvg.setName("Avg ");
    lineSeriesAvg.attachAxis(&axisXAvg);
    lineSeriesAvg.attachAxis(&axisYAvg);

    chart2.addSeries(&lineSeriesAvgTip);
    t_penLine.setColor(Qt::green);
    lineSeriesAvgTip.setMarkerSize(10);
    lineSeriesAvgTip.attachAxis(&axisXAvg);
    lineSeriesAvgTip.attachAxis(&axisYAvg);
    lineSeriesAvgTip.setPointLabelsVisible(true);
    lineSeriesAvgTip.setPointLabelsColor(Qt::green);

    QFont t_FontLab;
    t_FontLab.setPointSize(16);
    lineSeriesAvgTip.setPointLabelsFont(t_FontLab);
    lineSeriesAvgTip.setName("Tip ");
    t_penLine.setColor(Qt::green);
    lineSeriesAvgTip.setPen(t_penLine);

    chart2.legend()->setAlignment(Qt::AlignRight);
    chart2.setBackgroundBrush(Qt::lightGray);
    ui->tab_2->setChart(&chart2);
    ui->tab_2->setRenderHint(QPainter::Antialiasing);
}

//开始测量
void MainWindow::on_pushButton_clicked()
{

    if (ui->pushButton->text() == "开始测量"){

        if (ui->comboBox->currentText().isEmpty() ||
            ui->comboBox_2->currentText().isEmpty()){
            QMessageBox::critical(this,"错误","雷达串口或为转台串口空！");
            return ;
        }

        if ((ui->comboBox->currentText() == ui->comboBox_2->currentText())){
            QMessageBox::critical(this,"错误","雷达串口与转台串口冲突！");
            return ;
        }

        ui->pushButton->setText("停止测量");
        qDebug()<<"停止测量";
    } else{
        ui->pushButton->setText("开始测量");
        qDebug()<<"开始测量";
    }
}

void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::onComboBoxPopupShown_1(){

    ui->comboBox->clear();
    PortStringList.clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
//        qDebug()<<"Name:"<<info.portName();
//        qDebug()<<"Description:"<<info.description();
//        qDebug()<<"Manufacturer:"<<info.manufacturer();

        //这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            //将串口号添加到cmb
            //ui->comboBox->addItem(info.portName());
            //qDebug()<<"串口名称:"<<info.portName();
            PortStringList += info.portName();
            serial.close();
        }
    }
    ui->comboBox->addItems(PortStringList);
}


void MainWindow::onComboBoxPopupShown_2(){

    ui->comboBox_2->clear();
    PortStringList.clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
//        qDebug()<<"Name:"<<info.portName();
//        qDebug()<<"Description:"<<info.description();
//        qDebug()<<"Manufacturer:"<<info.manufacturer();

        //这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            //将串口号添加到cmb
            //ui->comboBox->addItem(info.portName());
            //qDebug()<<"串口名称:"<<info.portName();
            PortStringList += info.portName();
            serial.close();
        }
    }
    ui->comboBox_2->addItems(PortStringList);
}
