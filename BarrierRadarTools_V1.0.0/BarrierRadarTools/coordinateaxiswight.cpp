#include "coordinateaxiswight.h"
#include <QPen>
#include <QDebug>
#include <math.h>
#include <QWheelEvent>
#include <QTransform>

coordinateAxisWight::coordinateAxisWight(QWidget *parent) : QWidget(parent)
{
     gBottom = 0;
     gUp = 0;
     gLeft = 0;
     gRight = 0;
     single_x = maxX/(width() -25);
     single_y = maxY/(height()-25);
     setMouseTracking(true);
}

void coordinateAxisWight::updateArea(float bottom, float up,float left, float right){

    //qDebug()<<up;
    maxY = bottom + 1.0;
    maxX = fabs(left)>fabs(right)?fabs(left):fabs(right);
    maxX = maxX + 1;
    qDebug()<<maxX;
    single_x = maxX/(double)(width() -25);
    single_y = maxY/(double)(height()-25);

    gBottom = bottom/single_y;
    gUp = up/single_y;
    gLeft = left/(2*single_x);
    gRight = right/(2*single_x);
    //qDebug()<<gBottom<<gUp<<gLeft<<gRight;//<<single_x<<single_y;
    update();
}

void coordinateAxisWight::updatePoints(uint16_t *index,float *x,float *y,float *v,float *p,
                                       uint8_t *areaF,uint8_t *thrF,uint8_t *tF, uint8_t num,
                                       bool disInfo, bool disVel){

    single_x = maxX/(double)(width() -25);
    single_y = maxY/(double)(height()-25);

    memset((void *)pIdx, 0, sizeof(pIdx));
    memset((void *)px, 0, sizeof(px));
    memset((void *)py, 0, sizeof(py));
    memset((void *)pv, 0, sizeof(pv));
    memset((void *)pp, 0, sizeof(pp));
    memset((void *)parea, 0, sizeof(parea));
    memset((void *)pthr, 0, sizeof(pthr));
    memset((void *)pt, 0, sizeof(pt));
    pNum = num;
    disIf = disInfo;
    gdisVel = disVel;
    //qDebug()<<num;
    for(uint8_t i = 0; i < num; i++){
        pIdx[i] = index[i];
        px_Text[i] = x[i];
        py_Text[i] = y[i];
        px[i] = 8 + x[i]/(2*single_x);
        py[i] = 0 - y[i]/(single_y);
        pv[i] = v[i];
        pp[i] = p[i];
        parea[i] = areaF[i];
        pthr[i] = thrF[i];
        pt[i] = tF[i];
    }
    //qDebug()<<"updatePoints";
    update();
}

void coordinateAxisWight::wheelEvent(QWheelEvent *event){

    QPoint mousePos = event->pos();
    int stepx = (width() -25) / 6*scaleFactor;
    // Calculate the mouse position in the scaled coordinate system
    double x = (mousePos.x() - 3*stepx) / scaleFactor;
    double y = (height()-10 - mousePos.y()) / scaleFactor; // Invert y because Qt's y-axis is downwards

    // 根据滚轮滚动方向调整缩放比例
    if (event->angleDelta().y() > 0) {
         //qDebug()<<"wheelEvent up";
        scaleFactor *= 1.05;  // 放大
    } else {
        scaleFactor /= 1.05;  // 缩小
         //qDebug()<<"wheelEvent down";
    }

    //qDebug()<<mousePos;
    // 限制缩放比例范围
    if (scaleFactor < 1.0) scaleFactor = 1.0;
    if (scaleFactor > 1.15) scaleFactor = 1.15;

    lastMousePos = QPoint(
        static_cast<int>(x * scaleFactor + 3*stepx),
        static_cast<int>(y * -scaleFactor + height()-10)
    );

    // 重新绘制
    update();
}

