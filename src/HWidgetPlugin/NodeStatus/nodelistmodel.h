#ifndef NODELISTMODEL_H
#define NODELISTMODEL_H

#include"QStandardItemModel"
class NodeListModel:public QStandardItemModel
{
    Q_OBJECT
public:
    NodeListModel();
    ~NodeListModel();

    void addNodel(const QString& parentName,QStandardItem *item);

    void setError(const QString& parentName,const QString&nodeName);
private:
    void insert(const QString& parentName,QStandardItem *item);
private:
    QMap<QString, QList<QStandardItem*> > MyItem;
};

#endif // NODELISTMODEL_H
