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

    P2K = {Qt::Key_I/*Jump/Go up key*/,
           Qt::Key_J/*Left key*/,
           Qt::Key_K/*Crunch/Drop/Go down key*/,
           Qt::Key_L/*Right key*/,
           Qt::Key_O/*Throw key*/,
           Qt::Key_P/*Pick up/Interact key*/,
           Qt::Key_Shift/*Sprint key*/};

    PlayerKeys.push_back(P1K);
    PlayerKeys.push_back(P2K);

}

void MainWindow::keyPressEvent(QKeyEvent *Event){

    if(GameScreen && Event->key()){

        GameScreen = false;
        return;

    }

    /// NewUp = NewUp xor CurrentDown? NewUp : 0;

    if(PlayerKeys[0][0] == Event->key()){
        ///P1->MoveFunction(NewUp, CurrentDown, CurrentLeft, CurrentRight);
        ///CurrentUp = NewUp;
        ///NewUp = 0;
    }else
    if(PlayerKeys[0][1] == Event->key()){
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

    case Qt::Key_I: /*Jump Code (Redirect Function / Maze move upwards)*/ break;
    case Qt::Key_J: /*Move left Code*/ break;
    case Qt::Key_K: /*Crunch and fall from platform Code (Maze move downwards)*/ break;
    case Qt::Key_L: /*Move right Code*/ break;
    case Qt::Key_O: /*Throw head Code*/ break;
    case Qt::Key_P: /*Pick up items / interact objects Code*/ break;
    case Qt::Key_Shift: /*Sprint Code*/ break;
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
    usuario = new User(this);
    usuario->option = 1;
    usuario->show();
}

void MainWindow::on_BInicio_clicked()
{
    usuario = new User(this);
    usuario->option = 2;
    usuario->show();
}
