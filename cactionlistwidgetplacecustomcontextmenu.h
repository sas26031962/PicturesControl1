#ifndef CACTIONLISTWIDGETPLACECUSTOMCONTEXTMENU_H
#define CACTIONLISTWIDGETPLACECUSTOMCONTEXTMENU_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>

#include "cinifile.h"
#include "cloadfiles.h"

//-----------------------------------------------------------------------------
// ТИПЫ ДАННЫХ
//-----------------------------------------------------------------------------

enum class ListWidgetType{
    SUBJECT_TYPE,
    PLACE_TYPE,
    PROPERTY_TYPE,
    THEAME_TYPE
};


class cActionListWidgetPlaceCustomContextMenu : public QObject
{
    Q_OBJECT
public:

    //Тип списка для работы с кнотекстными меню

    ListWidgetType lwtListType = ListWidgetType::PLACE_TYPE;
    QListWidget * listWidget;
    QStringList * qslHashTagList;


    explicit cActionListWidgetPlaceCustomContextMenu(QObject *parent = 0);

signals:
    void execShowExecStatus(QString s);

public slots:
    void execRequest(const QPoint &pos);
};

#endif // CACTIONLISTWIDGETPLACECUSTOMCONTEXTMENU_H
