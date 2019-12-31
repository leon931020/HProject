#include "nodelog.h"
#include "ui_nodelog.h"

NodeLog::NodeLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeLog)
{
    ui->setupUi(this);
}

NodeLog::~NodeLog()
{
    delete ui;
}
