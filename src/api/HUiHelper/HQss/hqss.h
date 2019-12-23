#ifndef HQss_H
#define HQss_H
#include "qobject.h"
#include "qfont.h"
#include"qcolor.h"
#include"qsize.h"
class QPushButton;
class QLineEdit;
class QProgressBar;
class QSlider;
class QRadioButton;
class QScrollBar;
class QLabel;
class QAbstractButton;
class Q_DECL_EXPORT HQss:public QObject
{
    Q_OBJECT
public:
    enum Style {
        LightBlue=0,
        FlatWhite=1,
        FlatBlack=2
    };
public:

    static HQss *getInstance();

private:

    explicit HQss(QObject *parent = 0);

    virtual ~HQss();


//其它样式设置共有函数开始
public:

    //设置全局widget样式
    void setWidgetStyle(QWidget *outWidget,Style style);

    //设置label图形字体
    void setIcon(QLabel *lab, QChar c, quint32 size = 16);

    //设置button图形字体
    void setIcon(QAbstractButton *btn, QChar c, quint32 size = 16);

    //返回图形字体图标
    QIcon Ico(QChar c,  QColor color = QColor(255,0,0), QSize icoSize = QSize(16,16),int size = 16);



//其它样式设置共有函数结束



//qss样式设置公有函数开始
public :

    //设置按钮样式
    void setPushButtonQss(QPushButton *btn,                             //按钮对象
                          int radius = 5,                               //圆角半径
                          int padding = 8,                              //间距
                          const QString &normalColor = "#34495E",       //正常颜色
                          const QString &normalTextColor = "#FFFFFF",   //文字颜色
                          const QString &hoverColor = "#4E6D8C",        //悬停颜色
                          const QString &hoverTextColor = "#F0F0F0",    //悬停文字颜色
                          const QString &pressedColor = "#2D3E50",      //按下颜色
                          const QString &pressedTextColor = "#B8C6D1"); //按下文字颜色

    //设置文本框样式
    void setLineEditQss(QLineEdit *txt,                                 //文本框对象
                        int radius = 3,                                 //圆角半径
                        int borderWidth = 2,                            //边框大小
                        const QString &normalColor = "#DCE4EC",         //正常颜色
                        const QString &focusColor = "#34495E");         //选中颜色

    //设置进度条样式
    void setProgressBarQss(QProgressBar *bar,
                           int barHeight = 8,                           //进度条高度
                           int barRadius = 5,                           //进度条半径
                           int fontSize = 9,                            //文字字号
                           const QString &normalColor = "#E8EDF2",      //正常颜色
                           const QString &chunkColor = "#E74C3C");      //进度颜色

    //设置滑块条样式
    void setSliderQss(QSlider *slider,                                  //滑动条对象
                      int sliderHeight = 8,                             //滑动条高度
                      const QString &normalColor = "#E8EDF2",           //正常颜色
                      const QString &grooveColor = "#1ABC9C",           //滑块颜色
                      const QString &handleColor = "#1ABC9C");          //指示器颜色

    //设置单选框样式
    void setRadioButtonQss(QRadioButton *rbtn,                          //单选框对象
                           int indicatorRadius = 8,                     //指示器圆角角度
                           const QString &normalColor = "#D7DBDE",      //正常颜色
                           const QString &checkColor = "#34495E");      //选中颜色

    //设置滚动条样式
    void setScrollBarQss(QScrollBar *scroll,                            //滚动条对象
                         int radius = 6,                                //圆角角度
                         int min = 120,                                 //指示器最小长度
                         int max = 12,                                  //滚动条最大长度
                         const QString &bgColor = "#606060",            //背景色
                         const QString &handleNormalColor = "#34495E",  //指示器正常颜色
                         const QString &handleHoverColor = "#1ABC9C",   //指示器悬停颜色
                         const QString &handlePressedColor = "#E74C3C");//指示器按下颜色
//qss样式设置共有函数结束

private:

    //设置qss样式
    void setQss( QWidget *widget , const QString& path);

    //加载AwesomeFont图形字体库
    void loadAwesomeFont();


private:

    static HQss *m_uiInstance;

    QFont m_iconFont;


   // bool _loadedFont;

};

#endif // HQss_H
