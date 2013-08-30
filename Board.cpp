#include "Board.h"
#include "BoardDragBox.h"

#include <QPainter>
#include <QStyleOption>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Board::Board()
    :width(40), height(40), resizeBoxSize(16), title("Dummy window"),
     color(qrand() % 256, qrand() % 256, qrand() % 256),
     dragBox(this),
     minimumWidth(16),
     minimumHeight(16)
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

    if (position.y() <= 16) {
        update();
        moving = true;
        QGraphicsItem::mousePressEvent(event);
        return;
    }

    event->ignore();
}

void Board::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if (moving) {
        update();
        QGraphicsItem::mouseReleaseEvent(event);
        moving = false;
    }
}

void Board::resize(int argWidth, int argHeight)
{
    prepareGeometryChange();
      
    width = (argWidth < minimumWidth) ? minimumWidth : argWidth;
    height = (argHeight < minimumHeight) ? minimumHeight : argHeight;

    update();
}

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}

void Board::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (moving)
        QGraphicsItem::mouseMoveEvent(event);
}
