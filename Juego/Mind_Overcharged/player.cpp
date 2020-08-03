#include "player.h"
//#include "game.h"

//#include <QDebug>
#include <QPointF>

Player::Player(short HeadMass, short BodyMass, short id, QGraphicsItem *parent)
    : HeadStatus(true), OnPlatform(false), HMass(HeadMass), BMass(BodyMass), ID(id), SepTime(MAX_SEPARATE_TIME), Inmunity(3), AirRes(0), BGroundFr(0), HGroundFr(0)
{

    Head = new QGraphicsPixmapItem();

    setPixmap(QPixmap(":/Sprites/PlayerBody.png"));
    Head->setPixmap(QPixmap(":/Sprites/PlayerHead.png"));

    setHeadStatus(true);
    Head->setPos(qreal(this->x() - (this->pixmap().width() / 2)),
                 qreal(this->y() - Head->pixmap().height()));

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
    InmunityTimer = new QTimer;
    SeparateHeadTimer = new QTimer;

    connect(MoveTimer, SIGNAL(timeout()), this, SLOT(MovePlayer()));
    connect(ThrowTimer, SIGNAL(timeout()), this, SLOT(MoveHead()));
    connect(DischargeHeadTimer, SIGNAL(timeout()), this, SLOT(DischargeHead()));
    connect(SpritesTimer, SIGNAL(timeout()), this, SLOT(BodySprite()));
    connect(SpritesTimer, SIGNAL(timeout()), this, SLOT(HeadSprite()));
    connect(InmunityTimer, SIGNAL(timeout()), this, SLOT(InmunityTime()));
    connect(SeparateHeadTimer, SIGNAL(timeout()), this, SLOT(SeparateHead()));

    MoveStart(10);
    //SpritesStart(500);

}

void Player::ThrowObj(){

    setHeadStatus(false);

    HSpeed = QPointF(5, -5);
    HAccel = QPointF(0, qreal(G));

    ThrowStart(10);
    SeparateStart(1000);

}

void Player::PlayerDie(){



}

///**************************  Getters  **************************///
/// Body
float Player::getAccel_BX(){return float(BAccel.x());}
float Player::getAccel_BY(){return float(BAccel.y());}

float Player::getSpeed_BX(){return float(BSpeed.x());}
float Player::getSpeed_BY(){return float(BSpeed.y());}

double Player::getBodyGroundFriction(){return BGroundFr;}
bool Player::getOnPlatform(){return OnPlatform;}

/// Head
float Player::getAccel_HX(){return float(HAccel.x());}
float Player::getAccel_HY(){return float(HAccel.y());}

float Player::getSpeed_HX(){return float(HSpeed.x());}
float Player::getSpeed_HY(){return float(HSpeed.y());}

double Player::getHeadGroundFriction(){return HGroundFr;}
bool Player::getHeadOnPlatform(){return HeadOnPlatform;}

/// Player data
short Player::getLifes(){return P_Lifes;}
short Player::getID(){return ID;}
short Player::getCharge(){return HeadCharge;}
bool Player::getHeadStatus(){return HeadStatus;}
short Player::getSeparateTime(){return SepTime;}
Qt::Key Player::getKeyPressing(){return CurrentKey;}
double Player::getAirResistance(){return AirRes;}
short Player::getInmunityTime(){return Inmunity;}


///**************************  Setters  **************************///
/// Body
void Player::setAccel_BX(float Acceleration_X){BAccel.rx() = qreal(Acceleration_X);}
void Player::setAccel_BY(float Acceleration_Y){BAccel.ry() = qreal(Acceleration_Y);}

void Player::setSpeed_BX(float Speed_X){BSpeed.rx() = qreal(Speed_X);}
void Player::setSpeed_BY(float Speed_Y){BSpeed.ry() = qreal(Speed_Y);}

void Player::setBodyGroundFriction(double GroundFriction){BGroundFr = GroundFriction;}
void Player::setOnPlatform(bool Status){

    OnPlatform = Status;

    if(Status){
        setAccel_BY(0);
        setSpeed_BY(0);
    }

    else
        this->setAccel_BY(float(G));

    return;

}

