#include "MyDebug.h"
#include <QMutex>
#include <iostream>
#include <QDateTime>
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QTextStream>

//接收调试信息的函数
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    QMutexLocker lock(&mutex);

    QString text;
    switch(type)
    {
    //如果是debug信息，那么直接打印至应用程序输出，然后退出本函数
    case QtDebugMsg:
        text = QString("[Debug   ] ");
        break;

        //如果是警告，则继续执行后面的数据处理
    case QtWarningMsg:
        text = QString("[Warning ] ");
        break;

    case QtCriticalMsg:
        text = QString("[Critical] ");
        break;

    case QtFatalMsg:
        text = QString("[Fatal   ] ");
        break;

    default:
        text = QString("[Default ] ");
        break;
    }
    //获取单例
    MyDebug *instance = MyDebug::Instance();
    //消息输出位置
    QString context_info = QString(" File[%1] Fun[%2] Row[%3]")
            .arg(QString(context.file))
            .arg(QString(context.function))
            .arg(context.line);
    //消息打印时间
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("[%1] ")
            .arg(current_date_time);
    //调试信息
    QString message = QString("%1%2[%3]%4")
            .arg(current_date)
            .arg(text)
            .arg(msg)
            .arg(context_info);
    //log 位置
    QString logPahtHtml = "<a href = \"%1\">Click here to open the log directory.</a>\r\n";
    logPahtHtml = logPahtHtml.arg(QCoreApplication::applicationDirPath()+"/"+instance->logPath());
    //将调试信息格式化成 html 格式，
    QString msgHtml = msg;
    msgHtml.replace("  ", "&nbsp;");
    msgHtml.remove("\r");
    msgHtml.replace("\n", "<br>");
    msgHtml = QString("<font color=red>" + msgHtml + "</font>");

    QString contextInfoHtml = context_info;
    contextInfoHtml.remove("\r");
    contextInfoHtml.replace("\n", "<br>");
    //格式化后的调试信息
    QString messageHtml = QString("%1<br>%2<br>%3<br>%4<br>%5")
            .arg(text)
            .arg(logPahtHtml)
            .arg(current_date)
            .arg(contextInfoHtml)
            .arg("MSG : "+msgHtml);

    //将调试信息写入文件
    QFile file(instance->logPath() + instance->logName());
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
    //将处理好的调试信息发送出去
    instance->sigDebugStrData(message);
    //将处理成 html 的调试信息发送出去
    instance->sigDebugHtmlData(messageHtml);    
    //检查文件是否达到了指定大小
    if(file.size() < 1024*1024) {
        return ;
    }
    //log达到了限制值则将名字更改，防止文件越来越大
    for(int loop = 1; loop < 100; ++loop) {
        QString fileName = QString("%1/log_%2.txt").arg(instance->logPath()).arg(loop);
        QFile file_1(fileName);
        if(file_1.size() < 4) {
            file.rename(fileName);
            return ;
        }
    }
}

//MyDebug单例
MyDebug* MyDebug::self = nullptr;
MyDebug* MyDebug::Instance()
{
    if(!self) {
        QMutex muter;
        QMutexLocker clocker(&muter);

        if(!self) {
            self = new MyDebug();
        }
    }
    return self;
}
//安装消息器
void MyDebug::installMessageHandler()
{
    qInstallMessageHandler(outputMessage);
}
//卸载消息器
void MyDebug::uninstallMessageHandler()
{
    qInstallMessageHandler(0);
}
//建立文件路径
QString MyDebug::logPath()
{
    QString current_date_file_name = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QDir dir(QString("log/%1").arg(current_date_file_name));
    if(!dir.exists()) {
        dir.mkpath("./");
    }
    return dir.path() + "/" ;
}

QString MyDebug::logName()
{
    return "log.txt";
}

MyDebug::MyDebug(QObject *parent) : QObject(parent)
{    
    static MyDebug::GC gc;
}

MyDebug::~MyDebug()
{
//    std::cout << "~MyDebug" << std::endl;
}

//垃圾自动回收
MyDebug::GC::~GC()
{
    if (self != nullptr) {
        delete self;
        self = nullptr;
    }
}
