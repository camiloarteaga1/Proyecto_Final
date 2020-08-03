#include "platform.h"

Platform::Platform(float Fr, bool IsSolid, QString FileName, QGraphicsItem *parent)
    : Friction(Fr), Solid(IsSolid)
{

    setPixmap(QPixmap(FileName));

}

double Platform::getFriction(){return Friction;}
bool Platform::IsSolid(){return Solid;}


/*
void Platform::ConductElectricity(){

    if(!isActive || Type == 1)
        return;

    QList<QGraphicsItem *> CollitionItems = this->collidingItems();

    for(int i = 0; CollitionItems.size() < i; i++){
        if(typeid(CollitionItems[i]) == typeid(Platform)){
            dynamic_cast<Platform *>(CollitionItems[i])->setStatus(true);

        }
    }
}
*/
