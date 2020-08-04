#ifndef ESTRELLA_H
#define ESTRELLA_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Estrella:public QObject, public QGraphicsPixmapItem
{
public:
    Estrella(QGraphicsItem *parent = nullptr);
};

#endif // ESTRELLA_H
