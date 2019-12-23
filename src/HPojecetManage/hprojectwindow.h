#ifndef HPROJECTWINDOW_H
#define HPROJECTWINDOW_H

#include <QMainWindow>
class QStackedLayout ;
namespace Ui {
class HProjectWindow;
}

class HProjectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HProjectWindow(QWidget *parent = 0);
    ~HProjectWindow();

private:
    void initWorkSpace();
    void initTitleLayout();
    void setStackedLayout();
    bool switchProWnd(QString funName);
    void _setStyle();
private:
    QWidget * m_titlebar;

    QStackedLayout *m_stackedLayout;

    //the plugin's name-index in the m_stackedLayout;
    QHash<QString,int> m_layouHash;
private:

private:
    Ui::HProjectWindow *ui;
};

#endif // HPROJECTWINDOW_H
