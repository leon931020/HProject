#include "nodelistmodel.h"
#include"qdebug.h"
NodeListModel::NodeListModel()
{
    MyItem.clear();
}

NodeListModel::~NodeListModel()
{

}

void NodeListModel::addNodel(const QString& parentName, QStandardItem *item)
{
    item->setData(parentName+"_"+item->text(),Qt::UserRole+1);
    QList<QStandardItem *> parentItems = this->findItems(parentName);
    if (parentItems.size() > 0)
    {
        parentItems.at(0)->appendRow(item);

    }
    else
    {
        QStandardItem *parentNode = new QStandardItem(parentName);
        parentNode->setEditable(false);
        this->appendRow(parentNode);
        parentNode->appendRow(item);

    }


    insert(parentName,item);

}

void NodeListModel::setError(const QString &parentName, const QString &nodeName)
{
    if(MyItem.size()==0)
        return;
    QList<QStandardItem *> itemList = MyItem.value(parentName);
    foreach(QStandardItem *item,itemList)
    {
        if(item->text()==nodeName)
        {
            item->setBackground(QColor(255,50,0));
        }
    }

}

void NodeListModel::insert(const QString &parentName, QStandardItem *item)
{
    MyItem[parentName].append(item);
}
