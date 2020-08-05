#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QList>

#include "player.h"
#include "platform.h"
#include "wanderingenemy.h"
#include <QDebug>

namespace Ui {
class Multiplayer;
}

class Multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = nullptr);
    ~Multiplayer();
    void keyPressEvent(QKeyEvent *Event);
    void addFloor();
    void CollitionDetection();

    static Multiplayer *getMainWinPtr();

    QGraphicsView * view;
    QList <class Player *> Players;
    QList <Platform *> obstaculos;
    QList <WanderingEnemy *> W_Enemies;

    QTimer *CollitionsTimer;

private:
    Ui::Multiplayer *ui;

    QGraphicsScene * scene;

    static Multiplayer *pMultiplayer;
};

#endif // MULTIPLAYER_H
