/********************************************************************************
** Form generated from reading UI file 'radarareamainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADARAREAMAINWINDOW_H
#define UI_RADARAREAMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_radarAreaMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_7;
    QGridLayout *gridLayout_7;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget_9;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_8;
    QGridLayout *gridLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame;
    QMenuBar *menubar;

    void setupUi(QMainWindow *radarAreaMainWindow)
    {
        if (radarAreaMainWindow->objectName().isEmpty())
            radarAreaMainWindow->setObjectName(QString::fromUtf8("radarAreaMainWindow"));
        radarAreaMainWindow->resize(600, 430);
        radarAreaMainWindow->setMinimumSize(QSize(600, 430));
        radarAreaMainWindow->setMaximumSize(QSize(600, 430));
        centralwidget = new QWidget(radarAreaMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(10, 226, 581, 191));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        widget_7->setFont(font);
        gridLayout_7 = new QGridLayout(widget_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget_4 = new QWidget(widget_7);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setFont(font);
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(100, 25));
        lineEdit_2->setMaximumSize(QSize(100, 25));
        lineEdit_2->setFont(font);

        gridLayout_4->addWidget(lineEdit_2, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget_4, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        widget_3 = new QWidget(widget_7);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setFont(font);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(100, 25));
        lineEdit->setMaximumSize(QSize(100, 25));
        lineEdit->setFont(font);

        gridLayout_3->addWidget(lineEdit, 0, 2, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout_3->addWidget(label_3, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget_3, 0, 2, 1, 1);

        widget = new QWidget(widget_7);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget, 0, 0, 1, 1);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setFont(font);
        gridLayout_9 = new QGridLayout(widget_9);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        pushButton = new QPushButton(widget_9);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(120, 30));
        pushButton->setMaximumSize(QSize(120, 30));
        pushButton->setFont(font);

        gridLayout_9->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(widget_9);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(120, 30));
        pushButton_2->setMaximumSize(QSize(120, 30));
        pushButton_2->setFont(font);

        gridLayout_9->addWidget(pushButton_2, 0, 4, 1, 1);

        widget_8 = new QWidget(widget_9);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setFont(font);
        gridLayout_8 = new QGridLayout(widget_8);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout_8->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget_8);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(80, 25));
        lineEdit_5->setMaximumSize(QSize(80, 25));
        lineEdit_5->setFont(font);
        lineEdit_5->setMaxLength(2);

        gridLayout_8->addWidget(lineEdit_5, 0, 1, 1, 1);


        gridLayout_9->addWidget(widget_8, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_9, 2, 0, 1, 5);

        widget_5 = new QWidget(widget_7);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setFont(font);
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_3 = new QLineEdit(widget_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(100, 25));
        lineEdit_3->setMaximumSize(QSize(100, 25));
        lineEdit_3->setFont(font);

        gridLayout_5->addWidget(lineEdit_3, 0, 2, 1, 1);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_5->addWidget(label_5, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget_5, 0, 4, 1, 1);

        widget_2 = new QWidget(widget_7);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setFont(font);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(widget_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font);

        gridLayout_2->addWidget(comboBox_2, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget_2, 1, 0, 1, 1);

        widget_6 = new QWidget(widget_7);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setFont(font);
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget_6);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(100, 25));
        lineEdit_4->setMaximumSize(QSize(100, 25));
        lineEdit_4->setFont(font);

        gridLayout_6->addWidget(lineEdit_4, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget_6, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 581, 211));
        frame->setFont(font);
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/img/radarArea.bmp);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        radarAreaMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(radarAreaMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        radarAreaMainWindow->setMenuBar(menubar);

        retranslateUi(radarAreaMainWindow);

        comboBox_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(radarAreaMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *radarAreaMainWindow)
    {
        radarAreaMainWindow->setWindowTitle(QApplication::translate("radarAreaMainWindow", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("radarAreaMainWindow", "P2_Lat(m)", nullptr));
        lineEdit_2->setText(QApplication::translate("radarAreaMainWindow", "-6", nullptr));
        lineEdit->setText(QApplication::translate("radarAreaMainWindow", "6", nullptr));
        label_3->setText(QApplication::translate("radarAreaMainWindow", "P1_Lat(m)", nullptr));
        label->setText(QApplication::translate("radarAreaMainWindow", "\345\214\272\345\237\237\344\275\277\350\203\275", nullptr));
        comboBox->setItemText(0, QApplication::translate("radarAreaMainWindow", "Active", nullptr));
        comboBox->setItemText(1, QApplication::translate("radarAreaMainWindow", "InActive", nullptr));

        pushButton->setText(QApplication::translate("radarAreaMainWindow", "\350\257\273\345\217\226", nullptr));
        pushButton_2->setText(QApplication::translate("radarAreaMainWindow", "\345\272\224\347\224\250", nullptr));
        label_7->setText(QApplication::translate("radarAreaMainWindow", "\346\234\200\345\244\247\347\233\256\346\240\207\350\276\223\345\207\272\344\270\252\346\225\260", nullptr));
        lineEdit_5->setText(QApplication::translate("radarAreaMainWindow", "8", nullptr));
        lineEdit_3->setText(QApplication::translate("radarAreaMainWindow", "0", nullptr));
        label_5->setText(QApplication::translate("radarAreaMainWindow", "P1_Long(m)", nullptr));
        label_2->setText(QApplication::translate("radarAreaMainWindow", "\345\235\220\346\240\207\344\275\277\350\203\275", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("radarAreaMainWindow", "Active", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("radarAreaMainWindow", "InActive", nullptr));

        label_6->setText(QApplication::translate("radarAreaMainWindow", "P2_Long(m)", nullptr));
        lineEdit_4->setText(QApplication::translate("radarAreaMainWindow", "12", nullptr));
    } // retranslateUi

};

namespace Ui {
    class radarAreaMainWindow: public Ui_radarAreaMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADARAREAMAINWINDOW_H
