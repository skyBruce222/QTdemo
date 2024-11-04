/********************************************************************************
** Form generated from reading UI file 'textsetmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTSETMAINWINDOW_H
#define UI_TEXTSETMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textSetMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_6;
    QPushButton *pushButton;
    QCheckBox *checkBox_4;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox_2;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *checkBox_3;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *textSetMainWindow)
    {
        if (textSetMainWindow->objectName().isEmpty())
            textSetMainWindow->setObjectName(QString::fromUtf8("textSetMainWindow"));
        textSetMainWindow->resize(401, 225);
        centralwidget = new QWidget(textSetMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        checkBox_5->setFont(font);
        checkBox_5->setChecked(true);

        gridLayout->addWidget(checkBox_5, 3, 1, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font);
        checkBox_6->setChecked(true);

        gridLayout->addWidget(checkBox_6, 3, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setFont(font);
        checkBox_4->setChecked(true);

        gridLayout->addWidget(checkBox_4, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font);
        checkBox_2->setChecked(true);

        gridLayout->addWidget(checkBox_2, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font);
        checkBox_3->setChecked(true);

        gridLayout->addWidget(checkBox_3, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        textSetMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(textSetMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 401, 21));
        textSetMainWindow->setMenuBar(menubar);

        retranslateUi(textSetMainWindow);

        QMetaObject::connectSlotsByName(textSetMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *textSetMainWindow)
    {
        textSetMainWindow->setWindowTitle(QApplication::translate("textSetMainWindow", "MainWindow", nullptr));
        checkBox_5->setText(QApplication::translate("textSetMainWindow", "Target Sate", nullptr));
        checkBox->setText(QApplication::translate("textSetMainWindow", "Target Angle", nullptr));
        checkBox_6->setText(QApplication::translate("textSetMainWindow", "Target Class", nullptr));
        pushButton->setText(QApplication::translate("textSetMainWindow", "\345\272\224\347\224\250", nullptr));
        checkBox_4->setText(QApplication::translate("textSetMainWindow", "Target RCS", nullptr));
        checkBox_2->setText(QApplication::translate("textSetMainWindow", "Target Range", nullptr));
        checkBox_3->setText(QApplication::translate("textSetMainWindow", "Target Velocity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textSetMainWindow: public Ui_textSetMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTSETMAINWINDOW_H
