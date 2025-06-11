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

void cActionsExec::execActionShowNewFiles(bool x)
{
    QString s = "execActionShowNewFiles()";
    s += QString::number(x);

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    //--- Очистка рабочего списка
    cRecord::RecordList->clear();

    //---Чтение содержимого каталога ---

    if(cRecord::readDirectory(cIniFile::IniFile.getDirectoryPah()) > 0)
    {
        ListWidgetOther->clear();
        ListWidgetOther->addItem("==ActionShowNewFiles==");
        ListWidgetOther->addItem("=DirectoryNotFound=");
        ListWidgetOther->addItem("Path=" + cIniFile::IniFile.getDirectoryPah());
        return;
    }

    //cImportFiles::execSearchNewFiles();
    //---

    ListWidgetOther->clear();
    ListWidgetOther->addItem("==ActionShowNewFiles==");

    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList Groups = settings.childGroups();//Загрузка полного списка групп

    ListWidgetOther->addItem("AllGroupsListCount=" + QString::number(Groups.count()));

    QStringList slNewItems;
    slNewItems.clear();

    int iAddedFilesCounter = 0;
    int iSkippedFilesCounter = 0;

    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        const cRecord rec = *it;

        QString name = rec.qsName;
        int iDotPosition = name.indexOf('.');
        QString groupName = name.mid(0, iDotPosition);

        QString path = rec.qsPath;
        int iNamePosition = path.indexOf(name);
        QString PathWithoutName = path.mid(0, iNamePosition - 1);

        int iExtensionPosition = path.indexOf('.');
        QString qsExtension = path.mid(iExtensionPosition + 1);

        //Добавление записи в конфигурационный файл, если её там нет
        if(!Groups.contains(groupName))
        {
            //qDebug() << "###Add section:" << groupName << " Path+FileName=" << path;
            slNewItems.append(path);
            iAddedFilesCounter++;

        }
        else
        {
            iSkippedFilesCounter++;

            //qDebug() << "Skip existing section:" << groupName;
        }

    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)

    ListWidgetOther->addItem("AddedFilesCount=" + QString::number(iAddedFilesCounter));
    ListWidgetOther->addItem("SkipedFilesCount=" + QString::number(iSkippedFilesCounter));
    //qDebug() << "Result: added files counter=" << iAddedFilesCounter <<" skiped files couner=" << iSkippedFilesCounter;

    //Store data in file
    if(iAddedFilesCounter > 0)
    {
        if(cLoadFiles::saveStringListToFile(cIniFile::fileNewItems, slNewItems))
        {
             //qDebug() << "New items list stored in file:" << cIniFile::fileNewItems;
             ListWidgetOther->addItem("New items list stored in file:" + cIniFile::fileNewItems);
        }
        else
        {
            //qDebug() << "Store in file:" << cIniFile::fileNewItems << " process error";
            ListWidgetOther->addItem("NStore in file:" + cIniFile::fileNewItems + " process error");
        }
    }
    else
    {
        ListWidgetOther->addItem("=New items not founded=");
        //qDebug() << "New items not founded";
    }



    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================


