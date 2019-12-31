#ifndef NODELOGMODEL_H
#define NODELOGMODEL_H
#include"qstandarditemmodel.h"
#include"qdatetime.h"
class NodeLogModel:public QStandardItemModel
{
    Q_OBJECT
public:
    NodeLogModel();
    ~NodeLogModel();

    void addNode(const QString& dirName="folder",const QDateTime& time =QDateTime(QDate(1997, 12, 31)),const int& size=0,const int& num=0);

private:
    void init();

    void setHead();
};

#endif // NODELOGMODEL_H
