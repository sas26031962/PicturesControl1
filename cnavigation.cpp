#include "cnavigation.h"

cNavigation::cNavigation(QObject *parent) : QObject(parent)
{

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
    QListWidgetItem * item = new QListWidgetItem("==ShowCurrentIndexPicture==");
    item->setForeground(Qt::blue);
    ListWidget->addItem(item);
    QListWidgetItem * item1 = new QListWidgetItem("GroupsCount=" + QString::number(iGroupsCount));
    ListWidget->addItem(item1);
    ListWidget->setCurrentItem(item1);
    ListWidget->scrollToItem(item1);

    if(iGroupsCount > 0)
    {
        // Читаем значения из INI-файла
        QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
        int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        if(index > (cIniFile::Groups->count() - 1))
        {
            QListWidgetItem * item = new QListWidgetItem("Index > GroupsCount. Index=" + QString::number(index) + " Set Index to head of GroupsList");
            item->setForeground(Qt::red);
            ListWidget->addItem(item);
            ListWidget->setCurrentItem(item);
            ListWidget->scrollToItem(item);
            //qDebug() << "Loaded index out of range:" << index << " goto head of list";

            index = 0;
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

        }

        QString qsGroupName = cIniFile::Groups->at(index);
        //qDebug() << "showCurrentIndexPicture(): GroupName=" << qsGroupName;

        //Пропускаем RecordList
        if(qsGroupName == "RecordList")
        {
            index++;
            if(index > (iGroupsCount - 1))index = iGroupsCount - 1;//20250426
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);
            qsGroupName = cIniFile::Groups->at(index);

            QListWidgetItem * item = new QListWidgetItem("Skip 'RecordList' group");
            item->setForeground(Qt::yellow);
            ListWidget->addItem(item);
            ListWidget->setCurrentItem(item);
            ListWidget->scrollToItem(item);
        }

        QListWidgetItem * item = new QListWidgetItem("Index=" + QString::number(index));
        ListWidget->addItem(item);
        ListWidget->setCurrentItem(item);
        ListWidget->scrollToItem(item);
        //===
        settings.beginGroup(qsGroupName);

        QString qsPath, qsName, qsError;

        QStringList keys = settings.childKeys();
        int iStrings = keys.count();

        //qDebug() << "showCurrentIndexPicture(): GroupName=" << qsGroupName << " KeysCount=" << iStrings;
        QListWidgetItem * item1 = new QListWidgetItem("GroupName=" + qsGroupName + " KeysCount=" + QString::number(iStrings));
        ListWidget->addItem(item1);
        ListWidget->setCurrentItem(item1);
        ListWidget->scrollToItem(item1);

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
            //qDebug() << "iterator:" << key << " index:" << iIndex;
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
            ListWidget->addItem(item);
            ListWidget->setCurrentItem(item);
            ListWidget->scrollToItem(item);
            //qDebug() << "FilePath=" << qsPath << " FileName=" << qsName << " file not exist!!!";
            return;
        }

        QString imagePath = qsPath + '/' + qsName;

        if(qsError == "true")
        {
            QListWidgetItem * item = new QListWidgetItem("FullPaht=" + imagePath + " Error=" + qsError);
            item->setForeground(Qt::red);
            ListWidget->addItem(item);
            //qDebug() << "FullPath: " << imagePath << " Error:" << qsError;
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
        ListWidget->addItem(item);
        ListWidget->setCurrentItem(item);
        ListWidget->scrollToItem(item);

        emit showExecStatus(s);

    }

}
