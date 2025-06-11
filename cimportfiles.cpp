#include "cimportfiles.h"

//int cImportFiles::CurrentIndex = 0;

int cImportFiles::MaxIndexValue = MAX_INDEX_DEFAULT_VALUE;

QString cImportFiles::labelExecStatusText = "";
bool cImportFiles::IslabelExecStatusTextChanged = false;

QString cImportFiles::labelFileNameText = "";
bool cImportFiles::IslabelFileNameTextChanged = false;


cImportFiles::cImportFiles()
{

}

/******************************************************************************
 * Статическая функция bool cImportFiles::execImport() выполняет чтение
 * каталога - источника. Путь к каталогу задаётся исходя из типа
 * операционной системы
 * Целевым файлом функции является ini файл, имя которого задаётся исходя
 * из типа операционной системы.
 * Удалять файлы из каталога - источника запрещается!
 * Удалять секции из целевого ini файла запрещается!
 * Приведённая ниже функция производит добавление секций в целевой ini файл
 * СОДЕРЖИМОЕ КОНФИГУРАЦИОННОГО ФАЙЛА ОБНОВЛЯЕТСЯ, НО НЕ ПЕРЕЗАПИСЫВАЕТСЯ
 * Файлы с расширениями "mp4", "tif", "txt" в конфигурационный файл не добавляются
 *****************************************************************************/
void cImportFiles::execImport(QProgressBar * bar)
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList Groups = settings.childGroups();//Загрузка полного списка групп

    //---Добавление идентификационной секции
    cImportFiles::MaxIndexValue = cRecord::RecordList->count();
    cIniFile::IniFile.addInitalSection(cImportFiles::MaxIndexValue);
    bar->setRange(1, cImportFiles::MaxIndexValue);
    bar->setValue(0);
    iCurrentIndexGlobal.store(0);

    int iAddedFilesCounter = 0;
    int iSkippedFilesCounter = 0;

    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);
        int id = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        bar->setValue(id);


        const cRecord rec = *it;

        QString name = rec.qsName;
        int iDotPosition = name.indexOf('.');
        QString groupName = name.mid(0, iDotPosition);

        QString path = rec.qsPath;
        int iNamePosition = path.indexOf(name);
        QString PathWithoutName = path.mid(0, iNamePosition - 1);

        int size = rec.iSize;

        int iExtensionPosition = path.indexOf('.');
        QString qsExtension = path.mid(iExtensionPosition + 1);

        bool IsError = false;
        int width = 0;
        int height = 0;

        if(qsExtension.toLower() == "mp4")
        {
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << "Extension: mp4";
            IsError = true;
        }
        else if(qsExtension.toLower() == "tif")
        {
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << "Extension: tif";
            IsError = true;
        }
        else if(qsExtension.toLower() == "txt")
        {
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << "Extension: txt";
            IsError = true;
        }
        else
        {
        //qDebug() << "Id=" << iCurrentIndexGlobal;

        //Фрагмент для обработки файлов изображений
        QImage image(path);//name
        if(image.isNull())
        {
            IsError = true;
        }
        else
        {
            width = image.width();
            height = image.height();
            }
        }

        //Добавление записи в конфигурационный файл, если её там нет
        if(!Groups.contains(groupName))
        {
            qDebug() << "###Add section:" << groupName;
            iAddedFilesCounter++;

            settings.beginGroup(groupName);
            settings.setValue("Id", id);
            settings.setValue("name", name);
            settings.setValue("path", PathWithoutName);
            settings.setValue("size", size);
            settings.setValue("new", true);//Признак новой записи
            if(IsError)
            {
                settings.setValue("error", true);
            }
            else
            {
                settings.setValue("width", width);
                settings.setValue("height", height);
            }
            settings.endGroup();
        }
        else
        {
            iSkippedFilesCounter++;

            qDebug() << "Skip existing section:" << groupName;
        }

    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)

    settings.sync();

    qDebug() << "Result: added files counter=" << iAddedFilesCounter <<" skiped files couner=" << iSkippedFilesCounter;

}//End of void cImportFiles::execImport()

