#ifndef CAMERAEVENTFILTER_H
#define CAMERAEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QComboBox>

class cameraEventfilter : public QObject
{
    Q_OBJECT
public:
    explicit cameraEventfilter(QComboBox *combox, QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QComboBox *m_comboBox;

signals:
    void comboBoxPopupShown();
};

#endif // CAMERAEVENTFILTER_H
