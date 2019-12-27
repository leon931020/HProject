#include "nodelistview.h"
#include"nodelistmodel.h"
#include"QtAwesome.h"
#include"customfilterproxymodel.h"
NodeListView::NodeListView(QWidget *parent):QTreeView(parent),
    m_model(NULL),proxyModel(NULL)
{
    init();

    intProxyModel();
}

NodeListView::~NodeListView()
{
    if(m_model!=NULL)
    {
        delete m_model;
        m_model = NULL;
    }
}

void NodeListView::init()
{
    if(m_model == NULL)
        m_model = new NodeListModel;

    this->setModel(m_model);

    for(int i=0;i<10;i++)
    {
        QVariantMap options;
        options.insert("color",QColor(Qt::blue));
        options.insert("scale-factor",1.0);


        QIcon icon = QtAwesome::getInstance()->icon(fa::desktop, options);
        QString name = "node_" + QString::number(i);
        QStandardItem *item = new QStandardItem(icon,name);
        item->setEditable(false);

        m_model->addNodel("Domain:0",item);

        item = new QStandardItem(icon,name);
        m_model->addNodel("Domain:1",item);

        //m_model->setError("Domain:0","node_3");
    }

    //去掉工具树状表头.
    this->setHeaderHidden(true);

    //设置全部展开.
    this->expandAll();

}

void NodeListView::intProxyModel()
{
    if(proxyModel == NULL)
    {
        proxyModel = new CustomFilterProxyModel;
        proxyModel->setSourceModel(m_model);
        proxyModel->setFilterRole(Qt::UserRole+1);
        proxyModel->setFilterKeyColumn(0);
       // this->setModel(proxyModel);


    }

}

void NodeListView::filter(const QStringList &parentList, const QRegExp &exp)
{
    proxyModel->setFilterParent(parentList);
    proxyModel->setFilterRegExp(exp);
    this->setModel(proxyModel);
    this->expandAll();
}
