#include <QWidget>
#include <cmath>
#include"qpainter.h"

#include "starrating.h"
#include"QtAwesome.h"
const int PaintingScaleFactor = 10;

//! [0]
StarRating::StarRating(int starCount, int maxStarCount)
{
    myStarCount = starCount;
    myMaxStarCount = maxStarCount;


}
//! [0]

//! [1]
QSize StarRating::sizeHint() const
{
    return PaintingScaleFactor * QSize(myMaxStarCount, 1);
}



void StarRating::paint(QPainter *painter, const QRect &rect,
                       const QPalette &palette, EditMode mode) const
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QColor("#084871"));

    painter->setFont(QtAwesome::getInstance()->font(20));
    QRect newRect = rect;
    newRect.adjust(5,5,-5,-5);
    for (int i = 0; i < myStarCount; ++i) {
        if (i < myStarCount)
        {
            painter->drawText(newRect,QChar( fa::flash));

        }
        painter->translate(20, 0.0);
    }


    painter->restore();
}
//! [2]
