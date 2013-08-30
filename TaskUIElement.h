#ifndef TASKUIELEMENT_H
#define TASKUIELEMENT_H

#include <QGraphicsItem>

class TaskUIElement : public QGraphicsItem
{
    public:
        taskUIElement();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void drawBlankTask(QPainter *painter);

    private:
        QString text;
}

#endif
