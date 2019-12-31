#ifndef NODELOGVIEW_H
#define NODELOGVIEW_H

#include"qtreeview.h"
class NodeLogModel;
class NodeLogView:public QTreeView
{
    Q_OBJECT
public:
    NodeLogView(QWidget *parent=NULL);
    ~NodeLogView();

    void init();

public slots:
    void updateModel(const QModelIndex& index);

private:
    void replaceModel(NodeLogModel *model);
private:
    NodeLogModel * m_model;
};

#endif // NODELOGVIEW_H
