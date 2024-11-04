#include "coordinateaxiswight.h"
#include <QPen>
#include <QDebug>
#include <math.h>


coordinateAxisWight::coordinateAxisWight(QWidget *parent) : QWidget(parent)
{
    xScale_g = 10;
    yScale_g = 50;
    angle_g = 120;
    dataLen = 0;
    updateCnt = 0;
    displayInfo = false;
    memset((void *)p_ID, 0, sizeof(p_ID));
    memset((void *)point_X, 0, sizeof(point_X));
    memset((void *)point_Y, 0, sizeof(point_Y));
    memset((void *)x_axis, 0, sizeof(x_axis));
    memset((void *)y_axis, 0, sizeof(y_axis));
    memset((void *)velocity, 0, sizeof(velocity));
}

void coordinateAxisWight::updateAxis(int xScale, int yScale, int angle){
    xScale_g = xScale;
    yScale_g = yScale;
    angle_g = angle;
    update();
}

void coordinateAxisWight::updatePoints(
        float *x, float *y, float *vel,
        float *R, float *targetAngle,
        unsigned int *ID, unsigned int len,
        bool display){

   double single_y = yScale_g / (double)(height() - 50);
   double single_x = xScale_g /(double)(width() - 50);
   dataLen = len;
   displayInfo = display;
   bool updateFlag = false;
   for(unsigned int i=0; i<len; i++){
       p_ID[i] = ID[i];
       x_axis[i] = x[i];
       y_axis[i] = y[i];
       velocity[i] = vel[i];
       distance[i] = R[i];
       if (distance[i] != 0.0f){
           angle[i] = targetAngle[i];
           updateFlag = true;
       }
       point_X[i] = (width()-50)/2 + 25 + x[i]/(2*single_x);
       point_Y[i] = height()-25 - y[i]/single_y;

   }
   if (!updateFlag){
       updateCnt ++;
   }
   if (updateFlag || updateCnt >=5){//确保目标不闪屏，有时候can数据接受不完全，会导致闪屏
      updateCnt = 0;
      update();
   }
}


