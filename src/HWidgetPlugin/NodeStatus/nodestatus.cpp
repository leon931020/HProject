#include "nodestatus.h"
#include "ui_nodestatus.h"
#include "stardelegate.h"
#include "stareditor.h"
#include "starrating.h"
#include"QTableWidgetItem"
#include"QHBoxLayout"
#include"statusrating.h"
#include"nodelist.h"
#include"structuregraph.h"
#include"qpainter.h"
#include"QStyleOption"
NodeStatus::NodeStatus(QWidget *parent) :
    QWidget(parent),m_nodeTable(NULL),nodeList(NULL),graph(NULL),
    ui(new Ui::NodeStatus)
{
    ui->setupUi(this);
    init();


}

NodeStatus::~NodeStatus()
{
    delete ui;
}

void NodeStatus::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void NodeStatus::init()
{
    initNodeInfo();
    initNodeList();
    initStructGraph();

}

void NodeStatus::initNodeInfo()
{
    if(m_nodeTable == NULL)
        m_nodeTable = new QTableWidget(4,4);

    m_nodeTable->setItemDelegate(new StarDelegate);
    m_nodeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_nodeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_nodeTable->horizontalHeader()->setStretchLastSection(true);

    QStringList headerLabels;
    headerLabels << "Name" << "Status" << "ErrorPart" << "ErrorRank";
    m_nodeTable->setHorizontalHeaderLabels(headerLabels);

    populateTableWidget(m_nodeTable);

    m_nodeTable->resizeColumnsToContents();

    QHBoxLayout *layout = new QHBoxLayout(ui->nodeInfoWidget);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_nodeTable);

}

void NodeStatus::initNodeList()
{
    if(nodeList == NULL)
    {
        nodeList = new NodeList;
        QHBoxLayout *layout = new QHBoxLayout(ui->nodeListWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(nodeList);

        ui->nodeListWidget->setProperty("form",true);
    }
}

void NodeStatus::initStructGraph()
{
    if(graph == NULL)
    {
        graph = new StructureGraph;
        QHBoxLayout *layout = new QHBoxLayout(ui->structureGraphWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(graph);
    }
}
void NodeStatus:: populateTableWidget(QTableWidget *tableWidget)
{

    infoList.clear();
    for(int i=0;i<4;i++)
    {
        NodeInfo info;
        info.name = "Component" + QString::number(i);
        if(i%2!=0)
        {
            info.status = "1";
            info.errorPart="ReleaseSide";
            info.errorRank=QString::number(i);
        }
        infoList.append(info);
    }

    for (int row = 0; row<infoList.size(); ++row)
    {
        NodeInfo info = infoList.at(row);
        QTableWidgetItem *item0 = new QTableWidgetItem(info.name);
        QTableWidgetItem *item1 = new QTableWidgetItem;
        QTableWidgetItem *item2 = new QTableWidgetItem(info.errorPart);
        QTableWidgetItem *item3 = new QTableWidgetItem;
        StatusRating::Status s = StatusRating::Normal;
        if(info.status == "1")
        {
            s = StatusRating::Downtime;
        }
        item1->setData(0,QVariant::fromValue(StatusRating(s)));
        item3->setData(0,QVariant::fromValue(StarRating(info.errorRank.toInt())));

        tableWidget->setItem(row, 0, item0);
        tableWidget->setItem(row, 1, item1);
        tableWidget->setItem(row, 2, item2);
        tableWidget->setItem(row, 3, item3);

//        tableWidget->setStyleSheet("QHeaderView::vertical\
//        { \
//        background-color: #02172b;\
//        color: rgb(255, 255, 255);\
//        }");
    }
}
