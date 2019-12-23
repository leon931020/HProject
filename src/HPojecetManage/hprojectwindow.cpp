#include "hprojectwindow.h"
#include "ui_hprojectwindow.h"
#include"hwidgetdefine.h"
#include"hwidgetlibrary.h"
#include"hdefine.h"
#include"QHBoxLayout"
#include"qgridlayout.h"
#include"qstackedlayout.h"
#include"qdebug.h"
#include"hqss.h"
#include"hwindowapi.h"
HProjectWindow::HProjectWindow(QWidget *parent) :
    QMainWindow(parent),m_stackedLayout(NULL),m_titlebar(NULL),
    ui(new Ui::HProjectWindow)
{
    ui->setupUi(this);

    initTitleLayout();

    setStackedLayout();

    _setStyle();
}

HProjectWindow::~HProjectWindow()
{
    delete ui;
}


void HProjectWindow::initWorkSpace()
{
    foreach(HWIDGET_PLU_INFO *pluItem,HWidgetLibrary::getInstance()->m_wndList)
        {
        HWidgetPluginInterface *pluInter = reinterpret_cast<HWidgetPluginInterface *>(pluItem->pluClass);
            //判断是否是工具栏插件
            if (pluItem->pluType == HDefine::H_UI_PRO)
            {
                if (pluItem->pluName == "titleBar")
                {
                    this->m_titlebar = pluInter->createWindow(this);
                    qDebug()<<"get it";
                    continue;
                }
                else if(pluItem->pluName == "")
                {
                    continue;
                }




            }

    }
}

void HProjectWindow::initTitleLayout()
{
    foreach(HWIDGET_PLU_INFO *pluItem,HWidgetLibrary::getInstance()->m_wndList)
    {
        HWidgetPluginInterface *pluInter = reinterpret_cast<HWidgetPluginInterface *>(pluItem->pluClass);
        //判断是否是工具栏插件
        if (pluItem->pluType == HDefine::H_UI_PRO)
        {
            if (pluItem->pluName == "titleBar")
            {
                this->m_titlebar = pluInter->createWindow(this);
                continue;
            }
            else
            {
                continue;
            }




        }

    }

    if(m_titlebar!=NULL)
    {
        QVBoxLayout *layout = new QVBoxLayout(ui->titleWidget);
        layout->setContentsMargins(0,0,0,0);

        ui->titleWidget->setFixedHeight(m_titlebar->height());
        layout->setContentsMargins(0,0,0,0);

        layout->addWidget(m_titlebar);
    }




}

void HProjectWindow::setStackedLayout()
{
    int index = 0;

    if(m_stackedLayout == NULL)
    {
        m_stackedLayout = new QStackedLayout();
        QHBoxLayout *layout = new QHBoxLayout(ui->stackedWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addLayout(m_stackedLayout);

    }


    foreach(HWIDGET_PLU_INFO *pluItem,HWidgetLibrary::getInstance()->m_wndList)
    {
        //get plugin obj
        HWidgetPluginInterface *pluInter = reinterpret_cast<HWidgetPluginInterface *>(pluItem->pluClass);
        //
        if (pluItem->pluType == HDefine::H_UI_PRO)
        {
            if (pluItem->pluName == "titleBar")
            {
                //this->m_titlebar = pluInter->createWindow(this);
                //qDebug()<<"get it";
                continue;
            }
            else
            {
                m_stackedLayout->insertWidget(index,pluInter->createWindow(this));

                m_layouHash.insert(pluItem->pluName,index);
                index++;

            }

        }

    }

    switchProWnd("HLinkStatusGraph");



}

bool HProjectWindow::switchProWnd(QString funName)
{
    if (funName.isEmpty())
    {
        return false;
    }
    else
    {
        QHash<QString, int>::const_iterator indexItem = m_layouHash.constBegin();
        while (indexItem != m_layouHash.constEnd())
        {
            if (funName == indexItem.key())
            {
                m_stackedLayout->setCurrentIndex(indexItem.value());


            }

            ++indexItem;
        }
    }
    return true;
}

void HProjectWindow::_setStyle()
{
    HQss::getInstance()->setWidgetStyle(this,HQss::FlatBlack);
    this->setWindowFlags(Qt::FramelessWindowHint );
    HWindowApi *api = HWindowApi::getInstance();
    this->resize(api->screenWidth - 510,api->screenHeight - 150);
    this->move(api->screenWidth / 2 - this->width() / 2,api->screenHeight / 2 - this->height() / 2);

    this->setProperty("canMove", true);
    this->installEventFilter(HWindowApi::getInstance());

}



