#ifndef HTITLEBAR_H
#define HTITLEBAR_H

#include <QWidget>
#include"qmap.h"
class QToolButton;
class QtAwesome;
namespace Ui {
class HTitleBar;
}

class HTitleBar : public QWidget
{
    Q_OBJECT
typedef struct titleItem{
        QString name;
        QString displayName;
        QString icon;
        QString iconColor;
        int index;
        titleItem()
        {
            name = "";
            displayName = "";
            icon = "";
            iconColor = "";
            index = -1;
        }

}titleItem;

public:
    explicit HTitleBar(QWidget *parent = 0);
    ~HTitleBar();

    void paintEvent(QPaintEvent *);
private:
    void initStyle();

    bool getTitleItems();

    void fillTitle();

    void addQToolBtn(const titleItem & item);

    void init();

    static bool compareByIndex(const titleItem &r1,const titleItem &r2);
private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void itemClicked();
private:
    Ui::HTitleBar *ui;
    bool max;
    QRect location;
    QWidget *m_parent;
    QtAwesome* awesome;

    QList<titleItem> barInfo;
    QList<QToolButton *>btnList;
};

#endif // HTITLEBAR_H
