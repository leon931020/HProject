#ifndef NODESTATUS_H
#define NODESTATUS_H

#include <QWidget>
class QTableWidget;
class NodeList;
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
private:
    void populateTableWidget(QTableWidget *tableWidget);

    void init();

    void initNodeInfo();

    void initNodeList();
private:
    Ui::NodeStatus *ui;

    QTableWidget * m_nodeTable;

    NodeList *nodeList;

    QList<NodeInfo> infoList;
};

#endif // NODESTATUS_H
