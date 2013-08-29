#include <QPainter>
#include <QStyleOption>

#include <TaskUIElement.h>

taskeUIElement::taskUIElement()
{ }

QRectF boundingRect() const
{
    // dummy
    return QRectF(0, 0, 16, 16);
}

void taskeUIElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
{
   if (!text)
        drawBlankTask(painter);
}

void drawBlankTask(QPainter *painter)
{
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, 16, 16);
}
