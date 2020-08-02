#include "checkpoint.h"

Checkpoint::Checkpoint(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //draw the star
    setPixmap(QPixmap(":/new/prefix1/Images/CheckPoint.png"));
}
