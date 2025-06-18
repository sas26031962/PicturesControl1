#include "cnavigation.h"

cNavigation::cNavigation(QObject *parent) : QObject(parent)
{

}

void cNavigation::appEndItem(QListWidgetItem * item)
{
    ListWidget->addItem(item);
    ListWidget->setCurrentItem(item);
    ListWidget->scrollToItem(item);
}

void cNavigation::install(QListWidget* list_widget, QTableView *table_view)
{
    ListWidget = list_widget;
    TableView = table_view;
}

void cNavigation::showCurrentIndexPicture()
{

    //ListWidget->clear();

    int iGroupsCount = cIniFile::Groups->count();

    QListWidgetItem * item0 = new QListWidgetItem("==ShowCurrentIndexPicture==");
    item0->setForeground(Qt::blue);
    ListWidget->addItem(item0);
    QListWidgetItem * item1 = new QListWidgetItem("GroupsCount=" + QString::number(iGroupsCount));
    appEndItem(item1);

    if(iGroupsCount > 0)
    {
        // Читаем значения из INI-файла
        QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
        int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        if(index > (cIniFile::Groups->count() - 1))
        {
            QListWidgetItem * item = new QListWidgetItem("Index > GroupsCount. Index=" + QString::number(index) + " Set Index to head of GroupsList");
            item->setForeground(Qt::red);
            appEndItem(item);

            index = 0;
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

        }

        QString qsGroupName = cIniFile::Groups->at(index);

        //Пропускаем RecordList
        if(qsGroupName == "RecordList")
        {
            index++;
            if(index > (iGroupsCount - 1))index = iGroupsCount - 1;//20250426
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);
            qsGroupName = cIniFile::Groups->at(index);

            QListWidgetItem * item = new QListWidgetItem("Skip 'RecordList' group");
            item->setForeground(Qt::yellow);
            appEndItem(item);
        }

        QListWidgetItem * item = new QListWidgetItem("Index=" + QString::number(index));
        appEndItem(item);
        settings.beginGroup(qsGroupName);

        QString qsPath, qsName, qsError;

        QStringList keys = settings.childKeys();
        int iStrings = keys.count();

        QListWidgetItem * item1 = new QListWidgetItem("GroupName=" + qsGroupName + " KeysCount=" + QString::number(iStrings));
        appEndItem(item1);

        QStandardItemModel * model= new QStandardItemModel(iStrings, 2);
        QListIterator<QString> readIt(keys);
        int iIndex = 0;
        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            if(key == "path") qsPath = value;
            if(key == "name") qsName = value;
            if(key == "Eror") qsError = value;

            model->setItem(iIndex, 0, new QStandardItem(key));
            model->setItem(iIndex, 1, new QStandardItem(value));
            iIndex++;
        }
        model->setHeaderData(0, Qt::Horizontal, "Key");
        model->setHeaderData(1,Qt::Horizontal,"Value");
        TableView->setModel(model);

        settings.endGroup();
        //===
        if(!qsPath.count() || !qsName.count())
        {
            QListWidgetItem * item = new QListWidgetItem("FilePaht=" + qsPath + " FileName=" + qsName + " file not exit!!!");
            item->setForeground(Qt::red);
            appEndItem(item);
            return;
        }

        QString imagePath = qsPath + '/' + qsName;

        if(qsError == "true")
        {
            QListWidgetItem * item = new QListWidgetItem("FullPaht=" + imagePath + " Error=" + qsError);
            item->setForeground(Qt::red);
            appEndItem(item);
            return;
        }
        else
        {
            emit draw(imagePath);
        }
        cImportFiles::labelFileNameText = qsName;
        cImportFiles::IslabelFileNameTextChanged = true;

        //Сохранение текущего индекса
        int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        settings.beginGroup("RecordList");
        settings.setValue("index", x);
        settings.endGroup();
        settings.sync();
    }
    else
    {
        QString s = "Groups is empty!";
        QListWidgetItem * item = new QListWidgetItem(s);
        item->setForeground(Qt::yellow);
        appEndItem(item);

        emit showExecStatus(s);
    }

}//End of void cNavigation::showCurrentIndexPicture()

void cNavigation::loadRemovedSectionsList()
{
    cIniFile::qslDeletedSections = cLoadFiles::loadStringListFromFile(cIniFile::filePathRemovedSectionList);

    //ui->listWidgetOther->clear();
    QListWidgetItem * item0 = new QListWidgetItem("==LoadRemovedSectionsList==");
    item0->setForeground(Qt::blue);
    appEndItem(item0);
    QListWidgetItem * item1 = new QListWidgetItem("RemovedSectionsListCount=" + QString::number(cIniFile::qslDeletedSections.count()));
    appEndItem(item1);
    ListWidget->addItems(cIniFile::qslDeletedSections);
    QListWidgetItem * item2 = new QListWidgetItem("=RemovedSectionsList tail=");
    item2->setForeground(Qt::darkGreen);
    appEndItem(item2);

}//End of void cNavigation::loadRemovedSectionsList()
