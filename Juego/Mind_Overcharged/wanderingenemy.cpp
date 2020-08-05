#include "wanderingenemy.h"

#include <QDebug>

WanderingEnemy::WanderingEnemy(short M, short InitDirection, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), Direction(InitDirection), OnPlatform(false), GroundFr(0), AirFr(0), Mass(M)
{

    setPixmap(QPixmap(":/Sprites/WanderingEnemy.png"));

    MoveTimer = new QTimer;

    connect(MoveTimer, SIGNAL(timeout()), this, SLOT(Move()));
    connect(MoveTimer, SIGNAL(timeout()), this, SLOT(Sprite()));

    MoveTimer->start(10);

}

///************************  Getters  ************************///
qreal WanderingEnemy::getSpeed_X(){return Speed.x();}
qreal WanderingEnemy::getSpeed_Y(){return Speed.y();}
qreal WanderingEnemy::getAccel_X(){return Accel.x();}
qreal WanderingEnemy::getAccel_Y(){return Accel.y();}
qreal WanderingEnemy::getGroundFr(){return GroundFr;}
qreal WanderingEnemy::getAirFr(){return AirFr;}
bool WanderingEnemy::getOnPlatform(){return OnPlatform;}
bool WanderingEnemy::getDirection(){return Direction;}

///************************  Setters  ************************///
void WanderingEnemy::setSpeed_X(qreal Speed_X){Speed.setX(Speed_X);}
void WanderingEnemy::setSpeed_Y(qreal Speed_Y){Speed.setY(Speed_Y);}
void WanderingEnemy::setAccel_X(qreal Accel_X){Accel.setX(Accel_X);}
void WanderingEnemy::setAccel_Y(qreal Accel_Y){Accel.setY(Accel_Y);}
void WanderingEnemy::setGroundFr(qreal GroundFriction){GroundFr = GroundFriction;}
void WanderingEnemy::setAirFr(qreal AirFriction){AirFr = AirFriction;}
void WanderingEnemy::setOnPlatform(bool Status){

    OnPlatform = Status;

    if(Status){
        setAccel_Y(0);
        setSpeed_Y(0);
    }

    else
        this->setAccel_Y(float(G));

    return;

}
void WanderingEnemy::setDirection(bool Direction){this->Direction = Direction;}

///************************  Slots  ************************///
void WanderingEnemy::Move(){

    double TResistance = AirFr;

    Speed.setX(Direction? 1 : -1);

    TResistance += GroundFr;
    TResistance = TResistance > 1? 1 : TResistance;

    Speed.setX(Speed.x() - (Speed.x() * TResistance));
    Accel -= QPointF(Accel.x() * TResistance, Accel.y() * AirFr); /// Change acceleration

    /// Limit acceleration
    Accel.setY(Accel.y() < G - (G * AirFr)? G - (G * AirFr) : Accel.y());

    /// Change speed
    Speed.setY(Speed.y() + Accel.y());
    Speed.setX(Speed.x() + Accel.x());

    /// Limit speed
    Speed.setY(Speed.y() > Vt(Mass)? Vt(Mass) : Speed.y());

    if(OnPlatform && Speed.y() > 0)
        Speed.setY(0);

    /// Change pos
    setX(x() + Speed.x());
    setY(y() + Speed.y());

    //qDebug() << QString("Sobre plataforma: ") << QString::number(getOnPlatform());
    //qDebug() << QString("Resistencia total: ") << QString::number(TResistance);
    //qDebug() << QString("Velocidad terminal: ") << QString::number(Vt(this->HMass));
    //qDebug() << QString("Aceleracion X: ") << QString::number(Accel.x()) << QString("Aceleracion Y: ") << QString::number(Accel.y());
    //qDebug() << QString("Velocidad X: ") << QString::number(qreal(getSpeed_X())) << QString("Velocidad Y: ") << QString::number(qreal(getSpeed_Y()));
    //qDebug() << QString("Posicion X: ") << QString::number(x()) << QString("Posicion Y: ") << QString::number(y());

    return;
}

void WanderingEnemy::Sprite()
{
    /// Sprite code
}
