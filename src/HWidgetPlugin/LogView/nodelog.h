#ifndef NODELOG_H
#define NODELOG_H

#include <QWidget>

namespace Ui {
class NodeLog;
}

class NodeLog : public QWidget
{
    Q_OBJECT

public:
    explicit NodeLog(QWidget *parent = 0);
    ~NodeLog();

private:
    Ui::NodeLog *ui;
};

#endif // NODELOG_H
