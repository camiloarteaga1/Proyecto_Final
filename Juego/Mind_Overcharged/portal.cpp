#include "portal.h"

Portal::Portal(QString port, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //draw the star
    setPixmap(QPixmap(port));
}
