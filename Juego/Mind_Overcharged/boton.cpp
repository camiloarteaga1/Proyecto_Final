#include "boton.h"
#include "platform.h"
#include "mainwindow.h"

#include <QPen>

#define ESCALA 10

extern MainWindow *game;

Boton::Boton(float x, float y, short Rot, QGraphicsItem *parent){

    setPixmap(QPixmap(":/Images/Boton.png"));
    setPos(qreal(x), qreal(y));
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    setRotation(Rot);

    QVector<QPointF> Points;
    Points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) <<
              QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    for(int i = 0; i < Points.size(); i++)
        Points[i] *= ESCALA;

    QPolygonF Range(Points);

    DetectArea = new QGraphicsPolygonItem(Range, this);
    DetectArea->setPen(QPen(Qt::DashDotDotLine));

    QPointF AreaCenter(1.5, 1.5);
    AreaCenter *= ESCALA;
    AreaCenter = mapToScene(AreaCenter);
    QPointF BotonCenter(this->x() + (pixmap().width() / 2), this->y() + (pixmap().height() / 2));
    QLineF Line(AreaCenter, BotonCenter);
    DetectArea->setPos(this->x() + Line.dx(), this->y() + Line.dy());

}

bool Boton::getStatus(){return Status;}

void Boton::Interactions(){

    QList<QGraphicsItem *> CollidingItems = DetectArea->collidingItems();

    if(CollidingItems.size() == 1)
        return;

    for(int i = 0; CollidingItems.size() > i; i++){

        if(typeid(CollidingItems[i]) == typeid(Player)){

            /// Cool stuff...
            short PlayerID = dynamic_cast<Player *>(CollidingItems[i])->getID();
            if(dynamic_cast<Player *>(CollidingItems[i])->getKeyPress() == game->PlayerKeys.at(PlayerID).at(5))
                /// Crear getter para teclas de usuarios
                setStatus(!getStatus());
        }
    }
}

void Boton::setStatus(bool s){Status = s;}

