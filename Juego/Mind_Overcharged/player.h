#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <math.h>

#define MAX_LIFES 3 /// Player's max lifes
#define MAX_CHARGE 770 /// Player's max head charge
#define PI 3.1415 /// Pi constant declaration
#define G 0.00 //0.0988 /// Gravity
#define MAX_X_SPEED 3.00 /// Max horizontal player speed
#define Vt(Mass) pow((2 * Mass * G) / (1.17 * 0.06 * 0.4), 0.5) /// Terminal speed formula

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
/// Functions
public:
    Player(short HeadMass, short BodyMass, short ID, QGraphicsItem * = nullptr);

    void ThrowObj();

    //template<typename T>
    //void ObjInteraction(T &Object);

    ///**************************  Getters  **************************///
    /// Body
    float get_BX();
    float get_BY();
    float getAccel_BX();
    float getAccel_BY();
    float getSpeed_BX();
    float getSpeed_BY();

    /// Head
    float get_HX();
    float get_HY();
    float getAccel_HX();
    float getAccel_HY();
    float getSpeed_HX();
    float getSpeed_HY();

    /// Player data
    short getLifes();
    short getID();
    short getCharge();
    bool getHeadStatus();
    Qt::Key getKeyPressing();
    double getAirResistance();
    double getGroundFriction();

    ///**************************  Setters  **************************///
    /// Body
    void set_BX(float Pos_X);
    void set_BY(float Pos_Y);
    void setAccel_BX(float Acceleration_X);
    void setAccel_BY(float Acceleration_Y);
    void setSpeed_BX(float Speed_X);
    void setSpeed_BY(float Speed_Y);

    /// Head
    void set_HX(float Pos_X);
    void set_HY(float Pos_Y);
    void setAccel_HX(float Acceleration_X);
    void setAccel_HY(float Acceleration_Y);
    void setSpeed_HX(float Speed_X);
    void setSpeed_HY(float Speed_Y);

    /// Player data
    void setLifes(short LifesCount);
    void setCharge(short Charge);
    void setHeadStatus(bool HaveIt);
    void setKeyPressing(Qt::Key);
    void setAirResistance(double AirResistance);
    void setGroundFriction(double GroundFriction);

    ///************************** Timers controlers  **************************///
    /// Move Timer
    void MoveStart(int TimeMls);
    void MoveStop();

    /// Throw Timer
    void ThrowStart(int TimeMls);
    void ThrowStop();

    /// Discharge Timer
    void DischargeStart(int TimeMls);
    void DischargeStop();

    /// Sprites Timer
    void SpritesStart(int TimeMls);
    void SpritesStop();

private slots:
    /// Interactions
    void MovePlayer();
    void MoveHead();
    void DischargeHead();
    void PickUpHead();

public slots:
    /// Sprites
    void BodySprite();
    void HeadSprite();

/// Variables
public:
    QGraphicsPixmapItem *Head;

private:

    //QGraphicsPixmapItem Body;

    bool HeadStatus;
    Qt::Key CurrentKey;

    QTimer *MoveTimer;
    QTimer *ThrowTimer;
    QTimer *DischargeHeadTimer;
    QTimer *SpritesTimer;

    QPointF BAccel, BSpeed; /// Body
    QPointF HAccel, HSpeed; /// Head

    const short HMass, BMass;
    const short ID;
    short HeadCharge;
    short P_Lifes;

    double AirRes, GroundFr;


};

#endif // PLAYER_H
