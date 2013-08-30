#include "Board.h"
#include "BoardDragBox.h"
#include "BoardTitleBar.h"

#include <QPainter>
#include <QStyleOption>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Board::Board()
    :color(qrand() % 256, qrand() % 256, qrand() % 256),
     width(40),
     height(40),
     minimumWidth(16),
     minimumHeight(16),
     resizeBoxSize(16),
     dragBox(this),
     titleBar(this, "unnamed")
{
    setFlag(ItemIsMovable);
}

QRectF Board::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    // Draw the background box
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);
    painter->drawRect(0, 0, width, height);
    
    // Draw the bounding box
    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(0, 0, width, height);
}

void Board::advance(int step)
{
    // setPos(mapToParent(qrand() % 3 - 1, qrand() % 3 - 1));
}

void Board::startMoving()
{
    moving = true;
}

void Board::stopMoving()
{
    moving = false;
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

void Board::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (moving)
        QGraphicsItem::mousePressEvent(event);
}

void Board::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if (moving) {
        update();
        QGraphicsItem::mouseReleaseEvent(event);
        stopMoving();
    }
}

void Board::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (moving)
        QGraphicsItem::mouseMoveEvent(event);
}
