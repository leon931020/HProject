#ifndef HLINKSTATUSUI_H
#define HLINKSTATUSUI_H

#include <QWidget>
class GraphWidget;
class RightPanelWidget;
namespace Ui {
class HLinkStatusUi;
}

class HLinkStatusUi : public QWidget
{
    Q_OBJECT

public:
    explicit HLinkStatusUi(QWidget *parent = 0);
    ~HLinkStatusUi();
    void paintEvent(QPaintEvent *);
private:
    void init();
    void initLeftWidget();
    void initRightWidget();
    void initArray(int num);
    void initList();
private:
    GraphWidget *m_graphWidget;
    RightPanelWidget *m_rightWidget;

private:
    Ui::HLinkStatusUi *ui;
};

#endif // HLINKSTATUSUI_H
