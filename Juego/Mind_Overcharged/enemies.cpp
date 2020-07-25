#include "enemies.h"

Enemies::Enemies()
{

    //Draw enemy
    setRect(0, 0, 100, 100);

    timer = new QTimer();

    connect (timer, SIGNAL(timerout()), this, SLOT(move()));

    timer->start(50);
}

void Enemies::Move()
{
    setPos(x()+5,y());

    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy delete";
    }
}
