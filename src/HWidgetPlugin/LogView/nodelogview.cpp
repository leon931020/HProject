#include "nodelogview.h"
#include"nodelogmodel.h"
NodeLogView::NodeLogView(QWidget *parent):QTreeView(parent),m_model(NULL)
{
    init();
}

NodeLogView::~NodeLogView()
{

}

void NodeLogView::init()
{
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);

    if(m_model==NULL)
    {
        m_model = new NodeLogModel();
        this->setModel(m_model);
        for(int i=0;i<10;i++)
        {
            m_model->addNode();
        }
    }
}

void NodeLogView::updateModel(const QModelIndex &index)
{
    QString name = index.data(Qt::DisplayRole).toString();
    int last = name.right(1).toInt();

    NodeLogModel *model = new NodeLogModel;
    this->setModel(model);

    for(int i=0;i<last;i++)
    {
        model->addNode();
    }

    replaceModel(model);


}

void NodeLogView::replaceModel(NodeLogModel *model)
{
    if(model==NULL)
        return ;

    if(m_model!=NULL)
    {
        delete m_model;
        m_model = NULL;
    }
    else
    {
        m_model = model;
    }
}


