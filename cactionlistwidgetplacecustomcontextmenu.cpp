#include "cactionlistwidgetplacecustomcontextmenu.h"

cActionListWidgetPlaceCustomContextMenu::cActionListWidgetPlaceCustomContextMenu(QObject *parent) : QObject(parent)
{

}

void cActionListWidgetPlaceCustomContextMenu::execRequest(const QPoint &pos)
{
/*
    QString s = "execWidgetListPlaceCustomContextMenuRequested()";

    //Задание типа меню
    lwtListType = ListWidgetType::PLACE_TYPE;

    //QListWidget * listWidget = ui->listWidgetPlaces;
    QListWidgetItem * item = listWidget->itemAt(pos);
    if(!item)
    {
        s += ": no item selected!";
        //---
        emit execShowExecStatus(s);
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

        AddOrRemovePlaceItemToRecord();
    }

    else if (selectedAction == actionRemoveItemFromList)
    {
        // Обработка второго действия
        qDebug() << "exec actionRemoveItemFromList: item=" << item->text()<< " index of this item=" << index;

        //---Загрузка списка Place

        if(!loadHashTagListPlace())
        {
            qDebug() << "Error: Could not load HashTagListPlace from file: " << cIniFile::filePlaceHashTag;
            return;
        }

        qDebug() << ": loadHashTagListPlace is sucsess";
        //Здесь должна быть проверка на наличие удаляемого значения в списке
        if(qslHashTagList->indexOf(qsItem) > 0)
        {
            qslHashTagList->removeAll(qsItem);
            listWidget->clear();
            listWidget->addItems(*qslHashTagList);

            //Сохранение нового списка Place

            cLoadFiles::saveStringListToFile(cIniFile::filePlaceHashTag, *qslHashTagList);

            //Информационное сообщение
            s += "Removed item: ";
            s += qsItem;
        }
        else
        {
            qDebug() << "Item " << qsItem << "not found in HashTagListPlace";
        }
        //---

    }

    else if (selectedAction == actionInsertItemToList)
    {
        // Обработка третьего действия
        qDebug() << "exec actionInsertItemToList: item=" << ui->lineEditAddIterm->text();
        emit ui->actionInsertPlace->triggered();
    }

    //---
    emit execShowExecStatus(s);
    //---
*/
}
