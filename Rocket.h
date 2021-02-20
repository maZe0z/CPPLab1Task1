#ifndef ROCKET_H
#define ROCKET_H
#include "MyLine.h"
#include <QKeyEvent>
#include <QObject>
#include <QDebug>

class Rocket : public QObject, public MyLine
{
    Q_OBJECT
private:
    int XTopCoord;
    int YTopCoord;
    int speed = 10;

public:
    Rocket(int t_XTopCoord, int t_YTopCoord);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

    void keyPressEvent(QKeyEvent *event);

public slots:
    void move();
    void stop();
};

#endif // ROCKET_H
