#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <math.h>

#define PI 3.1415 /// Pi constant declaration
#define G 0.0988 /// Gravity
#define Vt(Mass) pow((2 * Mass * G) / (1.17 * 0.06 * 0.6), 0.5) /// Terminal speed formula

class WanderingEnemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    WanderingEnemy(short Mass, short InitDirection = 0, QGraphicsItem * = nullptr);

    qreal getSpeed_X();
    qreal getSpeed_Y();
    qreal getAccel_X();
    qreal getAccel_Y();
    qreal getGroundFr();
    qreal getAirFr();
    bool getOnPlatform();
    bool getDirection();

    void setSpeed_X(qreal Speed_X);
    void setSpeed_Y(qreal Speed_Y);
    void setAccel_X(qreal Accel_X);
    void setAccel_Y(qreal Accel_Y);
    void setGroundFr(qreal GroundFriction);
    void setAirFr(qreal AirFriction);
    void setOnPlatform(bool Status);
    void setDirection(bool Direction);

public slots:
    void Move();
    void Sprite();

private:
    bool Direction;
    bool OnPlatform;
    QTimer *MoveTimer;

    QPointF Speed, Accel;
    double GroundFr, AirFr;

    const short Mass;

};

#endif // ENEMY_H
