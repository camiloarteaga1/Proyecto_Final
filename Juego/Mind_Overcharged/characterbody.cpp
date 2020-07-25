#include "characterbody.h"

CharacterBody::CharacterBody(short M, QGraphicsItem *parent)
    : Accel_X(0), Accel_Y(0), Speed_X(0), Speed_Y(0), Mass(M)
{

    setPixmap(QPixmap(":/Images/PlayerBody.jpg"));

}

short CharacterBody::getMass(){return Mass;}

void CharacterBody::Sprite()
{

}
