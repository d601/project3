#include "TaskUIElementDeleteButton.h"

#include <QGraphicsItem>
#include <QPainter>

TaskUIElementDeleteButton::TaskUIElementDeleteButton(QGraphicsItem *parent)
    :QGraphicsItem(parent),
     size(8)
{

}

QRectF TaskUIElementDeleteButton::boundingRect() const
{
    return QRectF(0, 0, size, size);
}

void TaskUIElementDeleteButton::paint(QPainter *painter,
                                 const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, size, size);
}

void TaskUIElementDeleteButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void TaskUIElementDeleteButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
