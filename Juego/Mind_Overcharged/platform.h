#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Platform: public QGraphicsPixmapItem
{
public:
    Platform(float Friction = 1, bool IsSolid = 1, QString FileName = "", QGraphicsItem * = nullptr);

    double getFriction();
    bool IsSolid();

private:
    const double Friction;
    const bool Solid;

};

#endif // PLATFORM_H
