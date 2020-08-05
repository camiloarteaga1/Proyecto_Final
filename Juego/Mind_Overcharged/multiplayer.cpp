#include "multiplayer.h"
#include "ui_multiplayer.h"

#include "checkpoint.h"

Multiplayer * Multiplayer::pMultiplayer = nullptr;

Multiplayer::Multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Multiplayer)
{
    ui->setupUi(this);
    setWindowTitle("Multijugador");

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    Checkpoint * punto = new Checkpoint();

    obstaculos.reserve(30);

    scene->setSceneRect(0, 0, 740, 5000);
    view->setBackgroundBrush(QBrush/*(Qt::white)*/(QImage(":/new/prefix1/Images/BackgroundMulti.jpg"))); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(740, 900);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Add the players
    Players.push_back(new Player(40, 20, 0, 4, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/PlayerHead.png"));
    Players.push_back(new Player(40, 20, 1, 4, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/Player2Head.png"));

    Players[0]->setAirResistance(0.0117);
    Players[1]->setAirResistance(0.0117);

    scene->addItem(Players[0]);
    scene->addItem(Players[1]);

    scene->addItem(Players[0]->Head);
    scene->addItem(Players[1]->Head);

    Players[0]->setPos(50, 100);
    Players[1]->setPos(50, 100);

    //Add obstacles

    addFloor();

    //Add Checkpoint
    scene->addItem(punto);
    punto->setPos(420, 4920);

    CollitionDetection();

    pMultiplayer = this;
}

void Multiplayer::keyPressEvent(QKeyEvent *Event){

    //qDebug() << QString("Tecla: ") << QString(Event->key());

    ///Player 1 keys
    if(Qt::Key_W == Event->key()){ /// Jump Code (Redirect Function / Maze move upwards)
        if(Players[0]->getOnPlatform()){
            Players[0]->setSpeed_BY(-4);
            Players[0]->setAccel_BY(float(G));
        }
    }

    else if(Qt::Key_A == Event->key()){ /// Move left Code

        Players[0]->setAccel_BX(Players[0]->getAccel_BX() - 4);
        Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() - 2);

        if(Players[0]->getHeadOnPlatform()){
            Players[0]->setAccel_BX(Players[0]->getAccel_BX() - 2);
            Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() - 3);
        }

    }
    else if(Qt::Key_S == Event->key()){ /// Fall from platform Code (Maze move downwards)

        if(Players[0]->getOnPlatform() && /*Platform->isSolid()*/true)
        Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() > 0? Players[0]->getSpeed_BX() - (Players[0]->getSpeed_BX() * float(Players[0]->getBodyGroundFriction())/*Platform->getFriction()*/)
                                                             : Players[0]->getSpeed_BX() + (Players[0]->getSpeed_BX() * float(Players[0]->getBodyGroundFriction())/*Platform->getFriction()*/));

        else if(Players[0]->getOnPlatform() && /*!PlayerTest->PlatformOn()->isSolid()*/true){

            /*Platform->doTransparent(PlayerTest->getID());*/

        }
    }
    else if(Qt::Key_D == Event->key()){ /// Move right Code

        Players[0]->setAccel_BX(Players[0]->getAccel_BX() + 4);
        Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() + 3);

        if(Players[0]->getHeadOnPlatform()){
            Players[0]->setAccel_BX(Players[0]->getAccel_BX() + 2);
            Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() + 3);
        }

    }/*
    else if(Qt::Key_Q == Event->key() && Players[0]->getHeadStatus()){ // Throw head Code
        //Players[0]->ThrowObj();
        //CollitionHead->start(10);
    }
    else if(Qt::Key_G == Event->key()){ // Pick up items / interact objects Code

    }
    else if(Qt::Key_F == Event->key() && LastKey != Qt::Key_F){ // Sprint Code
        Players[0]->setAccel_BX(Players[0]->getAccel_BX() * 2);
    }*/

    Players[0]->setKeyPressing(Qt::Key(Event->key()));

    ///Player 2 keys
    if(Qt::Key_I == Event->key()){ /// Jump Code (Redirect Function / Maze move upwards)
        if(Players[1]->getOnPlatform()){
            Players[1]->setSpeed_BY(-4);
            Players[1]->setAccel_BY(float(G));
        }
    }

    else if(Qt::Key_J == Event->key()){ /// Move left Code

        Players[1]->setAccel_BX(Players[1]->getAccel_BX() - 2);

        if(Players[1]->getHeadOnPlatform()){
            Players[1]->setAccel_BX(Players[1]->getAccel_BX() - 2);
            Players[1]->setSpeed_BX(Players[1]->getSpeed_BX() - 3);
        }

    }
    else if(Qt::Key_K == Event->key()){ /// Fall from platform Code (Maze move downwards)

        if(Players[1]->getOnPlatform() && /*Platform->isSolid()*/true)
        Players[1]->setSpeed_BX(Players[1]->getSpeed_BX() > 0? Players[1]->getSpeed_BX() - (Players[1]->getSpeed_BX() * float(Players[1]->getBodyGroundFriction()))
                                                             : Players[1]->getSpeed_BX() + (Players[1]->getSpeed_BX() * float(Players[1]->getBodyGroundFriction())));

        else if(Players[1]->getOnPlatform() && /*!PlayerTest->PlatformOn()->isSolid()*/true){

            /*Platform->doTransparent(PlayerTest->getID());*/

        }
    }
    else if(Qt::Key_L == Event->key()){ /// Move right Code

        Players[1]->setAccel_BX(Players[1]->getAccel_BX() + 2);

        if(Players[1]->getHeadOnPlatform()){
            Players[1]->setAccel_BX(Players[1]->getAccel_BX() + 2);
            Players[1]->setSpeed_BX(Players[1]->getSpeed_BX() + 3);
        }

    }/*
    else if(Qt::Key_O == Event->key()){ // Throw head Code
        ///Player2->ThrowHead()
    }
    else if(Qt::Key_P == Event->key()){ // Pick up items / interact objects Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(Qt::Key_U == Event->key()){ // Sprint Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }*/

}

