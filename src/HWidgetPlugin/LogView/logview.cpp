#include "logview.h"
#include "ui_logview.h"
#include"nodelistview.h"
#include"QVBoxLayout"
#include"nodelogview.h"
#include"logtext.h"
LogView::LogView(QWidget *parent) :
    QWidget(parent),m_listView(NULL),
    ui(new Ui::LogView),m_logView(NULL),m_textView(NULL)
{
    ui->setupUi(this);

    init();

    bindSigSlots();

}

LogView::~LogView()
{
    delete ui;
}

void LogView::init()
{
    initListView();

    initNodeLogView();

    initNodeTextView();
}

void LogView::initListView()
{
    if(m_listView == NULL)
    {
        m_listView = new NodeListView;
        QVBoxLayout *layout = new QVBoxLayout(ui->nodeListWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(m_listView);
    }
}

void LogView::initNodeLogView()
{
    if(m_logView == NULL)
    {
        m_logView = new NodeLogView;
        QVBoxLayout *layout = new QVBoxLayout(ui->nodeLogWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(m_logView);

    }
}

void LogView::initNodeTextView()
{
    if(m_textView  == NULL)
    {
        m_textView = new LogText;
        QVBoxLayout *layout = new QVBoxLayout(ui->logTextWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(m_textView);

    }
}

void LogView::bindSigSlots()
{
    connect(m_listView,SIGNAL(listViewClicked(QModelIndex)),m_logView,SLOT(updateModel(QModelIndex)));
}
