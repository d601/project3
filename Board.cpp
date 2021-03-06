#include "Board.h"
#include "BoardResizeBox.h"
#include "BoardTitleBar.h"
#include "BoardAddTaskButton.h"
#include "TaskUIElement.h"

#include <QPainter>
#include <QStyleOption>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Board::Board()
    :color(60, 100, 240),
     width(200),
     height(200),
     minimumWidth(16),
     minimumHeight(16),
     resizeBoxSize(16),
     resizeBox(this),
     titleBar(this, "unnamed"),
     addTaskButton(this),
     taskSpacing(16),
     margin(8)
{
    setFlag(ItemIsMovable);

    tasks.append(new TaskUIElement(this));
    tasks.append(new TaskUIElement(this));
    tasks.append(new TaskUIElement(this));

    updateTaskPositions();
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

// This must be called every time a TaskUIElement changes geometry
// there's probably a way to get this called automatically!
// If it can be called automatically, the calling TUIE should skip
// the preceding items.
void Board::updateTaskPositions()
{
    int painterPositionY = titleBar.getHeight() + margin;

    QList<TaskUIElement *>::iterator i;
    for (i = tasks.begin(); i != tasks.end(); i++) {
        (* i)->setPos(margin, painterPositionY);
        painterPositionY += (* i)->boundingRect().height();
        // if (i != tasks.end())
            painterPositionY += taskSpacing;
    }

    addTaskButton.setPos(margin, painterPositionY);
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

    updateTaskPositions();

    update();
}

int Board::getWidth()
{
    return width;
}

// Returns the the width in terms of how far tasks can draw themselves
int Board::getTaskWidth()
{
    return width - margin;
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

void Board::addTask()
{
    tasks.append(new TaskUIElement(this));
    updateTaskPositions();
}
