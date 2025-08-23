#include "mainwindow.h"
#include "ui_mainwindow.h"

//-----------------------------------------------------------------------------
//Глобальные переменные
//-----------------------------------------------------------------------------

std::atomic<int> iCurrentIndexGlobal(0); //Индекс для отображения

//-----------------------------------------------------------------------------
//Реализации элементов класса
//-----------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cIniFile::Groups = new QStringList();
    cIniFile::Keys = new QStringList();
    cIniFile::SearchKeys = new QStringList();

    //---
    qDebug() << "Build abi: " << QSysInfo::buildAbi();
    qDebug() << "Build CPU architecture: " << QSysInfo::buildCpuArchitecture();
    qDebug() << "Current CPU architecture: " << QSysInfo::currentCpuArchitecture();
    qDebug() << "Kernel type: " << QSysInfo::kernelType();
    qDebug() << "Kernel version: " << QSysInfo::kernelVersion();
    qDebug() << "Machine host name: " << QSysInfo::machineHostName();
    qDebug() << "Product name: " << QSysInfo::prettyProductName();
    qDebug() << "Product type: " << QSysInfo::productType();
    qDebug() << "Product version: " << QSysInfo::productVersion();

    qDebug() << "Application name: " << qsApplicationName;

    // Определение конкретной ОС
    #if defined(Q_OS_WIN)
        qDebug() << "Running on Windows";
        cIniFile::iSystemType = WINDOWS_SYSTEM_TYPE;
    #elif defined(Q_OS_LINUX)
        qDebug() << "Running on Linux";
        cIniFile::iSystemType = LINUX_SYSTEM_TYPE;
    #else
        qDebug() << "Running on unknown OS";
        cIniFile::iSystemType = 0;
    #endif

    //--- Определение имён файлов

    // Создаем объект QSettings с указанием формата INI и пути к файлу

    QString qsApplicationDirPath = QCoreApplication::applicationDirPath();
    int iLastSlashIndex = qsApplicationDirPath.lastIndexOf('/');
    QString qsApplicationDirProgrammPath = qsApplicationDirPath.mid(0, iLastSlashIndex);

    qDebug() << "ApplicationDirPath=" << qsApplicationDirPath << " LastIndexOfSlash=" << iLastSlashIndex << " ApplicationDirProgrammPath=" << qsApplicationDirProgrammPath;

    //QString qsSettingsFileName = "C:/WORK/PicturesControl/PicturesControl1/programm/settings.ini";
    QString qsSettingsFileName = qsApplicationDirProgrammPath + "/settings.ini";

    QSettings settings(qsSettingsFileName, QSettings::IniFormat);
