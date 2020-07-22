#ifndef ESTRELLA_H
#define ESTRELLA_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "player.h"

class Estrella: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Estrella();
    void Picked(Player *);

public slots:
    void Sprite();

};

#endif // ESTRELLA_H
