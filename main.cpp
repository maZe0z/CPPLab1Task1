#include <QApplication>
#include <QGraphicsScene>
#include "MyLine.h"
#include "Rocket.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 1000, 1080);

    Rocket *rocket = new Rocket(500,650);

    scene->addItem(rocket);

    rocket->setFlag(QGraphicsItem::ItemIsFocusable);
    rocket->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
