#include "mainwindow.h"
#include <QApplication>
#include <QString>

//-----------------------------------------------------------------------------
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
//-----------------------------------------------------------------------------

QString qsApplicationName = "NoName";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.raise();
    w.activateWindow();
    w.show();


    int x = a.exec();
    qsApplicationName = a.applicationName();

    return x;
}
