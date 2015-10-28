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
    qualificationinit.cpp \
    editqualificationsview.cpp

HEADERS  += mainwindow.h \
            logindialog.h \
    qualificationinit.h \
    editqualificationsview.h

FORMS    += mainwindow.ui \
            logindialog.ui \
    qualificationinit.ui \
    editqualificationsview.ui
