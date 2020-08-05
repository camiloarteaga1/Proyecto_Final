#ifndef PORTAL_H
#define PORTAL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Portal:public QObject, public QGraphicsPixmapItem
{
public:
    Portal(QString port = "", float x = 0, float y = 0, QGraphicsItem *parent = nullptr);

    float get_X();
    float get_Y();

private:
        float xi = 0, yi = 0;
};


#endif // PORTAL_H
