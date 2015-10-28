#-------------------------------------------------
#
# Project created by QtCreator 2015-09-13T16:05:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stuPID
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        logindialog.cpp \  
    studentregister.cpp

HEADERS  += mainwindow.h \
            logindialog.h \
    studentregister.h

FORMS    += mainwindow.ui \
            logindialog.ui \
    studentregister.ui
