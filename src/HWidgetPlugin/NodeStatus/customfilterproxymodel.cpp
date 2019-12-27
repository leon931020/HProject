#include "customfilterproxymodel.h"
#include"qdebug.h"
CustomFilterProxyModel::CustomFilterProxyModel(QObject *parent):QSortFilterProxyModel(parent)
{
    //invalidateFilter();
}

//all nodes will apply this function;
//Because the parent node does not meet the conditions(return false),
//  the child nodes that meet the conditions will not be displayed(the defaut implement)
//so we should have parent nodes with the child nodes that meet the conditions return true;
bool CustomFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{

    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);

        if (!index.isValid())
            return false;

        if (index.data(Qt::UserRole+1).toString().contains(filterRegExp()))
            return true;

        int rows = sourceModel()->rowCount(index);
        for (int row = 0; row < rows; row++)
        {
            if (filterAcceptsRow(row, index))
            {
                return true;
                break ;
            }
        }

        return false;




}

void CustomFilterProxyModel::setFilterParent(const QStringList &list)
{
    this->needFilterParent = list;
    //invalidateFilter();
}
