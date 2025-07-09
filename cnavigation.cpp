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

void cNavigation::execNavigationCurrentIndex()
{
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);

    // Отобразить картинку
    execShowCurrentIndexPicture();

    ProgressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);

}

void cNavigation::install(QListWidget* list_widget,
    QTableView *table_view,
    QGroupBox *box
    )
{
    int iMaxHeight = 23;
    int iMaxButtonNavigationWidth = 23;
    int iMaxButtonActionWidth = 55;
    QString qsLabelStyle = "background-color: rgb(244, 255, 255);";

    Parent = box;
    QVBoxLayout * layout = new QVBoxLayout(Parent);

    lbRow0 = new QLabel();
    lbRow0->setMaximumHeight(iMaxHeight + 4);
    lbRow0->setStyleSheet("");

    lbRow1 = new QLabel();
    lbRow1->setMaximumHeight(iMaxHeight + 4);
    lbRow1->setStyleSheet("");

    lbRow2 = new QLabel();
    lbRow2->setMaximumHeight(iMaxHeight + 4);
    lbRow2->setStyleSheet("");


    layout->addWidget(lbRow0,0);
    layout->addWidget(lbRow1,1);
    layout->addWidget(lbRow2,2);

    pbBegin = new QPushButton();
    pbBegin->setMaximumHeight(iMaxHeight);
    pbBegin->setMaximumWidth(iMaxButtonNavigationWidth);
    pbBegin->setText("|<");

    pbPrevious = new QPushButton();
    pbPrevious->setMaximumHeight(iMaxHeight);
    pbPrevious->setMaximumWidth(iMaxButtonNavigationWidth);
    pbPrevious->setText("<");

    pbNext = new QPushButton();
    pbNext->setMaximumHeight(iMaxHeight);
    pbNext->setMaximumWidth(iMaxButtonNavigationWidth);
    pbNext->setText(">");

    pbEnd = new QPushButton();
    pbEnd->setMaximumHeight(iMaxHeight);
    pbEnd->setMaximumWidth(iMaxButtonNavigationWidth);
    pbEnd->setText(">|");

    ProgressBarNavigation = new QProgressBar();
    ProgressBarNavigation->setMaximumHeight(iMaxHeight);

    QHBoxLayout *layout0 = new QHBoxLayout(lbRow0);
    layout0->setContentsMargins(1,1,1,1);

    layout0->addWidget(pbBegin);
    layout0->addWidget(pbPrevious);
    layout0->addWidget(pbNext);
    layout0->addWidget(pbEnd);
    layout0->addWidget(ProgressBarNavigation);

    QHBoxLayout *layout1 = new QHBoxLayout(lbRow1);
    layout1->setContentsMargins(1,1,1,1);

    pbGoTo = new QPushButton();
    pbGoTo->setMaximumHeight(iMaxHeight);
    pbGoTo->setMaximumWidth(iMaxButtonActionWidth);
    pbGoTo->setText("Go to");

    pbRemove = new QPushButton();
    pbRemove->setMaximumHeight(iMaxHeight);
    pbRemove->setMaximumWidth(iMaxButtonActionWidth);
    pbRemove->setText("Remove");

    SpinBoxIndex = new QSpinBox();
    SpinBoxIndex->setMaximumHeight(iMaxHeight);

    pbErase = new QPushButton();
    pbErase->setMaximumHeight(iMaxHeight);
    pbErase->setMaximumWidth(iMaxButtonActionWidth);
    pbErase->setText("Erase");

    layout1->addWidget(pbGoTo);
    layout1->addWidget(SpinBoxIndex);
    layout1->addWidget(pbRemove);
    layout1->addWidget(pbErase);

    pbReload = new QPushButton();
    pbReload->setMaximumHeight(iMaxHeight);
    pbReload->setMaximumWidth(iMaxButtonActionWidth);
    pbReload->setText("Reload");

    QHBoxLayout *layout2 = new QHBoxLayout(lbRow2);
    layout2->setContentsMargins(1,1,1,1);
    layout2->addWidget(pbReload);

    ListWidget = list_widget;
    TableView = table_view;

    connect(pbGoTo, SIGNAL(pressed()), this, SLOT( execActionGotoIndex()));//***
    connect(pbBegin, SIGNAL(pressed()), this, SLOT( execActionSelectImageBegin()));//***
    connect(pbNext, SIGNAL(pressed()), this, SLOT( execActionSelectImageNext()));//***
    connect(pbPrevious, SIGNAL(pressed()), this, SLOT( execActionSelectImagePrevious()));//***
    connect(pbEnd, SIGNAL(pressed()), this, SLOT( execActionSelectImageEnd()));//***

}