/*
    //Кусок для тестирования, если что-то пошло не так
    QStringList SettingsGroups = settings.childGroups();
    qDebug() << "settings groups count:" << SettingsGroups.count();

    QListIterator<QString> readIt(SettingsGroups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        qDebug() << "SectionName=" << qsSection;
        settings.beginGroup(qsSection);
        //===
        qDebug() << "iterator: section=" << qsSection;
        QStringList keys = settings.childKeys();
        QListIterator<QString> readIt(keys);
        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            qDebug() << "iterator: key=" << key << "; value=" << value;
        }
        //===
        settings.endGroup();
    }

    qDebug() << "--------------------------------------";

    QString value1 = settings.value("IniFileNameWindows","1").toString();
    QString value2 = settings.value("IniFileNameLinux","2").toString();

    QString value3 = settings.value("ProjectPathWindows","3").toString();
    QString value4 = settings.value("ProjectPathLinux","4").toString();

    QString value5 = settings.value("HashTagFileNameSuffixWindows","5").toString();
    QString value6 = settings.value("HashTagFileNameSuffixLinux","6").toString();

    qDebug() << "Value1=" << value1;
    qDebug() << "Value2=" << value2;
    qDebug() << "Value3=" << value3;
    qDebug() << "Value4=" << value4;
    qDebug() << "Value5=" << value5;
    qDebug() << "Value6=" << value6;
*/
    // Читаем значения из INI-файла

    settings.beginGroup("Files");

    QString qsIniFileNameWindows = settings.value("IniFileNameWindows","1").toString();//"C:/Work/Ships";
    QString qsIniFileNameLinux = settings.value("IniFileNameLinux","2").toString();//"/home/andy/From Smartfone";

    QString qsProjectPathWindows = settings.value("ProjectPathWindows","3").toString();//"C:/WORK/PicturesControl";
    QString qsProjectPathLinux = settings.value("ProjectPathLinux","4").toString();//"/home/andy/MyQtProjects";

    QString qsHashTagFileNameSuffixWindows = settings.value("HashTagFileNameSuffixWindows","5").toString();//"Ships";
    QString qsHashTagFileNameSuffixLinux = settings.value("HashTagFileNameSuffixLinux","6").toString();//"Photos";

    settings.endGroup();

    QString qsIniFileName;
    qsProjectName = "/" + qsApplicationName;
    qsProjectNameDataSuffix = "/programm/data";
    qsProjectNameImgSuffix = "/programm/img/tmp";
    qsDataFileNameExtension = ".txt";

    if(cIniFile::iSystemType == LINUX_SYSTEM_TYPE)
    {

        qsProjectPath = qsProjectPathLinux;
        qsHashTagFileNameSuffix = qsHashTagFileNameSuffixLinux;
        cIniFile::GarbageCollectorPath = "/home/andy/GarbageCollector/";
        //qsProjectPath = "/home/andy/MyQtProjects";
        //qsHashTagFileNameSuffix = "Photos";
         qsIniFileName = qsIniFileNameLinux;

    }
    else
    {

        qsProjectPath = qsProjectPathWindows;
        qsHashTagFileNameSuffix = qsHashTagFileNameSuffixWindows;
        cIniFile::GarbageCollectorPath = "C:/WORK/GarbageCollector/";
        //qsProjectPath = "C:/WORK/PicturesControl";
        //qsHashTagFileNameSuffix = "Ships";
         qsIniFileName = qsIniFileNameWindows;
    }

    //---Прямые имена файлов
    //cIniFile::iniFilePath = "/home/andy/MyQtProjects/PicturesControl1/programm/data/FilesConfigPhotos.ini";//Linux version
    //cIniFile::iniFilePath = "C:/WORK/PicturesControl/PicturesControl1/programm/data/FilesConfigShips.ini";//Windows version

    cIniFile::iniFilePath = qsProjectPath + qsProjectName + "/programm/data/FilesConfig" + qsHashTagFileNameSuffix + ".ini";

    cIniFile::pattern1StringListFilePath = "./data/StringListPattern1.txt";//qsProjectPath + qsProjectName + "/programm/data/pattern1StringListFile" + qsDataFileNameExtension;
    cIniFile::pattern2StringListFilePath = "./data/StringListPattern2.txt";//qsProjectPath + qsProjectName + "/programm/data/pattern2StringListFile" + qsDataFileNameExtension;
    cIniFile::patternXStringListFilePath = qsProjectPath + qsProjectName + "/programm/data/pattern3StringListFile" + qsDataFileNameExtension;
    cIniFile::scaledImagePath = qsProjectPath + qsProjectName + "/programm/img/tmp/scaled_image.png";
    cIniFile::filePathRemovedSectionList = qsProjectPath + qsProjectName + "/programm/data/RemovedSectionList" + qsHashTagFileNameSuffix + qsDataFileNameExtension;
    cIniFile::fileSubjectHashTag = qsProjectPath + qsProjectName + "/programm/data/HashTagListSubject" + qsHashTagFileNameSuffix + qsDataFileNameExtension;
    cIniFile::filePlaceHashTag = qsProjectPath + qsProjectName + "/programm/data/HashTagListPlaces" + qsHashTagFileNameSuffix + qsDataFileNameExtension;
    cIniFile::filePropertyHashTag = qsProjectPath + qsProjectName + "/programm/data/HashTagListPropertyes" + qsHashTagFileNameSuffix + qsDataFileNameExtension;
    cIniFile::fileTheameHashTag = qsProjectPath + qsProjectName + "/programm/data/HashTagListTheams" + qsHashTagFileNameSuffix + qsDataFileNameExtension;

    cIniFile::fileNewItems = qsProjectPath + qsProjectName + "/programm/data/NewItems" + qsHashTagFileNameSuffix + qsDataFileNameExtension;

    qDebug() << "qsIniFileName=" << qsIniFileName;
    qDebug() << "cIniFile::iniFilePath=" << cIniFile::iniFilePath;
    qDebug() << "cIniFile::pattern1StringListFilePath=" << cIniFile::pattern1StringListFilePath;
    qDebug() << "cIniFile::pattern2StringListFilePath=" << cIniFile::pattern2StringListFilePath;
    qDebug() << "cIniFile::patternXStringListFilePath=" << cIniFile::patternXStringListFilePath;
    qDebug() << "cIniFile::scaledImagePath=" << cIniFile::scaledImagePath;
    qDebug() << "cIniFile::filePathRemovedSectionList=" << cIniFile::filePathRemovedSectionList;
    qDebug() << "cIniFile::fileSubjectHashTag=" << cIniFile::fileSubjectHashTag;
    qDebug() << "cIniFile::filePlaceHashTag=" << cIniFile::filePlaceHashTag;
    qDebug() << "cIniFile::filePropertyHashTag=" << cIniFile::filePropertyHashTag;
    qDebug() << "cIniFile::fileTheameHashTag=" << cIniFile::fileTheameHashTag;
    qDebug() << "cIniFile::fileNewItems=" << cIniFile::fileNewItems;


    cIniFile::IniFile.setDirectoryPaht(qsIniFileName);

    //---

    cIniFile::qslDeletedSections.clear();

    ui->setupUi(this);

    //20250821
    ui->listWidgetOther->clear();
    connect(this, &MainWindow::infoMessage, this, &MainWindow::execInfoMessage);
    connect(this, &MainWindow::beginMessage, this, &MainWindow::execBeginMessage);
    connect(this, &MainWindow::endMessage, this, &MainWindow::execEndMessage);

    //---20250820 Настройка пула потоков
    int iIdealThreadCount = QThread::idealThreadCount();

    qDebug() << "ctor: ideal thread count=" << iIdealThreadCount;

    emit infoMessage("Ideal thread count=" + QString::number(iIdealThreadCount));

    threadPool.setMaxThreadCount(iIdealThreadCount);
    //---

    ImportFilesInstance = new cImportFiles();
    ImportFilesInstance->install(
        ui->listWidgetOther,
        ui->listWidgetFounded,
        ui->listWidgetKeys
        );

    NavigationInstance = new cNavigation();
    NavigationInstance->install(
        ui->listWidgetOther,
        ui->tableViewCurrent,
        ui->groupBoxNavigation
        );

    ActionsExec = new cActionsExec();
    ActionsExec->install(ui->listWidgetOther);

    LoadFilesInstance = new cLoadFiles();
    LoadFilesInstance->install(ui->listWidgetOther);

    DrawFilesInstance = new cDrawFilex();
    DrawFilesInstance->install(ui->listWidgetOther);

    SearchInstance = new cSearch();
    SearchInstance->install(ui->listWidgetFounded, ui->listWidgetOther, ui->listWidgetKeys, ui->lineEditPattern, ui->lineEditSearchAllKeys);

    ListWidgetPlace = new cListWidgetPlace();
    ListWidgetPlace->install(ui->tab_Place);

    ListWidgetSubject = new cListWidgetSubject();
    ListWidgetSubject->install(ui->tab_Subject);

    ListWidgetProperty = new cListWidgetProperty();
    ListWidgetProperty->install(ui->tab_Property);

    ListWidgetTheame = new cListWidgetTheame();
    ListWidgetTheame->install(ui->tab_Theame);

    ui->comboBoxPatterns->clear();
    ui->comboBoxPatterns->addItem("^[Ii][Mm][Gg]_20[0-9]{6}_[0-9]{6}");
    ui->comboBoxPatterns->addItem("^20[0-9]{2}-[0-9]{2}-[0-9]{2} [0-9]{2}-[0-9]{2}-[0-9]{2}");
    ui->comboBoxPatterns->addItem("^20[0-9]{6}_[0-9]{6}");
    ui->comboBoxPatterns->addItem("^[Mm][Aa][Ii][Ll]");
    ui->comboBoxPatterns->addItem("^.+_1$");

    NavigationInstance->pbGoTo->setVisible(true);//РЕЖИМ АДМИНИСТРАТОРА
    NavigationInstance->pbReload->setVisible(true);//РЕЖИМ АДМИНИСТРАТОРА

    connect(SearchInstance, &cSearch::gotoInstallNavigation, NavigationInstance, &cNavigation::installNavigation);

    connect(ui->actionViewPicture, SIGNAL(triggered()), this, SLOT( execActionFormViewPicture()));
    connect(ui->actionGotoIndex, SIGNAL(triggered()), NavigationInstance, SLOT( execActionGotoIndex()));
    connect(ui->actionSelectImageBegin, SIGNAL(triggered()), NavigationInstance, SLOT( execActionSelectImageBegin()));
    connect(ui->actionSelectImageNext, SIGNAL(triggered()), NavigationInstance, SLOT( execActionSelectImageNext()));
    connect(ui->actionSelectImagePrevious, SIGNAL(triggered()), NavigationInstance, SLOT( execActionSelectImagePrevious()));
    connect(ui->actionSelectImageEnd, SIGNAL(triggered()), NavigationInstance, SLOT( execActionSelectImageEnd()));

    connect(ListWidgetTheame, &cListWidgetTheame::showExecStatus, this, &MainWindow::execShowExecStatus);

    connect(ui->actionRemoveSection, SIGNAL(triggered()), NavigationInstance, SLOT( execActionRemoveSection()));

    connect(ui->actionEraseSection, SIGNAL(triggered()), NavigationInstance, SLOT( execActionEraseSection()));

    connect(NavigationInstance->pbErase, SIGNAL(pressed()), NavigationInstance, SLOT( execActionEraseSection()));

    connect(ui->actionRotateCW, SIGNAL(triggered()), DrawFilesInstance, SLOT( execActionRotateCW()));

    connect(ui->actionRotateCCW, SIGNAL(triggered()), DrawFilesInstance, SLOT( execActionRotateCCW()));

    connect(ImportFilesInstance, SIGNAL(gotoInstallNavigation()), NavigationInstance, SLOT( installNavigation()));
    connect(NavigationInstance->pbReload, SIGNAL(pressed()), ImportFilesInstance, SLOT( execActionLoad()));

    connect(ui->pushButtonRotateCW, SIGNAL(pressed()), DrawFilesInstance, SLOT( execActionRotateCW()));
    connect(ui->pushButtonRotateCCW, SIGNAL(pressed()), DrawFilesInstance, SLOT( execActionRotateCCW()));

    connect(ui->pushButtonMemo, SIGNAL(pressed()), this, SLOT( execActionMemo()));

    connect(ui->spinBoxAngle, SIGNAL(valueChanged(int)), DrawFilesInstance, SLOT( execSpinBoxAngle(int)));

    connect(ui->actionGetGroupsList, SIGNAL(triggered()), ImportFilesInstance, SLOT( execActionGetGroupsList()));

    connect(ui->actionGetKeysList, SIGNAL(triggered()), ImportFilesInstance, SLOT( execActionGetKeysList()));

    connect(ui->actionLoadRemovedSectionsList, SIGNAL(triggered()), NavigationInstance, SLOT( loadRemovedSectionsList()));

    connect(ui->actionLoad, SIGNAL(triggered()), ImportFilesInstance, SLOT( execActionLoad()));

    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

    connect(ImportFilesInstance, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

    connect(ListWidgetPlace, &cListWidgetPlace::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetPlace, &cListWidgetPlace::showCurrentIndexPicture, NavigationInstance, &cNavigation::execShowCurrentIndexPicture);

    connect(ListWidgetSubject, &cListWidgetSubject::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetSubject, &cListWidgetSubject::showCurrentIndexPicture, NavigationInstance, &cNavigation::execShowCurrentIndexPicture);

    connect(ListWidgetProperty, &cListWidgetProperty::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetProperty, &cListWidgetProperty::showCurrentIndexPicture, NavigationInstance, &cNavigation::execShowCurrentIndexPicture);

    connect(ListWidgetTheame, &cListWidgetTheame::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetTheame, &cListWidgetTheame::showCurrentIndexPicture, NavigationInstance, &cNavigation::execShowCurrentIndexPicture);

    fmViewPicture = new fmView(this);
    fmViewPicture->setWindowFlags(Qt::Window);//3 flags
    //ViewPicture->setWindowFlags(Qt::Drawer);//1 flag
    //ViewPicture->setWindowFlags(Qt::Sheet);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Dialog);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Popup);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::Tool);//1 flag, immobil
    //ViewPicture->setWindowFlags(Qt::ToolTip);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::SplashScreen);//no flags, immobil

    fmViewPicture->ListWidget = ui->listWidgetOther;
    fmViewPicture->DrawFilesInstance->install(fmViewPicture->ListWidget);

    connect(fmViewPicture, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

    ui->actionViewPicture->setChecked(false);
    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    timerUpdate = new QTimer(this);
    connect(timerUpdate, &QTimer::timeout, this, &MainWindow::execTimerUpdate);
    timerUpdate->start(100);

    ProgressBarTasks = new QProgressBar();
    ProgressBarTasks->setRange(0, 100);
    ProgressBarTasks->setValue(0);
    ProgressBarTasks->setToolTip("ThreadPoolTasks progress");
    ui->statusBar->addWidget(ProgressBarTasks);

    labelExecStatus = new QLabel("ExecStatus");
    ui->statusBar->addWidget(labelExecStatus);

    labelFileName = new QLabel("LoadedFileName");
    ui->statusBar->addWidget(labelFileName);

    labelOsType = new QLabel();
    ui->statusBar->addWidget(labelOsType);

    switch(cIniFile::iSystemType)
    {
        case WINDOWS_SYSTEM_TYPE:
            labelOsType->setText("Windows OS");
        break;

        case LINUX_SYSTEM_TYPE:
            labelOsType->setText("Linux OS");
        break;

        default:
            labelOsType->setText("Unknown OS");
        break;
    }

    qslHashTagList = new QStringList();



    connect(ui->actionSearchRotated, &QAction::triggered, SearchInstance, &cSearch::execActionSearchRotated);

    ui->lineEditPattern->setText("^[Ii][Mm][Gg]_20[0-9]{6}_[0-9]{6}");//20250425

    connect(ui->actionSearchNamePattern1, &QAction::triggered, SearchInstance, &cSearch::execActionSearchNamePattern1);
    connect(ui->actionSearchNamePattern2, &QAction::triggered, SearchInstance, &cSearch::execActionSearchNamePattern2);
    connect(ui->actionSearchNamePatternX, &QAction::triggered, SearchInstance, &cSearch::execActionSearchNamePattern);
    connect(ui->pushButtonSearchPatternX, &QPushButton::pressed, SearchInstance, &cSearch::execActionSearchNamePattern);

    connect(ui->actionSearchOrYes, &QAction::triggered, SearchInstance, &cSearch::execActionSearchOrYes);
    connect(ui->pushButtonSearchOrYes, &QPushButton::pressed, SearchInstance, &cSearch::execActionSearchOrYes);

    connect(ui->actionSearchYesYes, &QAction::triggered, SearchInstance, &cSearch::execActionSearchYesYes);
    connect(ui->pushButtonSearchYesYes, &QPushButton::pressed, SearchInstance, &cSearch::execActionSearchYesYes);

    connect(ui->actionSearchNamePatterns12Intersection, &QAction::triggered, SearchInstance, &cSearch::execActionSearchNamePatterns12Intersection);

    connect(ui->actionSearchNamePatterns1XIntersection, &QAction::triggered, SearchInstance, &cSearch::execActionSearchNamePatterns1XIntersection);

    connect(ui->actionSearchFreshRecords, &QAction::triggered, SearchInstance, &cSearch::execActionSearchFreshRecords);

    connect(ui->actionRemove_Js, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemove_Js);
    connect(ui->actionRemove_Html, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemove_Html);
    connect(ui->actionRemoveMovie, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemoveMovie);
    connect(ui->actionRemoveText, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemoveText);
    connect(ui->actionRemoveTif, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemoveTif);
    connect(ui->actionRemoveBin, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemoveBin);
    connect(ui->actionRemove3gp, &QAction::triggered, ActionsExec, &cActionsExec::execActionRemove3gp);
    connect(ui->actionShowNewFiles, &QAction::triggered, ActionsExec, &cActionsExec::execActionShowNewFiles);

    connect(ui->listWidgetKeys, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetKeysItemClicked()));
    connect(ui->listWidgetSearch, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSearchItemClicked()));

    connect(ui->comboBoxPatterns, SIGNAL(currentIndexChanged(int)), this, SLOT(execComboBoxCurrentIndexChanged(int)));
    //connect(ui->comboBoxPatterns, &QComboBox::currentIndexChanged, this, &MainWindow::execComboBoxCurrentIndexChanged);
    //connect(ui->comboBoxPatterns, &QComboBox::editTextChanged, [](auto text){
    //    qDebug() << "Current text=" << text;
    //});

    //Подключение сигналов модуля Navigation
    connect(NavigationInstance, &cNavigation::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(NavigationInstance, &cNavigation::draw, fmViewPicture, &fmView::execDraw);

    //Подключение сигналов модуля DrawFilesxInstance
    connect(DrawFilesInstance, &cDrawFilex::draw, fmViewPicture, &fmView::execDraw);
    connect(DrawFilesInstance, &cDrawFilex::showExecStatus, this, &MainWindow::execShowExecStatus);

    connect(fmViewPicture->DrawFilesInstance, &cDrawFilex::foundMissingFile, this, &MainWindow::execFoundMissingFile);

    //Подключение сигналов модуля Search
    connect(SearchInstance, &cSearch::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(SearchInstance, &cSearch::showCurrentIndexPicture, NavigationInstance, &cNavigation::execShowCurrentIndexPicture);

    connect(ui->actionImport, &QAction::triggered, ImportFilesInstance, &cImportFiles::execActionImportInitial);
    //20250820
    connect(ui->actionStart_Threads, &QAction::triggered, this, &MainWindow::execActionStartThreads);
    //20250822
    connect(ui->actionImportTaskProcess, &QAction::triggered, this, &MainWindow::execActionImportTaskProcess);

}//End of ctor

MainWindow::~MainWindow()
{
    timerUpdate->stop();

    saveRemovedSectionsList();

    delete ListWidgetPlace;
    delete ListWidgetSubject;
    delete ListWidgetProperty;
    delete ListWidgetTheame;

    delete ActionsExec;
    delete ImportFilesInstance;
    delete NavigationInstance;
    delete LoadFilesInstance;
    delete DrawFilesInstance;
    delete SearchInstance;

    delete labelExecStatus;
    delete labelFileName;
    delete labelOsType;

    delete fmViewPicture;

    delete qslHashTagList;

    if(cIniFile::Groups != nullptr) delete cIniFile::Groups;
    if(cIniFile::Keys != nullptr) delete cIniFile::Keys;
    if(cIniFile::SearchKeys != nullptr) delete cIniFile::SearchKeys;

    //20250820
    threadPool.waitForDone(); // Ожидаем завершения всех задач

    delete ui;
}

//=============================================================================

void MainWindow::keyPressEvent(QKeyEvent * e)
{
    switch(e->key())
    {
        case 16777249://Qt::CTRL:
            qDebug() << "CTRL pressed";
            KeyPressed.push(e->key());
        break;
        //Key_B
        case 1048:
        case 66:
            qDebug() << "B pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+B pressed";
                emit ui->actionSelectImageBegin->triggered();// pushButtonBegin->pressed();
            }
        break;
        //Key_P
        case 1047:
        case 80:
            qDebug() << "P pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+P pressed";
                emit ui->actionSelectImagePrevious->triggered();// pushButtonPrevious->pressed();
            }
        break;

        //Key_N
        case 1058:
        case 78:
            qDebug() << "N pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+N pressed";
                emit ui->actionSelectImageNext->triggered();// pushButtonNext->pressed();
            }
        break;

        //Key_E
        case 1059:
        case 69:
            qDebug() << "E pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+E pressed";
                emit ui->actionSelectImageEnd->triggered();// pushButtonEnd->pressed();
            }
        break;

       //Key_D
       case 1042:
       case 68:
            qDebug() << "D pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+D pressed";
                emit ui->actionRemoveSection->triggered();// pushButtonEnd->pressed();
            }
       break;

       //Key_R поворот направо
       case 1050:
       case 82:
             qDebug() << "R pressed";
             KeyPressed.push(e->key());
             if(KeyPressed.Previous == 16777249)
             {
                 qDebug() << "CTRL+R pressed";
                 DrawFilesInstance->execActionRotateCW();
             }
       break;

       //Key_L поворот налево
       case 1044:
       case 76:
             qDebug() << "L pressed";
             KeyPressed.push(e->key());
             if(KeyPressed.Previous == 16777249)
             {
                 qDebug() << "CTRL+L pressed";
                 DrawFilesInstance->execActionRotateCCW();
             }
       break;

        default:
            qDebug() << "Key press:" << e->key();
        break;
    }

}//End of void MainWindow::keyPressEvent(QKeyEvent * e)

