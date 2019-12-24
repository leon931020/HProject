#ifndef NODESTATUS_H
#define NODESTATUS_H

#include <QWidget>

namespace Ui {
class NodeStatus;
}

class NodeStatus : public QWidget
{
    Q_OBJECT

public:
    explicit NodeStatus(QWidget *parent = 0);
    ~NodeStatus();

private:
    Ui::NodeStatus *ui;
};

#endif // NODESTATUS_H
