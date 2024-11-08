#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include "MyDebug.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    // 安装消息器
    MyDebug::Instance()->installMessageHandler();

    MainWindow w;
    w.show();
    return a.exec();
}
