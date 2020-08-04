#include "estrella.h"

Estrella::Estrella(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //draw the star
    setPixmap(QPixmap(":/new/prefix1/Images/0.png"));
}
