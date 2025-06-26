#include "csearch.h"

cSearch::cSearch(QObject *parent) : QObject(parent)
{
    //
}

void cSearch::install(QListWidget * other)
{
    ListWidgetFounded = other;
    connect(ListWidgetFounded, &QListWidget::itemClicked, this, &cSearch::execListWidgetFoundedItemClicked);
}

void cSearch::execListWidgetFoundedItemClicked()
{
    QString s = "execListWidgetFoundedItemClicked()";
    QString value = ListWidgetFounded->currentItem()->text();

    int FoundedIndex = -1;

    if(cIniFile::Groups->contains(value))
    {
        FoundedIndex = cIniFile::Groups->indexOf(value);
    }

    // Модификация индекса
    iCurrentIndexGlobal.store(FoundedIndex, std::memory_order_relaxed);

    // Отобразить картинку
    emit showCurrentIndexPicture();

    s += ": ";
    s += value;
    //---
    emit showExecStatus(s);
    //---
}



//=============================================================================

