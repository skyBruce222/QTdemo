#include "cameraeventfilter.h"
#include <QMouseEvent>

cameraEventfilter::cameraEventfilter(QComboBox *comboBox, QObject *parent) : QObject(parent),
                                    m_comboBox(comboBox)
{

}


bool cameraEventfilter::eventFilter(QObject *obj, QEvent *event){


    if (obj == m_comboBox && event->type() == QEvent::MouseButtonPress){
        emit comboBoxPopupShown();
    }
    return QObject::eventFilter(obj, event);
}
