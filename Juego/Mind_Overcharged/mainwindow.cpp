#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    scene->setSceneRect(0, 0, 2000, 2000);
    view->setScene(scene);
    view->resize(1000, 1000);
    this->resize(1000, 1000);*/

    GameScreen = true;
    Multiplayer = false;

    P1K = {Qt::Key_W/*Jump/Go up key*/,
           Qt::Key_A/*Left key*/,
           Qt::Key_S/*Crunch/Drop/Go down key*/,
           Qt::Key_D/*Right key*/,
           Qt::Key_Q/*Throw key*/,
           Qt::Key_R/*Pick up/Interact key*/,
           Qt::Key_F/*Sprint key*/};

    P2K = {Qt::Key_Up/*Jump/Go up key*/,
           Qt::Key_Left/*Left key*/,
           Qt::Key_Down/*Crunch/Drop/Go down key*/,
           Qt::Key_Right/*Right key*/,
           Qt::Key_O/*Throw key*/,
           Qt::Key_P/*Pick up/Interact key*/,
           Qt::Key_Control/*Sprint key*/};

    PlayerKeys.push_back(P1K);
    PlayerKeys.push_back(P2K);

}

void MainWindow::keyPressEvent(QKeyEvent *Event){

    if(GameScreen && Event->key()){

        GameScreen = false;
        return;

    }

    /// NewUp = NewUp xor CurrentDown? NewUp : 0;

    //Player 1 keys
    if(PlayerKeys[0][0] == Event->key()){ // Jump Code (Redirect Function / Maze move upwards)
        if()
        Players[0].MovePlayer(0, 10, 0, 0.1f, 9.8f);
    }
    else if(PlayerKeys[0][1] == Event->key()){ // Move left Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[0][2] == Event->key()){ // Crunch and fall from platform Code (Maze move downwards)
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[0][3] == Event->key()){ // Move right Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[0][4] == Event->key()){ // Throw head Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[0][5] == Event->key()){ // Pick up items / interact objects Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[0][6] == Event->key()){ // Sprint Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }

    //Player 2 keys
    if(PlayerKeys[1][0] == Event->key()){ // Jump Code (Redirect Function / Maze move upwards)
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[1][1] == Event->key()){ // Move left Code

    }
    else if(PlayerKeys[1][2] == Event->key()){ // Crunch and fall from platform Code (Maze move downwards)
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[1][3] == Event->key()){ // Move right Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[1][4] == Event->key()){ // Throw head Code
        ///Player2->ThrowHead()
    }
    else if(PlayerKeys[1][5] == Event->key()){ // Pick up items / interact objects Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }
    else if(PlayerKeys[1][6] == Event->key()){ // Sprint Code
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }

    switch(Event->key()){

    case Qt::Key_A: /*Move left Code*/ break;
    case Qt::Key_S: /*Crunch and fall from platform Code (Maze move downwards)*/ break;
    case Qt::Key_D: /*Move right Code*/ break;
    case Qt::Key_Q: /*Throw head Code*/ break;
    case Qt::Key_R: /*Pick up items / interact objects Code*/ break;
    case Qt::Key_F: /*Sprint Code*/ break;

    case Qt::Key_Up: /*Jump Code (Redirect Function / Maze move upwards)*/ break;
    case Qt::Key_Left: /*Move left Code*/ break;
    case Qt::Key_Down: /*Crunch and fall from platform Code (Maze move downwards)*/ break;
    case Qt::Key_Right: /*Move right Code*/ break;
    case Qt::Key_O: /*Throw head Code*/ break;
    case Qt::Key_P: /*Pick up items / interact objects Code*/ break;
    case Qt::Key_Control: /*Sprint Code*/ break;
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    default: break;

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BRegister_clicked()
{

}
