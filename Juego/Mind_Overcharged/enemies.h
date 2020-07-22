#ifndef ENEMIES_H
#define ENEMIES_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemies: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemies();

public slots:
    void Move();

};

#endif // ENEMIES_H
