#include "nivl2.h"
#include "ui_nivl2.h"

Nivl2 * Nivl2::pNivl2 = nullptr;

Nivl2::Nivl2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nivl2)
{
    ui->setupUi(this);
    setWindowTitle("Nivel 2");
    //Creates the scene
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    Checkpoint * punto = new Checkpoint();

    obstaculos.reserve(15);
    corazones.reserve(2);
    portal.reserve(24);

    scene->setSceneRect(0, 0, 3500, 5000);
    view->setBackgroundBrush(QBrush(Qt::white)); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(600, 350);
    ui->label_vidas->setText("x3");
    ui->label_vidas->setFont(QFont("Forte", 24));

    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /*//Creates the player and adds it to the scene
    Players.push_back(new Player(5, 55, 0, 1, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/GreenHead.png"));
    Players[0]->setAirResistance(0.08);
    scene->addItem(Players[0]);
    scene->addItem(Players[0]->Head);
    Players[0]->setPos(50, 100);*/

    //Portals
    //1
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR1.png"));
    scene->addItem(portal[0]);
    portal[0]->setPos(25, 4870); //Connects with 6 - 1

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[1]);
    portal[1]->setPos(360, 4870); //Connects with 1 - trap - 7
    //2
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[2]);
    portal[2]->setPos(25, 910); //Connects with 6 - 6

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[3]);
    portal[3]->setPos(360, 910); //Connects with 2 - 2
    //3
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[4]);
    portal[4]->setPos(125, 1710); //Connects with trap - 2

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[5]);
    portal[5]->setPos(460, 1710); //Connects with 3 - 3
    //4 trap
    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[6]);
    portal[6]->setPos(490, 2910); //Connects with 2 - 2
    //5
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[7]);
    portal[7]->setPos(535, 3910); //Connects with 3 - 5

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[8]);
    portal[8]->setPos(870, 3910); //Connects with 4 - 4
    //6
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[9]);
    portal[9]->setPos(1025, 910); //Connects with 3 - 2

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[10]);
    portal[10]->setPos(1360, 910); //Connects with 5 - 5
    //7
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[11]);
    portal[11]->setPos(1025, 4410); //Connects with 4 - trap

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[12]);
    portal[12]->setPos(1360, 4410); //Connects with 5 - 5
    //8
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[13]);
    portal[13]->setPos(1025, 2110); //Connects with 4 - 4
    //9
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[14]);
    portal[14]->setPos(2025, 4870); //Connects with 3 - 5

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[15]);
    portal[15]->setPos(2360, 4870); //Connects with 6 - 6
    //10
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[16]);
    portal[16]->setPos(2025, 1410); //Connects with 7 - 7

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[17]);
    portal[17]->setPos(2360, 1410); //Connects with 6 - 1
    //11
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[18]);
    portal[18]->setPos(2025, 2410); //Connects with 8 - trap - final

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[19]);
    portal[19]->setPos(2360, 2410); //Connects with 1 - trap - 7
    //12
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png"));
    scene->addItem(portal[20]);
    portal[20]->setPos(3025, 2410); //Connects with 1 - 1

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png"));
    scene->addItem(portal[21]);
    portal[21]->setPos(3360, 2410); //Connects with 7 - 7
    //13
    scene->addItem(punto);
    punto->setPos(3020, 4460);

    addFloor();

    pNivl2 = this;
}

void Nivl2::addFloor(){

    int P_Count = 15; /// Cantidad de plataformas a agregar

    for(int i = 0; P_Count > i; i++){

        obstaculos.push_back(new Platform(0.91f, 1));
    }

    //Floor
    obstaculos[0]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[0]->setPos(20, 4960); //1-1 *1

    obstaculos[1]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[1]->setPos(20, 1000); //6-1 *2

    obstaculos[2]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[2]->setPos(120, 1800); //2-2 *3

    obstaculos[3]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[3]->setPos(150, 3000); //Trap-2 *4

    obstaculos[4]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[4]->setPos(530, 4000); //3-3 *5

    obstaculos[5]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[5]->setPos(1020, 1000); //3-5 *6

    obstaculos[6]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[6]->setPos(1020, 4500); //4-4 *7

    obstaculos[7]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[7]->setPos(1020, 2200); //4-trap *8

    obstaculos[8]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[8]->setPos(2020, 4960); //5-5 *9

    obstaculos[9]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[9]->setPos(2020, 1500); //6-6 *10

    obstaculos[10]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[10]->setPos(2020, 2500); //7-trap-7 *11

    obstaculos[11]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[11]->setPos(3020, 2500); //1-trap-7 *12

    obstaculos[12]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[12]->setPos(3020, 4500); //8-final *13

    for(int i = 0; P_Count > i; i++)
        scene->addItem(obstaculos[i]);

}

Nivl2::~Nivl2()
{
    delete ui;
}

void Nivl2::keyPressEvent(QKeyEvent *Event){

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
}

Nivl2 *Nivl2::getMainWinPtr()
{
    return pNivl2;
}

