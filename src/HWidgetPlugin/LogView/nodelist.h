#ifndef NODELIST_H
#define NODELIST_H

#include <QWidget>

namespace Ui {
class NodeList;
}

class NodeList : public QWidget
{
    Q_OBJECT

public:
    explicit NodeList(QWidget *parent = 0);
    ~NodeList();

private:
    Ui::NodeList *ui;
};

#endif // NODELIST_H
