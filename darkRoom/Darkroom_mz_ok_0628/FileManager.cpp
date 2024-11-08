#include "FileManager.h"

FileManager::FileManager()
{
    in = NULL;
    file = NULL;
}

FileManager::FileManager(QString filepath)
{
    file = new QFile(filepath);
    in = NULL;
}

FileManager::~FileManager()
{
    if(file)
    {
        file->close();
        delete file;
    }
    if(in)
    {
        delete in;
    }
}

void FileManager::setFileName(const QString &filepath, const QString &start)
{
    if(filepath == "")
        return;
    if(file != NULL)
    {
        QMutexLocker locker(&_mutex);
        if(file->fileName() == filepath)
            return;
        else {
            if(in != NULL)
            {
                in->flush();
                delete in;
                in = NULL;
            }
            //file->flush();
            file->close();
        }
    }
    file = new QFile(filepath);
    append(start);
}

void FileManager::close()
{
    QMutexLocker locker(&_mutex);
    if(in)
    {
        in->flush();
        delete in;
        in = NULL;
    }
    if(file)
    {
        file->flush();
        file->close();
        delete file;
        file = NULL;
    }
}

QString FileManager::read()
{
    if(!file->isOpen())
        file->close();
    file->open(QIODevice::ReadOnly);
    if(in != NULL)
        delete in;
    in = new QTextStream(file);
    //in->setCodec("UTF-8");

    QString text = QString::fromLocal8Bit(in->readAll().toLocal8Bit());
    delete in;
    file->close();
    return text;
}

QStringList FileManager::read(const QString &sperator)
{
    return read().split(sperator);
}

void FileManager::write(const QString &text, QIODevice::OpenModeFlag flags, const QString &sperator)
{
    if(!file->isOpen())
        file->close();
    file->open(flags);
    if(in != NULL)
        delete in;
    in = new QTextStream(file);
    //in->setCodec("UTF-8");
    *in<<text<<sperator;
    in->flush();
    delete in;
    file->close();
}

//not close file
void FileManager::append(const QString &text, QIODevice::OpenModeFlag flags, const QString &sperator)
{
    QMutexLocker locker(&_mutex);
    if(!file->isOpen())
        file->open(flags);
    if(in == NULL)
    {
        in = new QTextStream(file);
        //in->setCodec("UTF-8");
    }

    *in<<text<<sperator;
    in->flush();
}
