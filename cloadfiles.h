#ifndef CLOADFILES_H
#define CLOADFILES_H

#include <QSettings>
#include <memory>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QListWidget>

#include "cimportfiles.h"
#include "cinifile.h"

class cLoadFiles
{
    //Атрибуты
    QListWidget * ListWidget;

    //Методы
    void appEndItem(QListWidgetItem * item);

public:
    //Конструкторы
    cLoadFiles();

    //Методы
    void install(QListWidget * other);

    void execLoadFilesSignedIsRotated();
    void execLoadFilesByConditionOrYes(QStringList yes);
    bool searchNamePattern(const QString& pattern);

    static bool saveStringListToFile(const QString& fileName, const QStringList& list);
    static QStringList loadStringListFromFile(const QString& fileName);

};

#endif // CLOADFILES_H
