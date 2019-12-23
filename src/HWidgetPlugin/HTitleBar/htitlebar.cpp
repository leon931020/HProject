#include "htitlebar.h"
#include "ui_htitlebar.h"
#include "QtAwesome.h"
#include"QStyleOption"
#include"QDesktopWidget"
#include"QPainter"
#include"qdebug.h"
HTitleBar::HTitleBar(QWidget *parent) :
    QWidget(parent),max(false),m_parent(parent),
    ui(new Ui::HTitleBar)
{
    ui->setupUi(this);


    location = m_parent->geometry();

    initStyle();
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
    QtAwesome* awesome = new QtAwesome();
    awesome->initFontAwesome();

    QVariantMap options;
    options.insert("color",QColor(Qt::red));
    options.insert("anim", qVariantFromValue( new QtAwesomeAnimation(ui->btnConfig) ) );

    ui->btnConfig->setIcon(awesome->icon( fa::group, options  ) );

    this->setProperty("form", "title");
    this->setProperty("form", true);


    ui->labIco->setFont(awesome->font(50));
    ui->labIco->setText(QChar( fa::group));

    ui->btnMenu_Min->setText(QChar(0xF068));
    ui->btnMenu_Max->setText( QChar(0xf2d0));
    ui->btnMenu_Close->setText(QChar(0xF00d));
}

void HTitleBar::addQToolBtn(QToolButton * btn)
{
    if(btn==NULL)
        return ;

    //btn = new QToolButton(ui->widgetTop);
    //btn->setObjectName(QStringLiteral("btn"));
    QSizePolicy sizePolicy1;
    sizePolicy1.setHeightForWidth(btn->sizePolicy().hasHeightForWidth());
    btn->setSizePolicy(sizePolicy1);
    btn->setStyleSheet(QStringLiteral(""));
   // QIcon icon1;
   // icon1.addFile(QStringLiteral(":/demo/main_help.png"), QSize(), QIcon::Normal, QIcon::Off);
   // btn->setIcon(icon1);
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->horizontalLayout_3->addWidget(btn);
}


void HTitleBar::on_btnMenu_Min_clicked()
{

    m_parent->showMinimized();


}

void HTitleBar::on_btnMenu_Max_clicked()
{

    //the current state is Maxed
    //will be normalSized
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

void HTitleBar::on_btnMenu_Close_clicked()
{
    exit(0);
    //m_parent->close();
}


