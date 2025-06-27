/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
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
    QAction *actionInsertSubject;
    QAction *actionInsertPlace;
    QAction *actionInsertProperty;
    QAction *actionInsertTheame;
    QAction *actionShowNewFiles;
    QAction *actionEraseSection;
    QAction *actionLoadRemovedSectionsList;
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
    QPushButton *pushButtonErase;
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
    QWidget *tab_Subject;
    QWidget *tab_Place;
    QWidget *tab_Property;
    QWidget *tab_Theame;
    QWidget *tab_6;
    QListWidget *listWidgetKeys;
    QListWidget *listWidgetSearch;
    QLabel *labelKeysCaption;
    QLabel *labelSearchKeysCaption;
    QPushButton *pushButtonSearchOrYes;
    QWidget *tab_7;
    QListWidget *listWidgetFounded;
    QGroupBox *groupBoxPattern;
    QLineEdit *lineEditPattern;
    QPushButton *pushButtonSearchPatternX;
    QComboBox *comboBoxPatterns;
    QGroupBox *groupBoxLog;
    QListWidget *listWidgetOther;
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
<<<<<<< Updated upstream
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(601, 640);
=======
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(892, 640);
>>>>>>> Stashed changes
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
        actionInsertSubject = new QAction(MainWindow);
        actionInsertSubject->setObjectName(QString::fromUtf8("actionInsertSubject"));
        actionInsertPlace = new QAction(MainWindow);
        actionInsertPlace->setObjectName(QString::fromUtf8("actionInsertPlace"));
        actionInsertProperty = new QAction(MainWindow);
        actionInsertProperty->setObjectName(QString::fromUtf8("actionInsertProperty"));
        actionInsertTheame = new QAction(MainWindow);
        actionInsertTheame->setObjectName(QString::fromUtf8("actionInsertTheame"));
        actionShowNewFiles = new QAction(MainWindow);
        actionShowNewFiles->setObjectName(QString::fromUtf8("actionShowNewFiles"));
        actionEraseSection = new QAction(MainWindow);
<<<<<<< Updated upstream
        actionEraseSection->setObjectName(QString::fromUtf8("actionEraseSection"));
=======
        actionEraseSection->setObjectName(QStringLiteral("actionEraseSection"));
        actionLoadRemovedSectionsList = new QAction(MainWindow);
        actionLoadRemovedSectionsList->setObjectName(QStringLiteral("actionLoadRemovedSectionsList"));
>>>>>>> Stashed changes
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QString::fromUtf8("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 271, 111));
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
        pushButtonErase = new QPushButton(groupBoxControl);
        pushButtonErase->setObjectName(QString::fromUtf8("pushButtonErase"));
        pushButtonErase->setGeometry(QRect(210, 80, 55, 25));
        labelIncomingListCaption = new QLabel(centralWidget);
        labelIncomingListCaption->setObjectName(QString::fromUtf8("labelIncomingListCaption"));
        labelIncomingListCaption->setGeometry(QRect(10, 10, 221, 20));
        tableViewCurrent = new QTableView(centralWidget);
        tableViewCurrent->setObjectName(QString::fromUtf8("tableViewCurrent"));
        tableViewCurrent->setGeometry(QRect(10, 30, 231, 341));
        groupBoxEdit = new QGroupBox(centralWidget);
        groupBoxEdit->setObjectName(QString::fromUtf8("groupBoxEdit"));
        groupBoxEdit->setGeometry(QRect(10, 510, 451, 51));
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
        tab_Subject = new QWidget();
        tab_Subject->setObjectName(QString::fromUtf8("tab_Subject"));
        tabWidget->addTab(tab_Subject, QString());
        tab_Place = new QWidget();
        tab_Place->setObjectName(QString::fromUtf8("tab_Place"));
        tabWidget->addTab(tab_Place, QString());
        tab_Property = new QWidget();
        tab_Property->setObjectName(QString::fromUtf8("tab_Property"));
        tabWidget->addTab(tab_Property, QString());
        tab_Theame = new QWidget();
        tab_Theame->setObjectName(QString::fromUtf8("tab_Theame"));
        tabWidget->addTab(tab_Theame, QString());
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
<<<<<<< Updated upstream
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        listWidgetOther = new QListWidget(tab_5);
        listWidgetOther->setObjectName(QString::fromUtf8("listWidgetOther"));
        listWidgetOther->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_5, QString());
