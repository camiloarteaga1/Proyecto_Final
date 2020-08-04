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

#include "vidas.h"
#include "checkpoint.h"
#include "estrella.h"
#include "player.h"
#include "platform.h"
#include "enemies.h"
#include "portal.h"
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

    QGraphicsScene * scene;
    QGraphicsView * view;
    class Player * player;
    QList <Portal *> portal;

    QList <Platform *> obstaculos;
    QList <Estrella *> corazones;
    //QList <Enemies *> enemigos;

    void keyPressEvent(QKeyEvent *Event);

    static Nivl2 *getMainWinPtr();

    static Nivl2 *pNivl2;

private:
    Ui::Nivl2 *ui;
};

#endif // NIVL2_H
