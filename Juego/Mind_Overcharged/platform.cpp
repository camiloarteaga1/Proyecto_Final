#include "platform.h"

#include <QDebug>
#include <QTimer>

Platform::Platform(float Fr, bool IsSolid,  QString FileName, bool IsConductive, QGraphicsItem *parent)
    : Friction(Fr), Solid(IsSolid), Conductive(IsConductive), isActive(false), Mode(2)
{

    setPixmap(QPixmap(FileName));

    DischargeTimer = new QTimer;
    TransparentTimer = new QTimer;
    ConductTimer = new QTimer;

    connect(DischargeTimer, SIGNAL(timeout()), this, SLOT(DisableCharge()));
    connect(TransparentTimer, SIGNAL(timeout()), this, SLOT(setTransparent()));
    connect(ConductTimer, SIGNAL(timeout()), this, SLOT(Conductivity()));

    AllowIDs.reserve(2);
    setIsCharged(false);
    setIsPlayerOnTop(false);
    setSpecialFunct([](){});

    //ConductStart(100);

}

///***********************  Functions  ***********************///
void Platform::setIsPlayerOnTop(bool Status){

    if(getIsConductive()){
        isPlayerOn = Status;
        setMode(1);
        DischargeStart(50);
    }
}
void Platform::setIsCharged(bool Status){isActive = Status;}
void Platform::AddPlayersQueue(short &Id){AllowIDs.push_back(Id);}
void Platform::setSpecialFunct(void (*Lambda)()){SpecialFunct = Lambda;}
void Platform::setMode(short M){Mode = M;}
bool Platform::getIsConductive(){return Conductive;}

///***********************  Getters  ***********************///
bool Platform::getIsPlayerOnTop(){return isPlayerOn;}
bool Platform::getIsCharged(){return isActive;}
double Platform::getFriction(){return Friction;}
bool Platform::IsSolid(){return Solid;}

///***********************  Timers  ***********************///
void Platform::DischargeStart(int TimeMls){DischargeTimer->start(TimeMls);}
void Platform::DischargeStop(){DischargeTimer->stop();}

void Platform::TransparentStart(int TimeMls){TransparentTimer->start(TimeMls);}
void Platform::TransparentStop(){TransparentTimer->stop();}

void Platform::ConductStart(int TimeMls){ConductTimer->start(TimeMls);}
void Platform::ConductStop(){ConductTimer->stop();}

///***********************  Slots  ***********************///
void Platform::Conductivity(){

    QList<QGraphicsItem *>CollidingItems = collidingItems();

    setMode(getIsPlayerOnTop()? 1 : 2);


    if(!CollidingItems.isEmpty()){
        foreach(QGraphicsItem *i, CollidingItems){

            Platform *Plat = dynamic_cast<Platform *>(i);

            switch(Mode){

            case 0:{

                if(Plat)
                    Plat->setMode(0);

                this->setIsCharged(false);
                this->setMode(2);
                break;
            }

            case 1:{

                if(this->getIsConductive()){

                    this->setIsCharged(true);

                    if(!getIsPlayerOnTop())
                        this->setMode(2);

                    if(Plat && Plat->getIsConductive())
                        Plat->setMode(1);

                }

                break;
            }

            case 2:{
                break;
            }
            }
        }
    }

    if(getIsCharged()){
        setPixmap(QPixmap(":/Images/ChargedPlatform.png"));
        SpecialFunct();
    }

    else
        setPixmap(QPixmap(":/Images/SolidPlatform.png"));

}

void Platform::DisableCharge(){

    static short CclsToDisable = 3;

    if(!CclsToDisable){
        setIsCharged(false);
        CclsToDisable = 3;
        DischargeStop();
    }

    CclsToDisable--;

}

void Platform::setTransparent(){

    static short CoolDown = 1;

    if(!CoolDown){
        AllowIDs.pop_back();
        CoolDown = 1;

        if(AllowIDs.isEmpty()){
            TransparentStop();
            return;
        }
    }

    CoolDown--;

}
