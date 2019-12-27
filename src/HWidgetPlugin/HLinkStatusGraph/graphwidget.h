
#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>

class Node;
class Edge;

//! [0]
class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = 0);

    void itemMoved();

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
#endif
    //void drawBackground(QPainter *painter, const QRectF &rect) Q_DECL_OVERRIDE;

    void scaleView(qreal scaleFactor);

public :
    void initGraph(int **a,int num);
    void initPointsList();
    //void setPos(QVector<int> *degreeVec,QVector<Node*> *nodesVec);
    static int compare(const void *a,const void *b);
private:
    QList<QPoint> pointsList;



private:
    int timerId;
    Node *centerNode;

    QVector<Node*> nodesVec;

    QVector<Edge*> edgesVec;

    QVector<int> degreeVec;
};
//! [0]

#endif // GRAPHWIDGET_H
