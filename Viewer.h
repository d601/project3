#ifndef VIEWER_H
#define VIEWER_H

class Viewer : public QGraphicsView
{
    protected:
        void mousePressEvent(QMouseEvent *event);
}
