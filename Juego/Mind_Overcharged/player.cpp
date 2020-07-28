#include "player.h"

#include <QDebug>

Player::Player(short HeadMass, short BodyMass, short id, QGraphicsItem *parent)
    : HMass(HeadMass), BMass(BodyMass), ID(id), AirRes(0), GroundFr(0)
{

    Head = new QGraphicsPixmapItem();

    setPixmap(QPixmap(":/new/prefix1/Images/PlayerBody.png"));
    Head->setPixmap(QPixmap(":/new/prefix1/Images/PlayerHead.png"));

    setHeadStatus(true);
    Head->setPos(qreal(this->get_BX() - (this->pixmap().width() / 2)),
                 qreal(this->get_BY() - Head->pixmap().height()));

    BAccel = QPointF(0, 0);
    BSpeed = QPointF(0, 0);

    HAccel = QPointF(0, 0);
    HSpeed = QPointF(0, 0);

    setCharge(MAX_CHARGE);
    setLifes(MAX_LIFES);

    MoveTimer = new QTimer;
    ThrowTimer = new QTimer;
    DischargeHeadTimer = new QTimer;
    SpritesTimer = new QTimer;

    connect(MoveTimer, SIGNAL(timeout()), this, SLOT(MovePlayer()));
    connect(ThrowTimer, SIGNAL(timeout()), this, SLOT(MoveHead()));
    connect(DischargeHeadTimer, SIGNAL(timeout()), this, SLOT(DischargeHead()));
    connect(SpritesTimer, SIGNAL(timeout()), this, SLOT(BodySprite()));
    connect(SpritesTimer, SIGNAL(timeout()), this, SLOT(HeadSprite()));

    MoveStart(1000);
    //SpritesStart(500);

}

void Player::ThrowObj(){

    setHeadStatus(false);

    HSpeed = QPointF(10, -10);
    HAccel = QPointF(0, qreal(G));

    ThrowStart(10);

}

///**************************  Getters  **************************///
/// Body
float Player::get_BX(){return float(this->x());}
float Player::get_BY(){return float(this->y());}

float Player::getAccel_BX(){return float(BAccel.x());}
float Player::getAccel_BY(){return float(BAccel.y());}

float Player::getSpeed_BX(){return float(BSpeed.x());}
float Player::getSpeed_BY(){return float(BSpeed.y());}

/// Head
float Player::get_HX(){return float(this->x());}
float Player::get_HY(){return float(this->y());}

float Player::getAccel_HX(){return float(HAccel.x());}
float Player::getAccel_HY(){return float(HAccel.y());}

float Player::getSpeed_HX(){return float(HSpeed.x());}
float Player::getSpeed_HY(){return float(HSpeed.y());}

/// Player data
short Player::getLifes(){return P_Lifes;}
short Player::getID(){return ID;}
short Player::getCharge(){return HeadCharge;}
bool Player::getHeadStatus(){return HeadStatus;}
Qt::Key Player::getKeyPressing(){return CurrentKey;}
double Player::getAirResistance(){return AirRes;}
double Player::getGroundFriction(){return GroundFr;}

///**************************  Setters  **************************///
/// Body
void Player::set_BX(float Pos_X){this->setX(qreal(Pos_X));}
void Player::set_BY(float Pos_Y){this->setY(qreal(Pos_Y));}

void Player::setAccel_BX(float Acceleration_X){BAccel.rx() = qreal(Acceleration_X);}
void Player::setAccel_BY(float Acceleration_Y){BAccel.ry() = qreal(Acceleration_Y);}

void Player::setSpeed_BX(float Speed_X){BSpeed.rx() = qreal(Speed_X);}
void Player::setSpeed_BY(float Speed_Y){BSpeed.ry() = qreal(Speed_Y);}

/// Head
void Player::set_HX(float Pos_X){Head->setX(qreal(Pos_X));}
void Player::set_HY(float Pos_Y){Head->setY(qreal(Pos_Y));}

void Player::setAccel_HX(float Acceleration_X){HAccel.rx() = qreal(Acceleration_X);}
void Player::setAccel_HY(float Acceleration_Y){HAccel.ry() = qreal(Acceleration_Y);}

void Player::setSpeed_HX(float Speed_X){HSpeed.rx() = qreal(Speed_X);}
void Player::setSpeed_HY(float Speed_Y){HSpeed.ry() = qreal(Speed_Y);}

/// Player data
void Player::setLifes(short LifesCount){P_Lifes = LifesCount;}
void Player::setCharge(short Charge){HeadCharge = Charge;}
void Player::setHeadStatus(bool HaveIt){HeadStatus = HaveIt;}
void Player::setKeyPressing(Qt::Key Key){CurrentKey = Key;}
void Player::setAirResistance(double AirResistance){AirRes = AirResistance;}
void Player::setGroundFriction(double GroundFriction){GroundFr = GroundFriction;}

///************************** Timers controlers  **************************///
/// Move Timer
void Player::MoveStart(int TimeMls){MoveTimer->start(TimeMls);}
void Player::MoveStop(){MoveTimer->stop();}

