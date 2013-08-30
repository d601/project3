#ifndef BOARDADDTASKBUTTON_H
#define BOARDADDTASKBUTTON_H

#include <QGraphicsItem>
#include <QPainter>

class BoardAddTaskButton : public QGraphicsItem
{
    public:
        BoardAddTaskButton(QGraphicsItem *parent);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        int size;
};

#endif
