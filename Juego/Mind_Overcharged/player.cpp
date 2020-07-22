#include "player.h"
#include "mainwindow.h"

Player::Player(QGraphicsItem *parent)
    : Lifes(3)
{

}

void Player::MovePlayer(float AX, float AY, float Fr/*Platform Obj*/, float FR, float G){

    Accel_X += AX - (AX * Fr);
    Accel_Y += AY - (AY * Fr);

    Accel_X += Accel_X - (Accel_X * FR);
    Accel_Y += Accel_Y - (Accel_Y * FR);

}
