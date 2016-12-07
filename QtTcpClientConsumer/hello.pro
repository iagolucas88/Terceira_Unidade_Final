#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T08:25:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hello
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plotter.cpp

HEADERS  += mainwindow.h \
    plotter.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    recursos.qrc
