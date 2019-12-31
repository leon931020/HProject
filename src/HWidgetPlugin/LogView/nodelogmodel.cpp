#include "nodelogmodel.h"

NodeLogModel::NodeLogModel()
{
    init();
}

NodeLogModel::~NodeLogModel()
{

}

void NodeLogModel::addNode(const QString &dirName, const QDateTime &time, const int &size, const int &num)
{
    this->insertRow(0);
    this->setData(this->index(0,0),dirName);
    this->setData(this->index(0,1),time);
    this->setData(this->index(0,2),size);
    this->setData(this->index(0,3),num);

}

void NodeLogModel::init()
{
    //setRowCount(1);
    setColumnCount(4);
    setHead();
}

void NodeLogModel::setHead()
{
    this->setHeaderData(0, Qt::Horizontal, "Folder");
    this->setHeaderData(1, Qt::Horizontal, "Date");
    this->setHeaderData(2, Qt::Horizontal, "Size");
    this->setHeaderData(3, Qt::Horizontal, "FileNums");

}
