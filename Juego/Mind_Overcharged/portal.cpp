#include "portal.h"

Portal::Portal(QString port, float x, float y, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //draw the star
    setPixmap(QPixmap(port));

    xi = x;
    yi = y;
}

float Portal::get_X()
{
    return xi;
}

float Portal::get_Y()
{
    return yi;
}
