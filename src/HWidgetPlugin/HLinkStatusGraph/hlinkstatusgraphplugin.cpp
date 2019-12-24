#include "hlinkstatusui.h"
#include "hlinkstatusgraphplugin.h"
#include "hdefine.h"
HLinkStatusGraphPlugin ::HLinkStatusGraphPlugin (QObject *parent) :
    QObject(parent)
{

}


QString HLinkStatusGraphPlugin ::getPluName() const
{
    QString pluName = tr("systemStatus");
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

    HLinkStatusUi *window = new HLinkStatusUi(parent);
    return  window;
}
