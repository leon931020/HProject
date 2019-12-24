#include "nodestatus.h"
#include "nodestatusplugin.h"
#include "hdefine.h"
NodeStatusPlugin ::NodeStatusPlugin (QObject *parent) :
    QObject(parent)
{

}


QString NodeStatusPlugin ::getPluName() const
{
    QString pluName = tr("nodeStatus");
    return pluName;
}

QIcon NodeStatusPlugin ::icon() const
{
    return QIcon("");
}

int NodeStatusPlugin ::windowType() const
{
    return HDefine::H_UI_PRO;
}

QWidget *NodeStatusPlugin ::createWindow(QWidget *parent) const
{
   // LayoutWindow *window=new LayoutWindow(parent);
   // window->initQss();
    NodeStatus *window = new NodeStatus(parent);
    return  window;
}
