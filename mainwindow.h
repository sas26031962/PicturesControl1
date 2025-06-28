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

    QProgressBar * progressBarProcess;
    QProgressBar * progressBarNavigation;
    QSpinBox * SpinBoxIndex;

    QTimer * timerUpdate;
    int iTimerUpdateCounter = 0;

    fmView * fmViewPicture;

    int iAngle = 90;

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
    cLoadFiles * LoadFilesInstance;
    cDrawFilex * DrawFilesInstance;
    cSearch * SearchInstance;

    //Методы
    bool deleteSection(QString s);
    bool eraseSection(QString s);

    void saveRemovedSectionsList();

public:
    //Атрибуты

    QListWidget * ListWidget;//20250616

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

    void execActionImportInitial();
    void execActionLoad();
    void execActionFormViewPicture();
    void execActionMemo();
    void execTimerUpdate();

    void execComboBoxCurrentIndexChanged(int x);

    void execListWidgetKeysItemClicked();
    void execListWidgetSearchItemClicked();

    void execActionSearchRotated();
    void execActionSearchNamePattern1();
    void execActionSearchNamePattern2();
    void execActionSearchNamePattern();
    void execActionSearchNamePatterns12Intersection();
    void execActionSearchNamePatterns1XIntersection();

    void execActionRemoveSection();
    void execActionEraseSection();

    void execActionGetGroupsList();
    void execActionGetKeysList();
    void execActionSearchOrYes();

    void execActionRotateCW();
    void execActionRotateCCW();
    void execSpinBoxAngle(int angle);
    void execShowExecStatus(QString s);

    void execFoundMissingFile(QString path);

public slots:

signals:
    void draw(QString s);
    void showExecStatus(QString s);
};

#endif // MAINWINDOW_H
