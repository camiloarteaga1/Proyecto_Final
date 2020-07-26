#ifndef CHARACTERHEAD_H
#define CHARACTERHEAD_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "platform.h"

#define MAX_CHARGE 770 //Amperios


class CharacterHead: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CharacterHead(short Mass, QGraphicsItem * = nullptr); ///
    float getCharge();
    short getMass();

    //void EnergiceObj(Platform &); ///
    void Collitions(); ///
    void setCharge(int Count);

public slots:
    void Sprite(); /// Do

private:
    float Charge;
    float Accel_X, Accel_Y;
    float Speed_X, Speed_Y;
    const short Mass;

};

#endif // CHARACTERHEAD_H
