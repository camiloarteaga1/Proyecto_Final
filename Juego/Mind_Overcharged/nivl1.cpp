#include "nivl1.h"
#include "ui_nivl1.h"
#include "user.h"

#include <QDebug>

Nivl1 * Nivl1::pNivl1 = nullptr;

Nivl1::Nivl1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nivl1)
{
    ui->setupUi(this);
    setWindowTitle("Nivel 1"); //Title

    //Creates the scene
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    DataCollector = new User; //To save the user data
    Checkpoint * punto = new Checkpoint(); //Flag that indicates another level

    //Objects added to the scene
    obstaculos.reserve(45);
    corazones.reserve(2);
    W_Enemies.reserve(10);

    scene->setSceneRect(0, 0, 740, 5000); //Scene rect
    view->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Images/1leveBackground.jpg"))); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(740, 900); //View rect

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Disables the scroll bars
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Creates the player and adds it to the scene
    Players.push_back(new Player(40, 20, 0, 1, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/GreenHead.png"));
    Players[0]->setAirResistance(0.0117);
    scene->addItem(Players[0]);
    scene->addItem(Players[0]->Head);
    Players[0]->setPos(50, 100);

    ui->label_vidas->setText(QString::number(Players[0]->getLifes())); //Label with player lifes
    ui->label_vidas->setFont(QFont("Forte", 24));

    //Add objects
    //Floor
    addFloor();

    //Enemies
    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[0]);
    W_Enemies[0]->setPos(400, 4440);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[1]);
    W_Enemies[1]->setPos(200, 3940);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[2]);
    W_Enemies[2]->setPos(540, 3440);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[3]);
    W_Enemies[3]->setPos(100, 2940);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[4]);
    W_Enemies[4]->setPos(300, 2440);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[5]);
    W_Enemies[5]->setPos(80, 1940);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[6]);
    W_Enemies[6]->setPos(560, 940);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[7]);
    W_Enemies[7]->setPos(400, 1440);


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

    CollitionDetection(); //Detects the collitions with the floor and the objects

}

