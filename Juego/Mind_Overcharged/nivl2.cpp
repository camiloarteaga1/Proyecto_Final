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

    DataCollector = new User; //To save the user data
    Checkpoint * punto = new Checkpoint();//Flag that indicates another level

    //Objects added to the scene
    obstaculos.reserve(24);
    corazones.reserve(5);
    portal.reserve(24);
    W_Enemies.reserve(8);

    scene->setSceneRect(0, 0, 3500, 5000); //Scene rect
    view->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Images/1leveBackground.jpg"))); //Gamemode background
    view->setScene(scene); //Scene initialized
    view->resize(600, 350); //View rect

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Scroll bar disabled
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Creates the player and adds it to the scene
    Players.push_back(new Player(40, 20, 0, 2, ":/new/prefix1/Images/PlayerBody.png", ":/new/prefix1/Images/GreenHead.png"));
    Players[0]->setAirResistance(0.0117);
    scene->addItem(Players[0]);
    scene->addItem(Players[0]->Head);
    Players[0]->setPos(192, 4870);
    Players[0]->setLifes(vidas); //Lifes of the player

    ui->label_vidas->setText(QString::number(Players[0]->getLifes())); //Label with player lifes
    ui->label_vidas->setFont(QFont("Forte", 24));

    //Portals
    //1
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR1.png", 192, 910));//Verified
    scene->addItem(portal[0]);
    portal[0]->setPos(25, 4870); //Connects with 6 - 1

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 3192, 2410));//Verified
    scene->addItem(portal[1]);
    portal[1]->setPos(360, 4870); //Connects with 1 - trap - 7
    //2
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 2192, 1410));//Verified
    scene->addItem(portal[2]);
    portal[2]->setPos(25, 910); //Connects with 6 - 6

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 292, 1710));//Verified
    scene->addItem(portal[3]);
    portal[3]->setPos(360, 910); //Connects with 2 - 2
    //3
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 200, 2910));//Verified
    scene->addItem(portal[4]);
    portal[4]->setPos(125, 1710); //Connects with trap - 2

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 702, 3910));//Verified
    scene->addItem(portal[5]);
    portal[5]->setPos(460, 1710); //Connects with 3 - 3
    //4 trap
    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 292, 1710));//Verified
    scene->addItem(portal[6]);
    portal[6]->setPos(490, 2910); //Connects with 2 - 2
    //5
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 1192, 910));//Verified
    scene->addItem(portal[7]);
    portal[7]->setPos(535, 3910); //Connects with 3 - 5

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 1192, 4410));//Verified
    scene->addItem(portal[8]);
    portal[8]->setPos(870, 3910); //Connects with 4 - 4
    //6
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 702, 3910));//Verified
    scene->addItem(portal[9]);
    portal[9]->setPos(1025, 910); //Connects with 3 - 3

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 2192, 4870));//Verified
    scene->addItem(portal[10]);
    portal[10]->setPos(1360, 910); //Connects with 5 - 5
    //7
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 1060, 2110));//Verified
    scene->addItem(portal[11]);
    portal[11]->setPos(1025, 4410); //Connects with 4 - trap

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 2192, 4870));//Verified
    scene->addItem(portal[12]);
    portal[12]->setPos(1360, 4410); //Connects with 5 - 5
    //8
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 1192, 4410));//Verified
    scene->addItem(portal[13]);
    portal[13]->setPos(1025, 2110); //Connects with 4 - 4
    //9
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 1192, 910));//Verified
    scene->addItem(portal[14]);
    portal[14]->setPos(2025, 4870); //Connects with 3 - 5

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 2192, 1410));//Verified
    scene->addItem(portal[15]);
    portal[15]->setPos(2360, 4870); //Connects with 6 - 6
    //10
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 2192, 2410));//Verified
    scene->addItem(portal[16]);
    portal[16]->setPos(2025, 1410); //Connects with 7 - 7

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 192, 910));//Verified
    scene->addItem(portal[17]);
    portal[17]->setPos(2360, 1410); //Connects with 6 - 1
    //11
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 3340, 4410));//Verified
    scene->addItem(portal[18]);
    portal[18]->setPos(2025, 2410); //Connects with 8 - trap - final

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 3192.5, 2410));//Verified
    scene->addItem(portal[19]);
    portal[19]->setPos(2360, 2410); //Connects with 1 - trap - 7
    //12
    portal.push_back(new Portal(":/new/prefix1/Images/PortalR2.png", 192, 4870));//Verified
    scene->addItem(portal[20]);
    portal[20]->setPos(3025, 2410); //Connects with 1 - 1

    portal.push_back(new Portal(":/new/prefix1/Images/Portal1.png", 2192, 1410));//Verified
    scene->addItem(portal[21]);
    portal[21]->setPos(3360, 2410); //Connects with 7 - 7
    //13
    scene->addItem(punto);
    punto->setPos(3020, 4460);

    addFloor();

    //Enemies
    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[0]);
    W_Enemies[0]->setPos(3150, 4440);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[1]);
    W_Enemies[1]->setPos(300, 2960);

    W_Enemies.push_back(new WanderingEnemy(5, 0));
    scene->addItem(W_Enemies[2]);
    W_Enemies[2]->setPos(1200, 2160);

    //Lifes
    corazones.push_back(new Estrella());
    scene->addItem(corazones[0]);
    corazones[0]->setPos(300, 2960);

    corazones.push_back(new Estrella());
    scene->addItem(corazones[1]);
    corazones[1]->setPos(1200, 2160);

    CollitionDetection();

    pNivl2 = this;
}

void Nivl2::addFloor(){

    int P_Count = 19; /// Cantidad de plataformas a agregar

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

    obstaculos[13]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[13]->setPos(3070, 4460); //trap wall 1-7

    obstaculos[14]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[14]->setPos(3300, 4460); //trap wall 1-7

    obstaculos[15]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[15]->setPos(260, 2960); //trap wall 2

    obstaculos[16]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[16]->setPos(460, 2960); //trap wall 2

    obstaculos[17]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[17]->setPos(1100, 2160); //trap wall 4

    obstaculos[18]->setPixmap(QPixmap(":/new/prefix1/Images/SolidPlatform.png"));
    obstaculos[18]->setPos(1360, 2160); //trap wall 4

    for(int i = 0; P_Count > i; i++)
        scene->addItem(obstaculos[i]);

}

Nivl2::~Nivl2()
{
    delete ui;
}

//Keys to move the player
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

//Detects the collitions
void Nivl2::CollitionDetection(){

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
                    Portal *Tp = dynamic_cast<Portal *>(i);
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

                    else if(Tp){

                        P->setX(Tp->getTp_X());
                        P->setY(Tp->getTp_Y());

                    }
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
                    //If collides with the finish lane
                    else if(Cp){

                        //DataCollector->overload(to_string(P->getLifes()), "0", this->UserName); //Modifica el archivo de guardado
                        message = new Final();
                        CollitionsTimer->stop(); //Stop timer to finish the game
                        message->exec(); //Show final game message
                        this->close(); //Close the level 2
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
