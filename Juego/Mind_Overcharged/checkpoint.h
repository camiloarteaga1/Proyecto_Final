#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Checkpoint:public QObject, public QGraphicsPixmapItem
{
public:
    Checkpoint(QGraphicsItem *parent = nullptr);
};

#endif // CHECKPOINT_H

