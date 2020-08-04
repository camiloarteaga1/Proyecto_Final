#include "nivl2.h"
#include "ui_nivl2.h"

Nivl2 * Nivl2::pNivl2 = nullptr;

Nivl2::Nivl2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nivl2)
{
    ui->setupUi(this);

    //Creates the scene
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    Checkpoint * punto = new Checkpoint();

    obstaculos.reserve(45);
    corazones.reserve(2);

    scene->setSceneRect(0, 0, 10000, 5000);
    view->setBackgroundBrush(QBrush(Qt::white)); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(9500, 800);
    ui->label_vidas->setText("x3");
    ui->label_vidas->setFont(QFont("Forte", 24));

    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /*//Creates the player and adds it to the scene
    player = new Player(5, 55, 0, 1, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/PlayerHead.png");
    player->setAirResistance(0.08);
    scene->addItem(player);
    scene->addItem(player->Head);
    player->setPos(50, 100);*/

    //Add obstacles
    //Floor
    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/LargeSolidPlatform.png"));
    scene->addItem(obstaculos[0]);
    obstaculos[0]->setPos(20, 4960);

    pNivl2 = this;
}

Nivl2::~Nivl2()
{
    delete ui;
}

void Nivl2::keyPressEvent(QKeyEvent *Event)
{
    static Qt::Key LastKey = Qt::Key_0;
    //qDebug() << QString("Tecla: ") << QString(Event->key());

    //Player 1 keys
    if(Qt::Key_W == Event->key()){ // Jump Code (Redirect Function / Maze move upwards)
        if(player->getOnPlatform()){
            player->setSpeed_BY(-4);
            player->setAccel_BY(float(G));
        }
    }

    else if(Qt::Key_A == Event->key()){ // Move left Code

        player->setAccel_BX(player->getAccel_BX() - 2);

        if(player->getHeadOnPlatform()){
            player->setAccel_BX(player->getAccel_BX() - 2);
            player->setSpeed_BX(player->getSpeed_BX() - 3);
        }

    }
    else if(Qt::Key_S == Event->key()){ // Fall from platform Code (Maze move downwards)

        if(player->getOnPlatform() && /*Platform->isSolid()*/true)
        player->setSpeed_BX(player->getSpeed_BX() > 0? player->getSpeed_BX() - (player->getSpeed_BX() * float(player->getBodyGroundFriction())/*Platform->getFriction()*/)
                                                             : player->getSpeed_BX() + (player->getSpeed_BX() * float(player->getBodyGroundFriction())/*Platform->getFriction()*/));

        else if(player->getOnPlatform() && /*!PlayerTest->PlatformOn()->isSolid()*/true){

            /*Platform->doTransparent(PlayerTest);*/

        }
    }
    else if(Qt::Key_D == Event->key()){ // Move right Code

        player->setAccel_BX(player->getAccel_BX() + 2);

        if(player->getHeadOnPlatform()){
            player->setAccel_BX(player->getAccel_BX() + 2);
            player->setSpeed_BX(player->getSpeed_BX() + 3);
        }

    }
    else if(Qt::Key_Q == Event->key() && player->getHeadStatus()){ // Throw head Code
        player->ThrowObj();
        //CollitionHead->start(10);
    }
    else if(Qt::Key_G == Event->key()){ // Pick up items / interact objects Code

    }
    else if(Qt::Key_F == Event->key() && LastKey != Qt::Key_F){ // Sprint Code
        player->setAccel_BX(player->getAccel_BX() * 2);
    }

    LastKey = Qt::Key(Event->key());
    player->setKeyPressing(LastKey);
    return;
}

Nivl2 *Nivl2::getMainWinPtr()
{
    return pNivl2;
}

