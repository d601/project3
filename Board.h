#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItem>

#include "BoardDragBox.h"

class Board : public QGraphicsItem
{
    public:
        Board();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    protected:
        void advance(int step);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    private:
        QColor color;
        int width;
        int height;
        // TODO: replace these with a state enum
        bool resizing;
        bool moving;

        int resizeBoxSize;
        QPointF resizeInitialPosition;

        QString title;
        BoardDragBox dragBox;
};

#endif 
