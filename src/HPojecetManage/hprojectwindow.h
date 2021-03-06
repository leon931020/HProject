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

    void _setStyle();
    void bindSigSlots();
private slots:
    bool switchProWnd(QString funName);
private:
    QWidget * m_titlebar;

    QWidget * m_statusBar;

    QStackedLayout *m_stackedLayout;

    //the plugin's name-index in the m_stackedLayout;
    QHash<QString,int> m_layouHash;
private:

private:
    Ui::HProjectWindow *ui;
};

#endif // HPROJECTWINDOW_H
