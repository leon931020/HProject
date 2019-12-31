#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include"qstyleditemdelegate.h"
class ItemDelegate:public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate(QObject *parent);
    ~ItemDelegate();
protected:
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:

    bool rightIconVisible;          //右侧图标是否显示
    bool tipVisible;                //是否显示提示信息
    int tipWidth;                   //提示信息宽度

    bool separateVisible;           //是否显示行分隔符
    int separateHeight;             //行分隔符高度
    QColor separateColor;           //行分隔符颜色

    bool lineLeft;                  //是否显示在左侧
    bool lineVisible;               //是否显示线条
    int lineWidth;                  //线条宽度
    QColor lineColor;               //线条颜色

    bool triangleLeft;              //是否显示在左侧
    bool triangleVisible;           //是否显示三角形
    int triangleWidth;              //三角形宽度
    QColor triangleColor;           //三角形颜色

    int parentIconMargin;           //父节点图标边距
    int parentMargin;               //父节点边距
    int parentFontSize;             //父节点字体大小
    int parentHeight;               //父节点高度
    QColor parentBgNormalColor;     //父节点正常背景色
    QColor parentBgSelectedColor;   //父节点选中背景色
    QColor parentBgHoverColor;      //父节点悬停背景色
    QColor parentTextNormalColor;   //父节点正常文字颜色
    QColor parentTextSelectedColor; //父节点选中文字颜色
    QColor parentTextHoverColor;    //父节点悬停文字颜色

    int childIconMargin;            //子节点图标边距
    int childMargin;                //子节点边距
    int childFontSize;              //子节点字体大小
    int childHeight;                //子节点高度
    QColor childBgNormalColor;      //子节点正常背景色
    QColor childBgSelectedColor;    //子节点选中背景色
    QColor childBgHoverColor;       //子节点悬停背景色
    QColor childTextNormalColor;    //子节点正常文字颜色
    QColor childTextSelectedColor;  //子节点选中文字颜色
    QColor childTextHoverColor;     //子节点悬停文字颜色

};

#endif // ITEMDELEGATE_H
