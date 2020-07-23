#include "platform.h"


Platform::Platform(float X, float Y, float Fr, float CR, char Facing[])
    : Friction(Fr), Temp(20.0), CondRes(CR), isActive(false)
{
    setPixmap(QPixmap(":/Images/IronPlatform.png"));

    switch(*Facing){

    case *"up": break;
    case *"down": break;
    case *"left": break;
    case *"right": break;
    default: try{throw(1);}
             catch(int){std::runtime_error Error("El valor ingresado no es valido.");}

    }

    setX(qreal(X));
    setY(qreal(Y));

}
