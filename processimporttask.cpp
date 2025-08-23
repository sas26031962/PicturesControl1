#include "processimporttask.h"

processImportTask::processImportTask(int taskId, QObject *receiver)
    : m_taskId(taskId), m_receiver(receiver)
{
    setAutoDelete(true); // Автоматическое удаление после выполнения
}

void processImportTask::run()
{
    //---Стартовое сообщение---
    QString qsStartMessage = "ImportTask:";
    qsStartMessage += QString::number(m_taskId);
    qsStartMessage += " run in thread";

    qDebug() << "Task #" << m_taskId << " run in thread:" << QThread::currentThreadId();

    QMetaObject::invokeMethod(m_receiver, "execBeginMessage",
                              Qt::QueuedConnection,
                              Q_ARG(QString, qsStartMessage));

    // Имитация длительной обработки
    for (int i = 0; i < 100; ++i)
    {
        QThread::msleep(30); // Задержка 30 мс

        QMetaObject::invokeMethod(m_receiver, "updateProgressImportTask",
                                      Qt::QueuedConnection,
                                      Q_ARG(int, i));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
//    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

//    QStringList Groups = settings.childGroups();//Загрузка полного списка групп

    //ListWidgetOther->addItem("Initial groups count=" + QString::number(Groups.count()));
    //Информационное сообщение
    QString qsInfoMessage = "ImportTask:Initial groups count=";
    qsInfoMessage += QString::number(cRecord::RecordList->count());

    QMetaObject::invokeMethod(m_receiver, "execInfoMessage",
                              Qt::QueuedConnection,
                              Q_ARG(QString, qsInfoMessage));


//    //---Добавление идентификационной секции
    cImportFiles::MaxIndexValue = cRecord::RecordList->count();
//    cIniFile::IniFile.addInitalSection(cImportFiles::MaxIndexValue);

//    //---Подготовка к обработке файла данных
//    iCurrentIndexGlobal.store(0);

//    int iAddedFilesCounter = 0;
//    int iSkippedFilesCounter = 0;
//    int iErrorFilesCounter = 0;

    int iCounter = 0;
    float fProgressWeight = cImportFiles::MaxIndexValue / 100.0;

    //---Начало обработки файла данных
    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
    {

        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);
        int id = iCurrentIndexGlobal.load(std::memory_order_relaxed);

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
            iErrorFilesCounter++;
        }
        else if(qsExtension.toLower() == "tif")
        {
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << "Extension: tif";
            IsError = true;
            iErrorFilesCounter++;
        }
        else if(qsExtension.toLower() == "txt")
        {
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << "Extension: txt";
            IsError = true;
            iErrorFilesCounter++;
        }
        else
        {
            //qDebug() << "Id=" << iCurrentIndexGlobal;

            //Фрагмент для обработки файлов изображений
            QImage image(path);//name
            if(image.isNull())
            {
                IsError = true;
                iErrorFilesCounter++;
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

        //---индикация процесса импорта
        iCounter++;
        int Progress = (int)(fProgressWeight * iCounter);
        QMetaObject::invokeMethod(
            m_receiver, "updateProgressImportTask",
            Qt::QueuedConnection,
            Q_ARG(int, Progress));
        //---

    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)

    //---Конец обработки файла данных

    //settings.sync();
*/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //--- Уведомление о завершении задачи ---
    QMetaObject::invokeMethod(
                m_receiver, "updateProgressImportTask",
                Qt::QueuedConnection,
                Q_ARG(int, 100)
                );

    //---Итоговое сообщение---
    QString qsFinishMessage = "ImportTask:";
    qsFinishMessage += QString::number(m_taskId);
    qsFinishMessage += " completed";
    QMetaObject::invokeMethod(m_receiver, "execEndMessage",
                              Qt::QueuedConnection,
                              Q_ARG(QString, qsFinishMessage));

}//End of void processImportTask::run()

