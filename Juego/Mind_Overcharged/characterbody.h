#ifndef CHARACTERBODY_H
#define CHARACTERBODY_H

#include <QGraphicsPixmapItem>

class CharacterBody: public QGraphicsPixmapItem
{
public:
    CharacterBody();
    void MoveBody(/*Obj Floor*/);

    //float Get_X(), Get_Y();
    //void Set_X(), Set_Y();

private:
    float /*X, Y,*/ Accel_X, Accel_Y;

};

#endif // CHARACTERBODY_H
