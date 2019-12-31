#include "hlinkstatusui.h"
#include "ui_hlinkstatusui.h"
#include"graphwidget.h"
#include "QHBoxLayout"
#include"qstyleoption.h"
#include"qpainter.h"
#include"rightpanelwidget.h"
#include"qpushbutton.h"
#include"QtAwesome.h"
HLinkStatusUi::HLinkStatusUi(QWidget *parent) :
    QWidget(parent),m_graphWidget(NULL),m_rightWidget(NULL),
    ui(new Ui::HLinkStatusUi)
{
    ui->setupUi(this);
    init();
    bindSigSlots();
}

HLinkStatusUi::~HLinkStatusUi()
{
    delete ui;
}

void HLinkStatusUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
void HLinkStatusUi::init()
{

    initLeftWidget();
    initRightWidget();

}

void HLinkStatusUi::initLeftWidget()
{
    if(m_graphWidget == NULL)
    {
        m_graphWidget = new GraphWidget();

        QHBoxLayout * layout = new QHBoxLayout(ui->leftWidget);
        layout->setContentsMargins(0,0,0,0);

        layout->addWidget(m_graphWidget);

        initArray(15);
    }
}

void HLinkStatusUi::initRightWidget()
{
    if(m_rightWidget == NULL)
    {
        m_rightWidget = new RightPanelWidget();
        //m_rightWidget->setFrame(0,"#ffffff");
        //m_rightWidget->setBorder(0,"#ffffff");
        QHBoxLayout * layout = new QHBoxLayout(ui->rightWidget);
        layout->setContentsMargins(0,0,0,0);

        layout->addWidget(m_rightWidget);

        initList();

    }
}

void HLinkStatusUi::initArray(int num)
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

void HLinkStatusUi::initList()
{
   if(!m_rightWidget)
       return ;

    QList<QWidget *> widgets1;

    for (int i = 1; i <= 20; i++) {
        QPushButton *btn = new QPushButton();
        btn->setText("DDS Node");
        btn->setFixedHeight(100);
       // btn->setFixedWidth(100);
        btn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        QVariantMap options;
        options.insert("color",QColor("#1ABC9C"));
        //scale-factor
        options.insert("scale-factor",1.0);
        //btn->setFont(awesome->font(50));
        btn->setIcon(QtAwesome::getInstance()->icon( fa::desktop, options  ) );


        widgets1.append(btn);
    }

    m_rightWidget->setWidget(widgets1, 3);

}

void HLinkStatusUi::bindSigSlots()
{
    connect(HQss::getInstance(),SIGNAL(styleChanged(HQss::Style)),this,SLOT(changeStyle(HQss::Style)));
}

void HLinkStatusUi::changeStyle(HQss::Style style)
{
    m_graphWidget->zoomIn();
    m_graphWidget->zoomOut();
}
