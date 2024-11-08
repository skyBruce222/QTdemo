#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QmutexLocker>

class FileManager
{
public:
    FileManager();
    FileManager(QString filepath);
    ~FileManager();

    void setFileName(const QString &filepath, const QString &start="");
    QString read();
    QStringList read(const QString &separator);

    void write(const QString &text, QIODevice::OpenModeFlag flags = QIODevice::Append, const QString &sperator="\r\n");
    void append(const QString &text, QIODevice::OpenModeFlag flags = QIODevice::Append, const QString &sperator="\r\n");

    void close();
private:
    QFile *file;
    QTextStream *in;
    QMutex _mutex;
};

#endif // FILEMANAGER_H
