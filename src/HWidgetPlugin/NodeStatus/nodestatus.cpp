#include "nodestatus.h"
#include "ui_nodestatus.h"

NodeStatus::NodeStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeStatus)
{
    ui->setupUi(this);
}

NodeStatus::~NodeStatus()
{
    delete ui;
}
