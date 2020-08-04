#include "nivl1.h"
#include "ui_nivl1.h"

#include <QDebug>

Nivl1 * Nivl1::pNivl1 = nullptr;

Nivl1::Nivl1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nivl1)
{
    ui->setupUi(this);
    setWindowTitle("Nivel 1");

    //Creates the scene
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    Checkpoint * punto = new Checkpoint();

    obstaculos.reserve(45);
    corazones.reserve(2);

    scene->setSceneRect(0, 0, 740, 5000);
    view->setBackgroundBrush(QBrush(Qt::white)); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(740, 900);
    ui->label_vidas->setText("x3");
    ui->label_vidas->setFont(QFont("Forte", 24));

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Creates the player and adds it to the scene
    player = new Player(5, 55, 0, 1, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/PlayerHead.png");
    player->setAirResistance(0.08);
    scene->addItem(player);
    scene->addItem(player->Head);
    player->setPos(50, 100);

    //Add obstacles
    //Floor
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

    //Walls
    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[25]);
    obstaculos[25]->setPos(360, 1460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[26]);
    obstaculos[26]->setPos(558, 1460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[27]);
    obstaculos[27]->setPos(518, 960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[28]);
    obstaculos[28]->setPos(676, 960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[29]);
    obstaculos[29]->setPos(20, 1960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[30]);
    obstaculos[30]->setPos(178, 1960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[31]);
    obstaculos[31]->setPos(240, 2460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[32]);
    obstaculos[32]->setPos(520, 2460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[33]);
    obstaculos[33]->setPos(0, 2960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[34]);
    obstaculos[34]->setPos(280, 2960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[35]);
    obstaculos[35]->setPos(465, 3460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[36]);
    obstaculos[36]->setPos(665, 3460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[37]);
    obstaculos[37]->setPos(140, 3960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[38]);
    obstaculos[38]->setPos(378, 3960);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[39]);
    obstaculos[39]->setPos(360, 4460);

    obstaculos.push_back(new Platform(0.91, true,":/new/prefix1/Images/SolidPlatform.png"));
    scene->addItem(obstaculos[40]);
    obstaculos[40]->setPos(680, 4460);

    //Lifes
    corazones.push_back(new Estrella());
    scene->addItem(corazones[0]);
    corazones[0]->setPos(60, 2460);

    corazones.push_back(new Estrella());
    scene->addItem(corazones[1]);
    corazones[1]->setPos(60, 3960);

    //Add Checkpoint
    scene->addItem(punto);
    punto->setPos(420, 4920);

    pNivl1 = this;

}

void Nivl1::keyPressEvent(QKeyEvent *Event){

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

Nivl1 *Nivl1::getMainWinPtr()
{
    return pNivl1;
}


Nivl1::~Nivl1()
{
    delete ui;
}
