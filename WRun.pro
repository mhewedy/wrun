#-------------------------------------------------
#
# Project created by QtCreator 2010-10-21T15:31:57
#
#-------------------------------------------------

QT       += core gui

TARGET = WRun
TEMPLATE = app


SOURCES += main.cc\
        mainwindow.cc \
    exefinder.cc \
    exeloaderthread.cc

HEADERS  += mainwindow.h \
    exefinder.h \
    exeloaderthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
