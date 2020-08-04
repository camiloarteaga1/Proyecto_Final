#ifndef PORTAL_H
#define PORTAL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Portal:public QObject, public QGraphicsPixmapItem
{
public:
    Portal(QString port = "", QGraphicsItem *parent = nullptr);
};


#endif // PORTAL_H
