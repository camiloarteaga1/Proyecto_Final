#ifndef NIVEL2_H
#define NIVEL2_H

#include <iostream>
#include <string.h>
#include <cmath>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QList>
#include <QWidget>

#include "vidas.h"
#include "checkpoint.h"
#include "estrella.h"
#include "player.h"
#include "platform.h"
#include "enemies.h"
using namespace std;

class Nivel2
{
public:
    Nivel2(QWidget *parent = nullptr);
};

#endif // NIVEL2_H
