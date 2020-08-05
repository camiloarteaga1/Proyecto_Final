#include "portal.h"

Portal::Portal(QString port, float x, float y, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), Tp_x(x), Tp_y(y)
{
    //draw the portal
    setPixmap(QPixmap(port));

}
//Pos to make the tp
float Portal::getTp_X(){return Tp_x;}
float Portal::getTp_Y(){return Tp_y;}
