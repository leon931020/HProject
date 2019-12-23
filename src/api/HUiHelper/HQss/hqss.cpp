#include "hqss.h"
#include"qslider.h"
#include"qpushbutton.h"
#include"qlineedit.h"
#include"qprogressbar.h"
#include"qradiobutton.h"
#include"qscrollbar.h"
#include"qwidget.h"
#include"qfile.h"
#include"qpalette.h"
#include"qlabel.h"
#include"qabstractbutton.h"
#include"qfontdatabase.h"
#include"qpainter.h"
#include"qicon.h"
#include"qimage.h"
HQss * HQss::m_uiInstance=NULL;

HQss *HQss::getInstance()
{
    if(m_uiInstance!=NULL)
    {
        return m_uiInstance;
    }
    else
    {
        return new HQss();
    }
}

HQss::HQss(QObject *parent):QObject(parent)
{
   // loadAwesomeFont();
}

HQss::~HQss()
{

}

void HQss::setWidgetStyle(QWidget *outWidget, HQss::Style style)
{
    if(style==LightBlue)
    {
        setQss(outWidget,":/other/qss/lightblue.css");
    }
    else if(style==FlatWhite)
    {
        setQss(outWidget,":/other/qss/flatwhite.css");
    }
    else if(style=FlatBlack)
    {
        setQss(outWidget,":/other/qss/flatblack.css");
    }
}

void HQss::setIcon(QLabel *lab, QChar c, quint32 size)
{

    m_iconFont.setPointSize(size);
    lab->setFont(m_iconFont);
    lab->setText(c);
}

void HQss::setIcon(QAbstractButton *btn, QChar c, quint32 size)
{

    m_iconFont.setPointSize(size);
    btn->setFont(m_iconFont);
    btn->setText(c);
}

QIcon HQss::Ico(QChar c, QColor color ,QSize icoSize ,int size )
{

    QImage image(icoSize, QImage::Format_ARGB32);
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);

    QPen pen = painter.pen();
    pen.setColor(color);
    m_iconFont.setPixelSize(size);
    painter.setPen(pen);

    painter.setFont(m_iconFont);

    painter.drawText(image.rect(), Qt::AlignCenter, c);
    return QIcon(QPixmap::fromImage(image));
}


void HQss::setPushButtonQss(QPushButton *btn, int radius, int padding,
                              const QString &normalColor, const QString &normalTextColor,
                              const QString &hoverColor, const QString &hoverTextColor,
                              const QString &pressedColor, const QString &pressedTextColor)
{
    QStringList qss;
    qss.append(QString("QPushButton{border-style:none;padding:%1px;border-radius:%2px;color:%3;background:%4;}")
               .arg(padding).arg(radius).arg(normalTextColor).arg(normalColor));
    qss.append(QString("QPushButton:hover{color:%1;background:%2;}")
               .arg(hoverTextColor).arg(hoverColor));
    qss.append(QString("QPushButton:pressed{color:%1;background:%2;}")
               .arg(pressedTextColor).arg(pressedColor));
    btn->setStyleSheet(qss.join(""));
}

void HQss::setLineEditQss(QLineEdit *txt, int radius, int borderWidth,
                            const QString &normalColor, const QString &focusColor)
{
    QStringList qss;
    qss.append(QString("QLineEdit{border-style:none;padding:3px;border-radius:%1px;border:%2px solid %3;}")
               .arg(radius).arg(borderWidth).arg(normalColor));
    qss.append(QString("QLineEdit:focus{border:%1px solid %2;}")
               .arg(borderWidth).arg(focusColor));
    txt->setStyleSheet(qss.join(""));
}

void HQss::setProgressBarQss(QProgressBar *bar, int barHeight, int barRadius, int fontSize,
                               const QString &normalColor, const QString &chunkColor)
{

    QStringList qss;
    qss.append(QString("QProgressBar{font:%1pt;background:%2;max-height:%3px;border-radius:%4px;text-align:center;border:1px solid %2;}")
               .arg(fontSize).arg(normalColor).arg(barHeight).arg(barRadius));
    qss.append(QString("QProgressBar:chunk{border-radius:%2px;background-color:%1;}")
               .arg(chunkColor).arg(barRadius));
    bar->setStyleSheet(qss.join(""));
}

