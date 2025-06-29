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

bool cSearch::searchFreshRecords()
{
    QListWidgetItem * item0 = new QListWidgetItem("==execSearchFreshRecords==");
    item0->setForeground(Qt::blue);
    ListWidgetOther->addItem(item0);

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла

    QStringList TotalGroups = settings.childGroups();//Загрузка полного списка групп

    QListWidgetItem * item1 = new QListWidgetItem("TotalGroups length: " + QString::number(TotalGroups.count()));
    ListWidgetOther->addItem(item1);

    cIniFile::Groups->clear();//Очистка результата

    int iCountYes = 0;// Очистка счётчика найденных объектов
    int iCountNo = 0;
    QListIterator<QString> readIt(TotalGroups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        //Проверка условия
        settings.beginGroup(qsSection);
        QStringList keys = settings.childKeys();
        settings.endGroup();

        bool match = (keys.count() <= 7);//true;

        //Запись результата в список
        if(match)
        {
            iCountYes++;//Подсчёт удачных попыток
            cIniFile::Groups->append(qsSection);
        }
        else
        {
            iCountNo++;//Подсчёт неудачных попыток
        }
    }

    QString qsItem2;
    qsItem2 = "Count NO in ";
    qsItem2 += QString::number(iCountNo);
    qsItem2 += " files";

    QString qsItem3;
    qsItem3 = "Count YES in ";
    qsItem3 += QString::number(iCountYes);
    qsItem3 += " files";

    QListWidgetItem * item2 = new QListWidgetItem(qsItem2);
    ListWidgetOther->addItem(item2);

    QListWidgetItem * item3 = new QListWidgetItem(qsItem3);
    ListWidgetOther->addItem(item3);

    //---
    bool x = cLoadFiles::saveStringListToFile(cIniFile::pattern1StringListFilePath, *cIniFile::Groups);
    //---
    return x;
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

/******************************************************************************
 * Функция выбирает из полного списка файлов те файлы, которые удовлетворяют
 * любому из списка условий, приведённых в списке yes, передаваемому как параметр.
 * Результат работы функции - список cIniFile::Groups
 *****************************************************************************/
void cSearch::execLoadFilesByConditionOrYes(QStringList yes)
{
    //--- Начало функции загрузки

    QListWidgetItem * item0 = new QListWidgetItem("==execLoadFilesByConditionOrYes==");
    item0->setForeground(Qt::blue);
    //item0->setForeground(Qt::yellow);
    ListWidgetOther->addItem(item0);

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла

    QStringList TotalGroups = settings.childGroups();//Загрузка полного списка групп
    cIniFile::Groups->clear();//Очистка результата

    // Выводим значения
    QListWidgetItem * item1 = new QListWidgetItem("TotalGroups length: " + QString::number(TotalGroups.count()));
    ListWidgetOther->addItem(item1);

    int iCount = 0;// Очистка счётчика найденных объектов

    QListIterator<QString> readIt(TotalGroups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        settings.beginGroup(qsSection);
        //===
        QString qsIsRotated;

        QStringList keys = settings.childKeys();
        QListIterator<QString> readIt(keys);

        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            QListIterator<QString> readItYes(yes);

            while (readItYes.hasNext())
            {
                QString key_yes = readItYes.next();
                //qDebug() << "iteratorYes: key=" << key_yes;// << " count=" << iCount;
                QString value_yes = settings.value(key_yes,"0").toString();
                if(key == key_yes)
                {
                    qsIsRotated = value_yes;
                    iCount++;
                    cIniFile::Groups->append(qsSection);
                    //qDebug() << "iterator: section=" << qsSection << " key=" << key << " count=" << iCount;
                }
            }
        }
        //===
        settings.endGroup();
    }

    QString qsItem2;
    if(iCount > 0)
    {
        qsItem2 = "Signed by condition OrYes key detected in ";
        qsItem2 += QString::number(iCount);
        qsItem2 += " files";
    }
    else
    {
        qsItem2 = "No signed by condition OrYes key detected";
    }

    QListWidgetItem * item2 = new QListWidgetItem(qsItem2);
    ListWidgetOther->addItem(item2);

    //--- Окончание функции загрузки

    settings.sync();

}//End of void cSearch::execLoadFilesByConditionOrYes(QStringList yes)

//=============================================================================

