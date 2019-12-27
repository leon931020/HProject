#ifndef CUSTOMFILTERPROXYMODEL_H
#define CUSTOMFILTERPROXYMODEL_H

#include"QSortFilterProxyModel"
class CustomFilterProxyModel:public QSortFilterProxyModel

{
    Q_OBJECT
public:
    CustomFilterProxyModel(QObject *parent =NULL);

    bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;

    void setFilterParent(const QStringList &list);
private:
    QStringList needFilterParent;
};

#endif // CUSTOMFILTERPROXYMODEL_H