void Multiplayer::addFloor(){

    int Count = 25;

    for(int i = 0; Count > i; i++)
        obstaculos.push_back(new Platform(0.91f, true));

    obstaculos[0]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[0]->setPos(20, 4960);

    obstaculos[1]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[1]->setPos(410, 4960);

    obstaculos[2]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[2]->setPos(800, 4960);

    obstaculos[3]->setPixmap(QPixmap(":/new/prefix1/Images/HolePlatform.png"));
    obstaculos[3]->setPos(20, 2000);

    obstaculos[4]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[4]->setPos(530, 2000);

    obstaculos[5]->setPixmap(QPixmap(":/new/prefix1/Images/HolePlatform.png"));
    obstaculos[5]->setPos(200, 1000);

    obstaculos[6]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[6]->setPos(100, 1000);

    obstaculos[7]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[7]->setPos(40, 1000);

    obstaculos[8]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[8]->setPos(800, 1000);

    obstaculos[9]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[9]->setPos(200, 1500);

    obstaculos[10]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[10]->setPos(20, 500);

    obstaculos[11]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[11]->setPos(600, 500);

    obstaculos[12]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[12]->setPos(640, 500);

    obstaculos[13]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[13]->setPos(680, 500);

    obstaculos[14]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[14]->setPos(240, 2500);

    obstaculos[15]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[15]->setPos(80, 3000);

    obstaculos[16]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[16]->setPos(40, 3000);

    obstaculos[17]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[17]->setPos(0, 3000);

    obstaculos[18]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[18]->setPos(20, 4000);

    obstaculos[19]->setPixmap(QPixmap(":/new/prefix1/Images/HolePlatform.png"));
    obstaculos[19]->setPos(-70, 4500);

    obstaculos[20]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[20]->setPos(20, 2500);

    obstaculos[21]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[21]->setPos(60, 2500);

    obstaculos[22]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[22]->setPos(680, 2500);

    obstaculos[23]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[23]->setPos(310, 3500);

    obstaculos[24]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[24]->setPos(440, 4500);

    for(int i = 0; Count > i; i++)
        scene->addItem(obstaculos[i]);

}

