#include "itemdelegate.h"
#include"qpainter.h"
#include"QtAwesome.h"
#include"nodelistmodel.h"
ItemDelegate::ItemDelegate(QObject *parent):QStyledItemDelegate(parent)
{

    rightIconVisible = true;
    tipVisible = true;
    tipWidth = 40;

    separateVisible = true;
    separateHeight = 1;
    separateColor = QColor(40, 43, 51);

    lineLeft = true;
    lineVisible = true;
    lineWidth = 6;
    lineColor = QColor(0, 187, 158);

    triangleLeft = false;
    triangleVisible = true;
    triangleWidth = 6;
    triangleColor = QColor(250, 250, 250);

    parentIconMargin = 5;
    parentMargin = 30;
    parentFontSize = 12;
    parentHeight = 35;
    parentBgNormalColor = QColor(57, 61, 73);
    parentBgSelectedColor = QColor(78, 83, 102);
    parentBgHoverColor = QColor(78, 83, 102);
    parentTextNormalColor = QColor(250, 250, 250);
    parentTextSelectedColor = QColor(250, 250, 250);
    parentTextHoverColor = QColor(250, 250, 250);

    childIconMargin = 15;
    childMargin = 35;
    childFontSize = 12;
    childHeight = 30;
    childBgNormalColor = QColor(40, 43, 51);
    childBgSelectedColor = QColor(20, 20, 20);
    childBgHoverColor = QColor(20, 20, 20);
    childTextNormalColor = QColor(180, 180, 180);
    childTextSelectedColor = QColor(250, 250, 250);
    childTextHoverColor = QColor(255, 255, 255);
}

ItemDelegate::~ItemDelegate()
{

}

QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size(50, 28);
    bool parent =index.data(Qt::UserRole+1).toBool();

    if (parent) {
        size = QSize(50, 30);
    } else {
        size = QSize(50, 50);
    }

    return size;
}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setRenderHint(QPainter::Antialiasing);
  //  NavModel::TreeNode *node = (NavModel::TreeNode *)index.data(Qt::UserRole).toULongLong();

    //定义变量存储区域
    QRect optionRect = option.rect;
    int x = optionRect.x();
    int y = optionRect.y();
    int width = optionRect.width();
    int height = optionRect.height();

    int fontSize = this->parentFontSize;


    //父节点和子节点颜色分开设置
   // bool parent = (node->level == 1);
    bool parent = index.data(Qt::UserRole+1).toBool();

    //根据不同的状态设置不同的颜色 bgColor-主背景色 textColor-主文字颜色 tipBgColor-提示信息背景颜色 tipTextColor-提示信息文字颜色
    QColor bgColor, textColor, tipBgColor, tipTextColor, iconColor;
    if (option.state & QStyle::State_Selected)
    {
        bgColor = parent ? this->parentBgSelectedColor : this->childBgSelectedColor;
        textColor = parent ? this->parentTextSelectedColor : this->childTextSelectedColor;
        tipBgColor = parent ? this->parentTextSelectedColor : this->childTextSelectedColor;
        tipTextColor = parent ? this->parentBgSelectedColor : this->childBgSelectedColor;
        iconColor = parent ? this->parentTextSelectedColor : this->childTextSelectedColor;
    } else if (option.state & QStyle::State_MouseOver)
    {
        bgColor = parent ? this->parentBgHoverColor : this->childBgHoverColor;
        textColor = parent ? this->parentTextHoverColor : this->childTextHoverColor;
        tipBgColor = parent ? this->parentTextSelectedColor : this->childTextSelectedColor;
        tipTextColor = parent ? this->parentBgSelectedColor : this->childBgSelectedColor;
        iconColor = parent ? this->parentTextHoverColor : this->childTextHoverColor;
    } else
    {
        bgColor = parent ? this->parentBgNormalColor : this->childBgNormalColor;
        textColor = parent ? this->parentTextNormalColor : this->childTextNormalColor;
        tipBgColor = parent ? this->parentBgSelectedColor : this->childBgSelectedColor;
        tipTextColor = parent ? this->parentTextSelectedColor : this->childTextSelectedColor;
        iconColor = parent ? this->parentTextNormalColor : this->childTextNormalColor;
    }

    //绘制背景
    painter->fillRect(optionRect, bgColor);

    //绘制线条,目前限定子节点绘制,如果需要父节点也绘制则取消parent判断即可
    int lineWidth = this->lineWidth;
    if (!parent && this->lineVisible && lineWidth > 0) {
        if ((option.state & QStyle::State_Selected) || (option.state & QStyle::State_MouseOver))
        {
            //设置偏移量,不然上下部分会有点偏移
            float offset = (float)lineWidth / 2;

            //计算上下两个坐标点
            QPointF pointTop(x, y + offset);
            QPointF pointBottom(x, height + y - offset);
            if (!this->lineLeft)
            {
                pointTop.setX(width);
                pointBottom.setX(width);
            }

            //设置线条颜色和宽度
            painter->setPen(QPen(this->lineColor, lineWidth));
            painter->drawLine(pointTop, pointBottom);
        }
    }

    //绘制三角形,目前限定子节点绘制,如果需要父节点也绘制则取消parent判断即可
    int triangleWidth = this->triangleWidth;
    if (!parent && this->triangleVisible && triangleWidth > 0)
    {
        if ((option.state & QStyle::State_Selected) || (option.state & QStyle::State_MouseOver))
        {
            QFont font = QtAwesome::getInstance()->font(fontSize + triangleWidth);

            painter->setFont(font);
            painter->setPen(this->triangleColor);

            //采用图形字体中的三角形绘制
            if (this->triangleLeft)
            {
                painter->drawText(optionRect, Qt::AlignLeft | Qt::AlignVCenter, QChar(0xf0da));
            }
            else
            {
                painter->drawText(optionRect, Qt::AlignRight | Qt::AlignVCenter, QChar(0xf0d9));
            }
        }
    }



    //icon
    if(!parent)
    {
        QFont font = QtAwesome::getInstance()->font(25);

        QRect iconRect = optionRect;

        iconRect.setY(y+5);
        iconRect.setHeight(30);
        painter->setFont(font);
        painter->setPen(this->triangleColor);

        //采用图形字体中的三角形绘制

        painter->drawText(iconRect, Qt::AlignCenter ,QChar(0xf108));

    }


    //绘制文字,如果文字为空则不绘制
    QString text = index.data(Qt::DisplayRole).toString();
    if (!text.isEmpty())
    {
        //文字离左边的距离+字体大小
        int margin = this->parentMargin;
        if (!parent)
        {
            margin = this->childMargin;
            fontSize = this->childFontSize;
        }

        //计算文字区域
        QRect textRect = optionRect;
        textRect.setWidth(width);
        textRect.setX(x);
        if(!parent)
            textRect.setY(y + 30);

        QFont font;
        font.setPixelSize(fontSize);
        painter->setFont(font);
        painter->setPen(textColor);
        painter->drawText(textRect, Qt::AlignCenter, text);
    }


    //计算绘制图标区域
    QRect iconRect = optionRect;
    iconRect.setLeft(this->parentIconMargin);

    //设置图形字体和画笔颜色
    QFont font = QtAwesome::getInstance()->font(fontSize);
    painter->setFont(font);
    painter->setPen(textColor);

    //绘制左侧图标,有图标则绘制图标,没有的话父窗体取 + -

    if (parent)
    {
        if (!index.data(NodeListModel::IsExpanded).toBool())
        {
            painter->drawText(iconRect, Qt::AlignLeft | Qt::AlignVCenter, QChar(0xf067));
        }
        else
        {
            painter->drawText(iconRect, Qt::AlignLeft | Qt::AlignVCenter, QChar(0xf068));
        }
    }



}
