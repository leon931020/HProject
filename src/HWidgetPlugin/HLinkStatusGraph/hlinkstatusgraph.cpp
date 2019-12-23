#include "hlinkstatusgraph.h"
#include"graphwidget.h"
#include "QHBoxLayout"
#include"qstyleoption.h"
#include"qpainter.h"
HLinkStatusGraph::HLinkStatusGraph(QWidget *parent) :
    QWidget(parent),m_graphWidget(NULL)
{
    init();
}
void HLinkStatusGraph::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
void HLinkStatusGraph::init()
{
    if(m_graphWidget == NULL)
    {
        m_graphWidget = new GraphWidget(this);

        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(m_graphWidget);

        initArray(15);
    }
}

void HLinkStatusGraph::initArray(int num)
{
    if(num<0)
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


        m_graphWidget->initGraph(Graph,num);
    }
}
