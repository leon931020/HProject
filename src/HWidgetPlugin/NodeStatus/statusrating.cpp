#include "statusrating.h"
#include"QtAwesome.h"
#include"qpainter.h"
#include"qrect.h"
#include"qpalette.h"
StatusRating::StatusRating(Status status ) :
    m_status(status)
{

}

void StatusRating::paint(QPainter *painter, const QRect &rect, const QPalette &palette, Status mode) const
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QColor("#084871"));

    painter->setFont(QtAwesome::getInstance()->font(20));
    QRect newRect = rect;
    newRect.adjust(5,5,-5,-5);
    if(m_status == Normal)
    {
        painter->drawText(newRect,QChar( fa::smileo));
    }
    else
    {
        painter->drawText(newRect,QChar( fa::frowno));
    }


    painter->restore();
}

