#include "logview.h"
#include "logviewplugin.h"
#include "hdefine.h"
LogViewPlugin ::LogViewPlugin (QObject *parent) :
    QObject(parent)
{

}


QString LogViewPlugin ::getPluName() const
{
    QString pluName = tr("logInfo");
    return pluName;
}

QIcon LogViewPlugin ::icon() const
{
    return QIcon("");
}

int LogViewPlugin ::windowType() const
{
    return HDefine::H_UI_PRO;
}

QWidget *LogViewPlugin ::createWindow(QWidget *parent) const
{

    LogView *window = new LogView(parent);
    return  window;
}
