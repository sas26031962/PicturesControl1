#include "clistwidgettheame.h"

cListWidgetTheame::cListWidgetTheame(QObject *parent) : QObject(parent)
{
    qslHashTagList = new QStringList;
}

cListWidgetTheame::~cListWidgetTheame()
{
    delete qslHashTagList;
    delete listWidget;
    delete qleAddItem;
}

void cListWidgetTheame::install(QWidget * qwidget)
{
    QRect qrListWidget = QRect(10, 10, 261, 261);
    listWidget = new QListWidget(qwidget);
    listWidget->setGeometry(qrListWidget);

    QRect qrLineEdit = QRect(10, 280, 261, 25);
    qleAddItem = new QLineEdit(qwidget);
    qleAddItem->setGeometry(qrLineEdit);

    //Очистка визуального списка
    listWidget->clear();
    //Загрузка списка хеш-тегов Theame
    if(loadHashTagList())
    {
        listWidget->addItems(*qslHashTagList);

        // Настройка контекстного меню
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(listWidget, &QListWidget::customContextMenuRequested, this, &cListWidgetTheame::execRequest);
        connect(listWidget, &QListWidget::itemClicked, this, &cListWidgetTheame::execListWidgetItemClicked);
    }
}

void cListWidgetTheame::execRequest(const QPoint &pos)
{

    QString s = "execWidgetListTheameCustomContextMenuRequested()";

    //Задание типа меню
    lwtListType = ListWidgetType::THEAME_TYPE;

    QListWidgetItem * item = listWidget->itemAt(pos);
    if(!item)
    {
        s += ": no item selected!";
        //---
        emit showExecStatus(s);
        //---
        return;
    }

    int index = listWidget->row(item);
    QString qsItem = item->text();

    QMenu contextMenu;
    QAction *actionAddOrRemoveItemToRecord = contextMenu.addAction("Добавить(удалить) элемент в запись");
    QAction *actionRemoveItemFromList = contextMenu.addAction("Удалить элемент из списка");
    QAction *actionInsertItemToList = contextMenu.addAction("Добавить элемент в список");

    QAction *selectedAction = contextMenu.exec(listWidget->viewport()->mapToGlobal(pos));

    if (selectedAction == actionAddOrRemoveItemToRecord)
    {
        // Обработка первого действия
        qDebug() << "exec actionAddOrRemoveItemToRecord: item=" << item->text()<< " index of this item=" << index;

        addOrRemovePlaceItemToRecord();
    }

    else if (selectedAction == actionRemoveItemFromList)
    {
        // Обработка второго действия
        qDebug() << "exec actionRemoveItemFromList: item=" << item->text()<< " index of this item=" << index;

        //---Загрузка списка Theame

        if(!loadHashTagList())
        {
            qDebug() << "Error: Could not load HashTagListTheame from file: " << cIniFile::fileTheameHashTag;
            return;
        }

        qDebug() << ": loadHashTagListTheame is sucsess#";
        //Здесь должна быть проверка на наличие удаляемого значения в списке
        if(qslHashTagList->indexOf(qsItem) > 0)
        {
            qslHashTagList->removeAll(qsItem);
            listWidget->clear();
            listWidget->addItems(*qslHashTagList);

            //Сохранение нового списка Theame

            cLoadFiles::saveStringListToFile(cIniFile::fileTheameHashTag, *qslHashTagList);

            //Информационное сообщение
            s += "Removed item: ";
            s += qsItem;
        }
        else
        {
            qDebug() << "Item " << qsItem << "not found in HashTagListTheame";
        }
        //---

    }

    else if (selectedAction == actionInsertItemToList)
    {
        // Обработка третьего действия
        qDebug() << "exec actionInsertItemToList: item=" << qleAddItem->text();
        addItemToList();
    }

    //---
    emit showExecStatus(s);
    //---

}

void cListWidgetTheame::addOrRemovePlaceItemToRecord()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execTheameItemClicked()";
    QString item = listWidget->currentItem()->text();
    qDebug() << "listWidgetTheame: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        settings.beginGroup(qsGroupName);
        QStringList list = settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            settings.setValue(item, "true");
        }
        settings.endGroup();
        settings.sync();
    }
    else
    {
        s = "List is empty, exec Load function!!!";
    }
    // Отобразить картинку
    emit showCurrentIndexPicture();

    //---
    emit showExecStatus(s);
    //---
}

bool cListWidgetTheame::loadHashTagList()
{

    QFile file(cIniFile::fileTheameHashTag);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << cIniFile::fileTheameHashTag;
        return false;
    }

    QTextStream in(&file);
    if(cIniFile::iSystemType == WINDOWS_SYSTEM_TYPE)
    {
        in.setCodec("Windows-1251");
        qDebug() << "Select Windows-1251 codec in loading case";
    }

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

bool cListWidgetTheame::addItemToList()
{
    QString s = "execActionInsertTheame()";

    QString qsGoal = qleAddItem->text();

    if(qsGoal.length() <= 0)
    {
        //Информационное сообщение
        s += ": Empty string, nothing to do!";
        s += qsGoal;

        //---
        emit showExecStatus(s);
        //---

        return false;
    }

    //---Загрузка списка Theame

    if(!loadHashTagList())
    {
        qDebug() << "Error: Could not load HashTagListTheame from file: " << cIniFile::fileTheameHashTag;
        return false;
    }

    qDebug() << ": loadHashTagListTheame is sucsess";

    //Здесь должна быть проверка на наличие нового значения в списке
    if(qslHashTagList->indexOf(qsGoal) < 0)
    {
        listWidget->clear();
        int iLast = qslHashTagList->count() - 1;
        if(qslHashTagList->at(iLast) == "")
        {
            qslHashTagList->replace(iLast, qsGoal);
        }
        else
        {
            qslHashTagList->append(qsGoal);
        }
        listWidget->addItems(*qslHashTagList);

        //Сохранение нового списка Theame

        cLoadFiles::saveStringListToFile(cIniFile::fileTheameHashTag, *qslHashTagList);

        //Информационное сообщение
        s += ": ";
        s += qsGoal;
    }
    else
    {
        //Информационное сообщение
        s += ": HashTagListTheame already contain ";
        s += qsGoal;
    }

    //---
    emit showExecStatus(s);
    //---
    return true;
}

void cListWidgetTheame::execListWidgetItemClicked()
{
    QString s = "Use RightMouseButton to Add / Remove item to record";
    //---
    emit showExecStatus(s);
    //---
}



