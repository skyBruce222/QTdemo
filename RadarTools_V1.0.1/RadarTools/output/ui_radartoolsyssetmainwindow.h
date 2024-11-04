/********************************************************************************
** Form generated from reading UI file 'radartoolsyssetmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADARTOOLSYSSETMAINWINDOW_H
#define UI_RADARTOOLSYSSETMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_radarToolSysSetMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *radarToolSysSetMainWindow)
    {
        if (radarToolSysSetMainWindow->objectName().isEmpty())
            radarToolSysSetMainWindow->setObjectName(QString::fromUtf8("radarToolSysSetMainWindow"));
        radarToolSysSetMainWindow->resize(360, 250);
        radarToolSysSetMainWindow->setMinimumSize(QSize(360, 250));
        radarToolSysSetMainWindow->setMaximumSize(QSize(360, 250));
        centralwidget = new QWidget(radarToolSysSetMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(20, 0, 320, 240));
        widget_4->setMinimumSize(QSize(320, 240));
        widget_4->setMaximumSize(QSize(320, 240));
        QFont font;
        font.setPointSize(10);
        widget_4->setFont(font);
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 5, 1, 1, 1);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setFont(font);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit_3 = new QLineEdit(widget_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(0, 25));
        lineEdit_3->setMaximumSize(QSize(16777215, 25));
        lineEdit_3->setFont(font);
        lineEdit_3->setMaxLength(6);

        gridLayout_3->addWidget(lineEdit_3, 0, 2, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        label_3->setFont(font1);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_3, 4, 1, 1, 1);

        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));
        lineEdit->setFont(font);
        lineEdit->setMaxLength(6);

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 1, 1, 1);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setFont(font);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 25));
        lineEdit_2->setMaximumSize(QSize(16777215, 25));
        lineEdit_2->setFont(font);
        lineEdit_2->setMaxLength(6);

        gridLayout_2->addWidget(lineEdit_2, 0, 2, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_2, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setFont(font);
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton = new QPushButton(widget_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(120, 30));
        pushButton->setMaximumSize(QSize(120, 30));
        pushButton->setFont(font1);

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_5, 6, 0, 1, 3);

        radarToolSysSetMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(radarToolSysSetMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 360, 21));
        radarToolSysSetMainWindow->setMenuBar(menubar);

        retranslateUi(radarToolSysSetMainWindow);

        QMetaObject::connectSlotsByName(radarToolSysSetMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *radarToolSysSetMainWindow)
    {
        radarToolSysSetMainWindow->setWindowTitle(QApplication::translate("radarToolSysSetMainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("radarToolSysSetMainWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("radarToolSysSetMainWindow", "\345\275\223\345\211\215\345\257\206\347\240\201", nullptr));
        label_2->setText(QApplication::translate("radarToolSysSetMainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("radarToolSysSetMainWindow", "\344\277\256    \346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class radarToolSysSetMainWindow: public Ui_radarToolSysSetMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADARTOOLSYSSETMAINWINDOW_H
