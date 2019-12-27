#include "nodelist.h"
#include "ui_nodelist.h"
#include"nodelistview.h"
#include"QHBoxLayout"
#include"qpainter.h"
#include"qstyleoption.h"
NodeList::NodeList(QWidget *parent) :
    QWidget(parent),listView(NULL),
    ui(new Ui::NodeList)
{
    ui->setupUi(this);
    init();
}

NodeList::~NodeList()
{
    delete ui;
}
void NodeList::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
void NodeList::init()
{
    if(listView == NULL)
    {
        listView = new NodeListView(this);
        QHBoxLayout *layout = new QHBoxLayout(ui->listViewWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(listView);

    }
}

void NodeList::on_normalBtn_clicked()
{
    QStringList list;
    list<<"Domain:0"<<"Domain:1";

    QRegExp regExp("Domain:0_node_1|node_2", Qt::CaseInsensitive, QRegExp::RegExp);

    listView->filter(list,regExp);

}

void NodeList::on_errorBtn_clicked()
{
    QStringList list;
    list<<"Domain:0"<<"Domain:1";

    QRegExp regExp("Domain:1_node_3", Qt::CaseInsensitive, QRegExp::RegExp);

    listView->filter(list,regExp);
}

void NodeList::on_allBtn_clicked()
{
    QStringList list;
    list<<"Domain:0"<<"Domain:1";

    QRegExp regExp("[\s\S]*", Qt::CaseInsensitive, QRegExp::RegExp);

    listView->filter(list,regExp);
}
