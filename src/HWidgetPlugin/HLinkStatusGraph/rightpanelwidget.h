#ifndef RIGHTPANELWIDGET_H
#define RIGHTPANELWIDGET_H

#include <QWidget>
class QScrollArea;
class QFrame;
class QVBoxLayout;
class QGridLayout;
class RightPanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightPanelWidget(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *event);
private:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;

public:
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    void setWidget(QList<QWidget *> widgets, int columnCount);
    void setBorder(int width, const QString &strColor);
    void setMargin(int left, int top, int right, int bottom);
    void setMargin(int margin);
    void setSpacing(int space);
    void setFrame(int border, const QString &strColor);
};


#endif // RIGHTPANELWIDGET_H
