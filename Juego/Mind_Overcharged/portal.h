#ifndef PORTAL_H
#define PORTAL_H

#include <QGraphicsPixmapItem>

class Portal: public QGraphicsPixmapItem
{
public:
    Portal(float Entrance_Pos_X, float Entrance_Pos_Y, float Exit_Pos_X, float Exit_Pos_Y, float Height);



};

#endif // PORTAL_H
