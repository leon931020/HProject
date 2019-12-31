#ifndef NODELISTVIEW_H
#define NODELISTVIEW_H

#include"qtreeview.h"
class NodeListModel;
class ItemDelegate;
class NodeListView:public QTreeView
{
    Q_OBJECT

public:
    NodeListView(QWidget *parent =NULL);
    ~NodeListView();
private slots:
    void onDoubleClicked(const QModelIndex &index);

    void onClickIndex(const QModelIndex&index);

signals:
    void listViewClicked(const QModelIndex& index);
private:
    void init();

    void bindSigSlots();

private:
    NodeListModel *m_model;
    ItemDelegate *m_delegate;




};

#endif // NODELISTVIEW_H
