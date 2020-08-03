#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include <QPixmap>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas; //Picture dimensions
    float ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Actualizar();

};

#endif // SPRITE_H
