#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItem>

#include "BoardDragBox.h"
#include "BoardTitleBar.h"

class Board : public QGraphicsItem
{
    public:
        Board();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void resize(int argWidth, int argHeight);
        int getWidth();
        int getHeight();
        void startMoving();
        void stopMoving();

    protected:
        void advance(int step);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    private:
        QColor color;
        int width;
        int height;
        int minimumWidth;
        int minimumHeight;

        bool moving;

        int resizeBoxSize;
        QPointF resizeInitialPosition;

        BoardDragBox dragBox;
        BoardTitleBar titleBar;
};

#endif 
