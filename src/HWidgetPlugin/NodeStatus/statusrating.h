#ifndef STATUSRATING_H
#define STATUSRATING_H
#include <QMetaType>
class QPainter;
class QRect;
class QPalette;

class StatusRating
{
public:
    enum Status{
        Normal = 0,
        Downtime =1
    };

public:
    explicit StatusRating(Status status = Normal);
    void paint(QPainter *painter, const QRect &rect,
               const QPalette &palette, Status mode) const;

private:
    Status m_status;
};

Q_DECLARE_METATYPE(StatusRating)

#endif // STATUSRATING_H
