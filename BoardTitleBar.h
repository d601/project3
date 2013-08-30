#ifndef BOARDTITLEBAR_H
#define BOARDTITLEBAR_H

#include <QGraphicsItem>

class BoardTitleBar : public QGraphicsItem
{
    public:
        BoardTitleBar(QGraphicsItem *parent, QString title);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        QString title;
        int height;
};

#endif
