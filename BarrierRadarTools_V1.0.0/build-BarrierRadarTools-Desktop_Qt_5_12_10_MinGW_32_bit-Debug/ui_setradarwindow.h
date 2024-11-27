/********************************************************************************
** Form generated from reading UI file 'setradarwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETRADARWINDOW_H
#define UI_SETRADARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <coordinateaxiswight.h>

QT_BEGIN_NAMESPACE

class Ui_setRadarWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QComboBox *comboBox;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *widget_7;
    QGridLayout *gridLayout_7;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget_9;
    QGridLayout *gridLayout_9;
    QComboBox *comboBox_4;
    QLabel *label_8;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget_8;
    QGridLayout *gridLayout_8;
    QLabel *label_7;
    QComboBox *comboBox_3;
    QWidget *widget_10;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *widget_13;
    QGridLayout *gridLayout_16;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QProgressBar *progressBar;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    coordinateAxisWight *widget_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_14;
    QWidget *widget_11;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QWidget *widget_12;
    QGridLayout *gridLayout_15;
    QLabel *label_10;
    QLabel *label_led;

    void setupUi(QMainWindow *setRadarWindow)
    {
        if (setRadarWindow->objectName().isEmpty())
            setRadarWindow->setObjectName(QString::fromUtf8("setRadarWindow"));
        setRadarWindow->resize(1088, 782);
        centralwidget = new QWidget(setRadarWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        centralwidget->setFont(font);
        gridLayout_11 = new QGridLayout(centralwidget);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(280, 0));
        groupBox->setMaximumSize(QSize(280, 16777215));
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        widget_6 = new QWidget(groupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        comboBox = new QComboBox(widget_6);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(127, 0));

        gridLayout_6->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_6, 4, 0, 1, 1);

        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget_5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_5->addWidget(lineEdit_4, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_5, 3, 0, 1, 1);

        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_4->addWidget(lineEdit_3, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_4, 2, 0, 1, 1);

        widget_7 = new QWidget(groupBox);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_7 = new QGridLayout(widget_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(widget_7);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(127, 0));

        gridLayout_7->addWidget(comboBox_2, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_7, 5, 0, 1, 1);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_3, 1, 0, 1, 1);

        widget_9 = new QWidget(groupBox);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_9 = new QGridLayout(widget_9);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        comboBox_4 = new QComboBox(widget_9);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(127, 0));

        gridLayout_9->addWidget(comboBox_4, 0, 1, 1, 1);

        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_9->addWidget(label_8, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_9, 7, 0, 1, 1);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget, 0, 0, 1, 1);

        widget_8 = new QWidget(groupBox);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout_8 = new QGridLayout(widget_8);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_8->addWidget(label_7, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(widget_8);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(127, 0));

        gridLayout_8->addWidget(comboBox_3, 0, 1, 1, 1);


        gridLayout_10->addWidget(widget_8, 6, 0, 1, 1);

        widget_10 = new QWidget(groupBox);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        gridLayout_12 = new QGridLayout(widget_10);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        pushButton_2 = new QPushButton(widget_10);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_12->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(widget_10);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_12->addWidget(pushButton_4, 0, 0, 2, 1);

        pushButton = new QPushButton(widget_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_12->addWidget(pushButton, 0, 1, 2, 1);

        pushButton_3 = new QPushButton(widget_10);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_12->addWidget(pushButton_3, 2, 1, 1, 1);


        gridLayout_10->addWidget(widget_10, 9, 0, 1, 1);

        widget_13 = new QWidget(groupBox);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        gridLayout_16 = new QGridLayout(widget_13);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        lineEdit_5 = new QLineEdit(widget_13);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_16->addWidget(lineEdit_5, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(widget_13);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(25, 0));
        pushButton_8->setMaximumSize(QSize(25, 16777215));

        gridLayout_16->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(widget_13);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_16->addWidget(pushButton_7, 1, 0, 1, 1);

        progressBar = new QProgressBar(widget_13);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_16->addWidget(progressBar, 2, 0, 1, 3);


        gridLayout_10->addWidget(widget_13, 8, 0, 1, 1);


        gridLayout_11->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new coordinateAxisWight(groupBox_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(8);
        widget_2->setFont(font1);

        gridLayout->addWidget(widget_2, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_2, 0, 0, 2, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_14 = new QGridLayout(groupBox_3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        widget_11 = new QWidget(groupBox_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        gridLayout_13 = new QGridLayout(widget_11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_5 = new QPushButton(widget_11);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_13->addWidget(pushButton_5, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(widget_11);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_13->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(widget_11);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_13->addWidget(pushButton_10, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(widget_11);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_13->addWidget(pushButton_9, 1, 1, 1, 1);


        gridLayout_14->addWidget(widget_11, 0, 0, 1, 1);

        widget_12 = new QWidget(groupBox_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        gridLayout_15 = new QGridLayout(widget_12);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_10 = new QLabel(widget_12);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_15->addWidget(label_10, 0, 0, 1, 1);

        label_led = new QLabel(widget_12);
        label_led->setObjectName(QString::fromUtf8("label_led"));
        label_led->setMinimumSize(QSize(40, 40));
        label_led->setMaximumSize(QSize(40, 40));

        gridLayout_15->addWidget(label_led, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_12, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 1, 1, 1, 1);

        setRadarWindow->setCentralWidget(centralwidget);

        retranslateUi(setRadarWindow);

        comboBox->setCurrentIndex(-1);
        comboBox_2->setCurrentIndex(-1);
        comboBox_4->setCurrentIndex(-1);
        comboBox_3->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(setRadarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *setRadarWindow)
    {
        setRadarWindow->setWindowTitle(QApplication::translate("setRadarWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("setRadarWindow", "\351\233\267\350\276\276\351\205\215\347\275\256", nullptr));
        label_5->setText(QApplication::translate("setRadarWindow", "\346\235\206\345\236\213\351\200\211\346\213\251", nullptr));
        comboBox->setItemText(0, QApplication::translate("setRadarWindow", "\347\233\264\346\235\206", nullptr));
        comboBox->setItemText(1, QApplication::translate("setRadarWindow", "\346\240\205\346\240\217", nullptr));
        comboBox->setItemText(2, QApplication::translate("setRadarWindow", "\345\271\277\345\221\212", nullptr));

        label_4->setText(QApplication::translate("setRadarWindow", "\345\217\263\350\267\235\347\246\273(m)    ", nullptr));
        label_3->setText(QApplication::translate("setRadarWindow", "\345\267\246\350\267\235\347\246\273(m)    ", nullptr));
        label_6->setText(QApplication::translate("setRadarWindow", "\346\235\206\344\273\266\346\226\271\345\220\221", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("setRadarWindow", "\345\267\246", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("setRadarWindow", "\345\217\263", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("setRadarWindow", "\346\231\256\351\200\232\347\233\264\346\235\206", nullptr));

        label_2->setText(QApplication::translate("setRadarWindow", "\350\265\267\345\247\213\350\267\235\347\246\273(m)", nullptr));
        comboBox_4->setItemText(0, QApplication::translate("setRadarWindow", "\345\274\200", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("setRadarWindow", "\345\205\263", nullptr));

        label_8->setText(QApplication::translate("setRadarWindow", "\351\233\267\350\276\276\346\227\245\345\277\227", nullptr));
        label->setText(QApplication::translate("setRadarWindow", "\347\272\265\345\220\221\350\267\235\347\246\273(m)", nullptr));
        label_7->setText(QApplication::translate("setRadarWindow", "\347\233\256\346\240\207\345\214\272\345\210\206", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("setRadarWindow", "\346\230\257", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("setRadarWindow", "\345\220\246", nullptr));

        pushButton_2->setText(QApplication::translate("setRadarWindow", "\350\257\273\345\217\226", nullptr));
        pushButton_4->setText(QApplication::translate("setRadarWindow", "\345\255\246\344\271\240", nullptr));
        pushButton->setText(QApplication::translate("setRadarWindow", "\351\205\215\347\275\256", nullptr));
        pushButton_3->setText(QApplication::translate("setRadarWindow", "\351\207\215\345\220\257", nullptr));
        pushButton_8->setText(QApplication::translate("setRadarWindow", "...", nullptr));
        pushButton_7->setText(QApplication::translate("setRadarWindow", "\345\233\272\344\273\266\345\215\207\347\272\247", nullptr));
        groupBox_2->setTitle(QApplication::translate("setRadarWindow", "\347\233\256\346\240\207\346\230\276\347\244\272", nullptr));
        groupBox_3->setTitle(QApplication::translate("setRadarWindow", "\346\230\276\347\244\272\351\205\215\347\275\256", nullptr));
        pushButton_5->setText(QApplication::translate("setRadarWindow", "\346\211\200\346\234\211\347\233\256\346\240\207", nullptr));
        pushButton_6->setText(QApplication::translate("setRadarWindow", "\346\230\276\347\244\272\351\200\237\345\272\246", nullptr));
        pushButton_10->setText(QApplication::translate("setRadarWindow", "\346\230\276\347\244\272\345\235\220\346\240\207", nullptr));
        pushButton_9->setText(QApplication::translate("setRadarWindow", "\345\201\234\346\255\242\346\230\276\347\244\272", nullptr));
        label_10->setText(QApplication::translate("setRadarWindow", "\346\227\266\351\227\264", nullptr));
        label_led->setText(QApplication::translate("setRadarWindow", "\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setRadarWindow: public Ui_setRadarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETRADARWINDOW_H
