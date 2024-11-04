#ifndef COLLISIONAREAMAINWINDOW_H
#define COLLISIONAREAMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class collisionAreaMainWindow;
}

class collisionAreaMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit collisionAreaMainWindow(QWidget *parent = nullptr);
    ~collisionAreaMainWindow();
     void switchLanguageSlot(QString);
private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::collisionAreaMainWindow *ui;
    void initCollisionAreaWindow();
    void switchLanguage(QString);
};

#endif // COLLISIONAREAMAINWINDOW_H
