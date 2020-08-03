#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QList>

#include "player.h"
#include "platform.h"
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

    static Multiplayer *getMainWinPtr();

    QGraphicsView * view;
    QList <Player *> Players;
    QList <Platform *> obstaculos;

private:
    Ui::Multiplayer *ui;

    QGraphicsScene * scene;

    static Multiplayer *pMultiplayer;
};

#endif // MULTIPLAYER_H
