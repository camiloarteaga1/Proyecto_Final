#include "vidas.h"
#include <QFont>

Vidas::Vidas(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar score en 0
    vidas = 0;

    //draw the text
    setPlainText(QString("")+QString::number(vidas));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

    /*//Image for counter
    m_countLogo = new BackgroundItem(QPixmap(":images/count"));       //Lo que está comentado es lo que se agrega a la escena, no va en esta clase
    m_countLogo->setPos(30, m_groundLevel -652 );
    addItem(m_countLogo)

    //Add coin counter
    m_count = new Vidas();
    m_count->setPos(65, m_groundLevel - m_count->boundingRect().height()-602);
    addItem(m_count);*/
}

void Vidas::increase()
{
    vidas++; //Increase the numeber of lifes to show later with the setPlainText
    setPlainText(QString("Vidas: ")+QString::number(vidas));
}

int Vidas::getVidas()
{
    return vidas; //Returns the number of lifes
}
