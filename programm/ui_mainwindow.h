/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(601, 640);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSelectImageBegin = new QAction(MainWindow);
        actionSelectImageBegin->setObjectName(QStringLiteral("actionSelectImageBegin"));
        actionSelectImageNext = new QAction(MainWindow);
        actionSelectImageNext->setObjectName(QStringLiteral("actionSelectImageNext"));
        actionSelectImagePrevious = new QAction(MainWindow);
        actionSelectImagePrevious->setObjectName(QStringLiteral("actionSelectImagePrevious"));
        actionSelectImageEnd = new QAction(MainWindow);
        actionSelectImageEnd->setObjectName(QStringLiteral("actionSelectImageEnd"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionViewPicture = new QAction(MainWindow);
        actionViewPicture->setObjectName(QStringLiteral("actionViewPicture"));
        actionViewPicture->setCheckable(true);
        actionViewPicture->setChecked(true);
        actionLoaadHashTagListSubject = new QAction(MainWindow);
        actionLoaadHashTagListSubject->setObjectName(QStringLiteral("actionLoaadHashTagListSubject"));
        actionLoadHashTagListPlace = new QAction(MainWindow);
        actionLoadHashTagListPlace->setObjectName(QStringLiteral("actionLoadHashTagListPlace"));
        actionRemoveMovie = new QAction(MainWindow);
        actionRemoveMovie->setObjectName(QStringLiteral("actionRemoveMovie"));
        actionRotateCW = new QAction(MainWindow);
        actionRotateCW->setObjectName(QStringLiteral("actionRotateCW"));
        actionRotateCCW = new QAction(MainWindow);
        actionRotateCCW->setObjectName(QStringLiteral("actionRotateCCW"));
        actionLoadHashTagListProperty = new QAction(MainWindow);
        actionLoadHashTagListProperty->setObjectName(QStringLiteral("actionLoadHashTagListProperty"));
        actionImportFiles = new QAction(MainWindow);
        actionImportFiles->setObjectName(QStringLiteral("actionImportFiles"));
        actionRotateCW_2 = new QAction(MainWindow);
        actionRotateCW_2->setObjectName(QStringLiteral("actionRotateCW_2"));
        actionRotateCCW_2 = new QAction(MainWindow);
        actionRotateCCW_2->setObjectName(QStringLiteral("actionRotateCCW_2"));
        actionRemoveText = new QAction(MainWindow);
        actionRemoveText->setObjectName(QStringLiteral("actionRemoveText"));
        actionRemoveTif = new QAction(MainWindow);
        actionRemoveTif->setObjectName(QStringLiteral("actionRemoveTif"));
        actionGetGroupsList = new QAction(MainWindow);
        actionGetGroupsList->setObjectName(QStringLiteral("actionGetGroupsList"));
        actionLoadHashTagListTheame = new QAction(MainWindow);
        actionLoadHashTagListTheame->setObjectName(QStringLiteral("actionLoadHashTagListTheame"));
        actionRemoveSection = new QAction(MainWindow);
        actionRemoveSection->setObjectName(QStringLiteral("actionRemoveSection"));
        actionGotoIndex = new QAction(MainWindow);
        actionGotoIndex->setObjectName(QStringLiteral("actionGotoIndex"));
        actionRemoveBin = new QAction(MainWindow);
        actionRemoveBin->setObjectName(QStringLiteral("actionRemoveBin"));
        actionRemove3gp = new QAction(MainWindow);
        actionRemove3gp->setObjectName(QStringLiteral("actionRemove3gp"));
        actionSearchRotated = new QAction(MainWindow);
        actionSearchRotated->setObjectName(QStringLiteral("actionSearchRotated"));
        actionSearchOrYes = new QAction(MainWindow);
        actionSearchOrYes->setObjectName(QStringLiteral("actionSearchOrYes"));
        actionGetKeysList = new QAction(MainWindow);
        actionGetKeysList->setObjectName(QStringLiteral("actionGetKeysList"));
        actionSearchNamePattern1 = new QAction(MainWindow);
        actionSearchNamePattern1->setObjectName(QStringLiteral("actionSearchNamePattern1"));
        actionSearchNamePattern2 = new QAction(MainWindow);
        actionSearchNamePattern2->setObjectName(QStringLiteral("actionSearchNamePattern2"));
        actionSearchNamePatterns12Intersection = new QAction(MainWindow);
        actionSearchNamePatterns12Intersection->setObjectName(QStringLiteral("actionSearchNamePatterns12Intersection"));
        actionSearchNamePatternX = new QAction(MainWindow);
        actionSearchNamePatternX->setObjectName(QStringLiteral("actionSearchNamePatternX"));
        actionOpenFoundRecord = new QAction(MainWindow);
        actionOpenFoundRecord->setObjectName(QStringLiteral("actionOpenFoundRecord"));
        actionSearchNamePatterns1XIntersection = new QAction(MainWindow);
        actionSearchNamePatterns1XIntersection->setObjectName(QStringLiteral("actionSearchNamePatterns1XIntersection"));
        actionInsertSubject = new QAction(MainWindow);
        actionInsertSubject->setObjectName(QStringLiteral("actionInsertSubject"));
        actionInsertPlace = new QAction(MainWindow);
        actionInsertPlace->setObjectName(QStringLiteral("actionInsertPlace"));
        actionInsertProperty = new QAction(MainWindow);
        actionInsertProperty->setObjectName(QStringLiteral("actionInsertProperty"));
        actionInsertTheame = new QAction(MainWindow);
        actionInsertTheame->setObjectName(QStringLiteral("actionInsertTheame"));
        actionShowNewFiles = new QAction(MainWindow);
        actionShowNewFiles->setObjectName(QStringLiteral("actionShowNewFiles"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QStringLiteral("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 271, 81));
        pushButtonBegin = new QPushButton(groupBoxControl);
        pushButtonBegin->setObjectName(QStringLiteral("pushButtonBegin"));
        pushButtonBegin->setGeometry(QRect(20, 20, 23, 23));
        pushButtonNext = new QPushButton(groupBoxControl);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(80, 20, 23, 23));
        pushButtonPrevious = new QPushButton(groupBoxControl);
        pushButtonPrevious->setObjectName(QStringLiteral("pushButtonPrevious"));
        pushButtonPrevious->setGeometry(QRect(50, 20, 23, 23));
        pushButtonEnd = new QPushButton(groupBoxControl);
        pushButtonEnd->setObjectName(QStringLiteral("pushButtonEnd"));
        pushButtonEnd->setGeometry(QRect(110, 20, 23, 23));
        progressBarNavigation = new QProgressBar(groupBoxControl);
        progressBarNavigation->setObjectName(QStringLiteral("progressBarNavigation"));
        progressBarNavigation->setGeometry(QRect(140, 20, 118, 23));
        progressBarNavigation->setValue(24);
        spinBoxIndex = new QSpinBox(groupBoxControl);
        spinBoxIndex->setObjectName(QStringLiteral("spinBoxIndex"));
        spinBoxIndex->setGeometry(QRect(82, 50, 111, 26));
        pushButtonGotoIndex = new QPushButton(groupBoxControl);
        pushButtonGotoIndex->setObjectName(QStringLiteral("pushButtonGotoIndex"));
        pushButtonGotoIndex->setGeometry(QRect(10, 50, 55, 25));
        pushButtonRemove = new QPushButton(groupBoxControl);
        pushButtonRemove->setObjectName(QStringLiteral("pushButtonRemove"));
        pushButtonRemove->setGeometry(QRect(210, 50, 55, 25));
        labelIncomingListCaption = new QLabel(centralWidget);
        labelIncomingListCaption->setObjectName(QStringLiteral("labelIncomingListCaption"));
        labelIncomingListCaption->setGeometry(QRect(10, 10, 221, 20));
        tableViewCurrent = new QTableView(centralWidget);
        tableViewCurrent->setObjectName(QStringLiteral("tableViewCurrent"));
        tableViewCurrent->setGeometry(QRect(10, 30, 231, 341));
        groupBoxEdit = new QGroupBox(centralWidget);
        groupBoxEdit->setObjectName(QStringLiteral("groupBoxEdit"));
        groupBoxEdit->setGeometry(QRect(10, 510, 451, 51));
        pushButtonLoad = new QPushButton(groupBoxEdit);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(10, 20, 75, 23));
        lineEditMemo = new QLineEdit(groupBoxEdit);
        lineEditMemo->setObjectName(QStringLiteral("lineEditMemo"));
        lineEditMemo->setGeometry(QRect(90, 20, 301, 23));
        pushButtonMemo = new QPushButton(groupBoxEdit);
        pushButtonMemo->setObjectName(QStringLiteral("pushButtonMemo"));
        pushButtonMemo->setGeometry(QRect(400, 20, 31, 23));
        groupBoxRotate = new QGroupBox(centralWidget);
        groupBoxRotate->setObjectName(QStringLiteral("groupBoxRotate"));
        groupBoxRotate->setGeometry(QRect(290, 380, 301, 51));
        pushButtonRotateCCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCCW->setObjectName(QStringLiteral("pushButtonRotateCCW"));
        pushButtonRotateCCW->setGeometry(QRect(93, 20, 75, 23));
        spinBoxAngle = new QSpinBox(groupBoxRotate);
        spinBoxAngle->setObjectName(QStringLiteral("spinBoxAngle"));
        spinBoxAngle->setGeometry(QRect(183, 20, 51, 22));
        spinBoxAngle->setMinimum(-90);
        spinBoxAngle->setMaximum(90);
        pushButtonRotateCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCW->setObjectName(QStringLiteral("pushButtonRotateCW"));
        pushButtonRotateCW->setGeometry(QRect(10, 20, 75, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(250, 30, 341, 341));
        tab_Subject = new QWidget();
        tab_Subject->setObjectName(QStringLiteral("tab_Subject"));
        tabWidget->addTab(tab_Subject, QString());
        tab_Place = new QWidget();
        tab_Place->setObjectName(QStringLiteral("tab_Place"));
        tabWidget->addTab(tab_Place, QString());
        tab_Property = new QWidget();
        tab_Property->setObjectName(QStringLiteral("tab_Property"));
        tabWidget->addTab(tab_Property, QString());
        tab_Theame = new QWidget();
        tab_Theame->setObjectName(QStringLiteral("tab_Theame"));
        tabWidget->addTab(tab_Theame, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        listWidgetKeys = new QListWidget(tab_6);
        listWidgetKeys->setObjectName(QStringLiteral("listWidgetKeys"));
        listWidgetKeys->setGeometry(QRect(10, 30, 150, 241));
        listWidgetSearch = new QListWidget(tab_6);
        listWidgetSearch->setObjectName(QStringLiteral("listWidgetSearch"));
        listWidgetSearch->setGeometry(QRect(175, 30, 150, 241));
        labelKeysCaption = new QLabel(tab_6);
        labelKeysCaption->setObjectName(QStringLiteral("labelKeysCaption"));
        labelKeysCaption->setGeometry(QRect(10, 5, 150, 20));
        labelKeysCaption->setAlignment(Qt::AlignCenter);
        labelSearchKeysCaption = new QLabel(tab_6);
        labelSearchKeysCaption->setObjectName(QStringLiteral("labelSearchKeysCaption"));
        labelSearchKeysCaption->setGeometry(QRect(175, 5, 150, 20));
        labelSearchKeysCaption->setAlignment(Qt::AlignCenter);
        pushButtonSearchOrYes = new QPushButton(tab_6);
        pushButtonSearchOrYes->setObjectName(QStringLiteral("pushButtonSearchOrYes"));
        pushButtonSearchOrYes->setGeometry(QRect(10, 280, 91, 23));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        listWidgetFounded = new QListWidget(tab_7);
        listWidgetFounded->setObjectName(QStringLiteral("listWidgetFounded"));
        listWidgetFounded->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_7, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        listWidgetOther = new QListWidget(tab_5);
        listWidgetOther->setObjectName(QStringLiteral("listWidgetOther"));
        listWidgetOther->setGeometry(QRect(10, 10, 261, 291));
        tabWidget->addTab(tab_5, QString());
        groupBoxPattern = new QGroupBox(centralWidget);
        groupBoxPattern->setObjectName(QStringLiteral("groupBoxPattern"));
        groupBoxPattern->setGeometry(QRect(290, 430, 301, 81));
        lineEditPattern = new QLineEdit(groupBoxPattern);
        lineEditPattern->setObjectName(QStringLiteral("lineEditPattern"));
        lineEditPattern->setGeometry(QRect(10, 14, 221, 25));
        QFont font;
        font.setPointSize(14);
        lineEditPattern->setFont(font);
        pushButtonSearchPatternX = new QPushButton(groupBoxPattern);
        pushButtonSearchPatternX->setObjectName(QStringLiteral("pushButtonSearchPatternX"));
        pushButtonSearchPatternX->setGeometry(QRect(240, 14, 51, 25));
        comboBoxPatterns = new QComboBox(groupBoxPattern);
        comboBoxPatterns->setObjectName(QStringLiteral("comboBoxPatterns"));
        comboBoxPatterns->setGeometry(QRect(10, 50, 221, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSelect_image = new QMenu(menuBar);
        menuSelect_image->setObjectName(QStringLiteral("menuSelect_image"));
        menuForms = new QMenu(menuBar);
        menuForms->setObjectName(QStringLiteral("menuForms"));
        menuTags = new QMenu(menuBar);
        menuTags->setObjectName(QStringLiteral("menuTags"));
        menuSearch = new QMenu(menuBar);
        menuSearch->setObjectName(QStringLiteral("menuSearch"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        menuFile->addAction(actionShowNewFiles);
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

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
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
        groupBoxControl->setTitle(QApplication::translate("MainWindow", "Navigation", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonBegin->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonBegin->setText(QApplication::translate("MainWindow", "|<", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonNext->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonNext->setText(QApplication::translate("MainWindow", ">", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonPrevious->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonPrevious->setText(QApplication::translate("MainWindow", "<", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonEnd->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonEnd->setText(QApplication::translate("MainWindow", ">|", 0));
        pushButtonGotoIndex->setText(QApplication::translate("MainWindow", "Goto", 0));
        pushButtonRemove->setText(QApplication::translate("MainWindow", "Remove", 0));
        labelIncomingListCaption->setText(QApplication::translate("MainWindow", "Incoming tag", 0));
        groupBoxEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonMemo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonMemo->setText(QApplication::translate("MainWindow", "M", 0));
        groupBoxRotate->setTitle(QApplication::translate("MainWindow", "Rotate", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonRotateCCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonRotateCCW->setText(QApplication::translate("MainWindow", "Rotate CCW", 0));
#ifndef QT_NO_TOOLTIP
        spinBoxAngle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonRotateCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
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
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Other", 0));
        groupBoxPattern->setTitle(QApplication::translate("MainWindow", "Pattern", 0));
        pushButtonSearchPatternX->setText(QApplication::translate("MainWindow", "Search", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSelect_image->setTitle(QApplication::translate("MainWindow", "Select image", 0));
        menuForms->setTitle(QApplication::translate("MainWindow", "Forms", 0));
        menuTags->setTitle(QApplication::translate("MainWindow", "Tags", 0));
        menuSearch->setTitle(QApplication::translate("MainWindow", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