void coordinateAxisWight::paintEvent(QPaintEvent *event){

    if (event){
        //NOP
    }

    //qDebug()<<"update";
    QPainter painter(this);
    QTransform transform;

    QPen pen(Qt::white, 2);//设置画笔为黑色,线宽3

    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿
    painter.setPen(pen);

    //qDebug()<<width()<< height();


    int stepx = (width() -25) / 6*scaleFactor;
    int stepy = (height() - 25) / maxY*scaleFactor;

    painter.translate(width()/2, height());
    painter.scale(scaleFactor, scaleFactor);

    for(int i = 0; i <= width(); i+=stepx){
        painter.drawLine(i, -height(), i, height());//绘制x轴
        painter.drawLine(-i, -height(), -i, height());//绘制x轴
    }
    for(int i = 0; i <= height(); i+=stepy){
        painter.drawLine(-width(), -i-10, width(), -i-10);//绘制y轴
        //painter.drawLine(-width(), i, width(), i);//绘制y轴
    }

    pen.setColor(Qt::black);
    pen.setWidth(3);//设置线宽为1
    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿
    painter.setPen(pen);
    float x = 0;
    for(int i = 0; i <= width(); i+=stepx){
        painter.drawText(QPoint(i,0),QString::number(x,'f',2));
        painter.drawText(QPoint(-i,0),QString::number(-x,'f',2));
        x += (maxX/6.0)*2;
    }

    int y = 0;
    for(int i = 0; i <= height(); i+=stepy){
        painter.drawText(QPoint(-width()/2,-i-5),QString::number(y));
        y += 1;
    }

    pen.setColor(Qt::red);
    pen.setWidth(1);//设置线宽为1
    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿
    painter.setPen(pen);

    painter.drawLine(0-gLeft*scaleFactor,0-gBottom*scaleFactor-maxY,0+gRight*scaleFactor,0 - gBottom*scaleFactor-maxY);//top
    painter.drawLine(0-gLeft*scaleFactor,0-gUp*scaleFactor-maxY,0+gRight*scaleFactor,0 - gUp*scaleFactor-maxY);//bottom
    painter.drawLine(0+gRight*scaleFactor,0-gUp*scaleFactor-maxY,0+gRight*scaleFactor,0-gBottom*scaleFactor-maxY);//right
    painter.drawLine(0-gLeft*scaleFactor,0-gUp*scaleFactor-maxY,0-gLeft*scaleFactor,0-gBottom*scaleFactor-maxY);//left

    QPolygonF triangle;
    pen.setWidth(2);//设置线宽为1

    for(uint8_t i = 0; i < pNum; i++){
        triangle << QPointF(px[i]*scaleFactor-12.5, py[i]*scaleFactor - 5) <<\
                    QPointF(px[i]*scaleFactor - 5 -12.5, py[i]*scaleFactor + 5)<<\
                    QPointF(px[i]*scaleFactor + 5-12.5, py[i]*scaleFactor + 5);
        if (pt[i] == 1){
            pen.setColor(Qt::darkGreen);
            painter.setPen(pen);
            painter.setBrush(QBrush(Qt::NoBrush));
        } else {
            pen.setColor(Qt::lightGray);
            painter.setPen(pen);
            painter.setBrush(QBrush(Qt::NoBrush));
        }
        painter.drawPolygon(triangle);
        triangle.clear();
    }

    pen.setWidthF(0.1);//设置线宽为1

    if (disIf){

        if (gdisVel){
            for(uint8_t i = 0; i < pNum; i++){
                if (pt[i] == 1){
                    pen.setColor(Qt::blue);
                    painter.setPen(pen);
                    painter.setBrush(QBrush(Qt::NoBrush));
                    QString text = "x:"+QString::number(px_Text[i],'f',2)+" "+\
                            "y:"+QString::number(py_Text[i],'f',2)+" "+\
                            "p:"+QString::number(pp[i])+" "+\
                            "V:"+QString::number(pv[i],'f',2);
                    painter.drawText(px[i]*scaleFactor-text.length()*3, py[i]*scaleFactor-5, text);
                } else {
                    pen.setColor(Qt::gray);
                    painter.setPen(pen);
                    painter.setBrush(QBrush(Qt::NoBrush));
                    QString text = "x:"+QString::number(px_Text[i],'f',2)+" "+\
                            "y:"+QString::number(py_Text[i],'f',2)+" "+\
                            "p:"+QString::number(pp[i])+" "+\
                            "V:"+QString::number(pv[i],'f',2);
                    painter.drawText(px[i]*scaleFactor-text.length()*3, py[i]*scaleFactor-5, text);
                }
            }
        } else {
            for(uint8_t i = 0; i < pNum; i++){
                if (pt[i] == 1){
                    pen.setColor(Qt::blue);
                    painter.setPen(pen);
                    painter.setBrush(QBrush(Qt::NoBrush));
                    QString text = "x:"+QString::number(px_Text[i],'f',2)+" "+\
                            "y:"+QString::number(py_Text[i],'f',2)+" "+\
                            "p:"+QString::number(pp[i]);
                    painter.drawText(px[i]*scaleFactor-text.length()*3, py[i]*scaleFactor-5, text);
                } else {
                    pen.setColor(Qt::gray);
                    painter.setPen(pen);
                    painter.setBrush(QBrush(Qt::NoBrush));
                    QString text = "x:"+QString::number(px_Text[i],'f',2)+" "+\
                            "y:"+QString::number(py_Text[i],'f',2)+" "+\
                            "p:"+QString::number(pp[i]);
                    painter.drawText(px[i]*scaleFactor-text.length()*3, py[i]*scaleFactor-5, text);
                }
            }
        }
    }

    pen.setColor(Qt::black);
    pen.setWidth(5);//设置线宽为1
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::NoBrush));
    QString text = "points:"+QString::number(pNum,'f',0);
    painter.drawText(-width()/2, -height()+10, text);
}
