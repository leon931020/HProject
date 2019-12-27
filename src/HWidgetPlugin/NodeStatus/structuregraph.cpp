#include "structuregraph.h"
#include "ui_structuregraph.h"
#include"graphwidget.h"
#include"qpainter.h"
#include"qstyleoption.h"
StructureGraph::StructureGraph(QWidget *parent) :
    QWidget(parent),releaseGraph(NULL),subscribleGraph(NULL),
    ui(new Ui::StructureGraph)
{
    ui->setupUi(this);
    init();
    bindSigSlots();
}

StructureGraph::~StructureGraph()
{
    delete ui;
}


void StructureGraph::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
void StructureGraph::init()
{
    initReleaseGraph();
    initSubscribleGraph();
}

void StructureGraph::initReleaseGraph()
{
    if(releaseGraph == NULL)
    {
        releaseGraph = new GraphWidget();

        QHBoxLayout * layout = new QHBoxLayout(ui->releaseGraphWidget);
        layout->setContentsMargins(8,8,8,8);

        layout->addWidget(releaseGraph);

        initArray(5,releaseGraph);
    }
}

void StructureGraph::initSubscribleGraph()
{
    if(subscribleGraph == NULL)
    {
        subscribleGraph  = new GraphWidget();

        QHBoxLayout * layout = new QHBoxLayout(ui->subscribleWidget);
        layout->setContentsMargins(8,8,8,8);

        layout->addWidget(subscribleGraph);

        initArray(5,subscribleGraph);
    }
}

void StructureGraph::initArray(int num, GraphWidget *graph)
{
    if(num<0||graph==NULL)
        return ;
    else
    {
        int** Graph = new int* [num];
        for(int i=0;i<num;i++)
            Graph[i] = new int[num];

        for(int i=0;i<num;i++)
            for(int j=0;j<num;j++)
            {
                if(i==j)
                    Graph[i][j]=0;
                else if(qrand()%2==0)
                {
                    Graph[i][j]=1;
                    Graph[j][i]=1;
                }
                else
                {
                    Graph[i][j]=0;
                    Graph[j][i]=0;

                }
            }


        graph->initGraph(Graph,num);

    }
}
void StructureGraph::bindSigSlots()
{
    connect(HQss::getInstance(),SIGNAL(styleChanged(HQss::Style)),this,SLOT(changeStyle(HQss::Style)));
}

void StructureGraph::changeStyle(HQss::Style style)
{
    releaseGraph->zoomIn();
    releaseGraph->zoomOut();

    subscribleGraph->zoomIn();
    subscribleGraph->zoomOut();

   // releaseGraph->update();
}
