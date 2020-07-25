#include "player.h"
#include "mainwindow.h"

Player::Player(QGraphicsItem *parent)
    : Lifes(3)
{

    PlayerHead = new CharacterHead(5);
    PlayerBody = new CharacterBody(55);

}

void Player::MovePlayer(float AX, float AY, float Fr/*Platform Obj*/, float FR, float G){

    Accel_X += AX - (AX * Fr);
    Accel_Y += AY - (AY * Fr);

    Accel_X += Accel_X - (Accel_X * FR);
    Accel_Y += Accel_Y - (Accel_Y * FR);
}

short Player::getID(){return ID;}

Qt::Key Player::getKeyPress(){return Key;}

void Player::setKeyPress(Qt::Key &Key){this->Key = Key;}

template<typename T>
void Player::ObjInteraction(T &Object)
{

}
