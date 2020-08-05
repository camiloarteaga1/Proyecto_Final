#include "checkpoint.h"

Checkpoint::Checkpoint(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //draw the checkpoint
    setPixmap(QPixmap(":/new/prefix1/Images/CheckPoint.png"));
}
