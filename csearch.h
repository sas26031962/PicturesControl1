#ifndef CSEARCH_H
#define CSEARCH_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QListWidget>
#include <QLineEdit>
#include <QListWidgetItem>

#include "cinifile.h"
#include "cloadfiles.h"

class cSearch : public QObject
{
    Q_OBJECT

    //Атрибуты
    QListWidget * ListWidgetFounded;
    QListWidget * ListWidgetOther;
    QLineEdit * LineEditPattern;

    QString qsFoundedDelimiter;

    //Методы
    void execLoadFilesSignedIsRotated();
    void appEndItem(QListWidgetItem * item);


public:
    //Конструктор
    explicit cSearch(QObject *parent = 0);

    //Методы
    void install(QListWidget * founded, QListWidget * other, QLineEdit * pattern);
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
    void execActionSearchNamePattern1();
    void execActionSearchNamePattern2();
    void execActionSearchNamePattern();
    void execActionSearchNamePatterns12Intersection();
    void execActionSearchNamePatterns1XIntersection();

};

#endif // CSEARCH_H