/*******************************************************************************
 * Функция создания списка файлов, не включённых в файл конфигурации
 ******************************************************************************/

void cImportFiles::execSearchNewFiles()
{

    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList Groups = settings.childGroups();//Загрузка полного списка групп

    qDebug() << "Groups count=" << Groups.count();

    QStringList slNewItems;
    slNewItems.clear();

    int iAddedFilesCounter = 0;
    int iSkippedFilesCounter = 0;

    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        const cRecord rec = *it;

        QString name = rec.qsName;
        int iDotPosition = name.indexOf('.');
        QString groupName = name.mid(0, iDotPosition);

        QString path = rec.qsPath;
        int iNamePosition = path.indexOf(name);
        QString PathWithoutName = path.mid(0, iNamePosition - 1);

        int iExtensionPosition = path.indexOf('.');
        QString qsExtension = path.mid(iExtensionPosition + 1);

        //Добавление записи в конфигурационный файл, если её там нет
        if(!Groups.contains(groupName))
        {
            qDebug() << "###Add section:" << groupName << " Path+FileName=" << path;
            slNewItems.append(path);
            iAddedFilesCounter++;

        }
        else
        {
            iSkippedFilesCounter++;

            qDebug() << "Skip existing section:" << groupName;
        }

    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)

    qDebug() << "Result: added files counter=" << iAddedFilesCounter <<" skiped files couner=" << iSkippedFilesCounter;

    //Store data in file
    if(iAddedFilesCounter > 0)
    {
        if(cLoadFiles::saveStringListToFile(cIniFile::fileNewItems, slNewItems))
        {
             qDebug() << "New items list stored in file:" << cIniFile::fileNewItems;
        }
        else
        {
            qDebug() << "Store in file:" << cIniFile::fileNewItems << " process error";
        }
    }
    else
    {
        qDebug() << "New items not founded";
    }

}

//-------------------------------------------------------------------------
// Получить список групп
//-------------------------------------------------------------------------
bool cImportFiles::getGroupsList()
{
    bool IsError = false;
/*
    cIniFile::Groups->clear();
    QFile file(cIniFile::iniFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось открыть файл для чтения: " << cIniFile::iniFilePath;
        IsError = true;
        return IsError; // Возвращаем флаг ошибки
    }

    qDebug() << "###getGroupsList from " << cIniFile::iniFilePath << " begin";
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // Читаем строку и убираем пробелы в начале и конце
        if (line.startsWith("[") && line.endsWith("]"))
        {
            QString groupName = line.mid(1, line.length() - 2); // Извлекаем имя секции
            if (!cIniFile::Groups->contains(groupName))
            {
                cIniFile::Groups->append(groupName); // Добавляем в список, если еще не существует
                //Чтение списка ключей
                cIniFile::settings.beginGroup(groupName);
                QList<QString> keys = cIniFile::settings.childKeys();
                int iKeysCount = keys.count();
                cIniFile::settings.endGroup();
                //Вывод сообщения в список
                qDebug() << "Section: " << groupName << " contains " << iKeysCount << " keys";
            }
            else
            {
                qDebug() << "Section already exist: " << groupName;
            }
        }
    }

    file.close();

    qDebug() << "###getGroupsList from " << cIniFile::iniFilePath << " complete";
*/

    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    *cIniFile::Groups = settings.childGroups();
    qDebug() << "cImportFiles::getGroupsList(): Groups count=" << cIniFile::Groups->count();

    return IsError;//Возвращаем флаг ошибки

}//End of bool cImportFiles::getGroupsList()

bool cImportFiles::getKeysList()
{
    bool IsError = true;
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    *cIniFile::Keys = settings.allKeys();

    if(cIniFile::Keys->count() > 0)IsError = false;

    return IsError;//Возвращаем флаг ошибки
}

