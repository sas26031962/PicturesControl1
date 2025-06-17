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
        //qsProjectPath = "/home/andy/MyQtProjects";
        //qsHashTagFileNameSuffix = "Photos";
         qsIniFileName = qsIniFileNameLinux;

    }
    else
    {

        qsProjectPath = qsProjectPathWindows;
        qsHashTagFileNameSuffix = qsHashTagFileNameSuffixWindows;
        //qsProjectPath = "C:/WORK/PicturesControl";
        //qsHashTagFileNameSuffix = "Ships";
         qsIniFileName = qsIniFileNameWindows;
    }

    //---Прямые имена файлов
    //cIniFile::iniFilePath = "/home/andy/MyQtProjects/PicturesControl1/programm/data/FilesConfigPhotos.ini";//Linux version
    //cIniFile::iniFilePath = "C:/WORK/PicturesControl/PicturesControl1/programm/data/FilesConfigShips.ini";//Windows version

    cIniFile::iniFilePath = qsProjectPath + qsProjectName + "/programm/data/FilesConfig" + qsHashTagFileNameSuffix + ".ini";

    cIniFile::pattern1StringListFilePath = qsProjectPath + qsProjectName + "/programm/data/pattern1StringListFile" + qsDataFileNameExtension;
    cIniFile::pattern2StringListFilePath = qsProjectPath + qsProjectName + "/programm/data/pattern2StringListFile" + qsDataFileNameExtension;
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

    qslDeletedSections.clear();

    ui->setupUi(this);

    ActionsExec = new cActionsExec();
    ActionsExec->install(ui->listWidgetOther);

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

    progressBarNavigation = ui->progressBarNavigation;
    SpinBoxIndex = ui->spinBoxIndex;

    ui->pushButtonGotoIndex->setVisible(true);//РЕЖИМ АДМИНИСТРАТОРА
    ui->pushButtonLoad->setVisible(false);//РЕЖИМ АДМИНИСТРАТОРА

    connect(ui->actionViewPicture, SIGNAL(triggered()), this, SLOT( execActionFormViewPicture()));
    connect(ui->actionGotoIndex, SIGNAL(triggered()), this, SLOT( execActionGotoIndex()));
    connect(ui->actionSelectImageBegin, SIGNAL(triggered()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->actionSelectImageNext, SIGNAL(triggered()), this, SLOT( execActionSelectImageNext()));
    connect(ui->actionSelectImagePrevious, SIGNAL(triggered()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->actionSelectImageEnd, SIGNAL(triggered()), this, SLOT( execActionSelectImageEnd()));

    connect(ListWidgetTheame, &cListWidgetTheame::showExecStatus, this, &MainWindow::execShowExecStatus);

    connect(ui->actionRemoveSection, SIGNAL(triggered()), this, SLOT( execActionRemoveSection()));

    connect(ui->pushButtonRemove, SIGNAL(pressed()), this, SLOT( execActionRemoveSection()));

    connect(ui->actionRotateCW_2, SIGNAL(triggered()), this, SLOT( execActionRotateCW()));
    connect(ui->actionRotateCCW_2, SIGNAL(triggered()), this, SLOT( execActionRotateCCW()));
    connect(ui->actionRotateCW, SIGNAL(triggered()), this, SLOT( execActionRotateCW()));
    connect(ui->actionRotateCCW, SIGNAL(triggered()), this, SLOT( execActionRotateCCW()));

    connect(ui->pushButtonGotoIndex, SIGNAL(pressed()), this, SLOT( execActionGotoIndex()));

    connect(ui->pushButtonBegin, SIGNAL(pressed()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->pushButtonNext, SIGNAL(pressed()), this, SLOT( execActionSelectImageNext()));
    connect(ui->pushButtonPrevious, SIGNAL(pressed()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->pushButtonEnd, SIGNAL(pressed()), this, SLOT( execActionSelectImageEnd()));
    connect(ui->pushButtonLoad, SIGNAL(pressed()), this, SLOT( execActionLoad()));
    connect(ui->pushButtonRotateCW, SIGNAL(pressed()), this, SLOT( execActionRotateCW()));
    connect(ui->pushButtonRotateCCW, SIGNAL(pressed()), this, SLOT( execActionRotateCCW()));
    connect(ui->pushButtonMemo, SIGNAL(pressed()), this, SLOT( execActionMemo()));
    connect(ui->spinBoxAngle, SIGNAL(valueChanged(int)), this, SLOT( execSpinBoxAngle(int)));

    connect(ui->actionImport, SIGNAL(triggered()), this, SLOT( execActionImportInitial()));

    connect(ui->actionGetGroupsList, SIGNAL(triggered()), this, SLOT( execActionGetGroupsList()));
    connect(ui->actionGetKeysList, SIGNAL(triggered()), this, SLOT( execActionGetKeysList()));

    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT( execActionLoad()));

    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));
    connect(ListWidgetPlace, &cListWidgetPlace::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetPlace, &cListWidgetPlace::showCurrentIndexPicture, this, &MainWindow::execShowCurrentIndexPicture);

    connect(ListWidgetSubject, &cListWidgetSubject::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetSubject, &cListWidgetSubject::showCurrentIndexPicture, this, &MainWindow::execShowCurrentIndexPicture);

    connect(ListWidgetProperty, &cListWidgetProperty::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetProperty, &cListWidgetProperty::showCurrentIndexPicture, this, &MainWindow::execShowCurrentIndexPicture);

    connect(ListWidgetTheame, &cListWidgetTheame::showExecStatus, this, &MainWindow::execShowExecStatus);
    connect(ListWidgetTheame, &cListWidgetTheame::showCurrentIndexPicture, this, &MainWindow::execShowCurrentIndexPicture);

    fmViewPicture = new fmView(this);
    fmViewPicture->setWindowFlags(Qt::Window);//3 flags
    //ViewPicture->setWindowFlags(Qt::Drawer);//1 flag
    //ViewPicture->setWindowFlags(Qt::Sheet);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Dialog);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Popup);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::Tool);//1 flag, immobil
    //ViewPicture->setWindowFlags(Qt::ToolTip);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::SplashScreen);//no flags, immobil

    connect(this, SIGNAL(draw(QString)), fmViewPicture, SLOT( execDraw(QString)));
    connect(fmViewPicture, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

    ui->actionViewPicture->setChecked(false);
    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT( execTimerUpdate()));
    timerUpdate->start(100);

    progressBarProcess = new QProgressBar();
    progressBarProcess->setOrientation(Qt::Horizontal);
    progressBarProcess->setRange(0, cImportFiles::MaxIndexValue);
    ui->statusBar->addWidget(progressBarProcess);

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



    connect(fmViewPicture, SIGNAL(shiftXValueChanged()), this, SLOT( execShiftXValueChanged()));
    connect(fmViewPicture, SIGNAL(shiftYValueChanged()), this, SLOT( execShiftYValueChanged()));

    connect(ui->actionSearchRotated, SIGNAL(triggered()), this, SLOT( execActionSearchRotated()));

    ui->lineEditPattern->setText("^[Ii][Mm][Gg]_20[0-9]{6}_[0-9]{6}");//20250425

    connect(ui->actionSearchNamePattern1, &QAction::triggered, this, &MainWindow::execActionSearchNamePattern1);
    connect(ui->actionSearchNamePattern2, &QAction::triggered, this, &MainWindow::execActionSearchNamePattern2);
    connect(ui->actionSearchNamePatternX, &QAction::triggered, this, &MainWindow::execActionSearchNamePattern);
    connect(ui->pushButtonSearchPatternX, &QPushButton::pressed, this, &MainWindow::execActionSearchNamePattern);

    connect(ui->actionSearchOrYes, SIGNAL(triggered()), this, SLOT( execActionSearchOrYes()));
    //connect(ui->pushButtonSearchOrYes, SIGNAL(pressed()), this, SLOT( execActionSearchOrYes()));
    connect(ui->pushButtonSearchOrYes, &QPushButton::pressed, this, &MainWindow::execActionSearchOrYes);

    connect(ui->actionSearchNamePatterns12Intersection, SIGNAL(triggered()), this, SLOT( execActionSearchNamePatterns12Intersection()));
    connect(ui->actionSearchNamePatterns1XIntersection, SIGNAL(triggered()), this, SLOT( execActionSearchNamePatterns1XIntersection()));

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

    connect(ui->actionOpenFoundRecord, &QAction::triggered, this, &MainWindow::execActionOpenFoundRecord);
    connect(ui->listWidgetFounded, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetFoundedItemClicked()));

    ListWidget = ui->listWidgetOther;//20250616

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

    delete progressBarProcess;
    delete labelExecStatus;
    delete labelFileName;
    delete labelOsType;

    delete fmViewPicture;

    delete qslHashTagList;

    if(cIniFile::Groups != nullptr) delete cIniFile::Groups;
    if(cIniFile::Keys != nullptr) delete cIniFile::Keys;
    if(cIniFile::SearchKeys != nullptr) delete cIniFile::SearchKeys;

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
                 execActionRotateCW();
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
                 execActionRotateCCW();
             }
       break;

        default:
            qDebug() << "Key press:" << e->key();
        break;
    }

}//End of void MainWindow::keyPressEvent(QKeyEvent * e)

