#ifndef HTITLEBAR_H
#define HTITLEBAR_H

#include <QWidget>
class QToolButton;
namespace Ui {
class HTitleBar;
}

class HTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit HTitleBar(QWidget *parent = 0);
    ~HTitleBar();

    void paintEvent(QPaintEvent *);
private:
    void initStyle();

    void addQToolBtn(QToolButton * btn);
private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
private:
    Ui::HTitleBar *ui;
    bool max;
    QRect location;
    QWidget *m_parent;
};

#endif // HTITLEBAR_H
