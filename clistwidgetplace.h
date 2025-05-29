#ifndef CLISTWIDGETPLACE_H
#define CLISTWIDGETPLACE_H

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

class cListWidgetPlace : public QObject
{
    Q_OBJECT
public:

    //Атрибуты
    ListWidgetType lwtListType = ListWidgetType::PLACE_TYPE;//Тип списка для работы с контекстными меню
    QStringList * qslHashTagList;                           //Рабочий список строк

    //Визуальные компоненты
    QRect qrListWidget;// = QRect(10, 10, 261, 261);
    QListWidget * listWidget;                               //Список строк как визуальная компонента

    QRect qrLineEdit;// = QRect(10, 280, 261, 25);
    QLineEdit * qleAddItem;                                 //Поле для ввода нового значения элемента

    //Конструктор
    explicit cListWidgetPlace(QObject *parent = 0);
    ~cListWidgetPlace();

    //Методы
    void addOrRemoveItemToRecord();
    bool loadHashTagList();
    bool addItemToList();
    void install(QWidget * qwidget);

signals:
    void showExecStatus(QString s);
    void showCurrentIndexPicture();

public slots:
    void execRequest(const QPoint &pos);
    void execListWidgetItemClicked();
};

#endif // CLISTWIDGETPLACE_H
