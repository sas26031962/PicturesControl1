#ifndef CNAVIGATION_H
#define CNAVIGATION_H

#include <QObject>
#include <QListWidget>
#include <QSettings>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QSpinBox>
#include <QProgressBar>

#include "cinifile.h"
#include "cimportfiles.h"

class cNavigation : public QObject
{
    Q_OBJECT
    //Атрибуты

    //Методы
    void appEndItem(QListWidgetItem * item);

public:

    QListWidget * ListWidget;
    QTableView * TableView;
    QSpinBox * SpinBoxIndex;
    QProgressBar * ProgressBarNavigation;

    //Конструкторы
    explicit cNavigation(QObject *parent = 0);

    //Методы
    void install(QListWidget* list_widget, QTableView* table_view, QSpinBox* spin_box, QProgressBar* progress_bar);
    void showCurrentIndexPicture();
    void installNavigation();

signals:
    void draw(QString s);
    void showExecStatus(QString s);

public slots:
    void loadRemovedSectionsList();
    void execActionGotoIndex();
    void execActionSelectImageBegin();
    void execActionSelectImageNext();
    void execActionSelectImagePrevious();
    void execActionSelectImageEnd();

};

#endif // CNAVIGATION_H
