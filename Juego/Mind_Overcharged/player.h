#ifndef PLAYER_H
#define PLAYER_H

#include "characterbody.h"
#include "characterhead.h"

#define MAX_SEPARATE_TIME 10 // Seconds

class Player
{
public:
    Player(QGraphicsItem * = nullptr);
    void MovePlayer(float Accel_X, float Accel_Y, float Friction/*Platform *Obj*/, float FluidResistance, float Gravity);
    void ChargeObj(/*Platform Obj*/);
    void ObjInteraction(/*Class Obj*/);
    void ThrowInteraction(Player *, float Accel_X, float Accel_Y);

    float Get_X();
    float Get_Y();


private:
    CharacterBody *PlayerBody;
    CharacterHead *PlayerHead;

    float X, Y, Accel_X, Accel_Y;

    bool HeadOn;

    short Lifes;

};

#endif // PLAYER_H