//=============================================================================

void MainWindow::saveRemovedSectionsList()
{

    cLoadFiles::saveStringListToFile(cIniFile::filePathRemovedSectionList, cIniFile::qslDeletedSections);

}//End of void MainWindow::saveRemovedSectionsList()

//=============================================================================

void MainWindow::execActionFormViewPicture()
{
    if(ui->actionViewPicture->isChecked())
    {
        fmViewPicture->show();
    }
    else
    {
        fmViewPicture->hide();
    }
    //---
    QString s = "execActionFormViewPicture()";
    emit execShowExecStatus(s);
   //---
}

//=============================================================================

void MainWindow::execTimerUpdate()
{
    //qDebug() << "CurrentIndex=" << CurrentIndex;
    iTimerUpdateCounter++;

    if(iTimerUpdateCounter == 1)
    {

        qDebug() << "CurrentIndex=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << " Action: open ViewPictureForm";
        int windowX = this->x();
        windowX = windowX + this->width();
        windowX = windowX + WINDOW_LEFT_MARGING;

        int windowY = this->y() + WINDOW_TOP_MARGING;

        int windowWidth = fmViewPicture->width();
        int windowHeight = fmViewPicture->height();

        QRect windowPlace = QRect(windowX, windowY, windowWidth, windowHeight);
        fmViewPicture->setGeometry(windowPlace);

        //fmViewPicture->show();
        //ui->actionViewPicture->setChecked(true);

        qDebug() << "CurrentIndex=" << iCurrentIndexGlobal.load(std::memory_order_relaxed);
        ImportFilesInstance->execActionLoad();

        //NavigationInstance->loadRemovedSectionsList();

    }//End of if(iTimerUpdateCounter == 1)

    if(cImportFiles::IslabelExecStatusTextChanged)
    {
        labelExecStatus->setText(cImportFiles::labelExecStatusText);
        cImportFiles::IslabelExecStatusTextChanged = false;
    }

    if(cImportFiles::IslabelFileNameTextChanged)
    {
        labelFileName->setText(cImportFiles::labelFileNameText);
        cImportFiles::IslabelFileNameTextChanged = false;
    }

}

