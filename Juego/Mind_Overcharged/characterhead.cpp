#include "characterhead.h"
#include "checkpoint.h"

CharacterHead::CharacterHead(short M, QGraphicsItem *parent)
    : Charge(MAX_CHARGE), Accel_X(0), Accel_Y(0), Speed_X(0), Speed_Y(0), Mass(M)
{

    setPixmap(QPixmap(":/Images/PlayerHead.jpg"));

}

float CharacterHead::getCharge(){return Charge;}

short CharacterHead::getMass(){return Mass;}

void CharacterHead::EnergiceObj(Platform &platform){

    if(this->getCharge() > 0 && !platform.getStatus()){

        platform.setStatus(true);

    }
}

void CharacterHead::Collitions(){

    QList<QGraphicsItem *> CollidingItems = this->collidingItems();

    for(int i = 0; CollidingItems.size() < i; i++){

        if(this->getCharge() > 0 && typeid(CollidingItems[i]) == typeid(Platform))
            dynamic_cast<Platform *>(CollidingItems[i])->setStatus(true);

        else if(typeid(CollidingItems[i]) == typeid(CheckPoint))
            this->setCharge(MAX_CHARGE);

    }

}

void CharacterHead::setCharge(int c){Charge = c;}

void CharacterHead::Sprite()
{

}

