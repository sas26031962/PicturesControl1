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
    ListWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'mp4' detected in " << iCount << " files";
    else
        qDebug() << "No 'mp4' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}//End of void cActionsExec::execActionRemoveMovie()

