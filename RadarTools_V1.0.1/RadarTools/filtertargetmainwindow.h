#ifndef FILTERTARGETMAINWINDOW_H
#define FILTERTARGETMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class filterTargetMainWindow;
}

class filterTargetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit filterTargetMainWindow(QWidget *parent = nullptr);
    ~filterTargetMainWindow();
    void switchLanguageSlot(QString);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::filterTargetMainWindow *ui;
    void initFilterWindow();
    void switchLanguage(QString);
};

#endif // FILTERTARGETMAINWINDOW_H
