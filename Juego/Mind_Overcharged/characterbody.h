#ifndef CHARACTERBODY_H
#define CHARACTERBODY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class CharacterBody: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CharacterBody(QGraphicsItem * = nullptr);

    //float Get_X(), Get_Y();
    //void Set_X(), Set_Y();

public slots:
    void Sprite();

private:
    float Accel_X, Accel_Y;
    float Mass;

};

#endif // CHARACTERBODY_H
