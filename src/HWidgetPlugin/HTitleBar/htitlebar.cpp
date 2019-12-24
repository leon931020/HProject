#include "htitlebar.h"
#include "ui_htitlebar.h"
#include "QtAwesome.h"
#include"QStyleOption"
#include"QDesktopWidget"
#include"QPainter"
#include"qdebug.h"
#include"hconfigmanage.h"
#include"qfile.h"
#include"QDomDocument"
#include"qtoolbutton.h"
#include"hwindowapi.h"
HTitleBar::HTitleBar(QWidget *parent) :
    QWidget(parent),max(false),m_parent(parent),awesome(NULL),
    ui(new Ui::HTitleBar)
{
    ui->setupUi(this);


    if(m_parent!=NULL)
        location = m_parent->geometry();

    init();

}

HTitleBar::~HTitleBar()
{
    delete ui;
}


void HTitleBar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void HTitleBar::initStyle()
{
    if(awesome == NULL)
    {
        awesome = new QtAwesome();
        awesome->initFontAwesome();
    }


    this->setProperty("form", "title");
    this->setProperty("nav", "top");



    ui->labIco->setFont(awesome->font(50));
    ui->labIco->setText(QChar( fa::group));

    ui->btnMenu_Min->setFont(awesome->font(20));
    ui->btnMenu_Min->setText(QChar(0xF068));
    ui->btnMenu_Max->setFont(awesome->font(20));
    ui->btnMenu_Max->setText( QChar(0xf2d0));
    ui->btnMenu_Close->setFont(awesome->font(20));
    ui->btnMenu_Close->setText(QChar(0xF00d));
}

bool HTitleBar::getTitleItems()
{
    QString filePath = HConfigManage::getInstance()->getAbsolutePath("/config/titleBar.xml");
    if(filePath == "")
        return false ;
    else
    {
        QDomDocument dom;
        QFile r_file(filePath);
        if (!r_file.open( QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }
        dom.setContent(&r_file);
        r_file.close();

        barInfo.clear();

        QDomElement root = dom.documentElement();
        QString root_name = root.tagName();
        //判断XML头格式<titleBar>
        if (root_name == "titleBar")
        {
            //根节点
            QDomElement person = root.firstChildElement();
            if (person.isNull())
            {
                return false;
            }
            QDomNodeList list = root.childNodes();
            int count = list.count();
            //第一层<function>子节点内容
            for (int i = 0;i < count;++i)
            {
                QDomNode dom_node = list.item(i);
                QDomElement element = dom_node.toElement();

                titleItem info;
                info.index = element.attributeNode("index").value().toInt();
                info.name = element.attributeNode("name").value();
                info.displayName = element.attributeNode("displayName").value();
                info.icon = element.attributeNode("icon").value();
                info.iconColor = element.attributeNode("iconColor").value();

                barInfo.append(info);
            }
        }


    }
}

void HTitleBar::fillTitle()
{

    qSort(barInfo.begin(),barInfo.end(),compareByIndex);
    QList<titleItem>::iterator itr = barInfo.begin();
    for (; itr != barInfo.end();++itr)
    {
        addQToolBtn(*itr);
    }
}

void HTitleBar::addQToolBtn(const titleItem & item)
{



    QToolButton * btn = new QToolButton(ui->widgetTop);
    btn->setFixedHeight(70);
    btn->setFixedWidth(70);
    btn->setObjectName(item.name);
    btn->setText(item.displayName);


    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->horizontalLayout_3->addWidget(btn);

    QVariantMap options;
    options.insert("color",QColor(item.iconColor));
    options.insert("scale-factor",1.0);
    //options.insert("anim", qVariantFromValue( new QtAwesomeAnimation(ui->btnConfig) ) );

    btn->setIcon(awesome->icon( item.icon.toInt(0,16), options  ) );

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(itemClicked()));

    btnList.append(btn);
}

void HTitleBar::init()
{
    initStyle();

    getTitleItems();

    fillTitle();
}

bool HTitleBar::compareByIndex(const HTitleBar::titleItem &r1, const HTitleBar::titleItem &r2)
{
    return r1.index < r2.index;
}




void HTitleBar::on_btnMenu_Min_clicked()
{
    if(m_parent!=NULL)
    {
        m_parent->showMinimized();
    }


}

void HTitleBar::on_btnMenu_Max_clicked()
{

    //the current state is Maxed
    //will be normalSized
    if(m_parent!=NULL)
    {
        if (max)
        {

            m_parent->setGeometry(location);
            m_parent->setProperty("canMove", true);
            ui->btnMenu_Max->setText( QChar(0xf2d0));
        } else {
            location = m_parent->geometry();
            m_parent->setGeometry(qApp->desktop()->availableGeometry());
            ui->btnMenu_Max->setText( QChar(0xf2d2));
            m_parent->setProperty("canMove", false);
        }

        max = !max;
    }
    else
    {
        return ;
    }
}

void HTitleBar::on_btnMenu_Close_clicked()
{
 //   exit(0);
    m_parent->close();
}

void HTitleBar::itemClicked()
{
    QToolButton *btn = (QToolButton *)sender();

    for(int i=0;i<barInfo.size();i++)
    {
        titleItem item = barInfo.at(i);
        QToolButton * temp = btnList.at(i);

        if(item.name == btn->objectName())
        {
            QVariantMap options;
            options.insert("color",QColor(item.iconColor));
            options.insert("scale-factor",1.0);
            options.insert("anim", qVariantFromValue( new QtAwesomeAnimation(btn) ) );

            btn->setIcon(awesome->icon( item.icon.toInt(0,16), options  ) );

        }
        else
        {
            QVariantMap options;
            options.insert("color",QColor(item.iconColor));
            options.insert("scale-factor",1.0);
            //options.insert("anim", qVariantFromValue( new QtAwesomeAnimation(btn) ) );

            temp->setIcon(awesome->icon( item.icon.toInt(0,16), options  ) );

        }

    }

    QString name = btn->objectName();

    emit HWindowApi::getInstance()->titleItemClicked(name);
}


