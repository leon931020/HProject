#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class Node;

//! [0]
class Edge : public QGraphicsItem
{
public:
    Edge(Node *sourceNode, Node *destNode);

    Node *sourceNode() const;
    Node *destNode() const;


    //更新sourcePoint和destPoint位置，进而更新边界矩形
    void adjust();


    //Type为Item的类型，默认的type为UserType=65536
    //当自定义Item且需要用到qgraphicsitem_cast(),则需要为自定义的item定义类型，其值必须大于UserType;
    enum { Type = UserType + 2 };
    int type() const Q_DECL_OVERRIDE { return Type; }

protected:

    //item边界矩形
    //sourcePoint与destPoint连线为对角线
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    //绘制自定义item
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    Node *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};
//! [0]

#endif // EDGE_H
