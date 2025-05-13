/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSelectImageBegin;
    QAction *actionSelectImageNext;
    QAction *actionSelectImagePrevious;
    QAction *actionSelectImageEnd;
    QAction *actionImport;
    QAction *actionLoad;
    QAction *actionViewPicture;
    QAction *actionLoaadHashTagListSubject;
    QAction *actionLoadHashTagListPlace;
    QAction *actionRemoveMovie;
    QAction *actionRotateCW;
    QAction *actionRotateCCW;
    QAction *actionLoadHashTagListProperty;
    QAction *actionImportFiles;
    QAction *actionRotateCW_2;
    QAction *actionRotateCCW_2;
    QAction *actionRemoveText;
    QAction *actionRemoveTif;
    QAction *actionGetGroupsList;
    QAction *actionLoadHashTagListTheame;
    QAction *actionRemoveSection;
    QAction *actionGotoIndex;
    QAction *actionRemoveBin;
    QAction *actionRemove3gp;
    QAction *actionSearchRotated;
    QAction *actionSearchOrYes;
    QAction *actionGetKeysList;
    QAction *actionSearchNamePattern1;
    QAction *actionSearchNamePattern2;
    QAction *actionSearchNamePatterns12Intersection;
    QAction *actionSearchNamePatternX;
    QAction *actionOpenFoundRecord;
    QAction *actionSearchNamePatterns1XIntersection;
    QWidget *centralWidget;
    QGroupBox *groupBoxControl;
    QPushButton *pushButtonBegin;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonPrevious;
    QPushButton *pushButtonEnd;
    QProgressBar *progressBarNavigation;
    QSpinBox *spinBoxIndex;
    QPushButton *pushButtonGotoIndex;
    QPushButton *pushButtonRemove;
    QLabel *labelIncomingListCaption;
    QTableView *tableViewCurrent;
    QGroupBox *groupBoxEdit;
    QPushButton *pushButtonLoad;
    QLineEdit *lineEditMemo;
    QPushButton *pushButtonMemo;
    QGroupBox *groupBoxRotate;
    QPushButton *pushButtonRotateCCW;
    QSpinBox *spinBoxAngle;
    QPushButton *pushButtonRotateCW;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QListWidget *listWidgetSubject;
    QWidget *tab;
    QListWidget *listWidgetPlaces;
    QWidget *tab_2;
    QListWidget *listWidgetPropertyes;
    QWidget *tab_3;
    QListWidget *listWidgetTheams;
    QWidget *tab_6;
    QListWidget *listWidgetKeys;
    QListWidget *listWidgetSearch;
    QLabel *labelKeysCaption;
    QLabel *labelSearchKeysCaption;
    QPushButton *pushButtonSearchOrYes;
    QWidget *tab_7;
    QListWidget *listWidgetFounded;
    QWidget *tab_5;
    QListWidget *listWidgetOther;
    QGroupBox *groupBoxPattern;
    QLineEdit *lineEditPattern;
    QPushButton *pushButtonSearchPatternX;
    QComboBox *comboBoxPatterns;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSelect_image;
    QMenu *menuForms;
    QMenu *menuTags;
    QMenu *menuSearch;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(601, 640);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSelectImageBegin = new QAction(MainWindow);
        actionSelectImageBegin->setObjectName(QString::fromUtf8("actionSelectImageBegin"));
        actionSelectImageNext = new QAction(MainWindow);
        actionSelectImageNext->setObjectName(QString::fromUtf8("actionSelectImageNext"));
        actionSelectImagePrevious = new QAction(MainWindow);
        actionSelectImagePrevious->setObjectName(QString::fromUtf8("actionSelectImagePrevious"));
        actionSelectImageEnd = new QAction(MainWindow);
        actionSelectImageEnd->setObjectName(QString::fromUtf8("actionSelectImageEnd"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionViewPicture = new QAction(MainWindow);
        actionViewPicture->setObjectName(QString::fromUtf8("actionViewPicture"));
        actionViewPicture->setCheckable(true);
        actionViewPicture->setChecked(true);
        actionLoaadHashTagListSubject = new QAction(MainWindow);
        actionLoaadHashTagListSubject->setObjectName(QString::fromUtf8("actionLoaadHashTagListSubject"));
        actionLoadHashTagListPlace = new QAction(MainWindow);
        actionLoadHashTagListPlace->setObjectName(QString::fromUtf8("actionLoadHashTagListPlace"));
        actionRemoveMovie = new QAction(MainWindow);
        actionRemoveMovie->setObjectName(QString::fromUtf8("actionRemoveMovie"));
        actionRotateCW = new QAction(MainWindow);
        actionRotateCW->setObjectName(QString::fromUtf8("actionRotateCW"));
        actionRotateCCW = new QAction(MainWindow);
        actionRotateCCW->setObjectName(QString::fromUtf8("actionRotateCCW"));
        actionLoadHashTagListProperty = new QAction(MainWindow);
        actionLoadHashTagListProperty->setObjectName(QString::fromUtf8("actionLoadHashTagListProperty"));
        actionImportFiles = new QAction(MainWindow);
        actionImportFiles->setObjectName(QString::fromUtf8("actionImportFiles"));
        actionRotateCW_2 = new QAction(MainWindow);
        actionRotateCW_2->setObjectName(QString::fromUtf8("actionRotateCW_2"));
        actionRotateCCW_2 = new QAction(MainWindow);
        actionRotateCCW_2->setObjectName(QString::fromUtf8("actionRotateCCW_2"));
        actionRemoveText = new QAction(MainWindow);
        actionRemoveText->setObjectName(QString::fromUtf8("actionRemoveText"));
        actionRemoveTif = new QAction(MainWindow);
        actionRemoveTif->setObjectName(QString::fromUtf8("actionRemoveTif"));
        actionGetGroupsList = new QAction(MainWindow);
        actionGetGroupsList->setObjectName(QString::fromUtf8("actionGetGroupsList"));
        actionLoadHashTagListTheame = new QAction(MainWindow);
        actionLoadHashTagListTheame->setObjectName(QString::fromUtf8("actionLoadHashTagListTheame"));
        actionRemoveSection = new QAction(MainWindow);
        actionRemoveSection->setObjectName(QString::fromUtf8("actionRemoveSection"));
        actionGotoIndex = new QAction(MainWindow);
        actionGotoIndex->setObjectName(QString::fromUtf8("actionGotoIndex"));
        actionRemoveBin = new QAction(MainWindow);
        actionRemoveBin->setObjectName(QString::fromUtf8("actionRemoveBin"));
        actionRemove3gp = new QAction(MainWindow);
        actionRemove3gp->setObjectName(QString::fromUtf8("actionRemove3gp"));
        actionSearchRotated = new QAction(MainWindow);
        actionSearchRotated->setObjectName(QString::fromUtf8("actionSearchRotated"));
        actionSearchOrYes = new QAction(MainWindow);
        actionSearchOrYes->setObjectName(QString::fromUtf8("actionSearchOrYes"));
        actionGetKeysList = new QAction(MainWindow);
        actionGetKeysList->setObjectName(QString::fromUtf8("actionGetKeysList"));
        actionSearchNamePattern1 = new QAction(MainWindow);
        actionSearchNamePattern1->setObjectName(QString::fromUtf8("actionSearchNamePattern1"));
        actionSearchNamePattern2 = new QAction(MainWindow);
        actionSearchNamePattern2->setObjectName(QString::fromUtf8("actionSearchNamePattern2"));
        actionSearchNamePatterns12Intersection = new QAction(MainWindow);
        actionSearchNamePatterns12Intersection->setObjectName(QString::fromUtf8("actionSearchNamePatterns12Intersection"));
        actionSearchNamePatternX = new QAction(MainWindow);
        actionSearchNamePatternX->setObjectName(QString::fromUtf8("actionSearchNamePatternX"));
        actionOpenFoundRecord = new QAction(MainWindow);
        actionOpenFoundRecord->setObjectName(QString::fromUtf8("actionOpenFoundRecord"));
        actionSearchNamePatterns1XIntersection = new QAction(MainWindow);
        actionSearchNamePatterns1XIntersection->setObjectName(QString::fromUtf8("actionSearchNamePatterns1XIntersection"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QString::fromUtf8("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 271, 81));
        pushButtonBegin = new QPushButton(groupBoxControl);
        pushButtonBegin->setObjectName(QString::fromUtf8("pushButtonBegin"));
        pushButtonBegin->setGeometry(QRect(20, 20, 23, 23));
        pushButtonNext = new QPushButton(groupBoxControl);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(80, 20, 23, 23));
        pushButtonPrevious = new QPushButton(groupBoxControl);
        pushButtonPrevious->setObjectName(QString::fromUtf8("pushButtonPrevious"));
        pushButtonPrevious->setGeometry(QRect(50, 20, 23, 23));
        pushButtonEnd = new QPushButton(groupBoxControl);
        pushButtonEnd->setObjectName(QString::fromUtf8("pushButtonEnd"));
        pushButtonEnd->setGeometry(QRect(110, 20, 23, 23));
        progressBarNavigation = new QProgressBar(groupBoxControl);
        progressBarNavigation->setObjectName(QString::fromUtf8("progressBarNavigation"));
        progressBarNavigation->setGeometry(QRect(140, 20, 118, 23));
        progressBarNavigation->setValue(24);
        spinBoxIndex = new QSpinBox(groupBoxControl);
        spinBoxIndex->setObjectName(QString::fromUtf8("spinBoxIndex"));
        spinBoxIndex->setGeometry(QRect(82, 50, 111, 26));
        pushButtonGotoIndex = new QPushButton(groupBoxControl);
        pushButtonGotoIndex->setObjectName(QString::fromUtf8("pushButtonGotoIndex"));
        pushButtonGotoIndex->setGeometry(QRect(10, 50, 55, 25));
        pushButtonRemove = new QPushButton(groupBoxControl);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));
        pushButtonRemove->setGeometry(QRect(210, 50, 55, 25));
        labelIncomingListCaption = new QLabel(centralWidget);
        labelIncomingListCaption->setObjectName(QString::fromUtf8("labelIncomingListCaption"));
        labelIncomingListCaption->setGeometry(QRect(10, 10, 221, 20));
        tableViewCurrent = new QTableView(centralWidget);
        tableViewCurrent->setObjectName(QString::fromUtf8("tableViewCurrent"));
        tableViewCurrent->setGeometry(QRect(10, 30, 231, 341));
        groupBoxEdit = new QGroupBox(centralWidget);
        groupBoxEdit->setObjectName(QString::fromUtf8("groupBoxEdit"));
        groupBoxEdit->setGeometry(QRect(20, 510, 451, 51));
        pushButtonLoad = new QPushButton(groupBoxEdit);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(10, 20, 75, 23));
        lineEditMemo = new QLineEdit(groupBoxEdit);
        lineEditMemo->setObjectName(QString::fromUtf8("lineEditMemo"));
        lineEditMemo->setGeometry(QRect(90, 20, 301, 23));
        pushButtonMemo = new QPushButton(groupBoxEdit);
        pushButtonMemo->setObjectName(QString::fromUtf8("pushButtonMemo"));
        pushButtonMemo->setGeometry(QRect(400, 20, 31, 23));
        groupBoxRotate = new QGroupBox(centralWidget);
        groupBoxRotate->setObjectName(QString::fromUtf8("groupBoxRotate"));
        groupBoxRotate->setGeometry(QRect(290, 380, 301, 51));
        pushButtonRotateCCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCCW->setObjectName(QString::fromUtf8("pushButtonRotateCCW"));
        pushButtonRotateCCW->setGeometry(QRect(93, 20, 75, 23));
        spinBoxAngle = new QSpinBox(groupBoxRotate);
        spinBoxAngle->setObjectName(QString::fromUtf8("spinBoxAngle"));
        spinBoxAngle->setGeometry(QRect(183, 20, 51, 22));
        spinBoxAngle->setMinimum(-90);
        spinBoxAngle->setMaximum(90);
        pushButtonRotateCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCW->setObjectName(QString::fromUtf8("pushButtonRotateCW"));
        pushButtonRotateCW->setGeometry(QRect(10, 20, 75, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(250, 30, 341, 341));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        listWidgetSubject = new QListWidget(tab_4);
        listWidgetSubject->setObjectName(QString::fromUtf8("listWidgetSubject"));
        listWidgetSubject->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listWidgetPlaces = new QListWidget(tab);
        listWidgetPlaces->setObjectName(QString::fromUtf8("listWidgetPlaces"));
        listWidgetPlaces->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        listWidgetPropertyes = new QListWidget(tab_2);
        listWidgetPropertyes->setObjectName(QString::fromUtf8("listWidgetPropertyes"));
        listWidgetPropertyes->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        listWidgetTheams = new QListWidget(tab_3);
        listWidgetTheams->setObjectName(QString::fromUtf8("listWidgetTheams"));
        listWidgetTheams->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        listWidgetKeys = new QListWidget(tab_6);
        listWidgetKeys->setObjectName(QString::fromUtf8("listWidgetKeys"));
        listWidgetKeys->setGeometry(QRect(10, 30, 150, 241));
        listWidgetSearch = new QListWidget(tab_6);
        listWidgetSearch->setObjectName(QString::fromUtf8("listWidgetSearch"));
        listWidgetSearch->setGeometry(QRect(175, 30, 150, 241));
        labelKeysCaption = new QLabel(tab_6);
        labelKeysCaption->setObjectName(QString::fromUtf8("labelKeysCaption"));
        labelKeysCaption->setGeometry(QRect(10, 5, 150, 20));
        labelKeysCaption->setAlignment(Qt::AlignCenter);
        labelSearchKeysCaption = new QLabel(tab_6);
        labelSearchKeysCaption->setObjectName(QString::fromUtf8("labelSearchKeysCaption"));
        labelSearchKeysCaption->setGeometry(QRect(175, 5, 150, 20));
        labelSearchKeysCaption->setAlignment(Qt::AlignCenter);
        pushButtonSearchOrYes = new QPushButton(tab_6);
        pushButtonSearchOrYes->setObjectName(QString::fromUtf8("pushButtonSearchOrYes"));
        pushButtonSearchOrYes->setGeometry(QRect(10, 280, 91, 23));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        listWidgetFounded = new QListWidget(tab_7);
        listWidgetFounded->setObjectName(QString::fromUtf8("listWidgetFounded"));
        listWidgetFounded->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_7, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        listWidgetOther = new QListWidget(tab_5);
        listWidgetOther->setObjectName(QString::fromUtf8("listWidgetOther"));
        listWidgetOther->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_5, QString());
        groupBoxPattern = new QGroupBox(centralWidget);
        groupBoxPattern->setObjectName(QString::fromUtf8("groupBoxPattern"));
        groupBoxPattern->setGeometry(QRect(290, 430, 301, 81));
        lineEditPattern = new QLineEdit(groupBoxPattern);
        lineEditPattern->setObjectName(QString::fromUtf8("lineEditPattern"));
        lineEditPattern->setGeometry(QRect(10, 14, 221, 25));
        QFont font;
        font.setPointSize(14);
        lineEditPattern->setFont(font);
        pushButtonSearchPatternX = new QPushButton(groupBoxPattern);
        pushButtonSearchPatternX->setObjectName(QString::fromUtf8("pushButtonSearchPatternX"));
        pushButtonSearchPatternX->setGeometry(QRect(240, 14, 51, 25));
        comboBoxPatterns = new QComboBox(groupBoxPattern);
        comboBoxPatterns->setObjectName(QString::fromUtf8("comboBoxPatterns"));
        comboBoxPatterns->setGeometry(QRect(10, 50, 221, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSelect_image = new QMenu(menuBar);
        menuSelect_image->setObjectName(QString::fromUtf8("menuSelect_image"));
        menuForms = new QMenu(menuBar);
        menuForms->setObjectName(QString::fromUtf8("menuForms"));
        menuTags = new QMenu(menuBar);
        menuTags->setObjectName(QString::fromUtf8("menuTags"));
        menuSearch = new QMenu(menuBar);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSelect_image->menuAction());
        menuBar->addAction(menuForms->menuAction());
        menuBar->addAction(menuTags->menuAction());
        menuBar->addAction(menuSearch->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionRemoveMovie);
        menuFile->addAction(actionRemoveText);
        menuFile->addAction(actionRemoveTif);
        menuFile->addAction(actionRemoveBin);
        menuFile->addAction(actionRemove3gp);
        menuFile->addAction(actionGetGroupsList);
        menuFile->addAction(actionGetKeysList);
        menuFile->addAction(actionRemoveSection);
        menuFile->addAction(actionExit);
        menuSelect_image->addAction(actionSelectImageBegin);
        menuSelect_image->addAction(actionSelectImageNext);
        menuSelect_image->addAction(actionSelectImagePrevious);
        menuSelect_image->addAction(actionSelectImageEnd);
        menuSelect_image->addAction(actionRotateCW_2);
        menuSelect_image->addAction(actionRotateCCW_2);
        menuSelect_image->addAction(actionGotoIndex);
        menuForms->addAction(actionViewPicture);
        menuTags->addAction(actionLoaadHashTagListSubject);
        menuTags->addAction(actionLoadHashTagListPlace);
        menuTags->addAction(actionLoadHashTagListProperty);
        menuTags->addAction(actionLoadHashTagListTheame);
        menuSearch->addAction(actionSearchRotated);
        menuSearch->addAction(actionSearchOrYes);
        menuSearch->addAction(actionSearchNamePattern1);
        menuSearch->addAction(actionSearchNamePattern2);
        menuSearch->addAction(actionSearchNamePatternX);
        menuSearch->addAction(actionSearchNamePatterns12Intersection);
        menuSearch->addAction(actionSearchNamePatterns1XIntersection);
        menuSearch->addAction(actionOpenFoundRecord);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PicturesControl1 ", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSelectImageBegin->setText(QCoreApplication::translate("MainWindow", "Begin", nullptr));
        actionSelectImageNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        actionSelectImagePrevious->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        actionSelectImageEnd->setText(QCoreApplication::translate("MainWindow", "End", nullptr));
        actionImport->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionViewPicture->setText(QCoreApplication::translate("MainWindow", "ViewPicture", nullptr));
        actionLoaadHashTagListSubject->setText(QCoreApplication::translate("MainWindow", "Subject", nullptr));
        actionLoadHashTagListPlace->setText(QCoreApplication::translate("MainWindow", "Place", nullptr));
        actionRemoveMovie->setText(QCoreApplication::translate("MainWindow", "RemoveMovie", nullptr));
        actionRotateCW->setText(QCoreApplication::translate("MainWindow", "RotateCW", nullptr));
        actionRotateCCW->setText(QCoreApplication::translate("MainWindow", "RotateCCW", nullptr));
        actionLoadHashTagListProperty->setText(QCoreApplication::translate("MainWindow", "Property", nullptr));
        actionImportFiles->setText(QCoreApplication::translate("MainWindow", "ImportFiles", nullptr));
        actionRotateCW_2->setText(QCoreApplication::translate("MainWindow", "RotateCW", nullptr));
        actionRotateCCW_2->setText(QCoreApplication::translate("MainWindow", "RotateCCW", nullptr));
        actionRemoveText->setText(QCoreApplication::translate("MainWindow", "RemoveText", nullptr));
        actionRemoveTif->setText(QCoreApplication::translate("MainWindow", "RemoveTif", nullptr));
        actionGetGroupsList->setText(QCoreApplication::translate("MainWindow", "GetGroupsList", nullptr));
        actionLoadHashTagListTheame->setText(QCoreApplication::translate("MainWindow", "Theame", nullptr));
        actionRemoveSection->setText(QCoreApplication::translate("MainWindow", "RemoveSection", nullptr));
        actionGotoIndex->setText(QCoreApplication::translate("MainWindow", "Goto index", nullptr));
        actionRemoveBin->setText(QCoreApplication::translate("MainWindow", "Remove Bin", nullptr));
        actionRemove3gp->setText(QCoreApplication::translate("MainWindow", "Remove 3gp", nullptr));
        actionSearchRotated->setText(QCoreApplication::translate("MainWindow", "SearchRotated", nullptr));
        actionSearchOrYes->setText(QCoreApplication::translate("MainWindow", "SearchOrYes", nullptr));
        actionGetKeysList->setText(QCoreApplication::translate("MainWindow", "GetKeysList", nullptr));
        actionSearchNamePattern1->setText(QCoreApplication::translate("MainWindow", "SearchNamePattern1", nullptr));
        actionSearchNamePattern2->setText(QCoreApplication::translate("MainWindow", "SearchNamePattern2", nullptr));
        actionSearchNamePatterns12Intersection->setText(QCoreApplication::translate("MainWindow", "SearchNamePatterns12Intersection", nullptr));
        actionSearchNamePatternX->setText(QCoreApplication::translate("MainWindow", "SearchNamePatternX", nullptr));
        actionOpenFoundRecord->setText(QCoreApplication::translate("MainWindow", "OpenFoundRecord", nullptr));
        actionSearchNamePatterns1XIntersection->setText(QCoreApplication::translate("MainWindow", "SearchNamePatterns1XIntersection", nullptr));
        groupBoxControl->setTitle(QCoreApplication::translate("MainWindow", "Navigation", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonBegin->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonBegin->setText(QCoreApplication::translate("MainWindow", "|<", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonNext->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonNext->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonPrevious->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonPrevious->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonEnd->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonEnd->setText(QCoreApplication::translate("MainWindow", ">|", nullptr));
        pushButtonGotoIndex->setText(QCoreApplication::translate("MainWindow", "Goto", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        labelIncomingListCaption->setText(QCoreApplication::translate("MainWindow", "Incoming tag", nullptr));
        groupBoxEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonMemo->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonMemo->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        groupBoxRotate->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonRotateCCW->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonRotateCCW->setText(QCoreApplication::translate("MainWindow", "Rotate CCW", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxAngle->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButtonRotateCW->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonRotateCW->setText(QCoreApplication::translate("MainWindow", "Rotate CW", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Subject", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Places", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Propertyes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Theams", nullptr));
        labelKeysCaption->setText(QCoreApplication::translate("MainWindow", "All keys", nullptr));
        labelSearchKeysCaption->setText(QCoreApplication::translate("MainWindow", "Keys for search", nullptr));
        pushButtonSearchOrYes->setText(QCoreApplication::translate("MainWindow", "Search OR YES", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Founded", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Other", nullptr));
        groupBoxPattern->setTitle(QCoreApplication::translate("MainWindow", "Pattern", nullptr));
        pushButtonSearchPatternX->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSelect_image->setTitle(QCoreApplication::translate("MainWindow", "Select image", nullptr));
        menuForms->setTitle(QCoreApplication::translate("MainWindow", "Forms", nullptr));
        menuTags->setTitle(QCoreApplication::translate("MainWindow", "Tags", nullptr));
        menuSearch->setTitle(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
