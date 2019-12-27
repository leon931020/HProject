#ifndef NODELIST_H
#define NODELIST_H

#include <QWidget>
class NodeListView;
namespace Ui {
class NodeList;
}

class NodeList : public QWidget
{
    Q_OBJECT

public:
    explicit NodeList(QWidget *parent = 0);
    ~NodeList();
private slots:
    void on_normalBtn_clicked();

    void on_errorBtn_clicked();

    void on_allBtn_clicked();

private:
    void init();

private:
    Ui::NodeList *ui;
    NodeListView * listView;
};

#endif // NODELIST_H