/// Head
void Player::setAccel_HX(float Acceleration_X){HAccel.rx() = qreal(Acceleration_X);}
void Player::setAccel_HY(float Acceleration_Y){HAccel.ry() = qreal(Acceleration_Y);}

void Player::setSpeed_HX(float Speed_X){HSpeed.rx() = qreal(Speed_X);}
void Player::setSpeed_HY(float Speed_Y){HSpeed.ry() = qreal(Speed_Y);}

void Player::setHeadGroundFriction(double GroundFriction){HGroundFr = GroundFriction;}
void Player::setHeadOnPlatform(bool Status){

    HeadOnPlatform = Status;

    if(Status){
        setAccel_HY(0);
        setSpeed_HY(0);
    }

    else
        this->setAccel_HY(float(G));

    return;

}

/// Player data
void Player::setLifes(short LifesCount){P_Lifes = LifesCount;}
void Player::setCharge(short Charge){HeadCharge = Charge;}
void Player::setHeadStatus(bool HaveIt){HeadStatus = HaveIt;}
void Player::setSeparateTime(short TimeSec){SepTime = TimeSec;}
void Player::setKeyPressing(Qt::Key Key){CurrentKey = Key;}
void Player::setAirResistance(double AirResistance){AirRes = AirResistance;}


void Player::setInmunityTime(short TimeSec){Inmunity = TimeSec;}


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

/// 10 seconds Timer
void Player::SeparateStart(int TimeMls){SeparateHeadTimer->start(TimeMls);}
void Player::SeparateStop(){SeparateHeadTimer->stop();}

/// Inmunity Timer
void Player::InmunityStart(int TimeMls){InmunityTimer->start(TimeMls);}
void Player::InmunityStop(){InmunityTimer->stop();}

///**************************  Slots  **************************///
/// Interactions
void Player::MovePlayer(){

    static qreal Last_XPos = 0;
    double TResistance = AirRes;
    QList<QGraphicsItem *> CollidingItems = collidingItems();

    if(!HeadStatus){
        foreach(QGraphicsItem *i, collidingItems()){

            QGraphicsPixmapItem *Obj = dynamic_cast<QGraphicsPixmapItem *>(i);
            if(Obj && Head->pos() == Obj->pos())
                    PickUpHead();

        }
    }

    TResistance += BGroundFr;
    TResistance = TResistance > 1? 1 : TResistance;

    BSpeed.setX(BSpeed.x() + (BAccel.x() * TResistance));
    BAccel -= QPointF(BAccel.x() * TResistance, BAccel.y() * AirRes); /// Change acceleration

    /// Limit acceleration
    BAccel.setX(BAccel.x() > MAX_X_SPEED? MAX_X_SPEED : BAccel.x() < -MAX_X_SPEED? -MAX_X_SPEED : BAccel.x());
    BAccel.setY(BAccel.y() < G * AirRes? G * AirRes : BAccel.y());

    /// Change speed
    BSpeed.setY(BSpeed.y() + BAccel.y());
    BSpeed.setX((BSpeed.x() * TResistance) + BAccel.x());

    /// Limit speed
    BSpeed.setX(BSpeed.x() > MAX_X_SPEED? MAX_X_SPEED : BSpeed.x() < -MAX_X_SPEED? -MAX_X_SPEED : BSpeed.x());
    BSpeed.setY(BSpeed.y() > Vt(this->BMass + (HeadStatus? this->HMass : 0))? Vt(this->BMass + (HeadStatus? this->HMass : 0)) : BSpeed.y());

    if(OnPlatform && BSpeed.y() > 0)
        BSpeed.setY(0);

    /// Change pos
    this->setX(x() + BSpeed.x());
    this->setY(y() + BSpeed.y());

    /// Move head with the body
    if(HeadStatus)
        Head->setPos(qreal(this->x() - (this->pixmap().width() / 2)),
                     qreal(this->y() - Head->pixmap().height()));

    /// If stopped by wall set move x variables to 0
    if(Last_XPos == this->x()){
        BAccel.setX(0);
        BSpeed.setX(0);
    }

     Game *Wenaz = Game::getMainWinPtr();
    Wenaz->view->centerOn(x(), y());

    Last_XPos = this->x();
    CurrentKey = Qt::Key_0;

    //qDebug() << QString("Head Status: ") << QString::number(getHeadOnPlatform());
    //qDebug() << QString("Resistencia total: ") << QString::number(TResistance);
    //qDebug() << QString("Velocidad terminal: ") << QString::number(Vt(this->BMass + (HeadStatus? this->HMass : 0)));
    //qDebug() << QString("Aceleracion X: ") << QString::number(BAccel.x()) << QString("Aceleracion Y: ") << QString::number(BAccel.y());
    //qDebug() << QString("Velocidad X: ") << QString::number(qreal(getSpeed_BX())) << QString("Velocidad Y: ") << QString::number(qreal(getSpeed_BY()));
    //qDebug() << QString("Posicion X: ") << QString::number(x()) << QString("Posicion Y: ") << QString::number(y());
    return;

}

