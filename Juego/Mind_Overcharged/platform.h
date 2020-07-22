#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "player.h"

class Platform: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Platform(float Pos_X, float Pos_Y, float Friction, float ConductivityResistance, char Orintation[1]);

    float get_Friction();
    void ConductionEffects(Player *, Platform *);


private:
    float Fr;
    float Temp;
    float CondRes;

};

#endif // PLATFORM_H
