#include "platform.h"


Platform::Platform(QGraphicsItem *parent)
    : TempBase(20.0f)
{

}

Platform::Platform(float X, float Y, float Fr, float CR, float AmbTemp, QGraphicsItem *parent)
    : Friction(Fr), TempBase(AmbTemp), Temp(TempBase), CondRes(CR), isActive(false)
{
    setPixmap(QPixmap(":/Images/IronPlatform.png"));

    setX(qreal(X));
    setY(qreal(Y));

}

float Platform::getFriction(){return Friction;}

float Platform::getTemperature(){return Temp;}

bool Platform::getStatus()
{

}

void Platform::setStatus(bool)
{

}

void Platform::ConductionEffects(){

    QList<QGraphicsItem *> CollidingItems = this->collidingItems();

    for(int i = 0; CollidingItems.size() < i; i++){
        if(typeid(CollidingItems[i]) == typeid(Player)){
            if(Player(CollidingItems[i]).isHeadOn()){

                isActive = true;
                /// Friction effect on player
                Player(CollidingItems[i]).setAccel_X(Player(CollidingItems[i]).getAccel_X() * Friction);

            }
        }

        else if(typeid(CollidingItems[i]) == typeid(Platform)){
            if(Platform(CollidingItems[i]).isActive) this->isActive = true;
            else this->isActive = false;
        }
    }
}

void Platform::TemperatureChange(){

    if(isActive && Temp < 1000)
        Temp += 0.01f;

    else if(!isActive && Temp > TempBase)
        Temp -= 0.001f;

}

