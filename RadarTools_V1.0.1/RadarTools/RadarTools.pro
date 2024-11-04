QT       += core gui
QT       += charts
QT += multimedia
QT += multimediawidgets

RC_ICONS = dragonbool.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cameraeventfilter.cpp \
    canthread.cpp \
    collisionareamainwindow.cpp \
    coordinateaxiswight.cpp \
    filtertargetmainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    radarareamainwindow.cpp \
    radarparasmainwindow.cpp \
    radarsetmainwindow.cpp \
    radartoolsyssetmainwindow.cpp \
    savedatamainwindow.cpp \
    targettypemainwindow.cpp \
    textsetmainwindow.cpp

HEADERS += \
    cameraeventfilter.h \
    canthread.h \
    collisionareamainwindow.h \
    coordinateaxiswight.h \
    filtertargetmainwindow.h \
    mainwindow.h \
    radarareamainwindow.h \
    radarparasmainwindow.h \
    radarsetmainwindow.h \
    radartoolsyssetmainwindow.h \
    savedatamainwindow.h \
    targettypemainwindow.h \
    textsetmainwindow.h

FORMS += \
    collisionareamainwindow.ui \
    filtertargetmainwindow.ui \
    mainwindow.ui \
    radarareamainwindow.ui \
    radarparasmainwindow.ui \
    radarsetmainwindow.ui \
    radartoolsyssetmainwindow.ui \
    savedatamainwindow.ui \
    targettypemainwindow.ui \
    textsetmainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imag.qrc #\
    #language.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lControlCAN
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lControlCAN

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
