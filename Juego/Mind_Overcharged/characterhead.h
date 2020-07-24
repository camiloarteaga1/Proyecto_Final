#ifndef CHARACTERHEAD_H
#define CHARACTERHEAD_H

#include <QGraphicsPixmapItem>
#include <QObject>

#define MAX_CHARGE 770 //Amperios


class CharacterHead: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CharacterHead(QGraphicsItem * = nullptr);
    void EnergiceObj(/*Class Obj*/);

    //float get_X(), get_Y();
    //void set_X(float X_Value), set_Y(float Y_Value);

public slots:
    void Sprite();

private:
    float Charge;
    float Accel_X, Accel_Y;
    float Mass;


};

#endif // CHARACTERHEAD_H
