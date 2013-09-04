#ifndef TASKUIELEMENTDELETEBUTTON_H
#define TASKUIELEMENTDELETEBUTTON_H

#include <QGraphicsItem>

class TaskUIElementDeleteButton : public QGraphicsItem
{
    public:
        TaskUIElementDeleteButton(QGraphicsItem *parent);
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
