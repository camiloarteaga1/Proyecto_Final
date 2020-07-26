#include "checkpoint.h"
#include "player.h"
#include "mainwindow.h"

CheckPoint::CheckPoint(float X, float Y, short ID, QGraphicsItem *parent){

    setPixmap(QPixmap(":/Images/CheckPoint.png"));

    setPos(qreal(X), qreal(Y));
    Active = false;
    RespawnPoint = QPointF(x(), y());
    this->ID = ID; /// IMPORTANT: This number must be diferent from others checkpoints id in the same level.

}

void CheckPoint::setStatus(bool S){Active = S;}

short CheckPoint::get_Id()
{

}

void CheckPoint::Sprite(){

    /// Flag animation

}

void CheckPoint::SetCheckPoint(){

    QList<QGraphicsItem *> CollidingItems = this->collidingItems();

    if(CollidingItems.isEmpty()) return;

    else if(typeid(CollidingItems.last()) == typeid(Player)) Active = true;

    else collidingItems().pop_back();


}



