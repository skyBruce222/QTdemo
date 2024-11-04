#ifndef RADARAREAMAINWINDOW_H
#define RADARAREAMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class radarAreaMainWindow;
}

class radarAreaMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit radarAreaMainWindow(QWidget *parent = nullptr);
    ~radarAreaMainWindow();
    void switchLanguageSlot(QString lang);

public slots:
    void connectSucceedSlot(bool);
    void radarDataRespond(short int, short int, short int, short int, short int, short int);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::radarAreaMainWindow *ui;
    bool connectFlag = false;
    bool languageFlag = true;
    void initAreaWin();
    void switchLanguage(QString);
signals:
    void setAreaSig(unsigned char *, uint8_t);
    void readAreaSig();
};

#endif // RADARAREAMAINWINDOW_H
