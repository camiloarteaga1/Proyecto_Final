#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QGraphicsPixmapItem>
#include <QPointF>

class CheckPoint: public QGraphicsPixmapItem
{
public:
    CheckPoint(float Pos_X, float Pos_Y);
    void set_X(float Pos_X);
    void set_Y(float Pos_Y);

private:
    bool Active;
    QPointF RespawnPoint;

};

#endif // CHECKPOINT_H