//=============================================================================

void MainWindow::execShowExecStatus(QString s)
{
    cImportFiles::labelExecStatusText = s;
    cImportFiles::IslabelExecStatusTextChanged = true;
}

//=============================================================================

void MainWindow::execActionMemo()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s;
    QString item = ui->lineEditMemo->text();
    if(item.length() > 0)
    {
        qDebug() << "execActionMemo():" << item;

        s = "execInsertMemoKeyValue()";

        // Сохранение параметра в INI-файле
        if(cIniFile::Groups->count() > 0)
        {
            QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
            settings.beginGroup(qsGroupName);
            QString key = "memo";
            QStringList list = settings.childKeys();
            if(list.contains(key))
            {
                qDebug() << qsGroupName << " contains " << key;
                settings.remove(key);
            }
            else
            {
                qDebug() << qsGroupName << " not contains " << key;
                settings.setValue(key, item);
            }
            settings.endGroup();
            settings.sync();
        }
        else
        {
            s = "List is empty, exec Load function!!!";
        }
        // Отобразить картинку
        NavigationInstance->execShowCurrentIndexPicture();
    }
    else
    {
        qDebug() << "execActionMemo(): nothing to do";

        s = "Memo is emtpy, nothing to do!";
    }
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetKeysItemClicked()
{
    //QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execKeysItemClicked()";
    QString item = ui->listWidgetKeys->currentItem()->text();
    s += ": ";
    s += item;

    if(
         item != "Id"
      && item != "height"
      && item != "name"
      && item != "path"
      && item != "size"
      && item != "width"
      )
    {
        cIniFile::SearchKeys->append(item);
        ui->listWidgetSearch->clear();
        ui->listWidgetSearch->addItems(*cIniFile::SearchKeys);
    }
    else
    {
        s += " forbidden value!!!";
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetSearchItemClicked()
{
    //QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execSearchItemClicked()";
    QString item = ui->listWidgetSearch->currentItem()->text();
    s += ": ";
    s += item;

    cIniFile::SearchKeys->removeAll(item);

    ui->listWidgetSearch->clear();
    ui->listWidgetSearch->addItems(*cIniFile::SearchKeys);
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execComboBoxCurrentIndexChanged(int x)
{
    QString value = ui->comboBoxPatterns->currentText();
    qDebug() << "ComboBoxCurrentIndexChanged(): index=" << x << " Text= " << value;
    ui->lineEditPattern->setText(value);
}

//=============================================================================

//
// Слот для обработки сигнала, возникающего при ошибке проведения операции с файлом
//
void MainWindow::execFoundMissingFile(QString path)
{
    qDebug() << "Found missing file:" << path;
}

//##############################################################################

void MainWindow::execActionStartThreads()
{
    qDebug() << "execActionStartThreads";

    ui->actionStart_Threads->setEnabled(false);
    emit beginMessage("==ActionStartThreads begin==");
    tasksCompleted = 0;
    totalTasks = 10; // Количество задач

    // Создаем и запускаем задачи
    for (int i = 0; i < totalTasks; ++i)
    {
        threadPool.start(new ProcessingTask(i, this));
    }

}

void MainWindow::execActionImportTaskProcess()
{
    ui->actionImportTaskProcess->setEnabled(false);
    emit beginMessage("==ActionImportTaskProcess begin==");

    threadPool.start(new processImportTask(PROCESS_IMPORT_TASK_ID, this));
}

/*
    Слот, который вызывается из потока задачи
*/
void MainWindow::updateProgress(int value)
{
    tasksCompleted += value;
    int progress = static_cast<int>((tasksCompleted * 100.0) / totalTasks);
    ProgressBarTasks->setValue(progress);

    if (tasksCompleted == totalTasks)
    {
        emit infoMessage("All tasks completed");
        ui->actionStart_Threads->setEnabled(true);
        ui->actionStart_Threads->setChecked(false);

        QMessageBox msgBox;
        msgBox.setText("Task pool execution");
        msgBox.setInformativeText("Ready");
        msgBox.exec();
    }
}

void MainWindow::updateProgressImportTask(int value)
{
    if(value > 0)
    {
        if(value < 100)
        {
            ProgressBarTasks->setValue(value);
        }
        else
        {
            ProgressBarTasks->setValue(0);

            emit infoMessage("Import task completed");
            ui->actionImportTaskProcess->setEnabled(true);
            ui->actionImportTaskProcess->setChecked(false);

            QMessageBox msgBox;
            msgBox.setText("ImportTask");
            msgBox.setInformativeText("Completed");
            msgBox.exec();
        }
    }
}

/*
    Слот, который выводит сообщение в ListWidgetOther
    Может вызываться из потока задачи
*/
void MainWindow::appEndItem(QListWidgetItem * item)
{
    ui->listWidgetOther->addItem(item);
    ui->listWidgetOther->setCurrentItem(item);
    ui->listWidgetOther->scrollToItem(item);
}

void MainWindow::execInfoMessage(QString s)
{
    QListWidgetItem * item = new QListWidgetItem(s);

    appEndItem(item);
}

void MainWindow::execBeginMessage(QString s)
{
    QListWidgetItem * item = new QListWidgetItem(s);
    item->setForeground(Qt::blue);
    appEndItem(item);
}

void MainWindow::execEndMessage(QString s)
{
    QListWidgetItem * item = new QListWidgetItem(s);
    item->setForeground(Qt::green);
    appEndItem(item);
}
