#ifndef CSEARCH_H
#define CSEARCH_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QListWidget>

#include "cinifile.h"
#include "cloadfiles.h"

class cSearch : public QObject
{
    Q_OBJECT

    //Атрибуты
    QListWidget * ListWidgetFounded;
    QListWidget * ListWidgetOther;

    //Методы
    void execLoadFilesSignedIsRotated();

public:
    //Конструктор
    explicit cSearch(QObject *parent = 0);

    //Методы
    void install(QListWidget * founded, QListWidget * other);
    void showGroupsList();
    bool searchNamePattern(const QString& pattern);
    void execLoadFilesByConditionOrYes(QStringList yes);
    void execLoadFilesByConditionYesYes(QStringList yes);
    bool searchFreshRecords();


signals:
    void showExecStatus(QString s);
    void showCurrentIndexPicture();
    void gotoInstallNavigation();

public slots:
    void execListWidgetFoundedItemClicked();

    void execActionSearchRotated();
    void execActionSearchYesYes();
    void execActionSearchOrYes();
    void execActionSearchFreshRecords();

};

#endif // CSEARCH_H
