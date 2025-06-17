#ifndef CNAVIGATION_H
#define CNAVIGATION_H

#include <QObject>
#include <QListWidget>
#include <QSettings>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>

#include "cinifile.h"
#include "cimportfiles.h"

class cNavigation : public QObject
{
    Q_OBJECT
    //Атрибуты
public:

    QListWidget * ListWidget;
    QTableView * TableView;

    //Конструкторы
    explicit cNavigation(QObject *parent = 0);

    //Методы
    void install(QListWidget* list_widget, QTableView* table_view);
    void showCurrentIndexPicture();

signals:
    void draw(QString s);
    void showExecStatus(QString s);

public slots:

};

#endif // CNAVIGATION_H
