#include "sprite.h"

Sprite::Sprite(QObject *parent, QString image) : QObject(parent)
{
    timer = new QTimer();

    filas = 0;
    columnas = 0;
    ancho = 100; //Tamaño
    alto = 100;

    pixmap = new QPixmap(image);

    connect(timer, &QTimer::timeout, this, &Sprite::Actualizar);
    timer->start(150);
}

void Sprite::Actualizar()
{
    columnas += 100;
    if (columnas >= 600){
        columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto); //Pos inicial de la pantalla
}

QRectF Sprite::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, 100, ancho, alto);
}

