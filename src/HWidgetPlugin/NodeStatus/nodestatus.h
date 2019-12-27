#ifndef NODESTATUS_H
#define NODESTATUS_H

#include <QWidget>
class QTableWidget;
class NodeList;
class StructureGraph;
namespace Ui {
class NodeStatus;
}

class NodeStatus : public QWidget
{
    Q_OBJECT
public:
    typedef struct NodeInfo{
        QString name;
        QString status;
        QString errorPart;
        QString errorRank;
        NodeInfo()
        {
            name = "";
            status = "0";//1:error;0:normal
            errorPart = "";
            errorRank = "";
        }
    }NodeInfo;

public:
    explicit NodeStatus(QWidget *parent = 0);
    ~NodeStatus();
    void paintEvent(QPaintEvent *event);
private:
    void populateTableWidget(QTableWidget *tableWidget);

    void init();

    void initNodeInfo();

    void initNodeList();

    void initStructGraph();
private:
    Ui::NodeStatus *ui;

    QTableWidget * m_nodeTable;

    NodeList *nodeList;

    StructureGraph *graph;

    QList<NodeInfo> infoList;
};

#endif // NODESTATUS_H
