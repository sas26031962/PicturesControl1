#include "csearch.h"

cSearch::cSearch(QObject *parent) : QObject(parent)
{
    //
}

void cSearch::install(QListWidget * founded, QListWidget *other)
{
    ListWidgetFounded = founded;
    ListWidgetOther = other;
    connect(ListWidgetFounded, &QListWidget::itemClicked, this, &cSearch::execListWidgetFoundedItemClicked);
}

//=============================================================================

//
// Отобразить содержимое списка cIniFile::Groups в элементе ui->listWidgetFounded
//
void cSearch::showGroupsList()
{
    ListWidgetFounded->clear();
    QListIterator<QString> readIt(*cIniFile::Groups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        ListWidgetFounded->addItem(qsSection);
    }
}

//=============================================================================

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

bool cSearch::searchNamePattern(const QString& pattern)
{
    QRegularExpression re(pattern);

    QListWidgetItem * item0 = new QListWidgetItem("==execSearchByNamePattern==");
    item0->setForeground(Qt::blue);
    ListWidgetOther->addItem(item0);

    QListWidgetItem * item1 = new QListWidgetItem("<Pattern>=" + pattern);
    ListWidgetOther->addItem(item1);

    //qDebug() << "Search pattern:" << pattern;

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла

    QStringList TotalGroups = settings.childGroups();//Загрузка полного списка групп

    QListWidgetItem * item2 = new QListWidgetItem("TotalGroups length: " + QString::number(TotalGroups.count()));
    ListWidgetOther->addItem(item2);

    cIniFile::Groups->clear();//Очистка результата

    int iCount = 0;// Очистка счётчика найденных объектов
    QListIterator<QString> readIt(TotalGroups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        bool match = re.match(qsSection.toLower()).hasMatch();
        if(match)
        {
            iCount++;
            cIniFile::Groups->append(qsSection);
            //qDebug() << "iterator: section=" << qsSection << " contain pattern:" << pattern << " count=" << iCount;
        }
    }

    QString qsItem3;
    if(iCount > 0)
    {
        qsItem3 = "<Pattern> in file names detected in ";
        qsItem3 += QString::number(iCount);
        qsItem3 += " files";
    }
    else
    {
        qsItem3 = "No <Pattern> in file names detected";
    }

    QListWidgetItem * item3 = new QListWidgetItem(qsItem3);
    ListWidgetOther->addItem(item3);

    //---
    bool x = cLoadFiles::saveStringListToFile(cIniFile::pattern1StringListFilePath, *cIniFile::Groups);
    //---
    return x;
}

//=============================================================================

