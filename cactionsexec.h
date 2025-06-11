#ifndef CACTIONSEXEC_H
#define CACTIONSEXEC_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QListWidget>

#include "cinifile.h"
#include "cimportfiles.h"

class cActionsExec : public QObject
{
    Q_OBJECT
public:
    //Атрибуты
    QListWidget * ListWidgetOther;
    QStringList qslDeletedSections;

    //Конструкторы
    explicit cActionsExec(QObject *parent = 0);

    //Методы
    void install(QListWidget * other);

signals:
    void execShowExecStatus(QString s);

public slots:
    void execActionRemoveMovie(bool x);
    void execActionRemoveText(bool x);
    void execActionRemoveTif(bool x);
    void execActionRemoveBin(bool x);
    void execActionRemove3gp(bool x);
    void execActionShowNewFiles(bool x);

};//End of class cActionsExec : public QObject

#endif // CACTIONSEXEC_H
