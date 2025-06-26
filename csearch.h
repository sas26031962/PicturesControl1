#ifndef CSEARCH_H
#define CSEARCH_H

#include <QObject>
#include <QString>
#include <QDebug>
//#include <QImage>
//#include <QPainter>
#include <QListWidget>

#include "cinifile.h"

class cSearch : public QObject
{
    Q_OBJECT

    //Атрибуты
    QListWidget * ListWidgetFounded;

public:
    //Конструктор
    explicit cSearch(QObject *parent = 0);

    //Методы
    void install(QListWidget * other);


signals:
    void showExecStatus(QString s);
    void showCurrentIndexPicture();

public slots:
    void execListWidgetFoundedItemClicked();
};

#endif // CSEARCH_H
