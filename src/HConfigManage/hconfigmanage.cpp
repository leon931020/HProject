#include "hconfigmanage.h"
#include"qapplication.h"
HConfigManage* HConfigManage::m_instance = NULL;
HConfigManage::CGarbo HConfigManage::Garbo;

HConfigManage::HConfigManage(QObject *parent) : QObject(parent)
{

}

HConfigManage::~HConfigManage()
{

}

HConfigManage *HConfigManage::getInstance()
{
    if(m_instance==NULL)
    {
        m_instance = new HConfigManage();
        return m_instance;
    }
    else
    {
        return m_instance;
    }
}

QString HConfigManage::getAbsolutePath(const QString relativePath) const
{
    QString dir = QApplication::applicationDirPath();
    QString dirPath = dir.mid(0,dir.size() - 4);
    dirPath += relativePath;
    return dirPath;
}
