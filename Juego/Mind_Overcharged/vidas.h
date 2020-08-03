#ifndef VIDAS_H
#define VIDAS_H

#include <QGraphicsTextItem>

class Vidas: public QGraphicsTextItem
{
public:
    Vidas(QGraphicsItem * parent=0);
    void increase();
    int getVidas();
private:
    int vidas;
};

#endif // VIDAS_H
