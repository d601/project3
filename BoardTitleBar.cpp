#include "BoardTitleBar.h"
#include "Board.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

BoardTitleBar::BoardTitleBar(QGraphicsItem *parent, QString title)
    :QGraphicsItem(parent),
     title(title),
     height(16)
{

}

QRectF BoardTitleBar::boundingRect() const
{
    Board *parent = (Board *) parentItem();
    return QRectF(0, 0, parent->getWidth(), height);
}

void BoardTitleBar::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    Board *parent = (Board *) parentItem();
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::gray);
    painter->drawRect(0, 0, parent->getWidth(), height);
    painter->setPen(Qt::black);
    painter->drawText(0, 0, parent->getWidth(), height, Qt::AlignCenter, title);
}

void BoardTitleBar::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    ((Board *) parentItem())->startMoving();
    event->ignore();
}
