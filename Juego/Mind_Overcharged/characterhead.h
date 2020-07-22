#ifndef CHARACTERHEAD_H
#define CHARACTERHEAD_H

#include <QGraphicsPixmapItem>
#include <QObject>

#define MAX_CHARGE 770 //Amperios

class CharacterHead: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CharacterHead();
    void MoveHead(float X, float Y, float Accel_X = 0, float Accel_Y = 0 /*Obj Floor, Class Fluid*/);
    void EnergiceObj(/*Class Obj*/);

    float get_X(), get_Y();
    void set_X(float X_Value), set_Y(float Y_Value);

private:
    float Charge;

    float X, Y, Accel_X, Accel_Y;

};

#endif // CHARACTERHEAD_H
