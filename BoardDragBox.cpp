#include "BoardDragBox.h"
#include "Board.h"

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

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

void BoardDragBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Record the mouse position when it clicks on the resize box
    // so we can calculate the delta when it moves
    // Perhaps there is a better way?
    resizeInitialPosition = event->pos();
    resizing = true;
    qDebug("pressed");
}

void BoardDragBox::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    resizing = false;
    qDebug("released");
}

void BoardDragBox::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!resizing)
        return;

    qDebug("moved");

    QGraphicsItem *parent = parentItem();
    
    QPointF mouseDelta = event->pos() - resizeInitialPosition;

    int width = (parent->boundingRect()).width() + mouseDelta.x();
    int height = (parent->boundingRect()).height() + mouseDelta.y();
    ((Board *) parent)->resize(width, height);

    resizeInitialPosition = event->pos();
}
