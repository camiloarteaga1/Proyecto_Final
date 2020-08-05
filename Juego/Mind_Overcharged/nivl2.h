#ifndef NIVL2_H
#define NIVL2_H

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

#include "checkpoint.h"
#include "estrella.h"
#include "player.h"
#include "platform.h"
#include "wanderingenemy.h"
#include "portal.h"
#include "final.h"
using namespace std;

namespace Ui {
class Nivl2;
}

class Nivl2 : public QWidget
{
    Q_OBJECT

public:
    explicit Nivl2(QWidget *parent = nullptr);
    ~Nivl2();
    void CollitionDetection();

    QGraphicsScene * scene;
    QGraphicsView * view;
    QList <class Player *> Players;
    QList <Portal *> portal;

    QList <Platform *> obstaculos;
    QList <Estrella *> corazones;
    QList <WanderingEnemy *> W_Enemies;

    void keyPressEvent(QKeyEvent *Event);

    static Nivl2 *getMainWinPtr();

    static Nivl2 *pNivl2;

    string UserName;

    int vidas;

    class User *DataCollector;

    Final *message;

private:
    Ui::Nivl2 *ui;
    QTimer *CollitionsTimer;

    void addFloor();
};

#endif // NIVL2_H
