#include "logtext.h"
#include "ui_logtext.h"
#include"qfile.h"
#include"hqss.h"
#include"qtextcodec.h"
#include"hconfigmanage.h"
LogText::LogText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogText)
{
    ui->setupUi(this);

    init();
}

LogText::~LogText()
{
    delete ui;
}

void LogText::updateLog(const QString &path)
{
    ui->textEdit->setCurrentFont(QFont(HQss::FontName, HQss::FontSize));
    QFile file(path);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QByteArray ba = file.readAll();
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QString str = codec->toUnicode(ba);
        ui->textEdit->setText(str);
        file.close();
    }
}

void LogText::init()
{
    QString filePath = HConfigManage::getInstance()->getAbsolutePath("/download/nodeLog/example.html");

    this->updateLog(filePath);
}