void Player::MoveHead(){

    static qreal Last_XPos = 0;
    double TResistance = AirRes;

    TResistance += HGroundFr;
    TResistance = TResistance > 1? 1 : TResistance;

    HSpeed.setX(HSpeed.x() - (HSpeed.x() * TResistance));
    HAccel -= QPointF(HAccel.x() * TResistance, HAccel.y() * AirRes); /// Change acceleration

    /// Limit acceleration
    HAccel.setY(HAccel.y() < G - (G * AirRes)? G - (G * AirRes) : HAccel.y());

    /// Change speed
    HSpeed.setY(HSpeed.y() + HAccel.y());
    HSpeed.setX(HSpeed.x() + HAccel.x());

    /// Limit speed
    HSpeed.setX(HSpeed.x() > MAX_X_SPEED? MAX_X_SPEED : HSpeed.x() < -MAX_X_SPEED? -MAX_X_SPEED : HSpeed.x());
    HSpeed.setY(HSpeed.y() > Vt(this->HMass)? Vt(this->HMass) : HSpeed.y());

    if(HeadOnPlatform && HSpeed.y() > 0)
        HSpeed.setY(0);

    /// Change pos
    Head->setX(Head->x() + HSpeed.x());
    Head->setY(Head->y() + HSpeed.y());

    /// If stopped by wall set move x variables to 0
    if(Last_XPos == Head->x()){
        BAccel.setX(0);
        BSpeed.setX(0);
    }

    Last_XPos = Head->x();

    //qDebug() << QString("Sobre plataforma: ") << QString::number(getOnPlatform());
    //qDebug() << QString("Resistencia total: ") << QString::number(TResistance);
    //qDebug() << QString("Velocidad terminal: ") << QString::number(Vt(this->HMass));
    //qDebug() << QString("Aceleracion X: ") << QString::number(HAccel.x()) << QString("Aceleracion Y: ") << QString::number(HAccel.y());
    //qDebug() << QString("Velocidad X: ") << QString::number(qreal(getSpeed_HX())) << QString("Velocidad Y: ") << QString::number(qreal(getSpeed_HY()));
    //qDebug() << QString("Posicion X: ") << QString::number(Head->x()) << QString("Posicion Y: ") << QString::number(Head->y());

    return;

}

void Player::DischargeHead(){

    setCharge(getCharge() - 1);

}

void Player::PickUpHead(){

    setHeadStatus(true);
    Head->setPos(qreal(this->x() - (this->pixmap().width() / 2)),
                 qreal(this->y() - Head->pixmap().height()));

    ThrowStop();
    SeparateStop();
    setSeparateTime(MAX_SEPARATE_TIME);

}

void Player::SeparateHead(){

    setSeparateTime(getSeparateTime() - 1);

    if(!getSeparateTime()) PlayerDie();

}

void Player::InmunityTime(){

    static short Joins = 0;
    static short ImT = getInmunityTime();

    if(!Joins)
        SpritesStop();

    else if(Joins == 12){
        InmunityStop();
        SpritesStart(250);
        Joins = 0;
        setInmunityTime(3);
        return;
    }



    /// Inmunity time sprite

    if(Joins % 4 == 0)
        ImT -= 1;

}

/// Sprites
void Player::BodySprite(){

    /// Sprite Code...

}

void Player::HeadSprite(){

    /// Sprite Code...

}
