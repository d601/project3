#ifndef TASKUIELEMENT_H
#define TASKUIELEMENT_H

#include <QGraphicsItem>

#include "TaskUIElementDeleteButton.h"

class TaskUIElement : public QGraphicsItem
{
    public:
        TaskUIElement(QGraphicsItem *parent);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void drawBlankTask(QPainter *painter);

    private:
        QString text;
        QFont font;
        int minimumHeight;
        TaskUIElementDeleteButton deleteButton;
};

#endif
