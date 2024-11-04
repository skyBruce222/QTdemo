/********************************************************************************
** Form generated from reading UI file 'radarparasmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADARPARASMAINWINDOW_H
#define UI_RADARPARASMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_radarParasMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_13;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkBox_6;
    QComboBox *comboBox_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QMenuBar *menubar;

    void setupUi(QMainWindow *radarParasMainWindow)
    {
        if (radarParasMainWindow->objectName().isEmpty())
            radarParasMainWindow->setObjectName(QString::fromUtf8("radarParasMainWindow"));
        radarParasMainWindow->resize(408, 261);
        centralwidget = new QWidget(radarParasMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_13 = new QGridLayout(centralwidget);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QFont font;
        font.setPointSize(9);
        widget_2->setFont(font);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(105, 0));
        comboBox->setMaximumSize(QSize(105, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        comboBox->setFont(font1);

        gridLayout_2->addWidget(comboBox, 0, 3, 1, 1);

        checkBox_2 = new QCheckBox(widget_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font1);

        gridLayout_2->addWidget(checkBox_2, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 4, 1, 1);


        gridLayout_13->addWidget(widget_2, 1, 0, 1, 1);

        widget_13 = new QWidget(centralwidget);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setFont(font);
        horizontalLayout = new QHBoxLayout(widget_13);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget_13);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(120, 30));
        pushButton->setMaximumSize(QSize(120, 30));
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget_13);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(120, 30));
        pushButton_3->setMaximumSize(QSize(120, 30));
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget_13);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(120, 30));
        pushButton_2->setMaximumSize(QSize(120, 30));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_13->addWidget(widget_13, 3, 0, 1, 2);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font1);

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(105, 0));
        lineEdit->setMaximumSize(QSize(105, 16777215));
        lineEdit->setFont(font1);
        lineEdit->setMaxLength(1);

        gridLayout->addWidget(lineEdit, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 4, 1, 1);


        gridLayout_13->addWidget(widget, 0, 0, 1, 1);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setFont(font);
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        checkBox_6 = new QCheckBox(widget_6);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font1);

        gridLayout_6->addWidget(checkBox_6, 0, 1, 1, 1);

        comboBox_5 = new QComboBox(widget_6);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setMinimumSize(QSize(105, 0));
        comboBox_5->setFont(font1);

        gridLayout_6->addWidget(comboBox_5, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 0, 4, 1, 1);


        gridLayout_13->addWidget(widget_6, 2, 0, 1, 1);

        radarParasMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(radarParasMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 408, 21));
        radarParasMainWindow->setMenuBar(menubar);

        retranslateUi(radarParasMainWindow);

        comboBox->setCurrentIndex(-1);
        comboBox_5->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(radarParasMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *radarParasMainWindow)
    {
        radarParasMainWindow->setWindowTitle(QApplication::translate("radarParasMainWindow", "MainWindow", nullptr));
        comboBox->setItemText(0, QApplication::translate("radarParasMainWindow", "None", nullptr));
        comboBox->setItemText(1, QApplication::translate("radarParasMainWindow", "Object", nullptr));
        comboBox->setItemText(2, QApplication::translate("radarParasMainWindow", "Cluster", nullptr));
        comboBox->setItemText(3, QApplication::translate("radarParasMainWindow", "Points", nullptr));

        checkBox_2->setText(QApplication::translate("radarParasMainWindow", "\351\233\267\350\276\276\346\250\241\345\274\217", nullptr));
        pushButton->setText(QApplication::translate("radarParasMainWindow", "\351\273\230\350\256\244", nullptr));
        pushButton_3->setText(QApplication::translate("radarParasMainWindow", "\350\257\273\345\217\226", nullptr));
        pushButton_2->setText(QApplication::translate("radarParasMainWindow", "\345\272\224\347\224\250", nullptr));
        checkBox->setText(QApplication::translate("radarParasMainWindow", "\351\233\267 \350\276\276  ID", nullptr));
        lineEdit->setText(QApplication::translate("radarParasMainWindow", "0", nullptr));
        checkBox_6->setText(QApplication::translate("radarParasMainWindow", "\346\263\242 \347\211\271 \347\216\207 ", nullptr));
        comboBox_5->setItemText(0, QApplication::translate("radarParasMainWindow", "250Kbps", nullptr));
        comboBox_5->setItemText(1, QApplication::translate("radarParasMainWindow", "500Kbps", nullptr));
        comboBox_5->setItemText(2, QApplication::translate("radarParasMainWindow", "1Mbps", nullptr));

    } // retranslateUi

};

namespace Ui {
    class radarParasMainWindow: public Ui_radarParasMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADARPARASMAINWINDOW_H
