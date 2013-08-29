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

    private:
        int size;
};

#endif
