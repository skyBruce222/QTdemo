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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_burnStatus_6;
    QLabel *label_23;
    QTextBrowser *textBrowser_burnStatus_8;
    QProgressBar *update_progressBar_4;
    QLabel *label_26;
    QLabel *label_10;
    QTextBrowser *textBrowser_burnStatus;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_13;
    QLabel *label_burnState_6;
    QLabel *label_2;
    QLabel *label;
    QProgressBar *update_progressBar_7;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_burnState_7;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_8;
    QTextBrowser *textBrowser_burnStatus_4;
    QComboBox *comboBox_uartNumber_5;
    QTextBrowser *textBrowser_burnStatus_5;
    QLabel *label_30;
    QLineEdit *firmwarename_lineEdit;
    QLabel *label_burnState_5;
    QProgressBar *update_progressBar_3;
    QSpacerItem *horizontalSpacer_11;
    QComboBox *comboBox_uartNumber_3;
    QComboBox *comboBox_uartNumber_6;
    QLabel *label_3;
    QLabel *label_29;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_25;
    QSpacerItem *verticalSpacer;
    QLabel *label_12;
    QTextBrowser *textBrowser_burnStatus_2;
    QLabel *label_burnState_8;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_15;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_4;
    QLabel *label_17;
    QComboBox *comboBox_uartNumber_7;
    QProgressBar *update_progressBar_8;
    QLabel *label_burnState;
    QLabel *label_32;
    QLabel *label_burnState_3;
    QSpacerItem *verticalSpacer_6;
    QProgressBar *update_progressBar_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *run_pushButton;
    QComboBox *comboBox_uartNumber_4;
    QComboBox *comboBox_uartNumber;
    QLabel *label_19;
    QPushButton *openbin_pushButton;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_burnState_4;
    QLabel *label_burnState_2;
    QComboBox *comboBox_uartNumber_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_31;
    QProgressBar *update_progressBar_5;
    QPushButton *pushButton_updateUart;
    QComboBox *comboBox_uartNumber_8;
    QLabel *label_8;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_24;
    QProgressBar *update_progressBar;
    QLabel *label_27;
    QLabel *label_7;
    QTextBrowser *textBrowser_burnStatus_3;
    QLabel *label_28;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *update_progressBar_6;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_14;
    QTextBrowser *textBrowser_burnStatus_7;
    QLabel *label_22;
    QLabel *label_33;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1267, 948);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser_burnStatus_6 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_6->setObjectName(QString::fromUtf8("textBrowser_burnStatus_6"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_6->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_6, 13, 5, 1, 3);

        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_23, 9, 9, 1, 1);

        textBrowser_burnStatus_8 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_8->setObjectName(QString::fromUtf8("textBrowser_burnStatus_8"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_8->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_8, 13, 13, 1, 3);

        update_progressBar_4 = new QProgressBar(centralWidget);
        update_progressBar_4->setObjectName(QString::fromUtf8("update_progressBar_4"));
        sizePolicy.setHeightForWidth(update_progressBar_4->sizePolicy().hasHeightForWidth());
        update_progressBar_4->setSizePolicy(sizePolicy);
        update_progressBar_4->setValue(0);

        gridLayout->addWidget(update_progressBar_4, 4, 14, 1, 2);

        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy1.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_26, 9, 13, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_10, 3, 5, 1, 1);

        textBrowser_burnStatus = new QTextBrowser(centralWidget);
        textBrowser_burnStatus->setObjectName(QString::fromUtf8("textBrowser_burnStatus"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus, 7, 1, 1, 3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 8, 16, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_13, 5, 13, 1, 1);

        label_burnState_6 = new QLabel(centralWidget);
        label_burnState_6->setObjectName(QString::fromUtf8("label_burnState_6"));

        gridLayout->addWidget(label_burnState_6, 11, 6, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        update_progressBar_7 = new QProgressBar(centralWidget);
        update_progressBar_7->setObjectName(QString::fromUtf8("update_progressBar_7"));
        sizePolicy.setHeightForWidth(update_progressBar_7->sizePolicy().hasHeightForWidth());
        update_progressBar_7->setSizePolicy(sizePolicy);
        update_progressBar_7->setValue(0);

        gridLayout->addWidget(update_progressBar_7, 10, 10, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 16, 0, 1, 18);

        label_burnState_7 = new QLabel(centralWidget);
        label_burnState_7->setObjectName(QString::fromUtf8("label_burnState_7"));

        gridLayout->addWidget(label_burnState_7, 11, 10, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_11, 3, 13, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 14, 8, 1, 1);

        textBrowser_burnStatus_4 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_4->setObjectName(QString::fromUtf8("textBrowser_burnStatus_4"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_4->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_4, 7, 13, 1, 3);

        comboBox_uartNumber_5 = new QComboBox(centralWidget);
        comboBox_uartNumber_5->setObjectName(QString::fromUtf8("comboBox_uartNumber_5"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_5->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_5, 9, 2, 1, 1);

        textBrowser_burnStatus_5 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_5->setObjectName(QString::fromUtf8("textBrowser_burnStatus_5"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_5->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_5, 13, 1, 1, 3);

        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout->addWidget(label_30, 12, 1, 1, 1);

        firmwarename_lineEdit = new QLineEdit(centralWidget);
        firmwarename_lineEdit->setObjectName(QString::fromUtf8("firmwarename_lineEdit"));
        sizePolicy.setHeightForWidth(firmwarename_lineEdit->sizePolicy().hasHeightForWidth());
        firmwarename_lineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(firmwarename_lineEdit, 1, 2, 1, 13);

        label_burnState_5 = new QLabel(centralWidget);
        label_burnState_5->setObjectName(QString::fromUtf8("label_burnState_5"));

        gridLayout->addWidget(label_burnState_5, 11, 2, 1, 1);

        update_progressBar_3 = new QProgressBar(centralWidget);
        update_progressBar_3->setObjectName(QString::fromUtf8("update_progressBar_3"));
        sizePolicy.setHeightForWidth(update_progressBar_3->sizePolicy().hasHeightForWidth());
        update_progressBar_3->setSizePolicy(sizePolicy);
        update_progressBar_3->setValue(0);

        gridLayout->addWidget(update_progressBar_3, 4, 10, 1, 2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 9, 7, 1, 1);

        comboBox_uartNumber_3 = new QComboBox(centralWidget);
        comboBox_uartNumber_3->setObjectName(QString::fromUtf8("comboBox_uartNumber_3"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_3->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_3, 3, 10, 1, 1);

        comboBox_uartNumber_6 = new QComboBox(centralWidget);
        comboBox_uartNumber_6->setObjectName(QString::fromUtf8("comboBox_uartNumber_6"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_6->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_6->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_6, 9, 6, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout->addWidget(label_29, 6, 13, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 9, 3, 1, 1);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy1.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_25, 11, 13, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 8, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_12, 4, 13, 1, 1);

        textBrowser_burnStatus_2 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_2->setObjectName(QString::fromUtf8("textBrowser_burnStatus_2"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_2->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_2, 7, 5, 1, 3);

        label_burnState_8 = new QLabel(centralWidget);
        label_burnState_8->setObjectName(QString::fromUtf8("label_burnState_8"));

        gridLayout->addWidget(label_burnState_8, 11, 14, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 9, 15, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_15, 9, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 3, 15, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_17, 11, 1, 1, 1);

        comboBox_uartNumber_7 = new QComboBox(centralWidget);
        comboBox_uartNumber_7->setObjectName(QString::fromUtf8("comboBox_uartNumber_7"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_7->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_7, 9, 10, 1, 1);

        update_progressBar_8 = new QProgressBar(centralWidget);
        update_progressBar_8->setObjectName(QString::fromUtf8("update_progressBar_8"));
        sizePolicy.setHeightForWidth(update_progressBar_8->sizePolicy().hasHeightForWidth());
        update_progressBar_8->setSizePolicy(sizePolicy);
        update_progressBar_8->setValue(0);

        gridLayout->addWidget(update_progressBar_8, 10, 14, 1, 2);

        label_burnState = new QLabel(centralWidget);
        label_burnState->setObjectName(QString::fromUtf8("label_burnState"));

        gridLayout->addWidget(label_burnState, 5, 2, 1, 1);

        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout->addWidget(label_32, 12, 9, 1, 1);

        label_burnState_3 = new QLabel(centralWidget);
        label_burnState_3->setObjectName(QString::fromUtf8("label_burnState_3"));

        gridLayout->addWidget(label_burnState_3, 5, 10, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 8, 10, 1, 1);

        update_progressBar_2 = new QProgressBar(centralWidget);
        update_progressBar_2->setObjectName(QString::fromUtf8("update_progressBar_2"));
        sizePolicy.setHeightForWidth(update_progressBar_2->sizePolicy().hasHeightForWidth());
        update_progressBar_2->setSizePolicy(sizePolicy);
        update_progressBar_2->setValue(0);

        gridLayout->addWidget(update_progressBar_2, 4, 6, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 18);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 9, 11, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 4, 1, 1);

        run_pushButton = new QPushButton(centralWidget);
        run_pushButton->setObjectName(QString::fromUtf8("run_pushButton"));
        sizePolicy.setHeightForWidth(run_pushButton->sizePolicy().hasHeightForWidth());
        run_pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(run_pushButton, 15, 15, 1, 1);

        comboBox_uartNumber_4 = new QComboBox(centralWidget);
        comboBox_uartNumber_4->setObjectName(QString::fromUtf8("comboBox_uartNumber_4"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_4->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_4, 3, 14, 1, 1);

        comboBox_uartNumber = new QComboBox(centralWidget);
        comboBox_uartNumber->setObjectName(QString::fromUtf8("comboBox_uartNumber"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber, 3, 2, 1, 1);

        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_19, 11, 5, 1, 1);

        openbin_pushButton = new QPushButton(centralWidget);
        openbin_pushButton->setObjectName(QString::fromUtf8("openbin_pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openbin_pushButton->sizePolicy().hasHeightForWidth());
        openbin_pushButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(openbin_pushButton, 1, 15, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 8, 14, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 8, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 8, 12, 1, 1);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_18, 5, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 3, 1, 1);

        label_burnState_4 = new QLabel(centralWidget);
        label_burnState_4->setObjectName(QString::fromUtf8("label_burnState_4"));

        gridLayout->addWidget(label_burnState_4, 5, 14, 1, 1);

        label_burnState_2 = new QLabel(centralWidget);
        label_burnState_2->setObjectName(QString::fromUtf8("label_burnState_2"));

        gridLayout->addWidget(label_burnState_2, 5, 6, 1, 1);

        comboBox_uartNumber_2 = new QComboBox(centralWidget);
        comboBox_uartNumber_2->setObjectName(QString::fromUtf8("comboBox_uartNumber_2"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_2->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_2, 3, 6, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 8, 6, 1, 1);

        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout->addWidget(label_31, 12, 5, 1, 1);

        update_progressBar_5 = new QProgressBar(centralWidget);
        update_progressBar_5->setObjectName(QString::fromUtf8("update_progressBar_5"));
        sizePolicy.setHeightForWidth(update_progressBar_5->sizePolicy().hasHeightForWidth());
        update_progressBar_5->setSizePolicy(sizePolicy);
        update_progressBar_5->setValue(0);

        gridLayout->addWidget(update_progressBar_5, 10, 2, 1, 2);

        pushButton_updateUart = new QPushButton(centralWidget);
        pushButton_updateUart->setObjectName(QString::fromUtf8("pushButton_updateUart"));
        sizePolicy2.setHeightForWidth(pushButton_updateUart->sizePolicy().hasHeightForWidth());
        pushButton_updateUart->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_updateUart, 15, 14, 1, 1);

        comboBox_uartNumber_8 = new QComboBox(centralWidget);
        comboBox_uartNumber_8->setObjectName(QString::fromUtf8("comboBox_uartNumber_8"));
        sizePolicy1.setHeightForWidth(comboBox_uartNumber_8->sizePolicy().hasHeightForWidth());
        comboBox_uartNumber_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_uartNumber_8, 9, 14, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_8, 4, 9, 1, 1);

        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_21, 10, 5, 1, 1);

        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_20, 9, 5, 1, 1);

        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy1.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_24, 10, 9, 1, 1);

        update_progressBar = new QProgressBar(centralWidget);
        update_progressBar->setObjectName(QString::fromUtf8("update_progressBar"));
        sizePolicy.setHeightForWidth(update_progressBar->sizePolicy().hasHeightForWidth());
        update_progressBar->setSizePolicy(sizePolicy);
        update_progressBar->setValue(0);

        gridLayout->addWidget(update_progressBar, 4, 2, 1, 2);

        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy1.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_27, 10, 13, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_7, 3, 9, 1, 1);

        textBrowser_burnStatus_3 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_3->setObjectName(QString::fromUtf8("textBrowser_burnStatus_3"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_3->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_3, 7, 9, 1, 3);

        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout->addWidget(label_28, 6, 9, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_16, 10, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 8, 8, 1, 1);

        update_progressBar_6 = new QProgressBar(centralWidget);
        update_progressBar_6->setObjectName(QString::fromUtf8("update_progressBar_6"));
        sizePolicy.setHeightForWidth(update_progressBar_6->sizePolicy().hasHeightForWidth());
        update_progressBar_6->setSizePolicy(sizePolicy);
        update_progressBar_6->setValue(0);

        gridLayout->addWidget(update_progressBar_6, 10, 6, 1, 2);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_9, 5, 9, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 8, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 3, 11, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_14, 4, 5, 1, 1);

        textBrowser_burnStatus_7 = new QTextBrowser(centralWidget);
        textBrowser_burnStatus_7->setObjectName(QString::fromUtf8("textBrowser_burnStatus_7"));
        sizePolicy.setHeightForWidth(textBrowser_burnStatus_7->sizePolicy().hasHeightForWidth());
        textBrowser_burnStatus_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_burnStatus_7, 13, 9, 1, 3);

        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_22, 11, 9, 1, 1);

        label_33 = new QLabel(centralWidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout->addWidget(label_33, 12, 13, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1267, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(firmwarename_lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TIBurnTool_v1.0.4", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_burnState_6->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\233\272\344\273\266\351\200\211\346\213\251\357\274\232", nullptr));
        label_burnState_7->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        label_burnState_5->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_burnState_8->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_burnState->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        label_burnState_3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        run_pushButton->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\347\203\247\345\275\225", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        openbin_pushButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_burnState_4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_burnState_2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        pushButton_updateUart->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\347\212\266\346\200\201\357\274\232", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
