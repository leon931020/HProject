#ifndef LOGVIEW_H
#define LOGVIEW_H

#include <QWidget>
class NodeListView;
class NodeLogView;
class LogText;
namespace Ui {
class LogView;
}

class LogView : public QWidget
{
    Q_OBJECT

public:
    explicit LogView(QWidget *parent = 0);
    ~LogView();
private:
    void init();

    void initListView();

    void initNodeLogView();

    void initNodeTextView();

    void bindSigSlots();
private:
    Ui::LogView *ui;
    NodeListView *m_listView;
    NodeLogView *m_logView;
    LogText *m_textView;
};

#endif // LOGVIEW_H
