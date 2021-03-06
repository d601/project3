#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItem>
#include <QList>

#include "BoardResizeBox.h"
#include "BoardTitleBar.h"
#include "BoardAddTaskButton.h"
#include "TaskUIElement.h"

class Board : public QGraphicsItem
{
    public:
        Board();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void updateTaskPositions();
        void resize(int argWidth, int argHeight);
        int getWidth();
        int getTaskWidth();
        int getHeight();
        void startMoving();
        void stopMoving();
        void addTask();

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

        BoardResizeBox resizeBox;
        BoardTitleBar titleBar;
        BoardAddTaskButton addTaskButton;

        QList<TaskUIElement *> tasks;        
        int taskSpacing;
        int margin;
};

#endif 
