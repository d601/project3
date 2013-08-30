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

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    private:
        int size;
};

#endif
