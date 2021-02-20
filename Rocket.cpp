#include "Rocket.h"
#include <QPainter>
#include <MyLine.h>
#include <QBrush>
#include <QDebug>
#include <QTimer>

Rocket::Rocket(int XTopCoord, int YTopCoord):MyLine(0, 0, 0, 0), XTopCoord(XTopCoord), YTopCoord(YTopCoord){}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawLine(XTopCoord,YTopCoord,XTopCoord-70,YTopCoord+350);
    painter->drawLine(XTopCoord-70,YTopCoord+350,XTopCoord+70,YTopCoord+350);
    painter->drawLine(XTopCoord,YTopCoord,XTopCoord+70,YTopCoord+350);

    painter->setPen(Qt::red);

    for (int i = XTopCoord-70; i <= XTopCoord+70; i+=20){
        painter->drawLine(i,YTopCoord+350,i,YTopCoord+385);
    }

    for (int i = XTopCoord-60; i <= XTopCoord+60; i+=20){
        painter->drawLine(i,YTopCoord+350,i,YTopCoord+400);
    }
}

void Rocket::keyPressEvent(QKeyEvent *event){

    QTimer *timer = new QTimer();

    if (event->key() == Qt::Key_Space){

        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(15);
    }
    else if(event->key() == Qt::Key_R){

        setPos(XTopCoord-490,YTopCoord-600);
    }
}

void Rocket::move(){
    setPos(x(),y()-10);
}

void Rocket::stop(){
    setPos(XTopCoord-490,YTopCoord);
}

QRectF Rocket::boundingRect() const
{
    return QRectF(XTopCoord - 70, YTopCoord, 140, 400);
}
