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
    studentregisterview.cpp \
        logindialog.cpp \
        sqlinit.cpp

HEADERS  += mainwindow.h \
    studentregisterview.h \
            logindialog.h

FORMS    += mainwindow.ui \
    studentregisterview.ui \
            logindialog.ui
