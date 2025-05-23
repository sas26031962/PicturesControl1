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

#include "cinifile.h"
#include "fmview.h"
#include "cimportfiles.h"
#include "stvarmem.h"
#include "cdrawfiles.h"
#include "cloadfiles.h"

#define STATUS_BAR_DELAY 500
#define WINDOW_LEFT_MARGING 40
#define WINDOW_TOP_MARGING 65

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //Атрибуты

//    int iSystemType = 0;

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

    QStringList qslDeletedSections;

    //Методы
    void showCurrentIndexPicture();
    bool loadHashTagListSubject();
    bool loadHashTagListPlace();
    bool loadHashTagListProperty();
    bool loadHashTagListTheame();
    bool deleteSection(QString s);

    bool saveStringListToFile(const QString& fileName, const QStringList& list);
    QStringList loadStringListFromFile(const QString& fileName);

    void loadRemovedSectionsList();
    void saveRemovedSectionsList();
    void showGroupsList();

public:
    //Атрибуты
//    QString filePathHashTag;// Путь к файлу для загрузки параметров
    QString fileNameHashTag;// Имя файла для загрузки параметров

    QString filePathRoot;// Путь к папке с исполняемым файлом (programm)

    //Конструкторы, деструкторы
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Методы
    void installNavigation();

protected:
    void keyPressEvent(QKeyEvent * e) override;//keys

private:
    Ui::MainWindow *ui;

private slots:

    void execActionSelectImageBegin();
    void execActionSelectImageNext();
    void execActionSelectImagePrevious();
    void execActionSelectImageEnd();
    void execActionImportInitial();
    void execActionLoad();
    void execActionFormViewPicture();
    void execActionMemo();
    void execTimerUpdate();

    void execListWidgetSubjectItemClicked();
    void execListWidgetPropertyItemClicked();
    void execListWidgetTheameItemClicked();
    void execListWidgetPlaceItemClicked();

    void execListWidgetFoundedItemClicked();

    void execComboBoxCurrentIndexChanged(int x);

    void execListWidgetKeysItemClicked();
    void execListWidgetSearchItemClicked();

    void execActionLoadHashTagListSubject();
    void execActionLoadHashTagListPlace();
    void execActionLoadHashTagListProperty();
    void execActionLoadHashTagListTheame();

    void execActionInsertSubject();
    void execActionInsertPlace();
    void execActionInsertProperty();
    void execActionInsertTheame();

    void execActionSearchRotated();
    void execActionSearchOrYes();
    void execActionSearchNamePattern1();
    void execActionSearchNamePattern2();
    void execActionSearchNamePattern();
    void execActionSearchNamePatterns12Intersection();
    void execActionSearchNamePatterns1XIntersection();

    void execActionRemoveMovie();
    void execActionRemoveText();
    void execActionRemoveTif();
    void execActionRemove3gp();
    void execActionRemoveBin();
    void execActionRemoveSection();

    void execActionGetGroupsList();
    void execActionGetKeysList();

    void execActionGotoIndex();

    void execActionOpenFoundRecord();

    void execActionRotateCW();
    void execActionRotateCCW();
    void execSpinBoxAngle(int angle);
    void execShowExecStatus(QString s);

    void execShiftXValueChanged();
    void execShiftYValueChanged();

    void execListWidgetSubjectCustomContextMenuRequested(const QPoint &pos);

public slots:

signals:
    void draw(QString s);
    void showExecStatus(QString s);
};

#endif // MAINWINDOW_H
