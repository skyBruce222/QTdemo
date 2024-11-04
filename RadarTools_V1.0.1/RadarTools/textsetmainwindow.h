#ifndef TEXTSETMAINWINDOW_H
#define TEXTSETMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class textSetMainWindow;
}

class textSetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit textSetMainWindow(QWidget *parent = nullptr);
    ~textSetMainWindow();
    void switchLanguageSlot(QString lang);

private slots:
    void on_pushButton_clicked();

private:
    Ui::textSetMainWindow *ui;
    void initTextSetWindow();
    void switchLanguage(QString);

signals:
    void textTypeSig(bool,bool,bool,bool,bool,bool);
};

#endif // TEXTSETMAINWINDOW_H
