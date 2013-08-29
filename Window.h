#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window();

private:
    QGraphicsScene scene;
    QGraphicsView view;
    QTimer timer;
};

#endif
