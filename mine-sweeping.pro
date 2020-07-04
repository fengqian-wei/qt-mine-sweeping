#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T19:33:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mine-sweeping
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    block.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    block.h \
    dialog.h

FORMS    += mainwindow.ui
