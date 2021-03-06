#include <QPainter>
#include <QStyleOption>
#include <QFontMetrics>

#include "TaskUIElement.h"
#include "TaskUIElementDeleteButton.h"
#include "Board.h"

TaskUIElement::TaskUIElement(QGraphicsItem *parent)
    :QGraphicsItem(parent),
     text("some really long text that will cause some text-wrapping"),
     font("Helvetica", 12),
     minimumHeight(32),
     deleteButton(this)
{ }

QRectF TaskUIElement::boundingRect() const
{
    Board *parent = (Board *) parentItem(); 

    QFontMetrics fontMetrics = QFontMetrics(font);
    QRect rect = fontMetrics.boundingRect(0,
                                          0,
                                          parent->getTaskWidth(),
                                          minimumHeight,
                                          Qt::TextWordWrap,
                                          text);
    
    return (QRectF) rect;
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
