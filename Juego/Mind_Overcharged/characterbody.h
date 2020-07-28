/*#ifndef CHARACTERBODY_H
#define CHARACTERBODY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class CharacterBody: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CharacterBody(short Mass, QGraphicsItem * = nullptr); ///
    short getMass();

public slots:
    void Sprite(); /// Do

private:
    float Accel_X, Accel_Y;
    float Speed_X, Speed_Y;
    const short Mass;

};

#endif // CHARACTERBODY_H
*/
