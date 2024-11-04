#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "radarsetmainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMainWindow();

private slots:
    void on_loginPushButton_clicked();

    void switchLanguage(const QString &lang);
    //void switchLanguageCh();

    void on_rememberPasswordCheckBox_clicked();

    void showMainwindow();

    void switchLanguageSlot(QString lang);

private:
    Ui::MainWindow *ui;
    radarSetMainWindow radarSetWin;
    bool rememberPasswd;
    bool languageSwitch = false;
    void actionEventHandle();
signals:
    void switchLanguageSig(QString lang);
};
#endif // MAINWINDOW_H