void HQss::setSliderQss(QSlider *slider, int sliderHeight,
                          const QString &normalColor, const QString &grooveColor,
                          const QString &handleColor)
{
    int sliderRadius = sliderHeight / 2;
    int handleWidth = (sliderHeight * 3) / 2 + (sliderHeight / 5);
    int handleRadius = handleWidth / 2;
    int handleOffset = handleRadius / 2;

    QStringList qss;
    qss.append(QString("QSlider::groove:horizontal{background:%1;height:%2px;border-radius:%3px;}")
               .arg(normalColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::add-page:horizontal{background:%1;height:%2px;border-radius:%3px;}")
               .arg(normalColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::sub-page:horizontal{background:%1;height:%2px;border-radius:%3px;}")
               .arg(grooveColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::handle:horizontal{width:%2px;margin-top:-%3px;margin-bottom:-%3px;border-radius:%4px;"
                       "background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #FFFFFF,stop:0.8 %1);}")
               .arg(handleColor).arg(handleWidth).arg(handleOffset).arg(handleRadius));

    //偏移一个像素
    handleWidth = handleWidth + 1;
    qss.append(QString("QSlider::groove:vertical{width:%2px;border-radius:%3px;background:%1;}")
               .arg(normalColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::add-page:vertical{width:%2px;border-radius:%3px;background:%1;}")
               .arg(grooveColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::sub-page:vertical{width:%2px;border-radius:%3px;background:%1;}")
               .arg(normalColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::handle:vertical{height:%2px;margin-left:-%3px;margin-right:-%3px;border-radius:%4px;"
                       "background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #FFFFFF,stop:0.8 %1);}")
               .arg(handleColor).arg(handleWidth).arg(handleOffset).arg(handleRadius));

    slider->setStyleSheet(qss.join(""));
}

void HQss::setRadioButtonQss(QRadioButton *rbtn, int indicatorRadius,
                               const QString &normalColor, const QString &checkColor)
{
    int indicatorWidth = indicatorRadius * 2;

    QStringList qss;
    qss.append(QString("QRadioButton::indicator{border-radius:%1px;width:%2px;height:%2px;}")
               .arg(indicatorRadius).arg(indicatorWidth));
    qss.append(QString("QRadioButton::indicator::unchecked{background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,"
                       "stop:0.6 #FFFFFF,stop:0.7 %1);}").arg(normalColor));
    qss.append(QString("QRadioButton::indicator::checked{background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,"
                       "stop:0 %1,stop:0.3 %1,stop:0.4 #FFFFFF,stop:0.6 #FFFFFF,stop:0.7 %1);}").arg(checkColor));

    rbtn->setStyleSheet(qss.join(""));
}

void HQss::setScrollBarQss(QScrollBar *scroll, int radius, int min, int max,
                             const QString &bgColor, const QString &handleNormalColor,
                             const QString &handleHoverColor, const QString &handlePressedColor)
{
    //滚动条离背景间隔
    int padding = 0;

    QStringList qss;

    //handle:指示器,滚动条拉动部分 add-page:滚动条拉动时增加的部分 sub-page:滚动条拉动时减少的部分 add-line:递增按钮 sub-line:递减按钮

    //横向滚动条部分
    qss.append(QString("QScrollBar:horizontal{background:%1;padding:%2px;border-radius:%3px;max-height:%4px;}")
               .arg(bgColor).arg(padding).arg(radius).arg(max));
    qss.append(QString("QScrollBar::handle:horizontal{background:%1;min-width:%2px;border-radius:%3px;}")
               .arg(handleNormalColor).arg(min).arg(radius));
    qss.append(QString("QScrollBar::handle:horizontal:hover{background:%1;}")
               .arg(handleHoverColor));
    qss.append(QString("QScrollBar::handle:horizontal:pressed{background:%1;}")
               .arg(handlePressedColor));
    qss.append(QString("QScrollBar::add-page:horizontal{background:none;}"));
    qss.append(QString("QScrollBar::sub-page:horizontal{background:none;}"));
    qss.append(QString("QScrollBar::add-line:horizontal{background:none;}"));
    qss.append(QString("QScrollBar::sub-line:horizontal{background:none;}"));

    //纵向滚动条部分
    qss.append(QString("QScrollBar:vertical{background:%1;padding:%2px;border-radius:%3px;max-width:%4px;}")
               .arg(bgColor).arg(padding).arg(radius).arg(max));
    qss.append(QString("QScrollBar::handle:vertical{background:%1;min-height:%2px;border-radius:%3px;}")
               .arg(handleNormalColor).arg(min).arg(radius));
    qss.append(QString("QScrollBar::handle:vertical:hover{background:%1;}")
               .arg(handleHoverColor));
    qss.append(QString("QScrollBar::handle:vertical:pressed{background:%1;}")
               .arg(handlePressedColor));
    qss.append(QString("QScrollBar::add-page:vertical{background:none;}"));
    qss.append(QString("QScrollBar::sub-page:vertical{background:none;}"));
    qss.append(QString("QScrollBar::add-line:vertical{background:none;}"));
    qss.append(QString("QScrollBar::sub-line:vertical{background:none;}"));

    scroll->setStyleSheet(qss.join(""));
}

void HQss::setQss(QWidget *widget, const QString &path)
{
    QFile file(path);

    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        widget->setPalette(QPalette(QColor(paletteColor)));
        widget->setStyleSheet(qss);
        file.close();
    }
}

void HQss::loadAwesomeFont()
{
    int fontId = QFontDatabase::addApplicationFont(":/font/other/fontawesome/fontawesome-webfont.ttf");

    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);

    m_iconFont = QFont(fontName);
}
