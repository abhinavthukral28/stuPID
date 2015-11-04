
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
    administrator.cpp \
    logincontroller.cpp \
    manageprojectscontroller.cpp \
    studentprojectregisterview.cpp \
    studentregistercontroller.cpp \
    qualificationinitController.cpp \
    studentmanageprojectview.cpp \
    createprojectview.cpp \
    sqlexception.cpp \
    createprojectviewcontroller.cpp

HEADERS  += \
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
    administrator.h \
    DatabaseQueries.h \
    logincontroller.h \
    manageprojectscontroller.h \
    studentprojectregisterview.h \
    qualificationinitController.h \
    studentregistercontroller.h \
    studentmanageprojectview.h \
    createprojectview.h \
    sqlexception.h \
    createprojectviewcontroller.h

FORMS    += \
    studentregister.ui \
            logindialog.ui \
    qualificationinit.ui \
    editqualificationsview.ui \
    manageprojectsview.ui \
    studentprojectregisterview.ui \
    studentmanageprojectview.ui \
    createprojectview.ui
