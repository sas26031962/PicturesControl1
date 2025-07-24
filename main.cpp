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

    w.raise();
    w.activateWindow();
    w.show();


    int x = a.exec();
    qsApplicationName = a.applicationName();

    return x;
}
