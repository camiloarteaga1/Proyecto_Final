#ifndef PLAYER_H
#define PLAYER_H

#include "characterbody.h"
#include "characterhead.h"
#include "platform.h"

#define MAX_SEPARATE_TIME 10 // Seconds
#define PI 3,1415
#define Tv(Fr, V, R) Fr/(6*PI*V*R) // Terminal speed by Stroke's law

/// size 16 Px tall
class Player
{
public:
    Player(QGraphicsItem * = nullptr);
    void MovePlayer(float Accel_X, float Accel_Y, float Friction/*Platform *Obj*/, float FluidResistance, float Gravity);
    //void ChargeObj(Platform *);

    template<typename T>
    void ObjInteraction(T *Object);
    void ThrowInteraction(Player *, float Accel_X, float Accel_Y);

    float Get_X();
    float Get_Y();
    float getAccel_X();
    float getAccel_Y();
    short getLifes();
    bool isHeadOn();

    void set_X(float Pos_X);
    void set_Y(float Pos_Y);
    void setLifes(short LifesCount);
    void setHeadStatus(bool isOn);
    void setAccel_X(float Acceleration_X);
    void setAccel_Y(float Acceleration_Y);

private:
    CharacterBody *PlayerBody;
    CharacterHead *PlayerHead;

    float X, Y, Accel_X, Accel_Y, Speed_X, Speed_Y;

    bool HeadOn;

    short Lifes;

};

#endif // PLAYER_H
