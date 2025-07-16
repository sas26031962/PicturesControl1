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

        bool match = (keys.count() <= 6);//true;

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

    int iCountYes = 0;// Очистка счётчика записей, удовлетворяющих условию
    int iCountNo = 0;// Очистка счётчика записей, не удовлетворяющих условию

    //============== ОПРОС ПОЛНОГО СПИСКА ===================
    QListIterator<QString> readItTotal(TotalGroups);
    while (readItTotal.hasNext())
    {
        QString qsSection = readItTotal.next();
        //qDebug() << qsSection;
        settings.beginGroup(qsSection);

        QString qsIsRotated;

        QStringList keys = settings.childKeys();
        QListIterator<QString> readItKeys(keys);

        //------ ОПРОС СПИСКА КЛЮЧЕЙ ТЕКУЩЕЙ ЗАПИСИ ---------
        while(readItKeys.hasNext())
        {
            QString key = readItKeys.next();
            QString value = settings.value(key,"0").toString();

            QListIterator<QString> readItYes(yes);
            //~~~ ПЕРЕБОР УСЛОВИЙ ПРИ ПРОВЕРКЕ ТЕКУЩЕГО КЛЮЧА ~~~

            while (readItYes.hasNext())
            {
                QString key_yes = readItYes.next();
                //qDebug() << "iteratorYes: key=" << key_yes;// << " count=" << iCount;
                QString value_yes = settings.value(key_yes,"0").toString();
                if(key == key_yes)
                {
                    qsIsRotated = value_yes;
                    iCountYes++;
                    cIniFile::Groups->append(qsSection);
                    //qDebug() << "iterator: section=" << qsSection << " key=" << key << " count=" << iCount;
                }
                else
                {
                    iCountNo++;
                }
            }
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        }//End of while(readItKeys.hasNext())

        //---------------------------------------------------
        settings.endGroup();

    }//End of while (readIt.hasNext())
    //=======================================================

    QString qsItem2;
    if(iCountYes > 0)
    {
        qsItem2 = "Signed by condition OrYes key detected in ";
        qsItem2 += QString::number(iCountYes);
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

/******************************************************************************
 * Функция выбирает из полного списка файлов те файлы, которые удовлетворяют
 * каждому из списка условий, приведённых в списке yes, передаваемому как параметр.
 * Результат работы функции - список cIniFile::Groups
 *****************************************************************************/
void cSearch::execLoadFilesByConditionYesYes(QStringList yes)
{
    //--- Начало функции загрузки

    QListWidgetItem * item0 = new QListWidgetItem("==execLoadFilesByConditionYesYes==");
    item0->setForeground(Qt::blue);
    //item0->setForeground(Qt::yellow);
    ListWidgetOther->addItem(item0);

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла

    QStringList TotalGroups = settings.childGroups();//Загрузка полного списка групп

    // Выводим значения
    QListWidgetItem * item1 = new QListWidgetItem("TotalGroups length: " + QString::number(TotalGroups.count()));
    ListWidgetOther->addItem(item1);

    int iCountYes = 0;// Очистка счётчика записей, удовлетворяющих условию
    int iCountNo = 0;// Очистка счётчика записей, не удовлетворяющих условию

    //============= ОПРОС ПЕРВОГО ЭЛЕМЕНТА ==================
    qDebug() << "#Check sections and keys for first elemen of StringList YES: BEGIN";
    QStringList FirstGroups;
    FirstGroups.clear();

    QListIterator<QString> readItTotal0(TotalGroups);
    while (readItTotal0.hasNext())
    {
        QString qsSection = readItTotal0.next();
        //qDebug() << qsSection;

        //Перебор всех ключей данной секции
        settings.beginGroup(qsSection);

        QStringList keys = settings.childKeys();
        QListIterator<QString> readItKeys(keys);

        //------ ОПРОС СПИСКА КЛЮЧЕЙ ТЕКУЩЕЙ ЗАПИСИ ---------
        QString key_yes = yes.at(0);

        while(readItKeys.hasNext())
        {
            QString key = readItKeys.next();

            //qDebug() << "iteratorYes: key=" << key_yes;// << " count=" << iCount;
            if(key == key_yes)
            {
                iCountYes++;
                FirstGroups.append(qsSection);
                qDebug() << "Inser section=" << qsSection << " becouse found key=" << key_yes;
            }
            else
            {
                iCountNo++;
            }
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        }//End of while(readItKeys.hasNext())

        //---------------------------------------------------
        settings.endGroup();

    }//End of while (readIt.hasNext())
    qDebug() << "#Check sections and keys for first elemen of StringList YES: END";
    qDebug() << "#Check sections and keys for first elemen of StringList YES: Found recors count=" << iCountYes;

    //Первая итерация результата
    //*cIniFile::Groups = FirstGroups;
    cIniFile::Groups->clear();
    cIniFile::Groups->append(FirstGroups);
    qDebug() << "ResultGroups count=" << cIniFile::Groups->count();

    if((yes.count() > 1))
    {
        //============ ОПРОС ОСТАВШЕГОСЯ СПИСКА =================
        qDebug() << "#Check sections and keys for tail elemens of StringList YES: BEGIN";

        QListIterator<QString> readItFirst(FirstGroups);
        while (readItFirst.hasNext())
        {
            QString qsSection = readItFirst.next();

            settings.beginGroup(qsSection);

            QListIterator<QString> readItYes(yes);

            readItYes.next();//Пропускаем первую секцию из StringList YES

            while (readItYes.hasNext())
            {
                QString key_yes = readItYes.next();

                QStringList keys = settings.childKeys();
                QListIterator<QString> readItKeys(keys);

                //------ ОПРОС СПИСКА КЛЮЧЕЙ ТЕКУЩЕЙ ЗАПИСИ ---------
                bool IsKeyFound = false;
                while(readItKeys.hasNext())
                {
                    QString key = readItKeys.next();


                    //~~~ ПЕРЕБОР УСЛОВИЙ ПРИ ПРОВЕРКЕ ТЕКУЩЕГО КЛЮЧА ~~~

                    if(key == key_yes)
                    {
                        IsKeyFound = true;
                    }

                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                }//End of while(readItKeys.hasNext())

                if(!IsKeyFound)
                {
                    //qDebug() << "Section=" << qsSection << " must be removed becouse not found key=";// << key_yes;
                    if(cIniFile::Groups->contains(qsSection))
                    {
                        iCountNo++;
                        iCountYes--;
                        cIniFile::Groups->removeOne(qsSection);//Удаление секции из списка, если не удовлетворяет условию
                        qDebug() << "Remove section=" << qsSection << " becouse not found key=";// << key_yes;
                    }
                }
                else
                {
                    qDebug() << "In section=" << qsSection << " found key=";// << key_yes;
                }

            }//End of while (readItYes.hasNext())

            //---------------------------------------------------
            settings.endGroup();

        }//End of while (readIt.hasNext())
        //=======================================================

        qDebug() << "#Check sections and keys for tail elemens of StringList YES: END";
    }

    QString qsItem2;
    if(iCountYes > 0)
    {
        qsItem2 = "Signed by condition OrYes key detected in ";
        qsItem2 += QString::number(iCountYes);
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

}//End of void cSearch::execLoadFilesByConditionYesYes(QStringList yes)

//=============================================================================

/******************************************************************************
 * Функция выбирает из полного списка файлов те файлы, которые содержат признак
 * IsRotated.
 * Результат работы функции - список cIniFile::Groups
 *****************************************************************************/
void cSearch::execLoadFilesSignedIsRotated()
{
    //--- Начало функции загрузки

    QListWidgetItem * item0 = new QListWidgetItem("==execLoadFilesSignedIsRotated==");
    item0->setForeground(Qt::blue);
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

            if(key == "IsRotated")
            {
                qsIsRotated = value;
                iCount++;
                cIniFile::Groups->append(qsSection);
                qDebug() << "iterator: section=" << qsSection << " key=" << key << " count=" << iCount;
            }
        }
        //===
        settings.endGroup();
    }

    QString qsItem2;
    if(iCount > 0)
    {
        qsItem2 = "IsRotated key detected in ";
        qsItem2 += QString::number(iCount);
        qsItem2 += " files";
        //qDebug() << "IsRotated key detected in " << iCount << " files";
    }
    else
    {
        qsItem2 = "No IsRotated key detected";
        //qDebug() << "No IsRotated key detected";
    }

    QListWidgetItem * item2 = new QListWidgetItem(qsItem2);
    ListWidgetOther->addItem(item2);

    //--- Окончание функции загрузки

    settings.sync();

}//End of void cLoadFiles::execLoadFilesSignedIsRotated()

