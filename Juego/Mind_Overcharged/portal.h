#ifndef PORTAL_H
#define PORTAL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Portal:public QObject, public QGraphicsPixmapItem
{
public:
    Portal(QString port = "", float Tp_x = 0, float Tp_y = 0, QGraphicsItem *parent = nullptr);

    float getTp_X();
    float getTp_Y();

private:
        float Tp_x = 0, Tp_y = 0;
};


#endif // PORTAL_H
