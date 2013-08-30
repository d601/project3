#ifndef BOARDDRAGBOX_H
#define BOARDDRAGBOX_H

#include <QGraphicsItem>
#include <QPainter>

class BoardDragBox : public QGraphicsItem
{
    public:
        BoardDragBox(QGraphicsItem *parent);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        QPointF getCorner() const;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    private:
        int size;
        bool resizing;
        QPointF resizeInitialPosition;
};

#endif
