#ifndef BOTON_H
#define BOTON_H

#include <QGraphicsPixmapItem>

class Boton: public QGraphicsPixmapItem
{
public:
    Boton(float Pos_X, float Pos_Y, char Type[1], char Orientation[1]);
    void setStatus(bool Status);
    bool getStatus();

private:
    bool Status;

};

#endif // BOTON_H