//=============================================================================

void cSearch::execActionSearchRotated()
{
    QString s = "SearchInstance::execActionSearchRotated()";

    execLoadFilesSignedIsRotated();

    emit gotoInstallNavigation();//Настройка навигации

    s += ": find ";
    s += QString::number(cImportFiles::MaxIndexValue);
    s += " records";
    //---
    emit showExecStatus(s);
    //---
}

//=============================================================================

void cSearch::execActionSearchYesYes()
{
    QString s = "SearchInstance::execActionSearchYesYes()";

    if(cIniFile::SearchKeys->count() > 0)
    {
        execLoadFilesByConditionYesYes(*cIniFile::SearchKeys);

        //NavigationInstance->installNavigation();//Настройка навигации
        emit gotoInstallNavigation();//Настройка навигации

        s += ": find ";
        s += QString::number(cImportFiles::MaxIndexValue);
        s += " records";
    }
    else
    {
        s += ": empy search task, nothing to do!!!";
    }
    //---
    emit showExecStatus(s);
    //---
}

//=============================================================================

void cSearch::execActionSearchOrYes()
{
    QString s = "SearchInstance::execActionSearchOrYes()";

    if(cIniFile::SearchKeys->count() > 0)
    {
        execLoadFilesByConditionOrYes(*cIniFile::SearchKeys);

        emit gotoInstallNavigation();//Настройка навигации

        s += ": find ";
        s += QString::number(cImportFiles::MaxIndexValue);
        s += " records";
    }
    else
    {
        s += ": empy search task, nothing to do!!!";
    }
    //---
    emit showExecStatus(s);
    //---
}

//=============================================================================

void cSearch::execActionSearchFreshRecords()
{
    QString s = "SearchInstance::execActionSearchFreshRecords()";

    bool x = searchFreshRecords();
    if(x)
    {
        s += ": successfull write result to file";
    }
    else
    {
        s += ": fault write result to file";
    }

    emit gotoInstallNavigation();//Настройка навигации

    //---
    emit showExecStatus(s);
    //---
}

//=============================================================================

