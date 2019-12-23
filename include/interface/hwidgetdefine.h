#ifndef HWIDGETDEFINE_H
#define HWIDGETDEFINE_H


#include <QIcon>
#include<QString>
typedef struct HWIDGET_PLU_INFO
{
    QString  pluName;                          //插件名称.
    QIcon    pluIcon;                        //插件图标.
    int      pluType;                       //插件类型
    void    *pluClass;                     //插件界面对象(pulgin).
}hWidget_plu_info;



#endif // HWIDGETDEFINE_H
