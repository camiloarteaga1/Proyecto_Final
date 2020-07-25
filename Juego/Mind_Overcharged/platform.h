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
    Platform(float Pos_X, float Pos_Y, float Friction, float ConductivityResistance, float AmbientTemperature, QGraphicsItem * = nullptr);
    float getFriction();
    float getTemperature();
    bool getStatus();

    void setStatus(bool);

public slots:
    void ConductionEffects();
    void TemperatureChange();

private:
    float Friction;
    const float TempBase;
    float Temp;
    float CondRes;
    bool isActive;

};

#endif // PLATFORM_H