void Multiplayer::CollitionDetection(){

    CollitionsTimer = new QTimer;

    connect(CollitionsTimer, &QTimer::timeout,[=](){

        ///*************** Player collitions
        foreach(Player *P, Players){

            QList<QGraphicsItem *> P_CollidingItems = P->collidingItems();
            bool ColPlat = false;
            static Platform *LastPlatformTouch;

            if(P_CollidingItems.isEmpty()){

                //static int Count = 0;
                //qDebug() << QString("Player collitions empty") << QString::number(Count++);
                P->setOnPlatform(false);
                P->setBodyGroundFriction(0);
                P->DischargeStop();

                if(LastPlatformTouch && P->getHeadStatus()){
                    LastPlatformTouch->setMode(0);
                    LastPlatformTouch->setIsPlayerOnTop(false);
                }
            }

            else{
                foreach(QGraphicsItem *i, P_CollidingItems){

                    Platform *Obj = dynamic_cast<Platform *>(i);
                    //Player *Pl = dynamic_cast<Player *>(i);
                    WanderingEnemy *We = dynamic_cast<WanderingEnemy *>(i);
                    Estrella *Star = dynamic_cast<Estrella *>(i);
                    Checkpoint *Cp = dynamic_cast<Checkpoint *>(i);
                    // Lazer Lz = dynamic_cast<Lazer *>(P1_CollidingItems[i]);

                    if(Obj){

                        ColPlat = true;
                        LastPlatformTouch = Obj;
                        if(P->getHeadStatus())
                            Obj->setMode(1);

                        if(Obj->getIsConductive() && P->getHeadStatus()){

                            Obj->setIsPlayerOnTop(true);

                            if(!P->IsDischarging())
                                P->DischargeStart();
                        }

                        if((P->y() < Obj->y()) || (P->y() < (Obj->y() + Obj->pixmap().height()))){

                            P->setOnPlatform(true);
                            P->setBodyGroundFriction(Obj->getFriction());
                            //ColPlat = true;

                        }
                        else if((P->y() > Obj->y()) || (P->y() > (Obj->y() + Obj->pixmap().height()))){

                            //ColPlat = true;
                            P->setSpeed_BY(-(P->getSpeed_BY() / 2));

                        }

                        if((((P->x() > Obj->x() - Obj->pixmap().width()) xor (P->x() < Obj->x()))) && (Obj->y() < P->y() + P->pixmap().height())){

                            P->setY(Obj->y() - P->pixmap().height());
                            //ColPlat = true;

                        }
                    }/// Collides a platform

                    else if(We){
                        if(!P->IsInmune()){

                            //if(Lz && Lz.isActive()){
                            //  P->setLifes(P->getLifes() - 1);
                            //}
                            //else (!Lz){
                            P->setLifes(P->getLifes() - 1);
                            P->InmunityStart(250);
                            if(!P->getLifes()){
                                scene->removeItem(P->Head);
                                scene->removeItem(P);
                            }
                            //}
                        }
                    }/// Damage player

                    else if(Star){

                        P->setLifes(P->getLifes() + 1);
                        P->InmunityStart(125);
                        Star->~Estrella();

                    }

                    else if(Cp){

                        //qDebug() << QString::fromStdString(this->UserName);
                        //DataCollector->overload(to_string(P->getLifes()), "1", this->UserName);

                    }
                }

                if(!ColPlat){
                    //qDebug() << QString("Tambien pasa aqui");
                    P->setOnPlatform(false);
                    P->setBodyGroundFriction(0);
                    P->DischargeStop();

                    if(LastPlatformTouch && P->getHeadStatus()){
                        LastPlatformTouch->setMode(0);
                        LastPlatformTouch->setIsPlayerOnTop(false);
                    }
                }
            }
        }
        ///****** Wandering enemy collitions
        foreach(WanderingEnemy *E, W_Enemies){

            QList<QGraphicsItem *> E_CollidingItems = E->collidingItems();
            bool ColPlat = false;

            if(E_CollidingItems.isEmpty()){

                E->setOnPlatform(false);
                E->setGroundFr(0);

            }

            else{
                foreach(QGraphicsItem *i, E_CollidingItems){
                    Platform *Obj = dynamic_cast<Platform *>(i);

                    if(Obj && !ColPlat){
                        if((E->y() < Obj->y()) || (E->y() < (Obj->y() + Obj->pixmap().height()))){

                            if((E->y() + (E->pixmap().height() / 2)) < Obj->y())
                                E->setY(Obj->y() - E->pixmap().height() - 0.1);

                            E->setOnPlatform(true);
                            E->setGroundFr(Obj->getFriction());
                            ColPlat = true;

                        }
                        else if((E->y() > Obj->y()) || (E->y() > (Obj->y() + Obj->pixmap().height()))){

                            ColPlat = false;
                            E->setSpeed_Y(-(E->getSpeed_Y() / 2));

                        }

                        if(((E->x() > Obj->x()) xor (E->x() < Obj->x())) && (Obj->y() < E->y() + E->pixmap().height() - 1)){

                            //E->setY(Obj->y() - E->pixmap().height());
                            //qDebug() << QString("Colisiona al muro");
                            E->setDirection(!E->getDirection());
                            E->setX(E->x() + (E->getDirection()? 2 : -2));

                            if((E->x() < Obj->x() && E->getAccel_X() > 0) xor (E->x() > Obj->x() && E->getAccel_X() < 0))
                                E->setAccel_X(0);

                        }
                    }
                }
                if(!ColPlat){
                    E->setOnPlatform(false);
                    E->setGroundFr(0);
                }
            }
        }
    });

    CollitionsTimer->start(10);

}


Multiplayer *Multiplayer::getMainWinPtr()
{
    return pMultiplayer;
}

Multiplayer::~Multiplayer()
{
    delete ui;
}
