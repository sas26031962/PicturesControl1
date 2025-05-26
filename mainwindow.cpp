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
    qDebug() << "Build abi:" << QSysInfo::buildAbi();
    qDebug() << "Build CPU architecture:" << QSysInfo::buildCpuArchitecture();
    qDebug() << "Current CPU architecture:" << QSysInfo::currentCpuArchitecture();
    qDebug() << "Kernel type:" << QSysInfo::kernelType();
    qDebug() << "Kernel version:" << QSysInfo::kernelVersion();
    qDebug() << "Machine host name:" << QSysInfo::machineHostName();
    qDebug() << "Product name:" << QSysInfo::prettyProductName();
    qDebug() << "Product type:" << QSysInfo::productType();
    qDebug() << "Product version:" << QSysInfo::productVersion();

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

    QString qsIniFileName;

    if(cIniFile::iSystemType == LINUX_SYSTEM_TYPE)
    {

         cIniFile::iniFilePath = "/home/andy/MyQtProjects/PicturesControl1/programm/data/FilesConfigPhotos.ini";
         cIniFile::pattern1StringListFilePath = "/home/andy/MyQtProjects/PicturesControl1/programm/data/pattern1StringListFile.txt";
         cIniFile::pattern2StringListFilePath = "/home/andy/MyQtProjects/PicturesControl1/programm/data/pattern2StringListFile.txt";
         cIniFile::patternXStringListFilePath = "/home/andy/MyQtProjects/PicturesControl1/programm/data/pattern3StringListFile.txt";
         cIniFile::rotatedImagePath = "/home/andy/MyQtProjects/PicturesControl1/programm/img/tmp/rotated_image.png";
         cIniFile::scaledImagePath = "/home/andy/MyQtProjects/PicturesControl1/programm/img/tmp/scaled_image.png";
         cIniFile::filePathRemovedSectionList = "/home/andy/MyQtProjects/PicturesControl1/programm/data/RemovedSectionListPhotos.txt";// Прямой путь к файлу
         cIniFile::fileSubjectHashTag = "/home/andy/MyQtProjects/PicturesControl1/programm/data/HashTagListSubjectPhotos.txt";// Прямой путь к файлу;
         cIniFile::filePlaceHashTag = "/home/andy/MyQtProjects/PicturesControl1/programm/data/HashTagListPlacesPhotos.txt";//Прямой путь к файлу;
         cIniFile::filePropertyesHashTag = "/home/andy/MyQtProjects/PicturesControl1//programm/data/HashTagListPropertyesPhotos.txt";// Путь прямой;
         cIniFile::fileTheamsHashTag = "/home/andy/MyQtProjects/PicturesControl1//programm/data/HashTagListTheamsPhotos.txt";// Путь прямой;
         qsIniFileName ="/home/andy/From Smartfone";

    }
    else
    {

         cIniFile::iniFilePath = "C:/WORK/PicturesControl/PicturesControl1/programm/data/FilesConfigShips.ini";
         cIniFile::pattern1StringListFilePath = "C:/WORK/PicturesControl/PicturesControl1/programm/data/pattern1StringListFile.txt";
         cIniFile::pattern2StringListFilePath = "C:/WORK/PicturesControl/PicturesControl1/programm/data/pattern2StringListFile.txt";
         cIniFile::patternXStringListFilePath = "C:/WORK/PicturesControl/PicturesControl1/programm/data/pattern3StringListFile.txt";
         cIniFile::rotatedImagePath = "C:/WORK/PicturesControl/PicturesControl1/programm/img/tmp/rotated_image.png";
         cIniFile::scaledImagePath = "C:/WORK/PicturesControl/PicturesControl1/programm/img/tmp/scaled_image.png";
         cIniFile::filePathRemovedSectionList = "C:/WORK/PicturesControl/PicturesControl1/programm/data/RemovedSectionListShips.txt";// Прямой путь к файлу
         cIniFile::fileSubjectHashTag = "C:/WORK/PicturesControl/PicturesControl1/programm/data/HashTagListSubjectShips.txt";// Прямой путь к файлу;
         cIniFile::filePlaceHashTag = "C:/WORK/PicturesControl/PicturesControl1/programm/data/HashTagListPlacesShips.txt";//Прямой путь к файлу;
         cIniFile::filePropertyesHashTag = "C:/WORK/PicturesControl/PicturesControl1/programm/data/HashTagListPropertyesShips.txt";// Путь прямой;
         cIniFile::fileTheamsHashTag = "C:/WORK/PicturesControl/PicturesControl1/programm/data/HashTagListTheamsShips.txt";// Путь п р ямой;
         qsIniFileName = "C:/Work/Ships";
    }
    cIniFile::IniFile.setDirectoryPaht(qsIniFileName);

    //---

    qslDeletedSections.clear();

    ui->setupUi(this);

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

    connect(ui->actionRemoveMovie, SIGNAL(triggered()), this, SLOT( execActionRemoveMovie()));
    connect(ui->actionRemoveText, SIGNAL(triggered()), this, SLOT( execActionRemoveText()));
    connect(ui->actionRemoveTif, SIGNAL(triggered()), this, SLOT( execActionRemoveTif()));
    connect(ui->actionRemoveBin, SIGNAL(triggered()), this, SLOT( execActionRemoveBin()));
    connect(ui->actionRemove3gp, SIGNAL(triggered()), this, SLOT( execActionRemove3gp()));
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

    //---Для удаления
    connect(ui->actionLoaadHashTagListSubject, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListSubject()));
    connect(ui->actionLoadHashTagListPlace, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListPlace()));
    connect(ui->actionLoadHashTagListProperty, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListProperty()));
    connect(ui->actionLoadHashTagListTheame, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListTheame()));
    //---

    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

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

    //std::unique_ptr<QStringList> ptrHashTagList(new QStringList());
    //qslHashTagList = ptrHashTagList.get();
    qslHashTagList = new QStringList();

    //Загрузка списка хеш-тегов Subject
    if(loadHashTagListSubject())
    {
        ui->listWidgetSubject->clear();
        ui->listWidgetSubject->addItems(*qslHashTagList);

        // Настройка контекстного меню
        ui->listWidgetSubject->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(ui->listWidgetSubject, &QListWidget::customContextMenuRequested, this, &MainWindow::execListWidgetSubjectCustomContextMenuRequested);

        connect(ui->listWidgetSubject, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSubjectItemClicked()));
    }

    //Загрузка списка хеш-тегов Propertyes
    if(loadHashTagListProperty())
    {
        ui->listWidgetPropertyes->clear();
        ui->listWidgetPropertyes->addItems(*qslHashTagList);

        connect(ui->listWidgetPropertyes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetPropertyItemClicked()));
    }

    //Загрузка списка хеш-тегов Places
    if(loadHashTagListPlace())
    {
        ui->listWidgetPlaces->clear();
        ui->listWidgetPlaces->addItems(*qslHashTagList);

        // Настройка контекстного меню
        ui->listWidgetPlaces->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(ui->listWidgetPlaces, &QListWidget::customContextMenuRequested, this, &MainWindow::execListWidgetPlaceCustomContextMenuRequested);

        connect(ui->listWidgetPlaces, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetPlaceItemClicked()));
    }

    //Загрузка списка хеш-тегов Theams
    if(loadHashTagListTheame())
    {
        ui->listWidgetTheams->clear();
        ui->listWidgetTheams->addItems(*qslHashTagList);

        connect(ui->listWidgetTheams, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetTheameItemClicked()));
    }

    connect(fmViewPicture, SIGNAL(shiftXValueChanged()), this, SLOT( execShiftXValueChanged()));
    connect(fmViewPicture, SIGNAL(shiftYValueChanged()), this, SLOT( execShiftYValueChanged()));

    connect(ui->actionSearchRotated, SIGNAL(triggered()), this, SLOT( execActionSearchRotated()));

    ui->lineEditPattern->setText("^[Ii][Mm][Gg]_20[0-9]{6}_[0-9]{6}");//20250425

    connect(ui->actionInsertSubject, &QAction::triggered, this, &MainWindow::execActionInsertSubject);
    connect(ui->actionInsertPlace, &QAction::triggered, this, &MainWindow::execActionInsertPlace);
    connect(ui->actionInsertProperty, &QAction::triggered, this, &MainWindow::execActionInsertProperty);
    connect(ui->actionInsertTheame, &QAction::triggered, this, &MainWindow::execActionInsertTheame);

    connect(ui->actionSearchNamePattern1, &QAction::triggered, this, &MainWindow::execActionSearchNamePattern1);
    connect(ui->actionSearchNamePattern2, &QAction::triggered, this, &MainWindow::execActionSearchNamePattern2);
    connect(ui->actionSearchNamePatternX, &QAction::triggered, this, &MainWindow::execActionSearchNamePattern);
    connect(ui->pushButtonSearchPatternX, &QPushButton::pressed, this, &MainWindow::execActionSearchNamePattern);

    connect(ui->actionSearchNamePatterns12Intersection, SIGNAL(triggered()), this, SLOT( execActionSearchNamePatterns12Intersection()));
    connect(ui->actionSearchNamePatterns1XIntersection, SIGNAL(triggered()), this, SLOT( execActionSearchNamePatterns1XIntersection()));

    connect(ui->actionSearchOrYes, SIGNAL(triggered()), this, SLOT( execActionSearchOrYes()));
    connect(ui->pushButtonSearchOrYes, SIGNAL(pressed()), this, SLOT( execActionSearchOrYes()));

    connect(ui->listWidgetKeys, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetKeysItemClicked()));
    connect(ui->listWidgetSearch, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSearchItemClicked()));

    connect(ui->comboBoxPatterns, SIGNAL(currentIndexChanged(int)), this, SLOT(execComboBoxCurrentIndexChanged(int)));
    //connect(ui->comboBoxPatterns, &QComboBox::currentIndexChanged, this, &MainWindow::execComboBoxCurrentIndexChanged);
    //connect(ui->comboBoxPatterns, &QComboBox::editTextChanged, [](auto text){
    //    qDebug() << "Current text=" << text;
    //});

    connect(ui->actionOpenFoundRecord, &QAction::triggered, this, &MainWindow::execActionOpenFoundRecord);
    connect(ui->listWidgetFounded, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetFoundedItemClicked()));

    //ui->labelMain->setText("Exec 'Load' option for get file name list");

    //execActionLoad();

    //execActionSelectImageBegin();

}//End of ctor

