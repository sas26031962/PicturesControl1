#ifndef CACTIONLISTWIDGETPLACECUSTOMCONTEXTMENU_H
#define CACTIONLISTWIDGETPLACECUSTOMCONTEXTMENU_H

/*****************************************************************************
 * Класс для работы со списком Places
 *****************************************************************************/

#include <QObject>
#include <QString>
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QDebug>
#include <QMenu>
#include <QFile>
#include <QTextStream>

#include "clistwidgettype.h"
#include "cinifile.h"
#include "cloadfiles.h"


class cActionListWidgetPlaceCustomContextMenu : public QObject
{
    Q_OBJECT
public:

    //Атрибуты
    ListWidgetType lwtListType = ListWidgetType::PLACE_TYPE;//Тип списка для работы с контекстными меню
    QStringList * qslHashTagList;                           //Рабочий список строк

    //Визуальные компоненты
    QListWidget * listWidget;                               //Список строк как визуальная компонента
    QLineEdit * qleAddItem;                                 //Поле для ввода нового значения элемента

    //Конструктор
    explicit cActionListWidgetPlaceCustomContextMenu(QObject *parent = 0);

    //Методы
    void addOrRemovePlaceItemToRecord();
    bool loadHashTagListPlace();
    bool addItemToList();

signals:
    void showExecStatus(QString s);
    void showCurrentIndexPicture();

public slots:
    void execRequest(const QPoint &pos);
    void execListWidgetPlaceItemClicked();
};

#endif // CACTIONLISTWIDGETPLACECUSTOMCONTEXTMENU_H
