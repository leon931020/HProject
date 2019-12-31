#ifndef LOGTEXT_H
#define LOGTEXT_H

#include <QWidget>

namespace Ui {
class LogText;
}

class LogText : public QWidget
{
    Q_OBJECT

public:
    explicit LogText(QWidget *parent = 0);
    ~LogText();
    void updateLog(const QString& path);

private:
    void init();

private:
    Ui::LogText *ui;
};

#endif // LOGTEXT_H
