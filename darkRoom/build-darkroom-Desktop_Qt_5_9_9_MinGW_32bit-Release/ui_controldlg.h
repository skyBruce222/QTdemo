/********************************************************************************
** Form generated from reading UI file 'controldlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLDLG_H
#define UI_CONTROLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox_4;
    QComboBox *comboBoxRotary;
    QLabel *label_5;
    QLineEdit *lineedit_Speed;
    QLineEdit *lineedit_position;
    QLabel *label_6;
    QLabel *label_4;
    QComboBox *comboType;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_lead;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_Ccw;
    QPushButton *buttonCw;
    QPushButton *pushButton_calibration;
    QGroupBox *groupBox_3;
    QComboBox *comboBoxRadars;
    QPushButton *pushButton_noput;
    QPushButton *pushButton_output;
    QLineEdit *lineEdit_radarID;
    QLabel *label_9;
    QPushButton *pushButton_uid;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_precision;
    QLabel *label_7;
    QCheckBox *checkBox_saveData;
    QPushButton *pushButton_refresh;
    QLineEdit *lineEdit_distance;
    QLabel *label_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(644, 443);
        Dialog->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(85, 85, 85);"));
        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 30, 611, 51));
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"color: rgb(36, 195, 207);"));
        lcdNumber->setDigitCount(7);
        lcdNumber->setProperty("value", QVariant(1111.11));
        groupBox_4 = new QGroupBox(Dialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(320, 160, 311, 271));
        comboBoxRotary = new QComboBox(groupBox_4);
        comboBoxRotary->setObjectName(QStringLiteral("comboBoxRotary"));
        comboBoxRotary->setGeometry(QRect(10, 20, 291, 21));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 50, 51, 41));
        label_5->setTextFormat(Qt::AutoText);
        lineedit_Speed = new QLineEdit(groupBox_4);
        lineedit_Speed->setObjectName(QStringLiteral("lineedit_Speed"));
        lineedit_Speed->setGeometry(QRect(70, 100, 231, 20));
        lineedit_position = new QLineEdit(groupBox_4);
        lineedit_position->setObjectName(QStringLiteral("lineedit_position"));
        lineedit_position->setGeometry(QRect(70, 140, 231, 20));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 54, 41));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 90, 54, 41));
        comboType = new QComboBox(groupBox_4);
        comboType->setObjectName(QStringLiteral("comboType"));
        comboType->setGeometry(QRect(70, 60, 231, 22));
        pushButton_stop = new QPushButton(groupBox_4);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(220, 230, 81, 31));
        pushButton_lead = new QPushButton(groupBox_4);
        pushButton_lead->setObjectName(QStringLiteral("pushButton_lead"));
        pushButton_lead->setGeometry(QRect(220, 180, 81, 31));
        pushButton_reset = new QPushButton(groupBox_4);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(120, 230, 81, 31));
        pushButton_Ccw = new QPushButton(groupBox_4);
        pushButton_Ccw->setObjectName(QStringLiteral("pushButton_Ccw"));
        pushButton_Ccw->setGeometry(QRect(120, 180, 81, 31));
        buttonCw = new QPushButton(groupBox_4);
        buttonCw->setObjectName(QStringLiteral("buttonCw"));
        buttonCw->setGeometry(QRect(20, 180, 81, 31));
        pushButton_calibration = new QPushButton(groupBox_4);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        pushButton_calibration->setGeometry(QRect(20, 230, 81, 31));
        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 160, 281, 271));
        comboBoxRadars = new QComboBox(groupBox_3);
        comboBoxRadars->setObjectName(QStringLiteral("comboBoxRadars"));
        comboBoxRadars->setGeometry(QRect(10, 20, 261, 22));
        pushButton_noput = new QPushButton(groupBox_3);
        pushButton_noput->setObjectName(QStringLiteral("pushButton_noput"));
        pushButton_noput->setGeometry(QRect(190, 180, 81, 31));
        pushButton_noput->setAutoDefault(true);
        pushButton_noput->setFlat(false);
        pushButton_output = new QPushButton(groupBox_3);
        pushButton_output->setObjectName(QStringLiteral("pushButton_output"));
        pushButton_output->setGeometry(QRect(100, 180, 81, 31));
        pushButton_output->setAutoDefault(true);
        pushButton_output->setFlat(false);
        lineEdit_radarID = new QLineEdit(groupBox_3);
        lineEdit_radarID->setObjectName(QStringLiteral("lineEdit_radarID"));
        lineEdit_radarID->setGeometry(QRect(70, 70, 201, 20));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 54, 41));
        pushButton_uid = new QPushButton(groupBox_3);
        pushButton_uid->setObjectName(QStringLiteral("pushButton_uid"));
        pushButton_uid->setGeometry(QRect(10, 180, 81, 31));
        pushButton_uid->setAutoDefault(true);
        pushButton_uid->setFlat(false);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 90, 611, 61));
        lineEdit_precision = new QLineEdit(groupBox);
        lineEdit_precision->setObjectName(QStringLiteral("lineEdit_precision"));
        lineEdit_precision->setGeometry(QRect(200, 20, 111, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 10, 54, 41));
        checkBox_saveData = new QCheckBox(groupBox);
        checkBox_saveData->setObjectName(QStringLiteral("checkBox_saveData"));
        checkBox_saveData->setGeometry(QRect(20, 20, 71, 21));
        QFont font;
        font.setFamily(QStringLiteral("ADMUI3Lg"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        checkBox_saveData->setFont(font);
        checkBox_saveData->setChecked(false);
        pushButton_refresh = new QPushButton(groupBox);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));
        pushButton_refresh->setGeometry(QRect(510, 20, 91, 21));
        pushButton_refresh->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_distance = new QLineEdit(groupBox);
        lineEdit_distance->setObjectName(QStringLiteral("lineEdit_distance"));
        lineEdit_distance->setGeometry(QRect(380, 20, 121, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(320, 10, 54, 41));

        retranslateUi(Dialog);

        pushButton_stop->setDefault(false);
        pushButton_lead->setDefault(false);
        pushButton_reset->setDefault(false);
        pushButton_Ccw->setDefault(false);
        buttonCw->setDefault(false);
        pushButton_calibration->setDefault(false);
        pushButton_noput->setDefault(false);
        pushButton_output->setDefault(false);
        pushButton_uid->setDefault(false);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        groupBox_4->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Dialog", "\350\275\254\345\217\260\344\270\262\345\217\243", Q_NULLPTR));
        comboBoxRotary->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_5->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "\346\216\247\345\210\266\350\275\264", Q_NULLPTR));
        lineedit_Speed->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineedit_Speed->setText(QApplication::translate("Dialog", "1.0", Q_NULLPTR));
        lineedit_position->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_6->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "\344\275\215    \347\275\256", Q_NULLPTR));
        label_4->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "\351\200\237   \345\272\246", Q_NULLPTR));
        comboType->clear();
        comboType->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\344\270\213\346\226\271\344\275\215\350\275\264", Q_NULLPTR)
         << QApplication::translate("Dialog", "\344\277\257\344\273\260\350\275\264", Q_NULLPTR)
         << QApplication::translate("Dialog", "\344\270\212\346\226\271\344\275\215\346\250\252\346\273\232", Q_NULLPTR)
        );
        comboType->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_stop->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("Dialog", "\345\201\234\346\255\242", Q_NULLPTR));
        pushButton_lead->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_lead->setText(QApplication::translate("Dialog", "\345\274\225\345\257\274", Q_NULLPTR));
        pushButton_reset->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_reset->setText(QApplication::translate("Dialog", "\351\207\215\347\275\256", Q_NULLPTR));
        pushButton_Ccw->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_Ccw->setText(QApplication::translate("Dialog", "\351\200\206\345\220\221", Q_NULLPTR));
        buttonCw->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        buttonCw->setText(QApplication::translate("Dialog", "\346\255\243\345\220\221", Q_NULLPTR));
        pushButton_calibration->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_calibration->setText(QApplication::translate("Dialog", "\346\240\241\351\233\266", Q_NULLPTR));
        groupBox_3->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Dialog", "\351\233\267\350\276\276\344\270\262\345\217\243", Q_NULLPTR));
        comboBoxRadars->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_noput->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_noput->setText(QApplication::translate("Dialog", "\347\246\201\346\255\242\350\276\223\345\207\272", Q_NULLPTR));
        pushButton_output->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_output->setText(QApplication::translate("Dialog", "\345\274\200\345\220\257\350\276\223\345\207\272", Q_NULLPTR));
        lineEdit_radarID->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_9->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog", "\351\233\267\350\276\276\346\240\207\345\217\267", Q_NULLPTR));
        pushButton_uid->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        pushButton_uid->setText(QApplication::translate("Dialog", "\350\216\267\345\217\226\346\240\207\345\217\267", Q_NULLPTR));
        groupBox->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "\351\205\215\347\275\256", Q_NULLPTR));
        lineEdit_precision->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineEdit_precision->setText(QApplication::translate("Dialog", "0.10", Q_NULLPTR));
        label_7->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", "\345\220\210\346\240\274\350\257\257\345\267\256", Q_NULLPTR));
        checkBox_saveData->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        checkBox_saveData->setText(QApplication::translate("Dialog", "\346\225\260\346\215\256\350\256\260\345\275\225", Q_NULLPTR));
        pushButton_refresh->setText(QApplication::translate("Dialog", "\345\210\267\346\226\260\344\270\262\345\217\243", Q_NULLPTR));
        lineEdit_distance->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        lineEdit_distance->setText(QApplication::translate("Dialog", "6.0", Q_NULLPTR));
        label_8->setStyleSheet(QApplication::translate("Dialog", "color: rgb(255, 255, 255);", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog", "\346\240\207\346\240\241\350\267\235\347\246\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLDLG_H