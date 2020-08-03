#include "multiplayer.h"
#include "ui_multiplayer.h"

#include "checkpoint.h"

Multiplayer * Multiplayer::pMultiplayer = nullptr;

Multiplayer::Multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Multiplayer)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    Checkpoint * punto = new Checkpoint();

    obstaculos.reserve(30);

    scene->setSceneRect(0, 0, 740, 5000);
    view->setBackgroundBrush(QBrush(Qt::white)/*(QImage(":/new/prefix1/Images/multiplayerback.png")*/); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(740, 900);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Add the players
    Players.push_back(new Player(5, 55, 0, true, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/PlayerHead.png"));
    Players.push_back(new Player(5, 55, 1, true, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/Player2Head.png"));

    Players[0]->setAirResistance(0.4);
    Players[1]->setAirResistance(0.4);

    scene->addItem(Players[0]);
    scene->addItem(Players[1]);

    scene->addItem(Players[0]->Head);
    scene->addItem(Players[1]->Head);

    Players[0]->setPos(50, 100);
    Players[1]->setPos(50, 100);

    //Add obstacles

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[0]);
    obstaculos[0]->setPos(20, 4960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[1]);
    obstaculos[1]->setPos(410, 4960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[2]);
    obstaculos[2]->setPos(800, 4960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/HolePlatform.png"));
    scene->addItem(obstaculos[3]);
    obstaculos[3]->setPos(20, 2000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[4]);
    obstaculos[4]->setPos(530, 2000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/HolePlatform.png"));
    scene->addItem(obstaculos[5]);
    obstaculos[5]->setPos(200, 1000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[6]);
    obstaculos[6]->setPos(100, 1000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[7]);
    obstaculos[7]->setPos(40, 1000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[8]);
    obstaculos[8]->setPos(800, 1000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[9]);
    obstaculos[9]->setPos(200, 1500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[10]);
    obstaculos[10]->setPos(20, 500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[11]);
    obstaculos[11]->setPos(600, 500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[12]);
    obstaculos[12]->setPos(640, 500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[13]);
    obstaculos[13]->setPos(680, 500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[14]);
    obstaculos[14]->setPos(240, 2500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[15]);
    obstaculos[15]->setPos(80, 3000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[16]);
    obstaculos[16]->setPos(40, 3000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[17]);
    obstaculos[17]->setPos(0, 3000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[18]);
    obstaculos[18]->setPos(20, 4000);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/HolePlatform.png"));
    scene->addItem(obstaculos[19]);
    obstaculos[19]->setPos(-70, 4500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[20]);
    obstaculos[20]->setPos(20, 2500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[21]);
    obstaculos[21]->setPos(60, 2500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[22]);
    obstaculos[22]->setPos(680, 2500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[23]);
    obstaculos[23]->setPos(310, 3500);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[24]);
    obstaculos[24]->setPos(440, 4500);

    //Add Checkpoint
    scene->addItem(punto);
    punto->setPos(420, 4920);

    pMultiplayer = this;
}

void Multiplayer::keyPressEvent(QKeyEvent *Event){

    static Qt::Key LastKey = Qt::Key_0;
    //qDebug() << QString("Tecla: ") << QString(Event->key());

    //Player 1 keys
    if(Qt::Key_W == Event->key()){ // Jump Code (Redirect Function / Maze move upwards)
        if(Players[0]->getOnPlatform()){
            Players[0]->setSpeed_BY(-4);
            Players[0]->setAccel_BY(float(G));
        }
    }

    else if(Qt::Key_A == Event->key()){ // Move left Code

        Players[0]->setAccel_BX(Players[0]->getAccel_BX() - 2);

        if(Players[0]->getHeadOnPlatform()){
            Players[0]->setAccel_BX(Players[0]->getAccel_BX() - 2);
            Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() - 3);
        }

    }
    else if(Qt::Key_S == Event->key()){ // Fall from platform Code (Maze move downwards)

        if(Players[0]->getOnPlatform() && /*Platform->isSolid()*/true)
        Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() > 0? Players[0]->getSpeed_BX() - (Players[0]->getSpeed_BX() * float(Players[0]->getBodyGroundFriction())/*Platform->getFriction()*/)
                                                             : Players[0]->getSpeed_BX() + (Players[0]->getSpeed_BX() * float(Players[0]->getBodyGroundFriction())/*Platform->getFriction()*/));

        else if(Players[0]->getOnPlatform() && /*!PlayerTest->PlatformOn()->isSolid()*/true){

            /*Platform->doTransparent(PlayerTest);*/

        }
    }
    else if(Qt::Key_D == Event->key()){ // Move right Code

        Players[0]->setAccel_BX(Players[0]->getAccel_BX() + 2);

        if(Players[0]->getHeadOnPlatform()){
            Players[0]->setAccel_BX(Players[0]->getAccel_BX() + 2);
            Players[0]->setSpeed_BX(Players[0]->getSpeed_BX() + 3);
        }

    }
    else if(Qt::Key_Q == Event->key() && Players[0]->getHeadStatus()){ // Throw head Code
        Players[0]->ThrowObj();
        //CollitionHead->start(10);
    }
    else if(Qt::Key_G == Event->key()){ // Pick up items / interact objects Code

    }
    else if(Qt::Key_F == Event->key() && LastKey != Qt::Key_F){ // Sprint Code
        Players[0]->setAccel_BX(Players[0]->getAccel_BX() * 2);
    }

    LastKey = Qt::Key(Event->key());
    Players[0]->setKeyPressing(LastKey);
    return;
/*
    //Player 2 keys
    if(Qt::Key_Up == Event->key()){ // Jump Code (Redirect Function / Maze move upwards)
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(Qt::Key_Left == Event->key()){ // Move left Code

    }
    else if(Qt::Key_Down == Event->key()){ // Crunch and fall from platform Code (Maze move downwards)
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(Qt::Key_Right == Event->key()){ // Move right Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(Qt::Key_O == Event->key()){ // Throw head Code
        ///Player2->ThrowHead()
    }
    else if(Qt::Key_P == Event->key()){ // Pick up items / interact objects Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(Qt::Key_L == Event->key()){ // Sprint Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
*/
}

Multiplayer *Multiplayer::getMainWinPtr()
{
    return pMultiplayer;
}

Multiplayer::~Multiplayer()
{
    delete ui;
}
