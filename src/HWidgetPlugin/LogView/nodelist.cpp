#include "nodelist.h"
#include "ui_nodelist.h"
NodeList::NodeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeList)
{
    ui->setupUi(this);
}

NodeList::~NodeList()
{
    delete ui;
}
