#ifndef SAVEDATAMAINWINDOW_H
#define SAVEDATAMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class saveDataMainWindow;
}

class saveDataMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit saveDataMainWindow(QWidget *parent = nullptr);
    ~saveDataMainWindow();
public slots:
    void switchLanguageSlot(QString lang);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::saveDataMainWindow *ui;
    void initSaveWindow();
    void switchLanguage(QString);
    bool languageSwt = false;

signals:
    void saveDataSig(QString,QString);
};

#endif // SAVEDATAMAINWINDOW_H
