/********************************************************************************
** Form generated from reading UI file 'savedatamainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDATAMAINWINDOW_H
#define UI_SAVEDATAMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saveDataMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *saveDataMainWindow)
    {
        if (saveDataMainWindow->objectName().isEmpty())
            saveDataMainWindow->setObjectName(QString::fromUtf8("saveDataMainWindow"));
        saveDataMainWindow->resize(391, 236);
        centralwidget = new QWidget(saveDataMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setPointSize(10);
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);
        lineEdit->setMaxLength(4);
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font1);
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 0, 3, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(160, 30));
        pushButton->setMaximumSize(QSize(160, 30));
        pushButton->setFont(font1);

        gridLayout_3->addWidget(pushButton, 2, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setFont(font);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);
        lineEdit_2->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(160, 30));
        pushButton_2->setMaximumSize(QSize(160, 30));
        pushButton_2->setFont(font1);

        gridLayout_3->addWidget(pushButton_2, 2, 1, 1, 1);

        saveDataMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(saveDataMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 391, 21));
        saveDataMainWindow->setMenuBar(menubar);

        retranslateUi(saveDataMainWindow);

        QMetaObject::connectSlotsByName(saveDataMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *saveDataMainWindow)
    {
        saveDataMainWindow->setWindowTitle(QApplication::translate("saveDataMainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("saveDataMainWindow", "\346\226\207\344\273\266\350\241\214\346\225\260", nullptr));
        lineEdit->setText(QApplication::translate("saveDataMainWindow", "10", nullptr));
        checkBox->setText(QApplication::translate("saveDataMainWindow", "\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        pushButton->setText(QApplication::translate("saveDataMainWindow", "\346\233\264\346\224\271", nullptr));
        label_2->setText(QApplication::translate("saveDataMainWindow", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        lineEdit_2->setText(QString());
        pushButton_2->setText(QApplication::translate("saveDataMainWindow", "\345\272\224\347\224\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saveDataMainWindow: public Ui_saveDataMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDATAMAINWINDOW_H
