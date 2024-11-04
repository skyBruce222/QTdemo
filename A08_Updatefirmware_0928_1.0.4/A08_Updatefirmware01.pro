#-------------------------------------------------
#
# Project created by QtCreator 2021-09-22T14:57:22
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#03：测试每包200个字节，可以升级；
#04：测试每包400个字节，发行版本；
TARGET = TIBurnTool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    serialthread.cpp \
    serialworkerthread.cpp


HEADERS += \
        mainwindow.h \
    serialthread.h \
    serialworkerthread.h

FORMS += \
    mainwindow.ui
