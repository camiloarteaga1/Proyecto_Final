#ifndef NIVL1_H
#define NIVL1_H

#include <QWidget>
#include <iostream>
#include <string.h>
#include <cmath>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QList>
#include <QObject>
#include <QTimer>

#include "user.h"
#include "checkpoint.h"
#include "estrella.h"
#include "player.h"
#include "platform.h"
#include "enemies.h"
#include "wanderingenemy.h"
#include "nivl2.h"
using namespace std;

namespace Ui {
class Nivl1;
}

class Nivl1 : public QWidget
{
    Q_OBJECT

public:
    explicit Nivl1(QWidget *parent = nullptr);
    ~Nivl1();
    QGraphicsScene * scene;
    QGraphicsView * view;
    class User *DataCollector;
    string UserName;
    int vid;

    QList <class Player *> Players;
    QList <Platform *> obstaculos;
    QList <Estrella *> corazones;
    QList <WanderingEnemy *> W_Enemies;
    //QList <Enemies *> enemigos;

    void keyPressEvent(QKeyEvent *Event);
    void addFloor();

    static Nivl1 *getMainWinPtr();

    static Nivl1 *pNivl1;

    void CollitionDetection();

    QTimer * CollitionsTimer;

    Nivl2 *nivl2;


    //Vidas *vidas;

private:
    Ui::Nivl1 *ui;

};

#endif // NIVL1_H
