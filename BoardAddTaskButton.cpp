#include "BoardAddTaskButton.h"

#include <QGraphicsItem>

BoardAddTaskButton::BoardAddTaskButton(QGraphicsItem *parent)
    :QGraphicsItem(parent),
     size(32)
{

}

QRectF BoardAddTaskButton::boundingRect() const
{
    return QRectF(0, 0, size, size);
}

void BoardAddTaskButton::paint(QPainter *painter,
                               const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, size, size);
}
