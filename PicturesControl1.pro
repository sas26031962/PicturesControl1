#-------------------------------------------------
#
# Project created by QtCreator 2025-03-04T15:08:51
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14 # Добавляем поддержку C++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PicturesControl1
TEMPLATE = app


SOURCES += main.cpp\
    cenvironment.cpp \
    crecorditem.cpp \
        mainwindow.cpp \
    cinifile.cpp \
    crecord.cpp \
    #programm/debug/moc_mainwindow.cpp \
    #programm/moc_mainwindow.cpp
    fmview.cpp \
    cimportfiles.cpp \
    cdrawfilex.cpp \
    cloadfiles.cpp \
    clistwidgetplace.cpp \
    clistwidgetsubject.cpp \
    clistwidgetproperty.cpp \
    clistwidgettheame.cpp \
    cactionsexec.cpp \
    cnavigation.cpp \
    csearch.cpp \
    ThreadPool/processingtask.cpp \
    ThreadPool/processimporttask.cpp \
    ThreadPool/processstorerecordlisttask.cpp

HEADERS  += mainwindow.h \
    cenvironment.h \
    cinifile.h \
    crecord.h \
    #programm/moc_predefs.h \
    #programm/ui_mainwindow.h
    crecorditem.h \
    fmview.h \
    cimportfiles.h \
    cloadfiles.h \
    clistwidgettype.h \
    clistwidgetplace.h \
    clistwidgetsubject.h \
    clistwidgetproperty.h \
    clistwidgettheame.h \
    cactionsexec.h \
    cnavigation.h \
    cdrawfilex.h \
    csearch.h \
    ThreadPool/processingtask.h \
    ThreadPool/processimporttask.h \
    ThreadPool/processstorerecordlisttask.h

FORMS    += mainwindow.ui \
    fmview.ui

win32 {
    RC_FILE += file.rc
    OTHER_FILES += file.rc
}

RESOURCES += \
    resourcedata.qrc

DISTFILES +=
