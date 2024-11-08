/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_A;
    QAction *action_O;
    QWidget *centralWidget;
    QLabel *label_logo;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_refresh;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineedit_StartAngle;
    QLineEdit *lineedit_Speed;
    QComboBox *comboType;
    QLabel *label_8;
    QComboBox *comboBoxRotary;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineedit_EndAngle;
    QComboBox *comboBox_azimuth;
    QLabel *label_37;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QComboBox *comboBoxRadars;
    QLabel *label_9;
    QLineEdit *lineedit_RadarBaudRate;
    QLabel *label_10;
    QLabel *label_13;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_11;
    QPushButton *pushButtonDetect;
    QLabel *label_12;
    QPushButton *BtnGenerateReport;
    QTabWidget *tabWidget;
    QChartView *tab;
    QChartView *tab_2;
    QLabel *label_in_status;
    QWidget *widget;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_4;
    QLabel *label_25;
    QLabel *label_CenterAngle;
    QLabel *label_15;
    QLabel *label_36;
    QLabel *label_16;
    QLabel *label_23;
    QLabel *label_34;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_31;
    QLabel *label_35;
    QLabel *label_19;
    QLabel *label_30;
    QLabel *label_28;
    QLabel *label_26;
    QLabel *label_22;
    QLabel *label_14;
    QLabel *label_33;
    QLabel *label_27;
    QLabel *label_17;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_29;
    QLabel *label_32;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_A;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1289, 854);
        MainWindow->setMinimumSize(QSize(1037, 478));
        MainWindow->setMaximumSize(QSize(10370, 4780));
        MainWindow->setBaseSize(QSize(1037, 478));
        MainWindow->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(85, 85, 85);"));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionAbout_A = new QAction(MainWindow);
        actionAbout_A->setObjectName(QStringLiteral("actionAbout_A"));
        action_O = new QAction(MainWindow);
        action_O->setObjectName(QStringLiteral("action_O"));
        action_O->setVisible(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_logo = new QLabel(centralWidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(260, 800, 881, 161));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/img/Mbit_Logo.png")));
        label_logo->setScaledContents(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 251, 781));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_refresh = new QPushButton(layoutWidget);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));
        pushButton_refresh->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_refresh);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 200));
        groupBox_4->setMaximumSize(QSize(250, 200));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 231, 181));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 5, 0, 1, 1, Qt::AlignRight);

        lineedit_StartAngle = new QLineEdit(layoutWidget1);
        lineedit_StartAngle->setObjectName(QStringLiteral("lineedit_StartAngle"));

        gridLayout_2->addWidget(lineedit_StartAngle, 3, 1, 1, 1);

        lineedit_Speed = new QLineEdit(layoutWidget1);
        lineedit_Speed->setObjectName(QStringLiteral("lineedit_Speed"));

        gridLayout_2->addWidget(lineedit_Speed, 5, 1, 1, 1);

        comboType = new QComboBox(layoutWidget1);
        comboType->setObjectName(QStringLiteral("comboType"));

        gridLayout_2->addWidget(comboType, 2, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1, Qt::AlignRight);

        comboBoxRotary = new QComboBox(layoutWidget1);
        comboBoxRotary->setObjectName(QStringLiteral("comboBoxRotary"));

        gridLayout_2->addWidget(comboBoxRotary, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1, Qt::AlignRight);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        lineedit_EndAngle = new QLineEdit(layoutWidget1);
        lineedit_EndAngle->setObjectName(QStringLiteral("lineedit_EndAngle"));

        gridLayout_2->addWidget(lineedit_EndAngle, 4, 1, 1, 1);

        comboBox_azimuth = new QComboBox(layoutWidget1);
        comboBox_azimuth->setObjectName(QStringLiteral("comboBox_azimuth"));

        gridLayout_2->addWidget(comboBox_azimuth, 1, 1, 1, 1);

        label_37 = new QLabel(layoutWidget1);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_2->addWidget(label_37, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 140));
        groupBox_3->setMaximumSize(QSize(250, 140));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 231, 91));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(10);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        comboBoxRadars = new QComboBox(layoutWidget2);
        comboBoxRadars->setObjectName(QStringLiteral("comboBoxRadars"));

        gridLayout_3->addWidget(comboBoxRadars, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1, Qt::AlignRight);

        lineedit_RadarBaudRate = new QLineEdit(layoutWidget2);
        lineedit_RadarBaudRate->setObjectName(QStringLiteral("lineedit_RadarBaudRate"));

        gridLayout_3->addWidget(lineedit_RadarBaudRate, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 150));
        groupBox->setMaximumSize(QSize(250, 150));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(26, 23, 191, 121));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(9);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(16777215, 19));

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        pushButtonDetect = new QPushButton(layoutWidget3);
        pushButtonDetect->setObjectName(QStringLiteral("pushButtonDetect"));

        gridLayout->addWidget(pushButtonDetect, 1, 1, 1, 1);

        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        BtnGenerateReport = new QPushButton(layoutWidget3);
        BtnGenerateReport->setObjectName(QStringLiteral("BtnGenerateReport"));

        gridLayout->addWidget(BtnGenerateReport, 2, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 5);

        verticalLayout->addWidget(groupBox);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(270, 0, 1001, 661));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QChartView();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setAutoFillBackground(false);
        tab->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QChartView();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setAutoFillBackground(false);
        tab_2->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab_2, QString());
        label_in_status = new QLabel(centralWidget);
        label_in_status->setObjectName(QStringLiteral("label_in_status"));
        label_in_status->setGeometry(QRect(10, 785, 331, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(520, 670, 541, 111));
        layoutWidget4 = new QWidget(widget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 0, 541, 111));
        gridLayout_4 = new QGridLayout(layoutWidget4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(layoutWidget4);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_4->addWidget(label_25, 2, 0, 1, 1);

        label_CenterAngle = new QLabel(layoutWidget4);
        label_CenterAngle->setObjectName(QStringLiteral("label_CenterAngle"));

        gridLayout_4->addWidget(label_CenterAngle, 0, 1, 1, 1);

        label_15 = new QLabel(layoutWidget4);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 0, 2, 1, 1);

        label_36 = new QLabel(layoutWidget4);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_4->addWidget(label_36, 3, 3, 1, 1);

        label_16 = new QLabel(layoutWidget4);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_4->addWidget(label_16, 1, 1, 1, 1);

        label_23 = new QLabel(layoutWidget4);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_4->addWidget(label_23, 0, 5, 1, 1);

        label_34 = new QLabel(layoutWidget4);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_4->addWidget(label_34, 2, 4, 1, 1);

        label_18 = new QLabel(layoutWidget4);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_4->addWidget(label_18, 0, 4, 1, 1);

        label_20 = new QLabel(layoutWidget4);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_4->addWidget(label_20, 1, 4, 1, 1);

        label_31 = new QLabel(layoutWidget4);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_4->addWidget(label_31, 3, 5, 1, 1);

        label_35 = new QLabel(layoutWidget4);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_4->addWidget(label_35, 3, 4, 1, 1);

        label_19 = new QLabel(layoutWidget4);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_4->addWidget(label_19, 0, 3, 1, 1, Qt::AlignRight);

        label_30 = new QLabel(layoutWidget4);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_4->addWidget(label_30, 3, 1, 1, 1);

        label_28 = new QLabel(layoutWidget4);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_4->addWidget(label_28, 3, 2, 1, 1);

        label_26 = new QLabel(layoutWidget4);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_4->addWidget(label_26, 2, 2, 1, 1);

        label_22 = new QLabel(layoutWidget4);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_4->addWidget(label_22, 1, 2, 1, 1);

        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1, Qt::AlignRight);

        label_33 = new QLabel(layoutWidget4);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_4->addWidget(label_33, 2, 5, 1, 1);

        label_27 = new QLabel(layoutWidget4);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_4->addWidget(label_27, 2, 1, 1, 1);

        label_17 = new QLabel(layoutWidget4);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_4->addWidget(label_17, 1, 0, 1, 1);

        label_21 = new QLabel(layoutWidget4);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_4->addWidget(label_21, 1, 3, 1, 1);

        label_24 = new QLabel(layoutWidget4);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_4->addWidget(label_24, 1, 5, 1, 1);

        label_29 = new QLabel(layoutWidget4);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_4->addWidget(label_29, 3, 0, 1, 1);

        label_32 = new QLabel(layoutWidget4);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_4->addWidget(label_32, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1289, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_A = new QMenu(menuBar);
        menu_A->setObjectName(QStringLiteral("menu_A"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(action_O);
        mainToolBar->addAction(actionAbout_A);
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_A->menuAction());
        menu->addAction(action_O);
        menu_A->addAction(actionAbout_A);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        actionAbout_A->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        action_O->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256(&O)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_O->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_logo->setText(QString());
        pushButton_refresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243", Q_NULLPTR));
        groupBox_4->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\350\275\254\345\217\260\344\270\262\345\217\243", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\275\254\345\217\260\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        label_4->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\350\275\254\351\200\237\357\274\232", Q_NULLPTR));
        lineedit_StartAngle->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineedit_StartAngle->setText(QApplication::translate("MainWindow", "-60.0", Q_NULLPTR));
        lineedit_Speed->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineedit_Speed->setText(QApplication::translate("MainWindow", "1.0", Q_NULLPTR));
        comboType->clear();
        comboType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\213\346\226\271\344\275\215\350\275\264", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\277\257\344\273\260\350\275\264", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\212\346\226\271\344\275\215\346\250\252\346\273\232", Q_NULLPTR)
        );
        comboType->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_8->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        comboBoxRotary->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_6->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_5->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\226\271\344\275\215\350\275\264\357\274\232", Q_NULLPTR));
        lineedit_EndAngle->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineedit_EndAngle->setText(QApplication::translate("MainWindow", "60.0", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "\346\226\271\344\275\215\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        groupBox_3->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\351\233\267\350\276\276\344\270\262\345\217\243", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\233\267\350\276\276\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        comboBoxRadars->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        lineedit_RadarBaudRate->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineedit_RadarBaudRate->setText(QApplication::translate("MainWindow", "115200", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\351\233\267\350\276\276\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "1.0.0", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "  \346\243\200\346\265\213\345\222\214\347\224\237\346\210\220\346\212\245\345\221\212", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", " \345\275\223\345\211\215\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_11->setText(QString());
        pushButtonDetect->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\265\213\351\207\217", Q_NULLPTR));
        label_12->setText(QString());
        BtnGenerateReport->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\346\212\245\345\221\212", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        label_in_status->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "-6dB\350\265\267\345\247\213\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_CenterAngle->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "-12dB\347\273\223\346\235\237\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "db", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\350\203\275\351\207\217\345\200\274\357\274\232", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "0.0", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "-6dB\350\247\222\345\272\246\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "-12dB\350\247\222\345\272\246\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\345\272\246", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "-6dB\347\273\223\346\235\237\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "-12dB\350\265\267\345\247\213\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\351\205\215\347\275\256(&C)", Q_NULLPTR));
        menu_A->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
