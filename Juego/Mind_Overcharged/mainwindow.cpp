#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define TEMP 0.01f

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*scene = new QGraphicsScene();
    view = new QGraphicsView();
    scene->setSceneRect(0, 0, 2000, 2000);
    view->setScene(scene);
    view->resize(1000, 1000);
    this->resize(1000, 1000);*/

    GameScreen = true;
    Multiplayer = false;

    Players.push_back(new Player(5, 55, 0));



    //view = new QGraphicsView;
    //scene = new QGraphicsScene;
    //PlayerTest = new Player(5, 55, 0);

    //scene->addItem(PlayerTest);
    //scene->addItem(PlayerTest->Head);

    //PlayerTest->setAirResistance(0.0017 /*0.0017 = Levels[i]->getAirResistance()*/);
    //PlayerTest->setGroundFriction(TEMP /* = Platform->getFriction()*/);
/*
    P1K = {Qt::Key_W Jump/Go up key,
           Qt::Key_A Left key,
           Qt::Key_S Crunch/Drop/Go down key ,
           Qt::Key_D Right key,
           Qt::Key_Q Throw key,
           Qt::Key_R Pick up/Interact key,
           Qt::Key_F Sprint key};

    P2K = {Qt::Key_Up Jump/Go up key,
           Qt::Key_Left Left key,
           Qt::Key_Down Crunch/Drop/Go down key,
           Qt::Key_Right Right key,
           Qt::Key_O Throw key,
           Qt::Key_P Pick up/Interact key,
           Qt::Key_Control Sprint key};

    PlayerKeys.push_back(P1K);
    PlayerKeys.push_back(P2K);
*/
    //view->setScene(scene);
    //view->show();

}

void MainWindow::keyPressEvent(QKeyEvent *Event){

    static Qt::Key LastKey = Qt::Key_0;
    qDebug() << QString("Tecla: ") << QString(Event->key());

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BRegister_clicked()
{
    usuario = new User(this);
    usuario->option = 1;
    usuario->show();
    this->hide();
}

void MainWindow::on_BInicio_clicked()
{
    usuario = new User(this);
    usuario->option = 2;
    usuario->show();
    this->hide();
}