void cNavigation::execShowCurrentIndexPicture()
{

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

        //Очистка средства отображения
        ProgressBarNavigation->setMaximum(DEFAULT_MAXIMUM_VAULE);
        ProgressBarNavigation->setValue(0);

        SpinBoxIndex->setMaximum(DEFAULT_MAXIMUM_VAULE);
        SpinBoxIndex->setValue(0);

        emit showExecStatus(s);
    }

}//End of void cNavigation::showCurrentIndexPicture()

void cNavigation::loadRemovedSectionsList()
{
    cIniFile::qslDeletedSections = cLoadFiles::loadStringListFromFile(cIniFile::filePathRemovedSectionList);

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

//=============================================================================

void cNavigation::execActionGotoIndex()
{

    int index = SpinBoxIndex->value();

    // Модификация индекса
    iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

    execNavigationCurrentIndex();
/*
    // Отобразить картинку
    execShowCurrentIndexPicture();

    ProgressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
*/
    //---
    QString s = "execActionGotoIndex(), goto index:";
    s += QString::number(index);
    emit showExecStatus(s);
    //---

}

//=============================================================================

void cNavigation::execActionSelectImageBegin()
{
    // Модификация индекса
    iCurrentIndexGlobal.store(0, std::memory_order_relaxed);

    execNavigationCurrentIndex();
/*
    // Отобразить картинку
    execShowCurrentIndexPicture();

    ProgressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
*/
    //---
    QString s = "execActionSelectImageBegin()";
    emit showExecStatus(s);
    //---

}//End of void MainWindow::execActionSelectImageBegin()


//=============================================================================

void cNavigation::execActionSelectImageNext()
{
    // Модификация индекса
    if(iCurrentIndexGlobal.load(std::memory_order_relaxed) < cIniFile::Groups->count() - 1)
    {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);
    }

    execNavigationCurrentIndex();
/*
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);

    // Отобразить картинку
    execShowCurrentIndexPicture();

    ProgressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
*/
    //---
    QString s = "execActionSelectImageNext()";
    emit showExecStatus(s);
    //---

}

//=============================================================================

void cNavigation::execActionSelectImagePrevious()
{
    // Модификация индекса
    if(iCurrentIndexGlobal.load(std::memory_order_relaxed) > 0)
    {
        iCurrentIndexGlobal.fetch_sub(1, std::memory_order_relaxed);
    }

    execNavigationCurrentIndex();
/*
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);

    // Отобразить картинку
    execShowCurrentIndexPicture();

    ProgressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
*/
    //---
    QString s = "execActionSelectImagePrevious()";
    emit showExecStatus(s);
    //---

}

//=============================================================================

void cNavigation::execActionSelectImageEnd()
{
    int index = cIniFile::Groups->count();
    if(index > 0)
    {
        index--;

        // Модификация индекса
        iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

        execNavigationCurrentIndex();
/*
        // Отобразить картинку
        execShowCurrentIndexPicture();

        ProgressBarNavigation->setValue(index);
        SpinBoxIndex->setValue(index);
*/
        qDebug() << "execActionSelectImageEnd(): SpinBoxMaxIndex=" << SpinBoxIndex->maximum();
    }
    else
    {
        //Очистка средства отображения
        ProgressBarNavigation->setMaximum(DEFAULT_MAXIMUM_VAULE);
        ProgressBarNavigation->setValue(0);

        SpinBoxIndex->setMaximum(DEFAULT_MAXIMUM_VAULE);
        SpinBoxIndex->setValue(0);

        qDebug() << "execActionSelectImageEnd(): index=" << index;
    }

    //---
    QString s = "execActionSelectImageEnd(), goto index";
    s += QString::number(index);
    emit showExecStatus(s);
    //---

}

//=============================================================================

void cNavigation::installNavigation()
{
    iCurrentIndexGlobal.store(0, std::memory_order_relaxed);

    //Настройка навигации
    cImportFiles::MaxIndexValue = cIniFile::Groups->count();

    // Установка текущего индекса
    iCurrentIndexGlobal.store(0);

    // Установка навигации
    ProgressBarNavigation->setRange(0, cImportFiles::MaxIndexValue);
    ProgressBarNavigation->setValue(0);

    SpinBoxIndex->setRange(0, cImportFiles::MaxIndexValue);
    SpinBoxIndex->setValue(0);

    // Переход к начальному индексу
    execActionSelectImageBegin();

}

//=============================================================================