//=============================================================================

void MainWindow::loadRemovedSectionsList()
{
    qslDeletedSections = cLoadFiles::loadStringListFromFile(cIniFile::filePathRemovedSectionList);

    //ui->listWidgetOther->clear();
    ui->listWidgetOther->addItem("==LoadRemovedSectionsList==");
    ui->listWidgetOther->addItem("RemovedSectionsListCount=" + QString::number(qslDeletedSections.count()));
    ui->listWidgetOther->addItems(qslDeletedSections);

}//End of void MainWindow::loadRemovedSectionsList()

//=============================================================================

void MainWindow::saveRemovedSectionsList()
{

    cLoadFiles::saveStringListToFile(cIniFile::filePathRemovedSectionList, qslDeletedSections);

}//End of void MainWindow::saveRemovedSectionsList()

//=============================================================================
void MainWindow::execActionGotoIndex()
{

    int index = SpinBoxIndex->value();

    // Модификация индекса
    iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    int value  = index;
    if(value < 0)
    {
        qDebug() << "execActionGotoIndex(): index < 0";
    }
    progressBarNavigation->setValue(value);
    SpinBoxIndex->setValue(value);
    //---
    QString s = "execActionGotoIndex(), goto index:";
    s += QString::number(index);
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionSelectImageBegin()
{
    int index = 0;
    // Модификация индекса
    iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    int value  = index;
    if(value < 0)
    {
        qDebug() << "execActionSelectImageBegin: index < 0";
    }
    progressBarNavigation->setValue(value);
    SpinBoxIndex->setValue(value);
    //---
    QString s = "execActionSelectImageBegin(), goto index:";
    s += QString::number(index);
    emit execShowExecStatus(s);
    //---

}//End of void MainWindow::execActionSelectImageBegin()

//=============================================================================

void MainWindow::execActionSelectImageNext()
{
    // Модификация индекса
    if(iCurrentIndexGlobal.load(std::memory_order_relaxed) < cIniFile::Groups->count() - 1)
    {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);
    }
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    int value  = index;
    if(value < 0)
    {
        qDebug() << "execActionSelectImageNext: index < 0";
    }
    progressBarNavigation->setValue(value);
    SpinBoxIndex->setValue(value);
    //---
    QString s = "execActionSelectImageNext(), goto index:";
    s += QString::number(index);
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionSelectImagePrevious()
{
    // Модификация индекса
    if(iCurrentIndexGlobal.load(std::memory_order_relaxed) > 0)
    {
        iCurrentIndexGlobal.fetch_sub(1, std::memory_order_relaxed);
    }
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    int value  = index;
    if(value < 0)
    {
        qDebug() << "execActionSelectImagePrevious: index < 0";
    }
    progressBarNavigation->setValue(value);
    SpinBoxIndex->setValue(value);
    //---
    QString s = "execActionSelectImagePrevious(), goto index:";
    s += QString::number(index);
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionSelectImageEnd()
{
    int index = cIniFile::Groups->count() - 1;
    // Модификация индекса
    iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    int value  = index;
    if(value < 0)
    {
        qDebug() << "execActionSelectImageEnd(): index < 0";
    }
    else if(value > cIniFile::Groups->count() - 1)
    {
        value =  cIniFile::Groups->count() - 1;
    }
    progressBarNavigation->setValue(value);
    SpinBoxIndex->setValue(value);
    //---
    QString s = "execActionSelectImageEnd(), goto index";
    s += QString::number(index);
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionImportInitial()
{
    //---
    QString s = "execActionImport()";
    emit execShowExecStatus(s);
    //---

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    //--- Очистка рабочего списка
    cRecord::RecordList->clear();

    //---Чтение содержимого каталога ---

    if(cRecord::readDirectory(cIniFile::IniFile.getDirectoryPah()) > 0)
    {
        //qDebug() << "Directory not found: " << directoryPath;
        IsError = true;
        return;
    }

    cImportFiles::execImport(progressBarProcess);

    emit execShowExecStatus("File import complete!");

    qslDeletedSections.clear();

    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItem("==FileImport complete==");

    //execActionLoad();//Выполнить загрузку изображений

}//End of void MainWindow::execActionImport()

//=============================================================================

void MainWindow::execActionLoad()
{
    //--- Начало функции загрузки
    qDebug() << "execActionLoad(): begin";

    // Читаем значение текущего индекса из INI-файла
    int LoadedCurrentIndex = cIniFile::getCurrentIndex();

    //Загрузка списка групп
    cImportFiles::getGroupsList();
    cImportFiles::MaxIndexValue = cIniFile::Groups->count();

    qDebug() << "execActionLoad(): load" << cImportFiles::MaxIndexValue << " records in cIniFile::Groups list";


    // Загрузка списка ключей
    execActionGetKeysList();

    // Установка текущего индекса
    iCurrentIndexGlobal.store(LoadedCurrentIndex);

    // Установка навигации
    progressBarNavigation->setRange(0, cImportFiles::MaxIndexValue);
    progressBarNavigation->setValue(LoadedCurrentIndex);

    SpinBoxIndex->setRange(0, cImportFiles::MaxIndexValue);
    SpinBoxIndex->setValue(LoadedCurrentIndex);

    // Переход к следующему индексу
    execActionSelectImageNext();

    //---
    QString s = "execActionLoad(), goto index:";
    s += QString::number(iCurrentIndexGlobal.load(std::memory_order_relaxed));
    emit execShowExecStatus(s);
    //---

}//End of void MainWindow::execActionLoad()

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

//
// Удалить секцию из ini файла
//
bool MainWindow::deleteSection(QString s)
{
    bool Error = false;

    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    settings.beginGroup(s);
    QList<QString> keys = settings.childKeys();
    int iKeysCount = keys.count();

    QString qsName = settings.value("name", "noName").toString();
    QString qsPath = settings.value("path", "noPath").toString();
    QString qsWay = qsPath + "/" + qsName;

    if(iKeysCount > 0)
    {
        // Перебор всей ключей в секции
        QListIterator<QString> readKeyIt(keys);
        while (readKeyIt.hasNext())
        {
            QString qsKey = readKeyIt.next();
            qDebug() << qsKey;
            settings.remove(qsKey);
        }
        qDebug() << "All keys in section " << s << " removed!";

    }
    else
    {
        qDebug() << "No keys in section " << s << " found!";
    }
    settings.endGroup();

    settings.remove(s);
    settings.sync();

    qDebug() << "Section " << s << " removed!";

    //Добавление секции в список - результат
    //qslDeletedSections.append(s);
    qslDeletedSections.append(qsWay);//#@

    return Error;
}

//=============================================================================

void MainWindow::execActionRemoveSection()
{
    QString s = "ActionRemoveSection()";

    // Читаем имя текущей секции
    QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));

    bool x = deleteSection(qsGroupName);
    // Выводим значения удалённых секций
    if(!x)
    {
        cIniFile::Groups->removeAt(iCurrentIndexGlobal.load(std::memory_order_relaxed));

        ui->listWidgetOther->clear();
        ui->listWidgetOther->addItem("==ActionRemoveSection==");
        ui->listWidgetOther->addItem(qsGroupName);
    }

    execActionSelectImagePrevious();//Перерисовка изображения

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRotateCW()
{
    QString s = "ActionRotateCW()";

    //iAngle = 90;
    //cDrawFiles::execRotate(iAngle);

    cDrawFiles::execRotateCW90();

    emit draw(cIniFile::currentRotatedImagePath);

    //===
    emit execShowExecStatus(s);
    //===

}

//=============================================================================

void MainWindow::execActionRotateCCW()
{
    QString s = "ActionRotateCCW()";

    //iAngle = 270;
    //cDrawFiles::execRotate(iAngle);

    cDrawFiles::execRotateCCW90();


    emit draw(cIniFile::currentRotatedImagePath);

    //===
    emit execShowExecStatus(s);
    //===

}

//=============================================================================

void MainWindow::execSpinBoxAngle(int angle)
{
    qDebug() << "Angle:" << angle;
    iAngle = angle;
    cDrawFiles::execRotate(iAngle);

    emit draw(cIniFile::currentRotatedImagePath);

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

        fmViewPicture->show();
        ui->actionViewPicture->setChecked(true);

        qDebug() << "CurrentIndex=" << iCurrentIndexGlobal.load(std::memory_order_relaxed);
        execActionLoad();

        loadRemovedSectionsList();

    }//End of if(iTimerUpdateCounter == 1)

//    progressBarProcess->setRange(0, cImportFiles::MaxIndexValue);
//    int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
//    progressBarProcess->setValue(x);

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

void MainWindow::execActionGetGroupsList()
{
    QString s = "execActionGetGroupsList()";

    ui->listWidgetFounded->clear();
    bool x = cImportFiles::getGroupsList();
    if(x)
    {
        s += ": error detected!";
    }
    else
    {
        s += ": sucsess!";

        ui->listWidgetFounded->addItems(*cIniFile::Groups);
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionGetKeysList()
{
    QString s = "execActionGetKeysList()";

    ui->listWidgetKeys->clear();
    bool x = cImportFiles::getKeysList();
    if(x)
    {
        s += ": error detected!";
    }
    else
    {
        s += ": sucsess!";

        //Удаление имени секции
        for(QList<QString>::iterator it = cIniFile::Keys->begin(); it != cIniFile::Keys->end(); ++it)
        {
            QString s = *it;
            int pos = s.lastIndexOf('/');
            if(pos > 0)
            {
                *it = s.mid(pos + 1);
            }
        }

        //---Удаление повторяющихся значений с сохранением порядка

        QSet<QString> seen;
        QStringList result;
        for(const QString &str : *cIniFile::Keys)
        {
            if(!seen.contains(str))
            {
                seen.insert(str);
                result.append(str);
            }
        }
        *cIniFile::Keys = result;

        //---
        ui->listWidgetKeys->addItems(*cIniFile::Keys);
        ui->labelKeysCaption->setText("All keys:" + QString::number(cIniFile::Keys->count()));
    }

    //---
    emit execShowExecStatus(s);
    //---
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
        showCurrentIndexPicture();
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

void MainWindow::installNavigation()
{
    iCurrentIndexGlobal.store(0, std::memory_order_relaxed);

    //Настройка навигации
    cImportFiles::MaxIndexValue = cIniFile::Groups->count();

    // Установка текущего индекса
    iCurrentIndexGlobal.store(0);

    // Установка навигации
    progressBarNavigation->setRange(0, cImportFiles::MaxIndexValue);
    progressBarNavigation->setValue(0);

    SpinBoxIndex->setRange(0, cImportFiles::MaxIndexValue);
    SpinBoxIndex->setValue(0);

    // Переход к начальному индексу
    execActionSelectImageBegin();

}

//=============================================================================

void MainWindow::execActionSearchRotated()
{
    QString s = "execActionSearchRotated()";

    cLoadFiles::execLoadFiles();

    installNavigation();//Настройка навигации

    s += ": find ";
    s += QString::number(cImportFiles::MaxIndexValue);
    s += " records";
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionSearchOrYes()
{
    QString s = "execActionSearchOrYes()";

//    cIniFile::SearchKeys->clear();
//    cIniFile::SearchKeys->append("IsRotated");
//    cIniFile::SearchKeys->append("Archive");

//    ui->listWidgetSearch->clear();
//    ui->listWidgetSearch->addItems(*cIniFile::SearchKeys);

    if(cIniFile::SearchKeys->count() > 0)
    {
        cLoadFiles::execLoadFilesByConditionOrYes(*cIniFile::SearchKeys);

        installNavigation();//Настройка навигации

        s += ": find ";
        s += QString::number(cImportFiles::MaxIndexValue);
        s += " records";
    }
    else
    {
        s += ": empy search task, nothing to do!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

//
// Отобразить содержимое списка cIniFile::Groups в элементе ui->listWidgetFounded
//
void MainWindow::showGroupsList()
{
    ui->listWidgetFounded->clear();
    QListIterator<QString> readIt(*cIniFile::Groups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        ui->listWidgetFounded->addItem(qsSection);
    }
}

//=============================================================================

void MainWindow::execActionSearchNamePattern1()
{
    QString s = "execActionSearchNamePattern1()";
    QString pattern = "^20[0-9]{6}_[0-9]{6}";

    bool x = cLoadFiles::searchNamePattern(pattern);

    showGroupsList();

    //---
    s += ": iCount=";
    s += QString::number(cIniFile::Groups->count());
    //---
    if(x)
    {
        s += "pattern1StringList stored in file";
    }
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionSearchNamePattern2()
{
    QString s = "execActionSearchNamePattern2()";
    QString pattern = "^20[0-9]{2}-[0-9]{2}-[0-9]{2} [0-9]{2}-[0-9]{2}-[0-9]{2}";

    bool x = cLoadFiles::searchNamePattern(pattern);

    showGroupsList();

    //---
    s += ": iCount=";
    s += QString::number(cIniFile::Groups->count());
    //---
    if(x)
    {
        s += "pattern1StringList stored in file";
    }
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionSearchNamePattern()
{
    QString s = "execActionSearchNamePattern3()";
    //QString pattern = "^IMG_20[0-9]{6}_[0-9]{6}";
    //QString pattern = "IMG_20[0-9]{6}_[0-9]{6}";
    QString pattern = ui->lineEditPattern->text();

    cLoadFiles::searchNamePattern(pattern);

    showGroupsList();

    //---
    s += ": iCount=";
    s += QString::number(cIniFile::Groups->count());
    //---
    bool x = cLoadFiles::saveStringListToFile(cIniFile::patternXStringListFilePath, *cIniFile::Groups);

    if(x)
    {
        s += "pattern1StringList stored in file";
    }
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execShiftXValueChanged()
{
    QString s = "ShiftXValueChanged:";
    s += QString::number(cDrawFiles::dx);

    cDrawFiles::execRotate(0);

    emit draw(cIniFile::currentRotatedImagePath);

    emit showExecStatus(s);

}

void MainWindow::execShiftYValueChanged()
{
    QString s = "ShiftYValueChanged:";
    s += QString::number(cDrawFiles::dy);

    cDrawFiles::execRotate(0);

    emit draw(cIniFile::currentRotatedImagePath);

    emit showExecStatus(s);
}

//=============================================================================

void MainWindow::execActionOpenFoundRecord()
{
    QString s = "execActionOpenFoundRecord()";

    emit showExecStatus(s);
}

//=============================================================================

void MainWindow::execComboBoxCurrentIndexChanged(int x)
{
    QString value = ui->comboBoxPatterns->currentText();
    qDebug() << "ComboBoxCurrentIndexChanged(): index=" << x << " Text= " << value;
    ui->lineEditPattern->setText(value);
}

//=============================================================================

void MainWindow::execActionSearchNamePatterns1XIntersection()
{
    QString s = "execActionSearchNamePattens1XIntersection()";

    QString pattern1 = "^20[0-9]{6}_[0-9]{6}";

    QStringList qslPattern1 = cLoadFiles::loadStringListFromFile(cIniFile::pattern1StringListFilePath);
    QStringList qslPatternX = cLoadFiles::loadStringListFromFile(cIniFile::patternXStringListFilePath);

    qDebug() << "ListPattern1 count=" << qslPattern1.count() << " ListPatternX count=" << qslPatternX.count();

    int iCount = 0;// Очистка счётчика найденных объектов
    ui->listWidgetFounded->clear();
    QListIterator<QString> readIt(qslPattern1);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        QRegularExpression re(pattern1);
        bool match = re.match(qsSection.toLower()).hasMatch();
        int Year, Month, Day, Hour, Min, Sec;
        QString qsMirror;
        if (match)
        {
            Year = qsSection.mid(0, 4).toInt();
            Month = qsSection.mid(4, 2).toInt();
            Day = qsSection.mid(6, 2).toInt();
            Hour = qsSection.mid(9, 2).toInt();
            Min = qsSection.mid(11, 2).toInt();
            Sec = qsSection.mid(13, 2).toInt();
            //qDebug() << "Строка " << qsSection << " is Ok for:" << pattern1 << ": Year=" << Year << " Month=" << Month << " Day=" << Day << " Hour=" << Hour << " Min=" << Min << " Sec=" << Sec;
            //Формирование шаблона по типу 3
            qsMirror = "IMG";
            qsMirror += QString::number(Year);
            if(Month < 10)qsMirror += "0";
            qsMirror += QString::number(Month);
            if(Day < 10)qsMirror += "0";
            qsMirror += QString::number(Day);
            qsMirror += "_";
            if(Hour < 10)qsMirror += "0";
            qsMirror += QString::number(Hour);
            if(Min < 10)qsMirror += "0";
            qsMirror += QString::number(Min);
            if(Sec < 10)qsMirror += "0";
            qsMirror += QString::number(Sec);
            qDebug() << "Строка " << qsSection << " is Ok for:" << pattern1 << ": Mirror=" << qsMirror;
            if(qslPatternX.contains(qsMirror))
            {
                iCount++;
                qDebug() << "String " << qsSection << " has mirror:" << qsMirror;
                ui->listWidgetFounded->addItem(qsSection);

                deleteSection(qsMirror);//!!!
            }
        }
    }
    s += ": mirrors count=";
    s += QString::number(iCount);
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

/******************************************************************************
 * Поиск пересечения списков qslPattern1 и qslPattern2 по признаку совпадения
 * даты.
 * Исходные данных содержатся в файлах с именами:
 * cIniFile::pattern1StringListFilePath и
 * cIniFile::pattern2StringListFilePath
 *
 ******************************************************************************/
void MainWindow::execActionSearchNamePatterns12Intersection()
{
    QString s = "execActionSearchNamePattens12Intersection()";


    QStringList qslPattern1 = cLoadFiles::loadStringListFromFile(cIniFile::pattern1StringListFilePath);
    QStringList qslPattern2 = cLoadFiles::loadStringListFromFile(cIniFile::pattern2StringListFilePath);

    qDebug() << "ListPattern1 count=" << qslPattern1.count() << " ListPattern2 count=" << qslPattern2.count();

    // Очистка результата
    int iCount = 0;
    ui->listWidgetFounded->clear();

    QListIterator<QString> readIt(qslPattern1);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;

        //Проверка строки на соответствие шаблону 1
        QString pattern1 = "^20[0-9]{6}_[0-9]{6}";
        QRegularExpression re(pattern1);
        bool match = re.match(qsSection.toLower()).hasMatch();
        int Year, Month, Day, Hour, Min, Sec;
        QString qsMirror;
        if (match)
        {
            //Извлечение даты
            Year = qsSection.mid(0, 4).toInt();
            Month = qsSection.mid(4, 2).toInt();
            Day = qsSection.mid(6, 2).toInt();
            Hour = qsSection.mid(9, 2).toInt();
            Min = qsSection.mid(11, 2).toInt();
            Sec = qsSection.mid(13, 2).toInt();
            //qDebug() << "Строка " << qsSection << " is Ok for:" << pattern1 << ": Year=" << Year << " Month=" << Month << " Day=" << Day << " Hour=" << Hour << " Min=" << Min << " Sec=" << Sec;

            //Формирование строки данных по стандарту шаблона 2
            qsMirror = QString::number(Year);
            qsMirror += "-";
            if(Month < 10)qsMirror += "0";
            qsMirror += QString::number(Month);
            qsMirror += "-";
            if(Day < 10)qsMirror += "0";
            qsMirror += QString::number(Day);
            qsMirror += " ";
            if(Hour < 10)qsMirror += "0";
            qsMirror += QString::number(Hour);
            qsMirror += "-";
            if(Min < 10)qsMirror += "0";
            qsMirror += QString::number(Min);
            qsMirror += "-";
            if(Sec < 10)qsMirror += "0";
            qsMirror += QString::number(Sec);
            qDebug() << "Строка " << qsSection << " is Ok for:" << pattern1 << ": Mirror=" << qsMirror;

            //Поиск сформированной строки в списке 2
            if(qslPattern2.contains(qsMirror))
            {
                //Подсчёт совпадений
                iCount++;
                qDebug() << "String " << qsSection << " has mirror:" << qsMirror;
                ui->listWidgetFounded->addItem(qsSection);

                //Удаление найденной строки из конфигурационного файла
                deleteSection(qsMirror);//!!!
            }
        }
    }
    s += ": mirrors count=";
    s += QString::number(iCount);
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================
void MainWindow::execListWidgetFoundedItemClicked()
{
    QString s = "execListWidgetFoundedItemClicked()";
    QString value = ui->listWidgetFounded->currentItem()->text();

    int FoundedIndex = -1;

    if(cIniFile::Groups->contains(value))
    {
        FoundedIndex = cIniFile::Groups->indexOf(value);
    }

    // Модификация индекса
    iCurrentIndexGlobal.store(FoundedIndex, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    s += ": ";
    s += value;
    //---
    emit execShowExecStatus(s);
    //---
}



//=============================================================================

void MainWindow::execShowCurrentIndexPicture()
{
    showCurrentIndexPicture();
}

//=============================================================================

void MainWindow::showCurrentIndexPicture()
{

    //ListWidget->clear();

    int iGroupsCount = cIniFile::Groups->count();
    QListWidgetItem * item = new QListWidgetItem("==ShowCurrentIndexPicture==");
    item->setForeground(Qt::blue);
    ListWidget->addItem(item);
    ListWidget->addItem("GroupsCount=" + QString::number(iGroupsCount));
    if(iGroupsCount > 0)
    {
        // Читаем значения из INI-файла
        QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
        int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        if(index > (cIniFile::Groups->count() - 1))
        {
            QListWidgetItem * item = new QListWidgetItem("Index > GroupsCount. Index=" + QString::number(index) + " Set Index to head of GroupsList");
            item->setForeground(Qt::red);
            ListWidget->addItem(item);
            //qDebug() << "Loaded index out of range:" << index << " goto head of list";

            index = 0;
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

        }

        QString qsGroupName = cIniFile::Groups->at(index);
        //qDebug() << "showCurrentIndexPicture(): GroupName=" << qsGroupName;

        //Пропускаем RecordList
        if(qsGroupName == "RecordList")
        {
            index++;
            if(index > (iGroupsCount - 1))index = iGroupsCount - 1;//20250426
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);
            qsGroupName = cIniFile::Groups->at(index);

            QListWidgetItem * item = new QListWidgetItem("Skip 'RecordList' group");
            item->setForeground(Qt::yellow);
            ListWidget->addItem(item);
        }

        ListWidget->addItem("Index=" + QString::number(index));
        //===
        settings.beginGroup(qsGroupName);

        QString qsPath, qsName, qsError;

        QStringList keys = settings.childKeys();
        int iStrings = keys.count();

        //qDebug() << "showCurrentIndexPicture(): GroupName=" << qsGroupName << " KeysCount=" << iStrings;
        ListWidget->addItem("GroupName=" + qsGroupName + " KeysCount=" + QString::number(iStrings));

        QStandardItemModel * model= new QStandardItemModel(iStrings, 2);
        QListIterator<QString> readIt(keys);
        int iIndex = 0;
        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            if(key == "path") qsPath = value;
            if(key == "name") qsName = value;
            if(key == "Eror") qsError = value;

            model->setItem(iIndex, 0, new QStandardItem(key));
            model->setItem(iIndex, 1, new QStandardItem(value));
            iIndex++;
            //qDebug() << "iterator:" << key << " index:" << iIndex;
        }
        model->setHeaderData(0, Qt::Horizontal, "Key");
        model->setHeaderData(1,Qt::Horizontal,"Value");
        ui->tableViewCurrent->setModel(model);

        settings.endGroup();
        //===
        if(!qsPath.count() || !qsName.count())
        {
            QListWidgetItem * item = new QListWidgetItem("FilePaht=" + qsPath + " FileName=" + qsName + " file not exit!!!");
            item->setForeground(Qt::red);
            ListWidget->addItem(item);
            //qDebug() << "FilePath=" << qsPath << " FileName=" << qsName << " file not exist!!!";
            return;
        }

        QString imagePath = qsPath + '/' + qsName;

        if(qsError == "true")
        {
            QListWidgetItem * item = new QListWidgetItem("FullPaht=" + imagePath + " Error=" + qsError);
            item->setForeground(Qt::red);
            ListWidget->addItem(item);
            //qDebug() << "FullPath: " << imagePath << " Error:" << qsError;
            return;
        }
        else
        {
            emit draw(imagePath);
        }
        cImportFiles::labelFileNameText = qsName;
        cImportFiles::IslabelFileNameTextChanged = true;

        //Сохранение текущего индекса
        int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        settings.beginGroup("RecordList");
        settings.setValue("index", x);
        settings.endGroup();
        settings.sync();
    }
    else
    {
        QString s = "Groups is empty!";
        ListWidget->addItem(s);

        emit showExecStatus(s);

    }
}

//=============================================================================

//##############################################################################