MainWindow::~MainWindow()
{
//    cIniFile::settings.sync();//20250417
    timerUpdate->stop();

    saveRemovedSectionsList();

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

void MainWindow::showCurrentIndexPicture()
{

    // Читаем значения из INI-файла
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
    if(index > (cIniFile::Groups->count() - 1))
    {
        qDebug() << "Loaded index out of range:" << index << " goto head of list";

        index = 0;
        iCurrentIndexGlobal.store(index, std::memory_order_relaxed);
    }
    int iGroupsCount = cIniFile::Groups->count();
    if(iGroupsCount > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(index);
        //qDebug() << "showCurrentIndexPicture(): GroupName=" << qsGroupName;
        //Пропускаем RecordList
        if(qsGroupName == "RecordList")
        {
            index++;
            if(index > (iGroupsCount - 1))index = iGroupsCount - 1;//20250426
            iCurrentIndexGlobal.store(index, std::memory_order_relaxed);
            qsGroupName = cIniFile::Groups->at(index);

        }

        settings.beginGroup(qsGroupName);

        QString qsPath, qsName, qsError;

        QStringList keys = settings.childKeys();
        int iStrings = keys.count();
        qDebug() << "showCurrentIndexPicture(): GroupName=" << qsGroupName << " KeysCount=" << iStrings;

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

        if(!qsPath.count() || !qsName.count())
        {
            qDebug() << "FilePath=" << qsPath << " FileName=" << qsName << " file not exist!!!";
            return;
        }

        QString imagePath = qsPath + '/' + qsName;

        if(qsError == "true")
        {
            qDebug() << "FullPath: " << imagePath << " Error:" << qsError;
            //ui->labelMain->setText(imagePath);
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
        emit showExecStatus(s);

    }

}

//=============================================================================

//
// Запись QStringList в файл
//
bool MainWindow::saveStringListToFile(const QString& fileName, const QStringList& list)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8"); // Установка кодировки

    for (const QString& str : list) {
        out << str << "\n";
    }

    file.close();
    return true;
}


//=============================================================================

QStringList MainWindow::loadStringListFromFile(const QString& fileName)
{
    QStringList list;
    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in.setCodec("UTF-8");

        while (!in.atEnd()) {
            list << in.readLine();
        }

        file.close();
    }
    return list;
}

