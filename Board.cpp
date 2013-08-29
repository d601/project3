#include "Board.h"
#include "BoardDragBox.h"

#include <QPainter>
#include <QStyleOption>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Board::Board()
    :width(40), height(40), resizeBoxSize(16), title("Dummy window"),
     color(qrand() % 256, qrand() % 256, qrand() % 256),
     dragBox(this)
{
}

QRectF Board::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    setFlag(ItemIsMovable);

    // Draw the background box
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);
    painter->drawRect(0, 0, width, height);

    // Draw the title bar
    painter->setBrush(Qt::gray);
    painter->drawRect(0, 0, width, 16);
    painter->setPen(Qt::black);
    painter->drawText(0, 0, width, 16, Qt::AlignCenter, title);
    
    // Draw the bounding box
    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(0, 0, width, height);
}

void Board::advance(int step)
{
    // setPos(mapToParent(qrand() % 3 - 1, qrand() % 3 - 1));
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QPointF position = event->pos();
    // Clicked resize box
    /*
    if ((position.x() >= width - resizeBoxSize) && (position.x() <= width)
        && (position.y() >= height - resizeBoxSize) && (position.y() <= height)) {
        resizeInitialPosition = event->pos();
        resizing = true;
    }
    */

    // Clicked title bar -> drag the window
    if (position.y() <= 16) {
        update();
        moving = true;
        QGraphicsItem::mousePressEvent(event);
    }
}

void Board::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    // resizing = false;

    if (moving) {
        update();
        QGraphicsItem::mouseReleaseEvent(event);
        moving = false;
    }
}

void Board::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    /*
    if (resizing) {
        prepareGeometryChange();

        QPointF d = event->pos() - resizeInitialPosition;

        width += d.x();
        if (width < resizeBoxSize)
            width = resizeBoxSize;
        height += d.y();
        if (height < resizeBoxSize)
            height = resizeBoxSize;

        resizeInitialPosition = event->pos();

        update();
    }
    */

    if (moving)
        QGraphicsItem::mouseMoveEvent(event);
}
