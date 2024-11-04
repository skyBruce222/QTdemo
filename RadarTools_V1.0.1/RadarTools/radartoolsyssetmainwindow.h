#ifndef RADARTOOLSYSSETMAINWINDOW_H
#define RADARTOOLSYSSETMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class radarToolSysSetMainWindow;
}

class radarToolSysSetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit radarToolSysSetMainWindow(QWidget *parent = nullptr);
    ~radarToolSysSetMainWindow();

public slots:
    void switchLanguageSlot(QString lang);
private slots:
    void on_pushButton_clicked();

private:
    Ui::radarToolSysSetMainWindow *ui;
    bool languageSwitch = false;

    void iniToolSysSetWindow();

    void switchLanguage(QString);


signals:
    void closeSysWin();
};

#endif // RADARTOOLSYSSETMAINWINDOW_H
