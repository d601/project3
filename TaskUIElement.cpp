#include <QPainter>
#include <QStyleOption>

#include <TaskUIElement.h>

TaskUIElement::taskUIElement()
{ }

QRectF boundingRect() const
{
    // dummy
    return QRectF(0, 0, 16, 16);
}

void TaskUIElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
{
   if (!text)
        drawBlankTask(painter);
}

void TaskUIElement::drawBlankTask(QPainter *painter)
{
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, 16, 16);
}
