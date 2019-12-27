#ifndef STRUCTUREGRAPH_H
#define STRUCTUREGRAPH_H

#include <QWidget>
#include"hqss.h"
class GraphWidget;
namespace Ui {
class StructureGraph;
}

class StructureGraph : public QWidget
{
    Q_OBJECT

public:
    explicit StructureGraph(QWidget *parent = 0);
    ~StructureGraph();
    void paintEvent(QPaintEvent *event);
private:
    void init();
    void initReleaseGraph();
    void initSubscribleGraph();

    void initArray(int num,GraphWidget *graph);

    void bindSigSlots();
private slots:
    void changeStyle(HQss::Style style);

private:
    Ui::StructureGraph *ui;

    GraphWidget *releaseGraph;
    GraphWidget *subscribleGraph;
};

#endif // STRUCTUREGRAPH_H
