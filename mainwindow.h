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

//QString qsApplicationName = "NoName";

extern QString qsApplicationName;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //Атрибуты

//    int iSystemType = 0;

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

public slots:

signals:
    void showExecStatus(QString s);
};

#endif // MAINWINDOW_H
