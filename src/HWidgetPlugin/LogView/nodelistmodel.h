#ifndef NODELISTMODEL_H
#define NODELISTMODEL_H

#include"QStandardItemModel"
class NodeListModel:public QStandardItemModel
{
    Q_OBJECT

public:
    enum{IsParent = Qt::UserRole+1,\
         IsExpanded = Qt::UserRole+2
        };
public:
    NodeListModel();
    ~NodeListModel();

    void addNodel(const QString& parentName,QStandardItem *item);

private:

    void insert(const QString& parentName,QStandardItem *item);
private:
    QMap<QString, QList<QStandardItem*> > MyItem;
};

#endif // NODELISTMODEL_H
