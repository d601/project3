#include <QPainter>
#include <QStyleOption>
#include <QFontMetrics>

#include "TaskUIElement.h"
#include "Board.h"

TaskUIElement::TaskUIElement(QGraphicsItem *parent)
    :QGraphicsItem(parent),
     text("blank"),
     font("Helvetica", 12),
     minimumHeight(32)
{ }

QRectF TaskUIElement::boundingRect() const
{
    Board *parent = (Board *) parentItem(); 

    QFontMetrics fontMetrics = QFontMetrics(font);
    boundingRect = fontMetrics.boundingRect(0,
                                            0,
                                            parent->getTaskWidth(),
                                            minimumHeight,
                                            Qt::TextWordWrap,
                                            text);
    
    return (QRectF) boundingRect;
}

void TaskUIElement::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
   if (text == "")
        drawBlankTask(painter);

    Board *parent = (Board *) parentItem(); 

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::black);
    painter->setFont(font);
    painter->drawText(boundingRect(), Qt::TextWordWrap, text);
}

void TaskUIElement::drawBlankTask(QPainter *painter)
{
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, 32, 32);
}