//Keys to move the character
void Nivl1::keyPressEvent(QKeyEvent *Event){

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

void Nivl1::addFloor(){

    int P_Count = 41; /// Cantidad de plataformas a agregar

    for(int i = 0; P_Count > i; i++){

        obstaculos.push_back(new Platform(0.91f, true)); //Add the floor to the QList
    }

    //Set the platform pos and picture
    obstaculos[0]->setPixmap(QPixmap(":/new/prefix1/Images/LargeSolidPlatform.png"));
    obstaculos[0]->setPos(60, 4960);

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

    //Walls
    obstaculos[25]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[25]->setPos(360, 1460);

    obstaculos[26]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[26]->setPos(558, 1460);

    obstaculos[27]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[27]->setPos(518, 960);

    obstaculos[28]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[28]->setPos(676, 960);

    obstaculos[29]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[29]->setPos(20, 1960);

    obstaculos[30]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[30]->setPos(178, 1960);

    obstaculos[31]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[31]->setPos(240, 2460);

    obstaculos[32]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[32]->setPos(520, 2460);

    obstaculos[33]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[33]->setPos(0, 2960);

    obstaculos[34]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[34]->setPos(280, 2960);

    obstaculos[35]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[35]->setPos(465, 3460);

    obstaculos[36]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[36]->setPos(665, 3460);

    obstaculos[37]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[37]->setPos(140, 3960);

    obstaculos[38]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[38]->setPos(378, 3960);

    obstaculos[39]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[39]->setPos(360, 4460);

    obstaculos[40]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[40]->setPos(680, 4460);


    for(int i = 0; P_Count > i; i++) //Add items to the scene
        scene->addItem(obstaculos[i]);

}

//To center the view
Nivl1 *Nivl1::getMainWinPtr()
{
    return pNivl1;
}


Nivl1::~Nivl1()
{
    delete ui;
}

//Detects the collitions
void Nivl1::CollitionDetection(){

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

                    //Collides with an enemy
                    else if(We){
                        if(!P->IsInmune()){

                            //if(Lz && Lz.isActive()){
                            //  P->setLifes(P->getLifes() - 1);
                            //}
                            //else (!Lz){
                            P->setLifes(P->getLifes() - 1);
                            P->InmunityStart(250);
                            ui->label_vidas->setText(QString::number(P->getLifes())); //Set scene lifes
                            ui->label_vidas->setFont(QFont("Forte", 24));
                            if(!P->getLifes()){
                                scene->removeItem(P->Head); //Remove head if player is out of lifes
                                scene->removeItem(P);
                            }
                            //}
                        }
                    }/// Damage player

                    //Add new life to the player
                    else if(Star){

                        P->setLifes(P->getLifes() + 1);
                        P->InmunityStart(125);
                        Star->~Estrella(); //Erase the star
                        ui->label_vidas->setText(QString::number(P->getLifes())); //Set scene lifes
                        ui->label_vidas->setFont(QFont("Forte", 24));

                    }
                    //Checkpoint collition
                    else if(Cp){

                        //qDebug() << QString::fromStdString(this->UserName);
                        DataCollector->overload(to_string(P->getLifes()), "2", this->UserName); //Modifica el archivo de guardado
                        nivl2 = new Nivl2();
                        nivl2->UserName = this->UserName;
                        nivl2->show(); //Shows second level
                        Players[0]->setPos(192, 4870); //Player pos in new scene
                        Players[0]->setLifes(Players[0]->getLifes());
                        CollitionsTimer->stop(); //Stop timer to start second level
                        this->close(); //Close this level
                        return;
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
        ///******** Player's head collitions
        foreach(Player *P, Players){

            if(P->getHeadStatus()) break;

            QList<QGraphicsItem *> PH_CollidingItems = P->Head->collidingItems();
            bool ColPlat = false;
            static Platform *LastPlatformTouch;

            if(PH_CollidingItems.isEmpty()){

                P->setHeadOnPlatform(false);
                P->setHeadGroundFriction(0);

                if(LastPlatformTouch){
                    LastPlatformTouch->setMode(0);
                    LastPlatformTouch->setIsPlayerOnTop(false);
                }
            }

            else{
                foreach(QGraphicsItem *i, PH_CollidingItems){
                    Platform *Obj = dynamic_cast<Platform *>(i);
                    Player *Pl = dynamic_cast<Player *>(i);
                    WanderingEnemy *We = dynamic_cast<WanderingEnemy *>(i);
                    // Lazer Lz = dynamic_cast<Lazer *>(P1_CollidingItems[i]);

                    if(Obj){

                        ColPlat = true;
                        LastPlatformTouch = Obj;
                        LastPlatformTouch->setMode(1);
                        LastPlatformTouch->setIsPlayerOnTop(true);

                        if(Obj->getIsConductive()){
                            Obj->setIsPlayerOnTop(true);

                            if(!P->IsDischarging())
                                P->DischargeStart();
                        }

                        if((P->Head->y() < Obj->y()) || (P->Head->y() < (Obj->y() + Obj->pixmap().height()))){

                            P->setHeadOnPlatform(true);
                            P->setHeadGroundFriction(Obj->getFriction());
                            //ColPlat = true;

                        }
                        else if((P->Head->y() > Obj->y()) || (P->Head->y() > (Obj->y() + Obj->pixmap().height()))){

                            //ColPlat = false;
                            //P->setSpeed_HY(-(P->getSpeed_HY() / 2));

                        }

                        if(((P->x() > Obj->x()) xor (P->x() < Obj->x())) && (Obj->y() < P->y() + P->pixmap().height() - 1)){

                            //E->setY(Obj->y() - E->pixmap().height());
                            //qDebug() << QString("Colisiona al muro");
                            P->Head->setY(Obj->y() - P->Head->pixmap().height());
                            P->setSpeed_HX(0);

                            if((P->Head->x() < Obj->x() && P->getAccel_HX() > 0) xor (P->Head->x() > Obj->x() && P->getAccel_HX() < 0))
                                P->setAccel_HX(0);

                        }
                    }

                    else if(Pl);

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
                    } /// Damage player

                    if(!ColPlat){
                        P->setHeadOnPlatform(false);
                        P->setHeadGroundFriction(0);
                        P->DischargeStop();

                        if(LastPlatformTouch){
                            LastPlatformTouch->setMode(0);
                            LastPlatformTouch->setIsPlayerOnTop(false);
                        }
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
