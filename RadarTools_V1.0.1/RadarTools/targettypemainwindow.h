#ifndef TARGETTYPEMAINWINDOW_H
#define TARGETTYPEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class targetTypeMainWindow;
}

class targetTypeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit targetTypeMainWindow(QWidget *parent = nullptr);
    ~targetTypeMainWindow();
    void switchLanguageSlot(QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::targetTypeMainWindow *ui;
    void initTargetTypeWindow();
    void switchLanguage(QString);
};

#endif // TARGETTYPEMAINWINDOW_H
