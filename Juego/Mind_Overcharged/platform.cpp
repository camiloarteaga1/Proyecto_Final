#include "platform.h"


Platform::Platform(QGraphicsItem *parent)
{

}

Platform::Platform(float X, float Y, float Fr, float CR, char Facing[])
    : Friction(Fr), Temp(20.0), CondRes(CR), isActive(false)
{
    setPixmap(QPixmap(":/Images/IronPlatform.png"));

    switch(*Facing){

    case *"up": break;
    case *"down": break;
    case *"left": break;
    case *"right": break;
    default: std::runtime_error Error("El valor ingresado no es valido.");

    }

    setX(qreal(X));
    setY(qreal(Y));

}

float Platform::getFriction(){return Friction;}

float Platform::getTemperature(){return Temp;}

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

        else if(typeid(CollidingItems[i]) == typeid(Platform))
            if(Platform(CollidingItems[i]).isActive) this->isActive = true;

    }
}

