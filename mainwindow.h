#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/qconfig.h>
#include <QDebug>
#include <QImage>
#include <QProgressBar>
#include <QSpinBox>
#include <QLabel>
#include <memory>
#include <QStringList>
#include <QTableView>
#include <QStandardItemModel>
#include <QStringListIterator>
#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QImage>
#include <QTransform>
#include <QTimer>
#include <atomic>
#include <QKeyEvent>
#include <QSet>
#include <QRegularExpression>
#include <QSysInfo>
#include <QTextCodec>
#include <QProcess>
#include <QCoreApplication>
#include <QListWidget>
#include <QThreadPool>
#include <QRunnable>
#include <QProgressBar>
#include <QMessageBox>

#include "cinifile.h"
#include "fmview.h"
#include "cimportfiles.h"
#include "stvarmem.h"
#include "cdrawfilex.h"
#include "cloadfiles.h"

#include "clistwidgetplace.h"
#include "clistwidgetsubject.h"
#include "clistwidgetproperty.h"
#include "clistwidgettheame.h"
#include "cactionsexec.h"
#include "cnavigation.h"
#include "csearch.h"

#include "ThreadPool/processingtask.h"
#include "processimporttask.h"


//-----------------------------------------------------------------------------
// КОНСТАНТЫ
//-----------------------------------------------------------------------------

#define STATUS_BAR_DELAY 500
#define WINDOW_LEFT_MARGING 40
#define WINDOW_TOP_MARGING 65

//-----------------------------------------------------------------------------
// ТИПЫ ДАННЫХ
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
//-----------------------------------------------------------------------------

extern QString qsApplicationName;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //Атрибуты

    QString qsProjectPath;
    QString qsProjectName;
    QString qsProjectNameDataSuffix;
    QString qsProjectNameImgSuffix;

    QString qsDataFileNameExtension;
    QString qsHashTagFileNameSuffix;

    varMem <int> KeyPressed;

    bool IsError = false;

    QLabel * labelExecStatus;
    QLabel * labelFileName;
    QLabel * labelOsType;
    QProgressBar * ProgressBarTasks;

    QTimer * timerUpdate;
    int iTimerUpdateCounter = 0;

    fmView * fmViewPicture;

    QStringList * qslHashTagList;

    //Тип списка для работы с кнотекстными меню

    ListWidgetType lwtListType = ListWidgetType::SUBJECT_TYPE;

    cListWidgetPlace * ListWidgetPlace;
    cListWidgetSubject * ListWidgetSubject;
    cListWidgetProperty * ListWidgetProperty;
    cListWidgetTheame * ListWidgetTheame;

    //20250606
    cActionsExec * ActionsExec;
    cNavigation * NavigationInstance;
    cImportFiles * ImportFilesInstance;
    cLoadFiles * LoadFilesInstance;
    cDrawFilex * DrawFilesInstance;
    cSearch * SearchInstance;

    //Методы
    void saveRemovedSectionsList();
    void appEndItem(QListWidgetItem * item);

public:
    //Атрибуты

    QString fileNameHashTag;// Имя файла для загрузки параметров

    QString filePathRoot;// Путь к папке с исполняемым файлом (programm)

    //Конструкторы, деструкторы
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Методы

protected:
    void keyPressEvent(QKeyEvent * e) override;//keys

private:
    Ui::MainWindow *ui;
    //20250820
    QThreadPool threadPool;
    int tasksCompleted = 0;
    int totalTasks = 0;

private slots:

    void execActionFormViewPicture();
    void execActionMemo();
    void execTimerUpdate();

    void execComboBoxCurrentIndexChanged(int x);

    void execListWidgetKeysItemClicked();
    void execListWidgetSearchItemClicked();

    void execShowExecStatus(QString s);

    //
    // Слот для обработки сигнала, возникающего при ошибке проведения операции с файлом
    //
    void execFoundMissingFile(QString path);

    //20250820
    void execActionStartThreads();
    void execInfoMessage(QString s);
    void execBeginMessage(QString s);
    void execEndMessage(QString s);
    void updateProgress(int value);

    //20250822
    void updateProgressImportTask(int value);
    void execActionImportTaskProcess();
    //20250824
    void execActionStoreRecordsList();

public slots:

signals:
    void showExecStatus(QString s);
    void infoMessage(QString s);
    void beginMessage(QString s);
    void endMessage(QString s);
};

#endif // MAINWINDOW_H
