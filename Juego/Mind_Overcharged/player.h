#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <math.h>

#define MAX_LIFES 3 /// Player's max lifes
#define MAX_CHARGE 770 /// Player's max head charge
#define MAX_SEPARATE_TIME 10.00 /// Time head can be separated from the body in sec
#define PI 3.1415 /// Pi constant declaration
#define G 0.0988 /// Gravity
#define MAX_X_SPEED 3.00 /// Max horizontal player speed
#define Vt(Mass) pow((2 * Mass * G) / (1.17 * 0.06 * 0.6), 0.5) /// Terminal speed formula


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
/// Functions
public:
    Player(short HeadMass, short BodyMass, short ID, QGraphicsItem * = nullptr);

    void ThrowObj();
    void PlayerDie(); /// Do

    ///**************************  Getters  **************************///
    /// Body
    float getAccel_BX();
    float getAccel_BY();
    float getSpeed_BX();
    float getSpeed_BY();
    double getBodyGroundFriction();
    bool getOnPlatform();

    /// Head
    float getAccel_HX();
    float getAccel_HY();
    float getSpeed_HX();
    float getSpeed_HY();
    double getHeadGroundFriction();
    bool getHeadOnPlatform();

    /// Player data
    short getLifes();
    short getID(); /// Revizar
    short getCharge();
    bool getHeadStatus();
    short getSeparateTime();
    Qt::Key getKeyPressing();
    double getAirResistance();
    short getInmunityTime();

    ///**************************  Setters  **************************///
    /// Body
    void setAccel_BX(float Acceleration_X);
    void setAccel_BY(float Acceleration_Y);
    void setSpeed_BX(float Speed_X);
    void setSpeed_BY(float Speed_Y);
    void setBodyGroundFriction(double GroundFriction);
    void setOnPlatform(bool Status);

    /// Head
    void setAccel_HX(float Acceleration_X);
    void setAccel_HY(float Acceleration_Y);
    void setSpeed_HX(float Speed_X);
    void setSpeed_HY(float Speed_Y);
    void setHeadGroundFriction(double GroundFriction);
    void setHeadOnPlatform(bool Status);

    /// Player data
    void setLifes(short LifesCount);
    void setCharge(short Charge);
    void setHeadStatus(bool HaveIt);
    void setSeparateTime(short TimeSec);
    void setKeyPressing(Qt::Key);
    void setAirResistance(double AirResistance);
    void setInmunityTime(short TimeSec);


    ///************************** Timers controlers  **************************///
    /// Move Timer
    void MoveStart(int TimeMls = 10);
    void MoveStop();

    /// Throw Timer
    void ThrowStart(int TimeMls = 10);
    void ThrowStop();

    /// Discharge Timer
    void DischargeStart(int TimeMls = 142);
    void DischargeStop();

    /// Sprites Timer
    void SpritesStart(int TimeMls = 500);
    void SpritesStop();

    /// 10 seconds Timer
    void SeparateStart(int TimeMls = 1000);
    void SeparateStop();

    /// Inmunity Timer
    void InmunityStart(int TimeMls = 1000);
    void InmunityStop();

private slots:
    /// Interactions
    void MovePlayer();
    void MoveHead();
    void DischargeHead();
    void PickUpHead();
    void SeparateHead();
    void InmunityTime();

public slots:
    /// Sprites
    void BodySprite();
    void HeadSprite();

/// Variables
public:
    QGraphicsPixmapItem *Head;

private:

    bool HeadStatus;
    bool OnPlatform;
    bool HeadOnPlatform;

    QTimer *MoveTimer;
    QTimer *ThrowTimer;
    QTimer *DischargeHeadTimer;
    QTimer *SpritesTimer;
    QTimer *SeparateHeadTimer;
    QTimer *InmunityTimer;

    QPointF BAccel, BSpeed; /// Body
    QPointF HAccel, HSpeed; /// Head

    const short HMass, BMass;
    const short ID;
    short HeadCharge;
    short P_Lifes;
    short SepTime;
    short Inmunity;


    //float SpriteRows, SpriteColumns; /// Sprite dimensions
    //float SpriteWidth, SpriteHeight;

    double AirRes, BGroundFr, HGroundFr;
    Qt::Key CurrentKey;

};


///***********************  Undefine Macros  ***********************///
/*#ifdef PLAYER_MACROS

#undef MAX_LIFES
#undef MAX_CHARGE
#undef MAX_SEPARATE_TIME
#undef PI
#undef G
#undef MAX_X_SPEED
#undef Vt

#endif*/

#endif // PLAYER_H
