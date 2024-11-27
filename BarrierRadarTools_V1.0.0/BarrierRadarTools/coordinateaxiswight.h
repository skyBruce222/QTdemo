#ifndef COORDINATEAXISWIGHT_H
#define COORDINATEAXISWIGHT_H

#include <QWidget>
#include <QPainter>
#include <QWheelEvent>
#include <cmath>

class coordinateAxisWight : public QWidget
{
    Q_OBJECT
public:
    explicit coordinateAxisWight(QWidget *parent = nullptr);
    void updateArea(float bottom, float up,float left, float right);
    void updatePoints(uint16_t *index,float *x,float *y,float *v,float *p,
                      uint8_t *areaF,uint8_t *thrF,uint8_t *tF, uint8_t num,
                      bool disInfo,bool disVel);

protected:
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event)  override;

    void mouseMoveEvent(QMouseEvent *event) override {
        // This is optional: you can use this to pan the view by adjusting the origin
        // based on the mouse movement difference since the last move.
        // For simplicity, we'll just store the last mouse position here.
        lastMousePos = event->pos();
    }
private:
    float gBottom,gUp,gLeft,gRight;
    double single_x, single_y;
    uint16_t pIdx[64];
    float px[64];
    float px_Text[64];
    float py_Text[64];
    float py[64];
    float pv[64];
    float pp[64];
    uint8_t parea[64];
    uint8_t pthr[64];
    uint8_t pt[64];
    uint8_t pNum;
    bool disIf = false;
    bool gdisVel = false;
    float maxY = 3.0;
    float maxX = 3.0;
    qreal scaleFactor = 1.0;
    QPointF lastMousePos;
public slots:
    //void updateWidght(int, int, int);


signals:

};

#endif // COORDINATEAXISWIGHT_H
