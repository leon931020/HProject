#include "nodelistview.h"
#include"nodelistmodel.h"
#include"itemdelegate.h"
NodeListView::NodeListView(QWidget *parent):QTreeView(parent),
    m_model(NULL),m_delegate(NULL)
{
    init();

    bindSigSlots();

}

NodeListView::~NodeListView()
{
    if(m_model!=NULL)
    {
        delete m_model;
        m_model = NULL;
    }
}

void NodeListView::onDoubleClicked(const QModelIndex &index)
{
    if(index.data(NodeListModel::IsParent).toBool())
    {
        QStandardItem * item = m_model->item(index.row(),index.column());
        bool data = !(index.data(NodeListModel::IsExpanded).toBool());
        item->setData(data,NodeListModel::IsExpanded);
    }


}

void NodeListView::onClickIndex(const QModelIndex &index)
{
    if(index.data(NodeListModel::IsParent).toBool())
    {
        return;
    }
    else
    {
        emit listViewClicked(index);
    }
}

void NodeListView::init()
{
    if(m_model == NULL)
        m_model = new NodeListModel;

    if(m_delegate==NULL)
        m_delegate = new ItemDelegate(this);

    this->setModel(m_model);
    this->setItemDelegate(m_delegate);
    this->setRootIsDecorated(false);
    this->setIndentation(0);


    for(int i=0;i<10;i++)
    {

        QString name = "node_" + QString::number(i);
        QStandardItem *item = new QStandardItem(name);
        item->setEditable(false);

        m_model->addNodel("Domain:0",item);

        item = new QStandardItem(name);
        m_model->addNodel("Domain:1",item);

    }

    //去掉工具树状表头.
    this->setHeaderHidden(true);

    this->setAnimated(true);
    //设置全部展开.
    this->expandAll();

}

void NodeListView::bindSigSlots()
{
    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onDoubleClicked(QModelIndex)));
    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(onClickIndex(QModelIndex)));
}


