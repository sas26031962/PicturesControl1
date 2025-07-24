#ifndef CLISTWIDGETSUBJECT_H
#define CLISTWIDGETSUBJECT_H

/*****************************************************************************
 * Класс для работы со списком Subject
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

class cListWidgetSubject : public QObject
{
    Q_OBJECT
public:

    //Атрибуты
    QString qsFileNameHashTag;                              //Имя файла для записи/чтения списка
    ListWidgetType lwtListType;                             //Тип списка для работы с контекстными меню
    QStringList * qslHashTagList;                           //Рабочий список строк

    //Визуальные компоненты
    QRect qrListWidget;// = QRect(10, 10, 261, 261);
    QListWidget * listWidget;                               //Список строк как визуальная компонента

    QRect qrLineEdit;// = QRect(10, 280, 261, 25);
    QLineEdit * qleAddItem;                                 //Поле для ввода нового значения элемента

    //Конструктор
    explicit cListWidgetSubject(QObject *parent = 0);
    ~cListWidgetSubject();

    //Методы
    void addOrRemovePlaceItemToRecord();
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

#endif // CLISTWIDGETSUBJECT_H
