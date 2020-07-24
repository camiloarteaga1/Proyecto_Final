#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "player.h"

/// Max size = 10*10 Px
class Platform: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Platform(QGraphicsItem * = nullptr);
    Platform(float Pos_X, float Pos_Y, float Friction, float ConductivityResistance, char Orintation[1]);
    float getFriction();
    float getTemperature();


public slots:
    void ConductionEffects();
    void TemperatureChange();

private:
    float Friction;
    float Temp;
    float CondRes;
    bool isActive;

};

#endif // PLATFORM_H
