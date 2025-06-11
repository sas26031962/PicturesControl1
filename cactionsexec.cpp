#include "cactionsexec.h"

cActionsExec::cActionsExec(QObject *parent) : QObject(parent)
{
    qslDeletedSections.clear();
}

void cActionsExec::install(QListWidget * other)
{
    ListWidgetOther = other;
}

void cActionsExec::execActionRemoveMovie(bool x)
{
    QString s = "ActionRemoveMovie()";
    s += QString::number(x);

    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        //---
        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".mp4") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;

                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ListWidgetOther->clear();
            ListWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }
        //---
    }//End of while (readIt.hasNext())
    // Выводим имена обрабатываемых файлов
    ListWidgetOther->clear();
    ListWidgetOther->addItem("==ActionRemoveMovie==");
    ListWidgetOther->addItem("=RemovedItemsList=");
    ListWidgetOther->addItem("RemovedItemsCount=" + QString::number(GroupsResult.count()));
    ListWidgetOther->addItems(GroupsResult);

    //===
    emit execShowExecStatus(s);
   //===

}//End of void cActionsExec::execActionRemoveMovie()

//=============================================================================

void cActionsExec::execActionRemoveText(bool x)
{
    QString s = "ActionRemoveText()";
    s += QString::number(x);
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".txt") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;

            //--- Удаление ключей секции: начало ---
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
            //--- Удаление ключей секции: конец ---
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            qslDeletedSections.append(qsWay);//#@
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ListWidgetOther->clear();
    ListWidgetOther->addItem("==ActionRemoveText==");
    ListWidgetOther->addItem("=RemovedItemsList=");
    ListWidgetOther->addItem("RemovedItemsCount=" + QString::number(GroupsResult.count()));
    ListWidgetOther->addItems(GroupsResult);

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void cActionsExec::execActionRemoveTif(bool x)
{

    QString s = "ActionRemoveTif()";
    s += QString::number(x);
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".tif") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ListWidgetOther->clear();
    ListWidgetOther->addItem("==ActionRemoveTif==");
    ListWidgetOther->addItem("=RemovedItemsList=");
    ListWidgetOther->addItem("RemovedItemsCount=" + QString::number(GroupsResult.count()));
    ListWidgetOther->addItems(GroupsResult);

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void cActionsExec::execActionRemoveBin(bool x)
{

    QString s = "ActionRemoveBin()";
    s += QString::number(x);
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".bin") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ListWidgetOther->clear();
    ListWidgetOther->addItem("==ActionRemoveBin==");
    ListWidgetOther->addItem("=RemovedItemsList=");
    ListWidgetOther->addItem("RemovedItemsCount=" + QString::number(GroupsResult.count()));
    ListWidgetOther->addItems(GroupsResult);

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void cActionsExec::execActionRemove3gp(bool x)
{
    QString s = "ActionRemove3gp()";
    s += QString::number(x);
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".3gp") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ListWidgetOther->clear();
    ListWidgetOther->addItem("==ActionRemove3gp==");
    ListWidgetOther->addItem("=RemovedItemsList=");
    ListWidgetOther->addItem("RemovedItemsCount=" + QString::number(GroupsResult.count()));
    ListWidgetOther->addItems(GroupsResult);

}

//=============================================================================


