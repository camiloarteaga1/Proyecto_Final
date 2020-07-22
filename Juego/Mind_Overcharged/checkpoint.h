#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>

class CheckPoint: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CheckPoint(float Pos_X, float Pos_Y, short CheckPoint_ID, QGraphicsItem * = nullptr);
    void setStatus(bool Status);
    short get_Id();

public slots:
    void Sprite();
    void SetCheckPoint();

private:
    bool Active;
    QPointF RespawnPoint;
    short ID;

};

#endif // CHECKPOINT_H
