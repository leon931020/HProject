#ifndef HLINKSTATUSGRAPH_H
#define HLINKSTATUSGRAPH_H

#include <QWidget>
class GraphWidget;
class HLinkStatusGraph : public QWidget
{
    Q_OBJECT

public:
    HLinkStatusGraph(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
private:
    void init();
    void initArray(int num);
private:
    GraphWidget *m_graphWidget;
};

#endif
