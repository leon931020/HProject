#ifndef NODELISTVIEW_H
#define NODELISTVIEW_H

#include"qtreeview.h"
class NodeListModel;
class CustomFilterProxyModel ;
class NodeListView:public QTreeView
{
    Q_OBJECT
public:
    NodeListView(QWidget *parent =NULL);
    ~NodeListView();

     void filter(const QStringList& parentList,const QRegExp& exp);
private:
    void init();

    void intProxyModel();

private:
    NodeListModel *m_model;

    CustomFilterProxyModel *proxyModel;


};



#endif // NODELISTVIEW_H