/// Throw Timer
void Player::ThrowStart(int TimeMls){ThrowTimer->start(TimeMls);}
void Player::ThrowStop(){ThrowTimer->stop();}

/// Discharge Timer
void Player::DischargeStart(int TimeMls){DischargeHeadTimer->start(TimeMls);}
void Player::DischargeStop(){DischargeHeadTimer->stop();}

/// Sprites Timer
void Player::SpritesStart(int TimeMls){SpritesTimer->start(TimeMls);}
void Player::SpritesStop(){SpritesTimer->stop();}

///**************************  Slots  **************************///
/// Interactions
void Player::MovePlayer(){

    static qreal Last_YPos = 0;
    static qreal Last_XPos = 0;
    double TResistance = AirRes;

    if(Last_YPos == this->y())
        TResistance += GroundFr;

    TResistance = TResistance > 1? 1 : TResistance;

    BAccel -= QPointF(BAccel.x() * TResistance, BAccel.y() * AirRes); /// Change acceleration


    if(BAccel.x() > MAX_X_SPEED)
        BAccel.setX(MAX_X_SPEED);
/*
    if(BAccel.y() > Vt((this->BMass + (HeadStatus? this->HMass : 0)), BAccel.y()))
        BAccel.setY(Vt((this->BMass + (HeadStatus? this->HMass : 0)), BAccel.y()));
*/
    else if(BAccel.y() < G)
        BAccel.setY(G);

    BSpeed += BAccel; /// Change speed

    if(BSpeed.x() > MAX_X_SPEED)
        BSpeed.setX(MAX_X_SPEED);

    if(BSpeed.y() > Vt((this->BMass + (HeadStatus? this->HMass : 0)), BAccel.y()))
        BSpeed.setY(Vt((this->BMass + (HeadStatus? this->HMass : 0)), BAccel.y()));

    this->pos() += BSpeed;
    this->set_BX(this->get_BX() + float(BSpeed.x()));
    this->set_BY(this->get_BY() + float(BSpeed.y()));

    if(HeadStatus)
        Head->setPos(qreal(this->get_BX() - (this->pixmap().width() / 2)),
                     qreal(this->get_BY() - Head->pixmap().height()));

    if(Last_XPos == this->x()){
        BAccel.setX(0);
        BSpeed.setX(0);
    }

    Last_YPos = this->y();
    Last_XPos = this->x();

    qDebug() << QString("Resistencia del aire: ") << QString::number(AirRes);
    qDebug() << QString("Velocidad terminal: ") << QString::number(Vt((this->BMass + (HeadStatus? this->HMass : 0)), BAccel.y()));
    qDebug() << QString("Aceleracion Y: ") << QString::number(BAccel.y());
    qDebug() << QString("Velocidad X: ") << QString::number(qreal(getSpeed_BX())) << QString("Velocidad Y: ") << QString::number(qreal(getSpeed_BY()));
    qDebug() << QString("Posicion X: ") << QString::number(qreal(get_BX())) << QString("Posicion Y: ") << QString::number(qreal(get_BY()));
    return;

}

void Player::MoveHead(){

    static qreal Last_YPos = 0;
    static qreal Last_XPos = 0;
    double TResistance = AirRes;

    if(Last_YPos == Head->y())
        TResistance += GroundFr;

    TResistance = TResistance > 1? 1 : TResistance;


    HAccel -= QPointF(HAccel.x() * TResistance, HAccel.y() * AirRes); /// Change acceleration

    if(HAccel.x() > MAX_X_SPEED)
        HAccel.setX(MAX_X_SPEED);

    if(HAccel.y() > Vt((HMass), HAccel.y()))
        HAccel.setY(Vt((HMass), HAccel.y()));

    else if(HAccel.y() < G)
        HAccel.setY(G);

    HSpeed += HAccel; /// Change speed

    if(HSpeed.x() > qreal(MAX_X_SPEED))
        HSpeed.setX(qreal(MAX_X_SPEED));

    if(HSpeed.y() > Vt((HMass), HAccel.y()))
        HSpeed.setY(Vt((HMass), HAccel.y()));


    Head->pos() += BSpeed; /// Change position
    set_HX(get_HX() + float(BSpeed.x()));
    set_HY(get_HY() + float(BSpeed.y()));


    if(Last_XPos == Head->x()){
        BAccel.setX(0);
        BSpeed.setX(0);
    }

    Last_YPos = this->y();
    Last_XPos = this->x();

}

void Player::DischargeHead(){

    setCharge(getCharge() - 1);

}

void Player::PickUpHead(){

    setHeadStatus(true);
    Head->setPos(qreal(this->get_BX() - (this->pixmap().width() / 2)),
                 qreal(this->get_BY() - Head->pixmap().height()));

}

/// Sprites
void Player::BodySprite(){

    /// Sprite Code...

}

void Player::HeadSprite(){

    /// Sprite Code...

}
