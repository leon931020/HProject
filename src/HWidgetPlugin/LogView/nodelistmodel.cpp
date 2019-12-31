#include "nodelistmodel.h"

NodeListModel::NodeListModel()
{

}

NodeListModel::~NodeListModel()
{

}

void NodeListModel::addNodel(const QString& parentName, QStandardItem *item)
{
    item->setData(false,IsParent);
    QList<QStandardItem *> parentItems = this->findItems(parentName);
    if (parentItems.size() > 0)
    {
        parentItems.at(0)->appendRow(item);

    }
    else
    {
        QStandardItem *parentNode = new QStandardItem(parentName);
        parentNode->setData(true,IsParent);
        parentNode->setData(true,IsExpanded);
        parentNode->setEditable(false);
        this->appendRow(parentNode);
        parentNode->appendRow(item);

    }


    insert(parentName,item);

}


void NodeListModel::insert(const QString &parentName, QStandardItem *item)
{
    MyItem[parentName].append(item);
}

