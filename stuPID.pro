
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
        studentmanageprojectview.cpp \
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
    createprojectview.cpp \
    sqlexception.cpp \
    createprojectviewcontroller.cpp \
    studentprojectregisterviewcontroller.cpp \
    teambuilder.cpp \
    distributor.cpp \
    pcibuilder.cpp \
    studentmanageprojectcontroller.cpp \
    adminviewresult.cpp \
    session.cpp \
    editqualificationscontroller.cpp \
    resultbuilder.cpp \
    adminviewresultcontroller.cpp \
    dbimpl.cpp \
    dbproxy.cpp \
    editprojectview.cpp \
    editprojectcontroller.cpp

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
    createprojectview.h \
    sqlexception.h \
    createprojectviewcontroller.h \
    studentprojectregisterviewcontroller.h \
        studentmanageprojectview.h \
    teambuilder.h \
    distributor.h \
    pcibuilder.h \
    studentmanageprojectcontroller.h \
    adminviewresult.h \
    session.h \
    editqualificationscontroller.h \
    resultbuilder.h \
    adminviewresultcontroller.h \
    dbimpl.h \
    dbproxy.h \
    editprojectview.h \
    editprojectcontroller.h

FORMS    += \
    studentregister.ui \
            logindialog.ui \
    qualificationinit.ui \
    editqualificationsview.ui \
    manageprojectsview.ui \
    studentprojectregisterview.ui \
    studentmanageprojectview.ui \
    createprojectview.ui \
    adminviewresult.ui \
    editprojectview.ui

RESOURCES += \
    resource.qrc
