#ifndef MYDEBUG_H
#define MYDEBUG_H

#include <QObject>
#include <iostream>

/*************************************
 * DEFINES += QT_MESSAGELOGCONTEXT
 * 使用前在pro文件中加上这句话
 * **********************************/
class MyDebug : public QObject
{
    Q_OBJECT
private:
    explicit MyDebug(QObject *parent = nullptr);
    ~MyDebug();
    static MyDebug* self;

public:
    static  MyDebug* Instance();
    void installMessageHandler();
    void uninstallMessageHandler();
    QString logPath();
    QString logName();

signals:
    void sigDebugStrData(const QString &);
    void sigDebugHtmlData(const QString &);

private:
    class GC
    {
    public:
        ~GC();
    };
};

#endif // MYDEBUG_H
