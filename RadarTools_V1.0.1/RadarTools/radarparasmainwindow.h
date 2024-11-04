#ifndef RADARPARASMAINWINDOW_H
#define RADARPARASMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class radarParasMainWindow;
}

class radarParasMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit radarParasMainWindow(QWidget *parent = nullptr);
    ~radarParasMainWindow();
    void switchLanguageSlot(QString lang);

public slots:
    void connectSucceedSlot(bool);
    void radarDataRespond(unsigned char id, unsigned char mode, unsigned char baud);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::radarParasMainWindow *ui;
    bool connectFlag = false;
    bool languageFlag = true;
    void initRadarParasWindow();
    void switchLanguage(QString);

signals:
    void setParasSig(unsigned char *data, uint8_t len);
    void readParasSig();
};

#endif // RADARPARASMAINWINDOW_H