=======
>>>>>>> Stashed changes
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
        groupBoxLog = new QGroupBox(centralWidget);
        groupBoxLog->setObjectName(QStringLiteral("groupBoxLog"));
        groupBoxLog->setGeometry(QRect(600, 30, 281, 551));
        listWidgetOther = new QListWidget(groupBoxLog);
        listWidgetOther->setObjectName(QStringLiteral("listWidgetOther"));
        listWidgetOther->setGeometry(QRect(10, 20, 261, 521));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
<<<<<<< Updated upstream
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 21));
=======
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 892, 21));
>>>>>>> Stashed changes
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
        menuFile->addAction(actionLoadRemovedSectionsList);
        menuFile->addAction(actionRemoveSection);
        menuFile->addAction(actionShowNewFiles);
        menuFile->addAction(actionEraseSection);
        menuFile->addAction(actionExit);
        menuSelect_image->addAction(actionSelectImageBegin);
        menuSelect_image->addAction(actionSelectImageNext);
        menuSelect_image->addAction(actionSelectImagePrevious);
        menuSelect_image->addAction(actionSelectImageEnd);
        menuSelect_image->addAction(actionRotateCW_2);
        menuSelect_image->addAction(actionRotateCCW_2);
        menuSelect_image->addAction(actionGotoIndex);
        menuForms->addAction(actionViewPicture);
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

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
<<<<<<< Updated upstream
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PicturesControl1 ", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionSelectImageBegin->setText(QApplication::translate("MainWindow", "Begin", nullptr));
        actionSelectImageNext->setText(QApplication::translate("MainWindow", "Next", nullptr));
        actionSelectImagePrevious->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        actionSelectImageEnd->setText(QApplication::translate("MainWindow", "End", nullptr));
        actionImport->setText(QApplication::translate("MainWindow", "Import", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        actionViewPicture->setText(QApplication::translate("MainWindow", "ViewPicture", nullptr));
        actionLoaadHashTagListSubject->setText(QApplication::translate("MainWindow", "LoadSubject", nullptr));
        actionLoadHashTagListPlace->setText(QApplication::translate("MainWindow", "LoadPlace", nullptr));
        actionRemoveMovie->setText(QApplication::translate("MainWindow", "RemoveMovie", nullptr));
        actionRotateCW->setText(QApplication::translate("MainWindow", "RotateCW", nullptr));
        actionRotateCCW->setText(QApplication::translate("MainWindow", "RotateCCW", nullptr));
        actionLoadHashTagListProperty->setText(QApplication::translate("MainWindow", "LoadProperty", nullptr));
        actionImportFiles->setText(QApplication::translate("MainWindow", "ImportFiles", nullptr));
        actionRotateCW_2->setText(QApplication::translate("MainWindow", "RotateCW", nullptr));
        actionRotateCCW_2->setText(QApplication::translate("MainWindow", "RotateCCW", nullptr));
        actionRemoveText->setText(QApplication::translate("MainWindow", "RemoveText", nullptr));
        actionRemoveTif->setText(QApplication::translate("MainWindow", "RemoveTif", nullptr));
        actionGetGroupsList->setText(QApplication::translate("MainWindow", "GetGroupsList", nullptr));
        actionLoadHashTagListTheame->setText(QApplication::translate("MainWindow", "LoadTheame", nullptr));
        actionRemoveSection->setText(QApplication::translate("MainWindow", "RemoveSection", nullptr));
        actionGotoIndex->setText(QApplication::translate("MainWindow", "Goto index", nullptr));
        actionRemoveBin->setText(QApplication::translate("MainWindow", "Remove Bin", nullptr));
        actionRemove3gp->setText(QApplication::translate("MainWindow", "Remove 3gp", nullptr));
        actionSearchRotated->setText(QApplication::translate("MainWindow", "SearchRotated", nullptr));
        actionSearchOrYes->setText(QApplication::translate("MainWindow", "SearchOrYes", nullptr));
        actionGetKeysList->setText(QApplication::translate("MainWindow", "GetKeysList", nullptr));
        actionSearchNamePattern1->setText(QApplication::translate("MainWindow", "SearchNamePattern1", nullptr));
        actionSearchNamePattern2->setText(QApplication::translate("MainWindow", "SearchNamePattern2", nullptr));
        actionSearchNamePatterns12Intersection->setText(QApplication::translate("MainWindow", "SearchNamePatterns12Intersection", nullptr));
        actionSearchNamePatternX->setText(QApplication::translate("MainWindow", "SearchNamePatternX", nullptr));
        actionOpenFoundRecord->setText(QApplication::translate("MainWindow", "OpenFoundRecord", nullptr));
        actionSearchNamePatterns1XIntersection->setText(QApplication::translate("MainWindow", "SearchNamePatterns1XIntersection", nullptr));
        actionInsertSubject->setText(QApplication::translate("MainWindow", "InsertSubject", nullptr));
        actionInsertPlace->setText(QApplication::translate("MainWindow", "InsertPlace", nullptr));
        actionInsertProperty->setText(QApplication::translate("MainWindow", "InsertProperty", nullptr));
        actionInsertTheame->setText(QApplication::translate("MainWindow", "InsertTheame", nullptr));
        actionShowNewFiles->setText(QApplication::translate("MainWindow", "ShowNewFiles", nullptr));
        actionEraseSection->setText(QApplication::translate("MainWindow", "EraseSection", nullptr));
        groupBoxControl->setTitle(QApplication::translate("MainWindow", "Navigation", nullptr));
=======
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PicturesControl1 ", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSelectImageBegin->setText(QApplication::translate("MainWindow", "Begin", 0));
        actionSelectImageNext->setText(QApplication::translate("MainWindow", "Next", 0));
        actionSelectImagePrevious->setText(QApplication::translate("MainWindow", "Previous", 0));
        actionSelectImageEnd->setText(QApplication::translate("MainWindow", "End", 0));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionViewPicture->setText(QApplication::translate("MainWindow", "ViewPicture", 0));
        actionLoaadHashTagListSubject->setText(QApplication::translate("MainWindow", "LoadSubject", 0));
        actionLoadHashTagListPlace->setText(QApplication::translate("MainWindow", "LoadPlace", 0));
        actionRemoveMovie->setText(QApplication::translate("MainWindow", "RemoveMovie", 0));
        actionRotateCW->setText(QApplication::translate("MainWindow", "RotateCW", 0));
        actionRotateCCW->setText(QApplication::translate("MainWindow", "RotateCCW", 0));
        actionLoadHashTagListProperty->setText(QApplication::translate("MainWindow", "LoadProperty", 0));
        actionImportFiles->setText(QApplication::translate("MainWindow", "ImportFiles", 0));
        actionRotateCW_2->setText(QApplication::translate("MainWindow", "RotateCW", 0));
        actionRotateCCW_2->setText(QApplication::translate("MainWindow", "RotateCCW", 0));
        actionRemoveText->setText(QApplication::translate("MainWindow", "RemoveText", 0));
        actionRemoveTif->setText(QApplication::translate("MainWindow", "RemoveTif", 0));
        actionGetGroupsList->setText(QApplication::translate("MainWindow", "GetGroupsList", 0));
        actionLoadHashTagListTheame->setText(QApplication::translate("MainWindow", "LoadTheame", 0));
        actionRemoveSection->setText(QApplication::translate("MainWindow", "RemoveSection", 0));
        actionGotoIndex->setText(QApplication::translate("MainWindow", "Goto index", 0));
        actionRemoveBin->setText(QApplication::translate("MainWindow", "Remove Bin", 0));
        actionRemove3gp->setText(QApplication::translate("MainWindow", "Remove 3gp", 0));
        actionSearchRotated->setText(QApplication::translate("MainWindow", "SearchRotated", 0));
        actionSearchOrYes->setText(QApplication::translate("MainWindow", "SearchOrYes", 0));
        actionGetKeysList->setText(QApplication::translate("MainWindow", "GetKeysList", 0));
        actionSearchNamePattern1->setText(QApplication::translate("MainWindow", "SearchNamePattern1", 0));
        actionSearchNamePattern2->setText(QApplication::translate("MainWindow", "SearchNamePattern2", 0));
        actionSearchNamePatterns12Intersection->setText(QApplication::translate("MainWindow", "SearchNamePatterns12Intersection", 0));
        actionSearchNamePatternX->setText(QApplication::translate("MainWindow", "SearchNamePatternX", 0));
        actionOpenFoundRecord->setText(QApplication::translate("MainWindow", "OpenFoundRecord", 0));
        actionSearchNamePatterns1XIntersection->setText(QApplication::translate("MainWindow", "SearchNamePatterns1XIntersection", 0));
        actionInsertSubject->setText(QApplication::translate("MainWindow", "InsertSubject", 0));
        actionInsertPlace->setText(QApplication::translate("MainWindow", "InsertPlace", 0));
        actionInsertProperty->setText(QApplication::translate("MainWindow", "InsertProperty", 0));
        actionInsertTheame->setText(QApplication::translate("MainWindow", "InsertTheame", 0));
        actionShowNewFiles->setText(QApplication::translate("MainWindow", "ShowNewFiles", 0));
        actionEraseSection->setText(QApplication::translate("MainWindow", "EraseSection", 0));
        actionLoadRemovedSectionsList->setText(QApplication::translate("MainWindow", "GetRemovedSectionsList", 0));
        groupBoxControl->setTitle(QApplication::translate("MainWindow", "Navigation", 0));
>>>>>>> Stashed changes
#ifndef QT_NO_TOOLTIP
        pushButtonBegin->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonBegin->setText(QApplication::translate("MainWindow", "|<", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonNext->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonNext->setText(QApplication::translate("MainWindow", ">", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonPrevious->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonPrevious->setText(QApplication::translate("MainWindow", "<", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonEnd->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonEnd->setText(QApplication::translate("MainWindow", ">|", nullptr));
        pushButtonGotoIndex->setText(QApplication::translate("MainWindow", "Goto", nullptr));
        pushButtonRemove->setText(QApplication::translate("MainWindow", "Remove", nullptr));
        pushButtonErase->setText(QApplication::translate("MainWindow", "Erase", nullptr));
        labelIncomingListCaption->setText(QApplication::translate("MainWindow", "Incoming tag", nullptr));
        groupBoxEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonMemo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonMemo->setText(QApplication::translate("MainWindow", "M", nullptr));
        groupBoxRotate->setTitle(QApplication::translate("MainWindow", "Rotate", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonRotateCCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonRotateCCW->setText(QApplication::translate("MainWindow", "Rotate CCW", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBoxAngle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonRotateCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
<<<<<<< Updated upstream
        pushButtonRotateCW->setText(QApplication::translate("MainWindow", "Rotate CW", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Subject), QApplication::translate("MainWindow", "\320\241\321\203\321\211\320\275\320\276\321\201\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Place), QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Property), QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Theame), QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\260", nullptr));
        labelKeysCaption->setText(QApplication::translate("MainWindow", "All keys", nullptr));
        labelSearchKeysCaption->setText(QApplication::translate("MainWindow", "Keys for search", nullptr));
        pushButtonSearchOrYes->setText(QApplication::translate("MainWindow", "Search OR YES", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Founded", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Other", nullptr));
        groupBoxPattern->setTitle(QApplication::translate("MainWindow", "Pattern", nullptr));
        pushButtonSearchPatternX->setText(QApplication::translate("MainWindow", "Search", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuSelect_image->setTitle(QApplication::translate("MainWindow", "Select image", nullptr));
        menuForms->setTitle(QApplication::translate("MainWindow", "Forms", nullptr));
        menuTags->setTitle(QApplication::translate("MainWindow", "Tags", nullptr));
        menuSearch->setTitle(QApplication::translate("MainWindow", "Search", nullptr));
=======
        pushButtonRotateCW->setText(QApplication::translate("MainWindow", "Rotate CW", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Subject), QApplication::translate("MainWindow", "\320\241\321\203\321\211\320\275\320\276\321\201\321\202\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Place), QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Property), QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Theame), QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\260", 0));
        labelKeysCaption->setText(QApplication::translate("MainWindow", "All keys", 0));
        labelSearchKeysCaption->setText(QApplication::translate("MainWindow", "Keys for search", 0));
        pushButtonSearchOrYes->setText(QApplication::translate("MainWindow", "Search OR YES", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Founded", 0));
        groupBoxPattern->setTitle(QApplication::translate("MainWindow", "Pattern", 0));
        pushButtonSearchPatternX->setText(QApplication::translate("MainWindow", "Search", 0));
        groupBoxLog->setTitle(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSelect_image->setTitle(QApplication::translate("MainWindow", "Select image", 0));
        menuForms->setTitle(QApplication::translate("MainWindow", "Forms", 0));
        menuTags->setTitle(QApplication::translate("MainWindow", "Tags", 0));
        menuSearch->setTitle(QApplication::translate("MainWindow", "Search", 0));
>>>>>>> Stashed changes
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