//=============================================================================

void MainWindow::loadRemovedSectionsList()
{
    qslDeletedSections = loadStringListFromFile(cIniFile::filePathRemovedSectionList);

    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(qslDeletedSections);

}//End of void MainWindow::loadRemovedSectionsList()

//=============================================================================

void MainWindow::saveRemovedSectionsList()
{

    saveStringListToFile(cIniFile::filePathRemovedSectionList, qslDeletedSections);

}//End of void MainWindow::saveRemovedSectionsList()

//=============================================================================
void MainWindow::execActionGotoIndex()
{

    int index = SpinBoxIndex->value();

    // Модификация индекса
    iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
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

    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
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

    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
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

    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
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

    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
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
    ui->listWidgetOther->addItems(qslDeletedSections);

    //execActionLoad();//Выполнить загрузку изображений

}//End of void MainWindow::execActionImport()

//=============================================================================

void MainWindow::execActionLoad()
{
    //--- Начало функции загрузки

    // Читаем значение текущего индекса из INI-файла
    int LoadedCurrentIndex = cIniFile::getCurrentIndex();

    //Загрузка списка групп
    cImportFiles::getGroupsList();
    cImportFiles::MaxIndexValue = cIniFile::Groups->count();

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

bool MainWindow::loadHashTagListSubject()
{

    QFile file(cIniFile::fileSubjectHashTag);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << cIniFile::fileSubjectHashTag;
        return false;
    }

    QTextStream in(&file);
    if(cIniFile::iSystemType == WINDOWS_SYSTEM_TYPE)
    {
        in.setCodec("Windows-1251");
    }

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

//=============================================================================

bool MainWindow::loadHashTagListPlace()
{

    QFile file(cIniFile::filePlaceHashTag);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << cIniFile::filePlaceHashTag;
        return false;
    }

    QTextStream in(&file);
    if(cIniFile::iSystemType == WINDOWS_SYSTEM_TYPE)
    {
        in.setCodec("Windows-1251");
        qDebug() << "Select Windows-1251 codec in loading case";
    }

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

//=============================================================================
bool MainWindow::loadHashTagListTheame()
{

    QFile file(cIniFile::fileTheamsHashTag);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << cIniFile::fileTheamsHashTag;
        return false;
    }
    else
    {
        qDebug() << "File: " << cIniFile::fileTheamsHashTag << " is loaded!";
    }

    QTextStream in(&file);
    if(cIniFile::iSystemType == WINDOWS_SYSTEM_TYPE)
    {
        in.setCodec("Windows-1251");
    }

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;

}

bool MainWindow::loadHashTagListProperty()
{

    QFile file(cIniFile::filePropertyesHashTag);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << cIniFile::filePropertyesHashTag;
        return false;
    }
    else
    {
        qDebug() << "File: " << cIniFile::filePropertyesHashTag << " is loaded!";
    }

    QTextStream in(&file);
    if(cIniFile::iSystemType == WINDOWS_SYSTEM_TYPE)
    {
        in.setCodec("Windows-1251");
    }

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

//=============================================================================

void MainWindow::execActionLoadHashTagListSubject()
{
    QString s = "ActionLoadHashTagListSubject()";
    if(loadHashTagListSubject())
    {
        qDebug() << s << ": loadHashTagListSubject is sucsess";
        ui->listWidgetSubject->clear();
        ui->listWidgetSubject->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetSubject->clear();
        qDebug() << s << ": loadHashTagListSubject is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionLoadHashTagListPlace()
{
    QString s = "ActionLoadHashTagListPlace()";

    if(loadHashTagListPlace())
    {
        qDebug() << s << ": loadHashTagListPlace is sucsess";
        ui->listWidgetPlaces->clear();
        ui->listWidgetPlaces->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetPlaces->clear();
        qDebug() << s << ": loadHashTagListPlace is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionLoadHashTagListProperty()
{
    QString s = "ActionLoadHashTagListProperty()";

    if(loadHashTagListProperty())
    {
        qDebug() << s << ": loadHashTagListProperty is sucsess";
        ui->listWidgetPropertyes->clear();
        ui->listWidgetPropertyes->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetPropertyes->clear();
        qDebug() << s << ": loadHashTagListPrperty is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionLoadHashTagListTheame()
{

    QString s = "ActionLoadHashTagListTheame()";

    if(loadHashTagListTheame())
    {
        qDebug() << s << ": loadHashTagListTheame is sucsess";
        ui->listWidgetTheams->clear();
        ui->listWidgetTheams->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetTheams->clear();
        qDebug() << s << ": loadHashTagListTheame is broken!!!";
    }
    //---
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
        ui->listWidgetOther->addItems(qslDeletedSections);
    }

    execActionSelectImagePrevious();//Перерисовка изображения

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveText()
{
    QString s = "ActionRemoveText()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".txt") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;

            //--- Удаление ключей секции: начало ---
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
            //--- Удаление ключей секции: конец ---
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'txt' detected in " << iCount << " files";
    else
        qDebug() << "No 'txt' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveTif()
{

    QString s = "ActionRemoveTif()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".tif") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'tif' detected in " << iCount << " files";
    else
        qDebug() << "No 'tif' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemove3gp()
{

    QString s = "ActionRemove3gp()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".3gp") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension '3gp' detected in " << iCount << " files";
    else
        qDebug() << "No '3gp' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveBin()
{

    QString s = "ActionRemoveBin()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".bin") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'bin' detected in " << iCount << " files";
    else
        qDebug() << "No 'bin' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveMovie()
{
    QString s = "ActionRemoveMovie()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        //---
        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".mp4") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;

                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }
        //---
    }//End of while (readIt.hasNext())
    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'mp4' detected in " << iCount << " files";
    else
        qDebug() << "No 'mp4' in file names detected, Ok!";

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

void MainWindow::AddOrRemoveSubjectItemToRecord()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execSubjectItemClicked()";
    QString item = ui->listWidgetSubject->currentItem()->text();
    qDebug() << "listWidgetSubject: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        settings.beginGroup(qsGroupName);
        QStringList list = settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            settings.setValue(item, "true");
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
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetSubjectItemClicked()
{

    QString s = "Use RightMouseButton to Add / Remove item to record";
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetPropertyItemClicked()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execPropertyItemClicked()";
    QString item = ui->listWidgetPropertyes->currentItem()->text();
    qDebug() << "listWidgetProperty: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        settings.beginGroup(qsGroupName);
        QStringList list = settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            settings.setValue(item, "true");
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
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetTheameItemClicked()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execTheameItemClicked()";
    QString item = ui->listWidgetTheams->currentItem()->text();
    qDebug() << "listWidgetTheame: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        settings.beginGroup(qsGroupName);
        QStringList list = settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            settings.setValue(item, "true");
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

void MainWindow::AddOrRemovePlaceItemToRecord()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString s = "execPlaceItemClicked()";
    QString item = ui->listWidgetPlaces->currentItem()->text();
    qDebug() << "listWidgetPlace: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        settings.beginGroup(qsGroupName);
        QStringList list = settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            settings.setValue(item, "true");
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
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetPlaceItemClicked()
{
    QString s = "Use RightMouseButton to Add / Remove item to record";
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

void MainWindow::execActionSearchNamePatterns12Intersection()
{
    QString s = "execActionSearchNamePattens12Intersection()";

    QString pattern1 = "^20[0-9]{6}_[0-9]{6}";

    QStringList qslPattern1 = cLoadFiles::loadStringListFromFile(cIniFile::pattern1StringListFilePath);
    QStringList qslPattern2 = cLoadFiles::loadStringListFromFile(cIniFile::pattern2StringListFilePath);

    qDebug() << "ListPattern1 count=" << qslPattern1.count() << " ListPattern2 count=" << qslPattern2.count();

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
            if(qslPattern2.contains(qsMirror))
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

void MainWindow::execActionInsertSubject()
{
    QString s = "execActionInsertSubject()";

    QString qsGoal = ui->lineEditAddIterm->text();

    if(qsGoal.length() <= 0)
    {
        //Информационное сообщение
        s += ": Empty string, nothing to do!";
        s += qsGoal;

        //---
        emit execShowExecStatus(s);
        //---

        return;
    }

    //---Загрузка списка Subject

    if(!loadHashTagListSubject())
    {
        qDebug() << "Error: Could not load HashTagListSubject from file: " << cIniFile::fileSubjectHashTag;
        return;
    }

    qDebug() << ": loadHashTagListSubject is sucsess";
    //---

    //Здесь должна быть проверка на наличие нового значения в списке
    if(qslHashTagList->indexOf(qsGoal) < 0)
    {
        ui->listWidgetSubject->clear();
        int iLast = qslHashTagList->count() - 1;
        if(qslHashTagList->at(iLast) == "")
        {
            qslHashTagList->replace(iLast, qsGoal);
        }
        else
        {
            qslHashTagList->append(qsGoal);
        }
        ui->listWidgetSubject->addItems(*qslHashTagList);

        //Сохранение нового списка Subject

        cLoadFiles::saveStringListToFile(cIniFile::fileSubjectHashTag, *qslHashTagList);

        //Информационное сообщение
        s += ": ";
        s += qsGoal;
    }
    else
    {
        //Информационное сообщение
        s += ": HashTagListSubject already contain ";
        s += qsGoal;
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionInsertPlace()
{
    QString s = "execActionInsertPlace()";

    QString qsGoal = ui->lineEditAddIterm->text();

    if(qsGoal.length() <= 0)
    {
        //Информационное сообщение
        s += ": Empty string, nothing to do!";
        s += qsGoal;

        //---
        emit execShowExecStatus(s);
        //---

        return;
    }

    //---Загрузка списка Place

    if(!loadHashTagListPlace())
    {
        qDebug() << "Error: Could not load HashTagListPlace from file: " << cIniFile::filePlaceHashTag;
        return;
    }

    qDebug() << ": loadHashTagListPlace is sucsess";

    //Здесь должна быть проверка на наличие нового значения в списке
    if(qslHashTagList->indexOf(qsGoal) < 0)
    {
        ui->listWidgetPlaces->clear();
        int iLast = qslHashTagList->count() - 1;
        if(qslHashTagList->at(iLast) == "")
        {
            qslHashTagList->replace(iLast, qsGoal);
        }
        else
        {
            qslHashTagList->append(qsGoal);
        }
        ui->listWidgetPlaces->addItems(*qslHashTagList);

        //Сохранение нового списка Place

        cLoadFiles::saveStringListToFile(cIniFile::filePlaceHashTag, *qslHashTagList);

        //Информационное сообщение
        s += ": ";
        s += qsGoal;
    }
    else
    {
        //Информационное сообщение
        s += ": HashTagListPlace already contain ";
        s += qsGoal;
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionInsertProperty()
{
    QString s = "execActionInsertProperty()";

    QString qsGoal = ui->lineEditAddIterm->text();

    if(qsGoal.length() <= 0)
    {
        //Информационное сообщение
        s += ": Empty string, nothing to do!";
        s += qsGoal;

        //---
        emit execShowExecStatus(s);
        //---

        return;
    }

    //---Загрузка списка Property

    if(!loadHashTagListProperty())
    {
        qDebug() << "Error: Could not load HashTagListProperty from file: " << cIniFile::filePropertyesHashTag;
        return;
    }

    qDebug() << ": loadHashTagListProperty is sucsess";

    //Здесь должна быть проверка на наличие нового значения в списке
    if(qslHashTagList->indexOf(qsGoal) < 0)
    {
        ui->listWidgetPropertyes->clear();
        int iLast = qslHashTagList->count() - 1;
        if(qslHashTagList->at(iLast) == "")
        {
            qslHashTagList->replace(iLast, qsGoal);
        }
        else
        {
            qslHashTagList->append(qsGoal);
        }
        ui->listWidgetPropertyes->addItems(*qslHashTagList);

        //Сохранение нового списка Property

        cLoadFiles::saveStringListToFile(cIniFile::filePropertyesHashTag, *qslHashTagList);

        //Информационное сообщение
        s += ": ";
        s += qsGoal;
    }
    else
    {
        //Информационное сообщение
        s += ": HashTagListPropertyes already contain ";
        s += qsGoal;
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionInsertTheame()
{
    QString s = "execActionInsertTheame()";

    QString qsGoal = ui->lineEditAddIterm->text();

    if(qsGoal.length() <= 0)
    {
        //Информационное сообщение
        s += ": Empty string, nothing to do!";
        s += qsGoal;

        //---
        emit execShowExecStatus(s);
        //---

        return;
    }

    //---Загрузка списка Theame

    if(!loadHashTagListTheame())
    {
        qDebug() << "Error: Could not load HashTagListTheame from file: " << cIniFile::fileTheamsHashTag;
        return;
    }

    qDebug() << ": loadHashTagListTheams is sucsess";

    //Здесь должна быть проверка на наличие нового значения в списке
    if(qslHashTagList->indexOf(qsGoal) < 0)
    {
        ui->listWidgetTheams->clear();
        int iLast = qslHashTagList->count() - 1;
        if(qslHashTagList->at(iLast) == "")
        {
            qslHashTagList->replace(iLast, qsGoal);
        }
        else
        {
            qslHashTagList->append(qsGoal);
        }
        ui->listWidgetTheams->addItems(*qslHashTagList);

        //Сохранение нового списка Theams

        cLoadFiles::saveStringListToFile(cIniFile::fileTheamsHashTag, *qslHashTagList);

        //Информационное сообщение
        s += ": ";
        s += qsGoal;
    }
    else
    {
        //Информационное сообщение
        s += ": HashTagListTheams already contain ";
        s += qsGoal;
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void  MainWindow::execListWidgetSubjectCustomContextMenuRequested(const QPoint &pos)
{
    QString s = "execWidgetListSubjectCustomContextMenuRequested()";

    //Задание типа меню
    lwtListType = ListWidgetType::SUBJECT_TYPE;

    QListWidget * listWidget = ui->listWidgetSubject;
    QListWidgetItem * item = listWidget->itemAt(pos);
    if(!item)
    {
        s += ": no item selected!";
        //---
        emit execShowExecStatus(s);
        //---
        return;
    }

    int index = listWidget->row(item);
    QString qsItem = item->text();

    QMenu contextMenu;
    QAction *actionAddOrRemoveItemToRecord = contextMenu.addAction("Добавить(удалить) элемент в запись");
    QAction *actionRemoveItemFromList = contextMenu.addAction("Удалить элемент из списка");
    QAction *actionInsertItemToList = contextMenu.addAction("Добавить элемент в список");

    QAction *selectedAction = contextMenu.exec(listWidget->viewport()->mapToGlobal(pos));

    if (selectedAction == actionAddOrRemoveItemToRecord)
    {
        // Обработка первого действия
        qDebug() << "exec actionAddOrRemoveItemToRecord: item=" << item->text()<< " index of this item=" << index;

        AddOrRemoveSubjectItemToRecord();
    }

    else if (selectedAction == actionRemoveItemFromList)
    {
        // Обработка второго действия
        qDebug() << "exec actionRemoveItemFromList: item=" << item->text()<< " index of this item=" << index;

        //---Загрузка списка Subject

        if(!loadHashTagListSubject())
        {
            qDebug() << "Error: Could not load HashTagListSubject from file: " << cIniFile::fileSubjectHashTag;
            return;
        }

        qDebug() << ": loadHashTagListSubject is sucsess";
        //Здесь должна быть проверка на наличие удаляемого значения в списке
        if(qslHashTagList->indexOf(qsItem) > 0)
        {
            qslHashTagList->removeAll(qsItem);
            listWidget->clear();
            listWidget->addItems(*qslHashTagList);

            //Сохранение нового списка Subject

            cLoadFiles::saveStringListToFile(cIniFile::fileSubjectHashTag, *qslHashTagList);

            //Информационное сообщение
            s += "Removed item: ";
            s += qsItem;
        }
        //---

    }

    else if (selectedAction == actionInsertItemToList)
    {
        // Обработка третьего действия
        qDebug() << "exec actionInsertItemToList: item=" << ui->lineEditAddIterm->text();
        emit ui->actionInsertSubject->triggered();
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetPlaceCustomContextMenuRequested(const QPoint &pos)
{
    QString s = "execWidgetListPlaceCustomContextMenuRequested()";

    //Задание типа меню
    lwtListType = ListWidgetType::PLACE_TYPE;

    QListWidget * listWidget = ui->listWidgetPlaces;
    QListWidgetItem * item = listWidget->itemAt(pos);
    if(!item)
    {
        s += ": no item selected!";
        //---
        emit execShowExecStatus(s);
        //---
        return;
    }

    int index = listWidget->row(item);
    QString qsItem = item->text();

    QMenu contextMenu;
    QAction *actionAddOrRemoveItemToRecord = contextMenu.addAction("Добавить(удалить) элемент в запись");
    QAction *actionRemoveItemFromList = contextMenu.addAction("Удалить элемент из списка");
    QAction *actionInsertItemToList = contextMenu.addAction("Добавить элемент в список");

    QAction *selectedAction = contextMenu.exec(listWidget->viewport()->mapToGlobal(pos));

    if (selectedAction == actionAddOrRemoveItemToRecord)
    {
        // Обработка первого действия
        qDebug() << "exec actionAddOrRemoveItemToRecord: item=" << item->text()<< " index of this item=" << index;

        AddOrRemovePlaceItemToRecord();
    }

    else if (selectedAction == actionRemoveItemFromList)
    {
        // Обработка второго действия
        qDebug() << "exec actionRemoveItemFromList: item=" << item->text()<< " index of this item=" << index;

        //---Загрузка списка Place

        if(!loadHashTagListPlace())
        {
            qDebug() << "Error: Could not load HashTagListPlace from file: " << cIniFile::filePlaceHashTag;
            return;
        }

        qDebug() << ": loadHashTagListPlace is sucsess";
        //Здесь должна быть проверка на наличие удаляемого значения в списке
        if(qslHashTagList->indexOf(qsItem) > 0)
        {
            qslHashTagList->removeAll(qsItem);
            listWidget->clear();
            listWidget->addItems(*qslHashTagList);

            //Сохранение нового списка Place

            cLoadFiles::saveStringListToFile(cIniFile::filePlaceHashTag, *qslHashTagList);

            //Информационное сообщение
            s += "Removed item: ";
            s += qsItem;
        }
        else
        {
            qDebug() << "Item " << qsItem << "not found in HashTagListPlace";
        }
        //---

    }

    else if (selectedAction == actionInsertItemToList)
    {
        // Обработка третьего действия
        qDebug() << "exec actionInsertItemToList: item=" << ui->lineEditAddIterm->text();
        emit ui->actionInsertPlace->triggered();
    }

    //---
    emit execShowExecStatus(s);
    //---
}
