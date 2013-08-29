#include "BoardDragBox.h"

#include <QGraphicsItem>

BoardDragBox::BoardDragBox(QGraphicsItem *parent)
    :QGraphicsItem(parent), size(16)
{
}

QRectF BoardDragBox::boundingRect() const
{
    return QRectF(getCorner().x(), getCorner().y(), size, size);
}

void BoardDragBox::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::gray);
    painter->drawRect(getCorner().x(), getCorner().y(), size, size);
}

// Returns the upper left corner of the box with respect to the parent's
// window coordinates
QPointF BoardDragBox::getCorner() const
{
    QGraphicsItem *parent = parentItem();
    int x = (parent->boundingRect()).width() - size;
    int y = (parent->boundingRect()).height() - size;
    return QPointF(x, y);
}