void coordinateAxisWight::paintEvent(QPaintEvent *event){

    if (event){
        //NOP
    }
    //qDebug()<<"update";
    QPainter painter(this);

    QPen pen(Qt::black, 3);//设置画笔为黑色,线宽3

    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿
    painter.setPen(pen);

//    int numX = xScale_g;
    int numY = yScale_g;
    int cntY = 0;
//    while(numX != 0){
//        numX = numX/10;
//        cntX++;
//    }
    while(numY != 0){
        numY = numY/10;
        cntY++;
    }


    //画布大小固定为800*550，坐标轴大小为750*500，其中剩余的50像素点为坐标轴下标使用
    painter.drawLine(25 ,25, width()-25, 25);//绘制X轴
    painter.drawText(QPoint(15,height() - 10),QString::number(-xScale_g));//下标标号
    painter.drawLine(25, height()-25, width()-25, height()-25);//绘制X轴
    painter.drawText(QPoint(770,height() - 10),QString::number(xScale_g));//下标标号

    painter.drawLine(width()-25, 25, width()-25, height()-25);//绘制Y轴
    if (cntY == 3){
        painter.drawText(QPoint(5,30),QString::number(yScale_g));//下标标号
    } else {
        painter.drawText(QPoint(10,30),QString::number(yScale_g));//下标标号
    }

    painter.drawLine(25, 25, 25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,height()-25),QString::number(0));//下标标号

    pen.setWidthF(0.05);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿
    painter.setPen(pen);
    painter.drawLine(25 ,(height()-50)/10 + 25, width()-50, (height()-50)/10 + 25);//绘制X轴
    painter.drawText(QPoint(92,height() - 10),QString::number(-xScale_g + xScale_g/5));//下标标号
    painter.drawLine(25 ,(height()-50)*2/10 + 25, width()-50, (height()-50)*2/10 + 25);//绘制X轴
    painter.drawText(QPoint(167,height() - 10),QString::number(-xScale_g + xScale_g*2/5));//下标标号
    painter.drawLine(25 ,(height()-50)*3/10 + 25, width()-50, (height()-50)*3/10 + 25);//绘制X轴
    painter.drawText(QPoint(242,height() - 10),QString::number(-xScale_g + xScale_g*3/5));//下标标号
    painter.drawLine(25 ,(height()-50)*4/10 + 25, width()-50, (height()-50)*4/10 + 25);//绘制X轴
    painter.drawText(QPoint(317,height() - 10),QString::number(-xScale_g + xScale_g*4/5));//下标标号
    painter.drawLine(25 ,(height()-50)*5/10 + 25, width()-50, (height()-50)*5/10 + 25);//绘制X轴
    painter.drawText(QPoint(397,height() - 10),QString::number(0));//下标标号
    painter.drawLine(25 ,(height()-50)*6/10 + 25, width()-50, (height()-50)*6/10 + 25);//绘制X轴
    painter.drawText(QPoint(472,height() - 10),QString::number(xScale_g/5));//下标标号
    painter.drawLine(25 ,(height()-50)*7/10 + 25, width()-50, (height()-50)*7/10 + 25);//绘制X轴
    painter.drawText(QPoint(547,height() - 10),QString::number(xScale_g*2/5));//下标标号
    painter.drawLine(25 ,(height()-50)*8/10 + 25, width()-50, (height()-50)*8/10 + 25);//绘制X轴
    painter.drawText(QPoint(622,height() - 10),QString::number(xScale_g*3/5));//下标标号
    painter.drawLine(25 ,(height()-50)*9/10 + 25, width()-50, (height()-50)*9/10 + 25);//绘制X轴
    painter.drawText(QPoint(697,height() - 10),QString::number(xScale_g*4/5));//下标标号

    painter.drawLine((width()-50)/10+25, 25, (width()-50)/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,80),QString::number(yScale_g - yScale_g/10));//下标标号
    painter.drawLine((width()-50)*2/10+25, 25, (width()-50)*2/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,130),QString::number(yScale_g - yScale_g*2/10));//下标标号
    painter.drawLine((width()-50)*3/10+25, 25, (width()-50)*3/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,180),QString::number(yScale_g - yScale_g*3/10));//下标标号
    painter.drawLine((width()-50)*4/10+25, 25, (width()-50)*4/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,230),QString::number(yScale_g - yScale_g*4/10));//下标标号
    painter.drawLine((width()-50)*5/10+25, 25, (width()-50)*5/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,280),QString::number(yScale_g - yScale_g*5/10));//下标标号
    painter.drawLine((width()-50)*6/10+25, 25, (width()-50)*6/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,330),QString::number(yScale_g - yScale_g*6/10));//下标标号
    painter.drawLine((width()-50)*7/10+25, 25, (width()-50)*7/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,380),QString::number(yScale_g - yScale_g*7/10));//下标标号
    painter.drawLine((width()-50)*8/10+25, 25, (width()-50)*8/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,430),QString::number(yScale_g - yScale_g*8/10));//下标标号
    painter.drawLine((width()-50)*9/10+25, 25, (width()-50)*9/10+25, height()-25);//绘制Y轴
    painter.drawText(QPoint(10,480),QString::number(yScale_g - yScale_g*9/10));//下标标号

    //qDebug()<< 10* tan(30*(3.1415926/180));
    pen.setWidth(1);//设置线宽为1
    pen.setColor(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿
    painter.setPen(pen);

    //qDebug()<<((width()-50)/10);

    //x轴刻度
    for (int i = 25; i <= width()-25; i +=(((width()-50)/10)/5)){
        if ((i - 25)%((width()-50)/10) == 0){
           painter.drawLine(i, height() - 25, i, height() - height()/50 - 25);
           //painter.drawText();
        } else {
           painter.drawLine(i, height() - 25, i, height() - height()/100 - 25);
        }
    }


    //qDebug() <<  (height() - 50)/10;
    //y轴刻度
    for (int i = 25; i <= height() - 25; i += (((height()-50)/10)/5)){
        if ((i-25)%((height()-50)/10) == 0){
            painter.drawLine(25, i, 35, i);
        } else {
            painter.drawLine(25, i, 30, i);
        }
    }

    for (int i = 25; i <= height() - 25; i += (((height() -50)/10)/5)){
        if ((i -25 )%((height()-50)/10) == 0)
            painter.drawLine(width()-35, i, width()-25, i);
        else
            painter.drawLine(width()-30, i, width()-25, i);
    }

    pen.setColor(Qt::red);
    painter.setPen(pen);

    double angleRad = (90 - angle_g/2)*(3.1415926/180);
    double opposite = xScale_g*tan(angleRad);
    double single = yScale_g / (double)(height() - 50);
    double Ylength = opposite/single;
    painter.drawLine(width()/2, height()-25, width()-25, height() -25 - Ylength);
    painter.drawLine(width()/2, height()-25, 25, height() -25 - Ylength);

    QPolygonF triangle;

    painter.setBrush(QBrush(Qt::NoBrush));
    for(unsigned int  i = 0; i < dataLen; i++){
        triangle << QPointF(point_X[i], point_Y[i] - 5) << QPointF(point_X[i] - 5, point_Y[i] + 5)<< QPointF(point_X[i] + 5, point_Y[i] + 5);
        painter.drawPolygon(triangle);
        triangle.clear();
    }

    if (displayInfo){
        pen.setColor(Qt::darkGray);
        painter.setPen(pen);
        for(unsigned int i = 0; i < dataLen; i++){
            QString text = "ID="+QString::number(p_ID[i])+" "+\
                    "R="+QString::number(distance[i],'f',2)+"m"+" "+\
                    "A="+QString::number(angle[i],'f',2)+"°"+""+\
                    "V="+QString::number(velocity[i],'f',2)+"km/h";
            painter.drawText(point_X[i]-text.length()*3, point_Y[i]-5, text);
        }
    } else {
        pen.setColor(Qt::darkGray);
        painter.setPen(pen);
        for(unsigned int i = 0; i < dataLen; i++){
            QString text = "ID="+QString::number(p_ID[i]);
            painter.drawText(point_X[i]-text.length()*3, point_Y[i]-5, text);
        }
    }
}
