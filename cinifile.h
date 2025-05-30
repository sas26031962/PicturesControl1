#ifndef CINIFILE_H
#define CINIFILE_H

#include <QString>
#include <QSettings>
#include <QDebug>
#include <QImage>
#include <atomic>
#include <memory>

#include "crecord.h"

/******************************************************************************
 * === Выбор вариантов работы осуществляется автоматически
 * по типу операционной системы
 * ===
 *****************************************************************************/

#define WINDOWS_SYSTEM_TYPE 1
#define LINUX_SYSTEM_TYPE 2

//-----------------------------------------------------------------------------
//Глобальные переменные
//-----------------------------------------------------------------------------

extern std::atomic<int> iCurrentIndexGlobal;

class cIniFile
{
private:
    QString directoryPath;
public:
    //Атрибуты
    static QStringList * Groups;
    static QStringList * Keys;
    static QStringList * SearchKeys;
    static QStringList * currentGroups;

    static QString iniFilePath;
    static QString rotatedImagePath;
    static QString scaledImagePath;
    static QString currentImagePath;
    static QString currentRotatedImagePath;

    static QString filePathRemovedSectionList;
    static QString fileSubjectHashTag;
    static QString filePlaceHashTag;
    static QString filePropertyHashTag;
    static QString fileTheameHashTag;


    static QString pattern1StringListFilePath;
    static QString pattern2StringListFilePath;
    static QString patternXStringListFilePath;

    static cIniFile IniFile;
    static int iSystemType;


    int iRecordListLength = 0;  //Полное число записей

    //Конструктор
    cIniFile(QString sourcePath);

    //Методы
    QString getDirectoryPah();
    void setDirectoryPaht(QString sourcePath);

    void addInitalSection(int n);
    void addRecordListData();

    static void getCurrentImagePath();
    static int getCurrentIndex();

};

#endif // CINIFILE_H
