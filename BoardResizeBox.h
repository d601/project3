#ifndef BOARDRESIZEBOX_H
#define BOARDRESIZEBOX_H

#include <QGraphicsItem>
#include <QPainter>

class BoardResizeBox : public QGraphicsItem
{
    public:
        BoardResizeBox(QGraphicsItem *parent);
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
