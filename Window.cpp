#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QObject>

#include "Window.h"
#include "Board.h"

#include <stdio.h>

Window::Window()
{
    setWindowTitle(tr("A crappy program"));
    
    scene.setSceneRect(0, 0, 200, 200);

    //scene.addText("Hello world!");
    Board *board = new Board;
    board->setPos(0, 0);
    scene.addItem(board);

    view.setScene(&scene);
    // view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.show();

    this->setCentralWidget(&view);
    
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

}
