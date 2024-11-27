#ifndef SERIALGETEVENT_H
#define SERIALGETEVENT_H

#include <QObject>
#include <QEvent>
#include <QComboBox>

class serialGetEvent : public QObject
{
    Q_OBJECT
public:
    explicit serialGetEvent(QComboBox *combox, QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QComboBox *m_comboBox;

signals:
    void comboBoxPopupShown();
};

#endif // SERIALGETEVENT_H
