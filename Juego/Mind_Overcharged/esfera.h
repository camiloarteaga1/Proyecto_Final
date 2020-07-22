#ifndef ESFERA_H
#define ESFERA_H

#include <QGraphicsPixmapItem>

class Esfera: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Esfera(float Pos_X, float Pos_Y, float EffectRange, float Force, char Orientation[1]);

    template<typename T>
    void Electromagnetism(T Entity);

private:
    float Range, Force;

};

#endif // ESFERA_H
