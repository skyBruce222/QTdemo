#-------------------------------------------------
#
# Project created by QtCreator 2019-05-06T11:16:13
#
#-------------------------------------------------

QT       += core gui serialport charts printsupport

TARGET = DarkroomDetect
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseControlThread.cpp \
    Communicate.cpp \
    FileManager.cpp \
    MyDebug.cpp \
    MyTitlebar.cpp \
    RadarControlThread.cpp \
    RemoteDoc.cpp \
    RotaryControlThread.cpp \
    Spcomm.cpp \
    WriterControlThread.cpp \
    controldlg.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
    Axis.h \
    BaseControlThread.h \
    Communicate.h \
    FileManager.h \
    MyDebug.h \
    MyTitlebar.h \
    RadarControlThread.h \
    RemoteDoc.h \
    Repository.hpp \
    RotaryControlThread.h \
    Spcomm.h \
    WriterControlThread.h \
    controldlg.h \
        mainwindow.h

FORMS += \
        controldlg.ui \
        mainwindow.ui

CONFIG += c++11

RESOURCES += \
    rc.qrc

RC_ICONS = img/mbit.ico
