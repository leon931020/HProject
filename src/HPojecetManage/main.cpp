#include"hprojectwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HProjectWindow w;
    w.show();

    return a.exec();
}
