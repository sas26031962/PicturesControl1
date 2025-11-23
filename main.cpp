#include "mainwindow.h"
#include <QApplication>
#include <QString>

//-----------------------------------------------------------------------------
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
//-----------------------------------------------------------------------------

QString qsApplicationName = "PicturesControl1";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(qsApplicationName);
    MainWindow w;
    //20251123
    QString sName = w.windowTitle();
    sName += PROGRAMM_SUFFICS;
    w.setWindowTitle(sName);

    w.raise();
    w.activateWindow();
    w.show();

    int x = a.exec();

    return x;
}
