#-------------------------------------------------
#
# Project created by QtCreator 2015-09-13T16:05:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
TARGET = stuPID
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
<<<<<<< HEAD
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
=======
    studentregisterview.cpp \
        logindialog.cpp \
    Database.cpp

HEADERS  += mainwindow.h \
    studentregisterview.h \
            logindialog.h \
    Database.h

FORMS    += mainwindow.ui \
    studentregisterview.ui \
            logindialog.ui
>>>>>>> 481721efecc91a7a58ec1f88db533ff773f0a5c5
