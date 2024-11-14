#ifndef COORDINATEAXISWIGHT_H
#define COORDINATEAXISWIGHT_H

#include <QWidget>
#include <QPainter>

class coordinateAxisWight : public QWidget
{
    Q_OBJECT
public:
    explicit coordinateAxisWight(QWidget *parent = nullptr);
    void updateAxis( int xScale, int yScale, int angle);
    void updataArea(int p1_long, int p1_lat, int p2_long, int p2_lat);
    void updatePoints(float *x, float *y, float *vel,
                          float *R, float *targetAngle,
                          unsigned int *ID, unsigned int len,
                          bool display);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int xScale_g = 10;
    int yScale_g = 50;
    int angle_g = 120;
    double lat1 = 0;
    double lat2 = 0;
    double long1 = 0;
    double long2 = 0;
    unsigned int dataLen;
    int point_X[64],point_Y[64];
    float x_axis[64],y_axis[64], distance[64],angle[64], velocity[64];
    unsigned int p_ID[64];
    bool displayInfo = false;
    uint8_t updateCnt = 0;
    double single_y,single_x;

public slots:
    //void updateWidght(int, int, int);


signals:

};

#endif // COORDINATEAXISWIGHT_H
