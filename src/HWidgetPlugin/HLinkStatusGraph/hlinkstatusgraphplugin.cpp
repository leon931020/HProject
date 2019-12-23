#include "hlinkstatusgraph.h"
#include "hlinkstatusgraphplugin.h"
#include "hdefine.h"
HLinkStatusGraphPlugin ::HLinkStatusGraphPlugin (QObject *parent) :
    QObject(parent)
{

}


QString HLinkStatusGraphPlugin ::getPluName() const
{
    QString pluName = tr("HLinkStatusGraph");
    return pluName;
}

QIcon HLinkStatusGraphPlugin ::icon() const
{
    return QIcon("");
}

int HLinkStatusGraphPlugin ::windowType() const
{
    return HDefine::H_UI_PRO;
}

QWidget *HLinkStatusGraphPlugin ::createWindow(QWidget *parent) const
{
   // LayoutWindow *window=new LayoutWindow(parent);
   // window->initQss();
    HLinkStatusGraph *window = new HLinkStatusGraph(parent);
    return  window;
}
