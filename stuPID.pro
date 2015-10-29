
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
        logindialog.cpp \  
    studentregister.cpp \
    qualificationinit.cpp \
    editqualificationsview.cpp \
    manageprojectsview.cpp \
    Database.cpp \
    user.cpp \
    student.cpp \
    project.cpp \
    qualification.cpp \
    team.cpp \
    administrator.cpp

HEADERS  += mainwindow.h \
    studentregister.h \
            logindialog.h \
    qualificationinit.h \
    editqualificationsview.h \
        Database.h \
    manageprojectsview.h \
    user.h \
    student.h \
    project.h \
    qualification.h \
    team.h \
    administrator.h

FORMS    += mainwindow.ui \
    studentregister.ui \
            logindialog.ui \
    qualificationinit.ui \
    editqualificationsview.ui \
    manageprojectsview.ui

 
