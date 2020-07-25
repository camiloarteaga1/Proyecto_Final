#ifndef BOTON_H
#define BOTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>

class Boton: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Boton(float Pos_X, float Pos_Y, short RotationDegrees, QGraphicsItem * = nullptr); ///
    bool getStatus();

    void Interactions(); ///
    void setStatus(bool Status);


private:
    QGraphicsPolygonItem *DetectArea;
    bool Status;

    //short Type;

};

#endif // BOTON_H
