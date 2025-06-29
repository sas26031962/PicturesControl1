#ifndef CSEARCH_H
#define CSEARCH_H

#include <QObject>
#include <QString>
#include <QDebug>
//#include <QImage>
//#include <QPainter>
#include <QListWidget>

#include "cinifile.h"
#include "cloadfiles.h"

class cSearch : public QObject
{
    Q_OBJECT

    //Атрибуты
    QListWidget * ListWidgetFounded;
    QListWidget * ListWidgetOther;

public:
    //Конструктор
    explicit cSearch(QObject *parent = 0);

    //Методы
    void install(QListWidget * founded, QListWidget * other);
    void showGroupsList();
    bool searchNamePattern(const QString& pattern);
    void execLoadFilesByConditionOrYes(QStringList yes);
    bool searchFreshRecords();

signals:
    void showExecStatus(QString s);
    void showCurrentIndexPicture();

public slots:
    void execListWidgetFoundedItemClicked();
};

#endif // CSEARCH_H
