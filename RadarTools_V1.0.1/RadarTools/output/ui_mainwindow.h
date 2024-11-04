/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionch;
    QAction *actionen;
    QWidget *centralwidget;
    QFrame *frame;
    QWidget *login_widget;
    QGridLayout *gridLayout_3;
    QWidget *loginWidget;
    QGridLayout *gridLayout_4;
    QCheckBox *rememberPasswordCheckBox;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *loginPushButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QWidget *passwordWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *passwordLineEdit;
    QLabel *passwordLabel;
    QWidget *usernameWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *usernameLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *usernameLabel;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(426, 363);
        MainWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        actionch = new QAction(MainWindow);
        actionch->setObjectName(QString::fromUtf8("actionch"));
        actionen = new QAction(MainWindow);
        actionen->setObjectName(QString::fromUtf8("actionen"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setFont(font);
        centralwidget->setAutoFillBackground(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(140, 0, 141, 131));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/img/OIP-C.jfif);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        login_widget = new QWidget(centralwidget);
        login_widget->setObjectName(QString::fromUtf8("login_widget"));
        login_widget->setGeometry(QRect(0, 150, 421, 181));
        login_widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(login_widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        loginWidget = new QWidget(login_widget);
        loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        gridLayout_4 = new QGridLayout(loginWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        rememberPasswordCheckBox = new QCheckBox(loginWidget);
        rememberPasswordCheckBox->setObjectName(QString::fromUtf8("rememberPasswordCheckBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        rememberPasswordCheckBox->setFont(font1);

        gridLayout_4->addWidget(rememberPasswordCheckBox, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 1, 0, 1, 1);

        loginPushButton = new QPushButton(loginWidget);
        loginPushButton->setObjectName(QString::fromUtf8("loginPushButton"));
        loginPushButton->setMinimumSize(QSize(100, 30));
        loginPushButton->setMaximumSize(QSize(100, 30));
        loginPushButton->setFont(font1);
        loginPushButton->setAutoFillBackground(false);
        loginPushButton->setStyleSheet(QString::fromUtf8("#frame{\n"
"	border-image: url(:/img/radar.jpg);\n"
"}"));

        gridLayout_4->addWidget(loginPushButton, 1, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 1, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 1, 4, 1, 1);


        gridLayout_3->addWidget(loginWidget, 3, 0, 1, 2);

        passwordWidget = new QWidget(login_widget);
        passwordWidget->setObjectName(QString::fromUtf8("passwordWidget"));
        gridLayout_2 = new QGridLayout(passwordWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        passwordLineEdit = new QLineEdit(passwordWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setMinimumSize(QSize(150, 30));
        passwordLineEdit->setMaximumSize(QSize(150, 30));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setMaxLength(6);
        passwordLineEdit->setFrame(true);

        gridLayout_2->addWidget(passwordLineEdit, 0, 3, 1, 1);

        passwordLabel = new QLabel(passwordWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font1);
        passwordLabel->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(passwordLabel, 0, 1, 1, 1);


        gridLayout_3->addWidget(passwordWidget, 1, 0, 2, 2);

        usernameWidget = new QWidget(login_widget);
        usernameWidget->setObjectName(QString::fromUtf8("usernameWidget"));
        usernameWidget->setStyleSheet(QString::fromUtf8("#frame{\n"
"border-image: url(:/img/radar.jpg);\n"
"}"));
        gridLayout = new QGridLayout(usernameWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        usernameLineEdit = new QLineEdit(usernameWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setMinimumSize(QSize(150, 30));
        usernameLineEdit->setMaximumSize(QSize(150, 30));
        usernameLineEdit->setFont(font);
        usernameLineEdit->setLayoutDirection(Qt::LeftToRight);
        usernameLineEdit->setStyleSheet(QString::fromUtf8(""));
        usernameLineEdit->setMaxLength(32);
        usernameLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(usernameLineEdit, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        usernameLabel = new QLabel(usernameWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setFont(font1);
        usernameLabel->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(usernameLabel, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 4, 1, 1);


        gridLayout_3->addWidget(usernameWidget, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 426, 22));
        QFont font2;
        font2.setPointSize(10);
        menubar->setFont(font2);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(actionch);
        menu->addSeparator();
        menu->addAction(actionen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionch->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207", nullptr));
        actionen->setText(QApplication::translate("MainWindow", "English", nullptr));
        rememberPasswordCheckBox->setText(QApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        loginPushButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        passwordLabel->setText(QApplication::translate("MainWindow", "\345\257\206  \347\240\201", nullptr));
        usernameLabel->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\350\257\255\350\250\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
