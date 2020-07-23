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
    float getTemperature();


public slots:
    void ConductionEffects(Player *, Platform *);
    void TemperatureChange();

private:
    float Friction;
    float Temp;
    float CondRes;
    bool isActive;

};

#endif // PLATFORM_H
