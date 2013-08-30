#include "BoardResizeBox.h"
#include "Board.h"

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

BoardResizeBox::BoardResizeBox(QGraphicsItem *parent)
    :QGraphicsItem(parent), size(16)
{
}

QRectF BoardResizeBox::boundingRect() const
{
    return QRectF(getCorner().x(), getCorner().y(), size, size);
}

void BoardResizeBox::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::gray);
    painter->drawRect(getCorner().x(), getCorner().y(), size, size);
}

// Returns the upper left corner of the box with respect to the parent's
// window coordinates
QPointF BoardResizeBox::getCorner() const
{
    Board *parent = (Board *) parentItem();
    int x = parent->getWidth() - size;
    int y = parent->getHeight() - size;
    return QPointF(x, y);
}

void BoardResizeBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Record the mouse position when it clicks on the resize box
    // so we can calculate the delta when it moves
    // Perhaps there is a better way?
    resizeInitialPosition = event->pos();
    resizing = true;
}

void BoardResizeBox::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    resizing = false;
}

void BoardResizeBox::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!resizing)
        return;

    Board *parent = (Board *) parentItem();
    
    QPointF mouseDelta = event->pos() - resizeInitialPosition;

    int width = parent->getWidth() + mouseDelta.x();
    int height = parent->getHeight() + mouseDelta.y();
    parent->resize(width, height);

    resizeInitialPosition = event->pos();
}
