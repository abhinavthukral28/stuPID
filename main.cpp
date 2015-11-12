#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "createprojectview.h"
#include "logindialog.h"
#include "project.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //view.show();
    //LoginDialog view;
    Database::getInstance();
    LoginDialog view;
    view.show();
/*
    Database* database = Database::getInstance();
    int tempID = -1;
    QString title = "imaproject";
    Project* project = new Project(tempID,title);


    database->createProject(*project);

    QList<Project*>& projects = database->getAllProjects();

    for (int i = 0; i < projects->count(); i++)
    {
        qDebug() << "this is fucked";
        QString temp = projects->at(i)->getTitle();
        std::cout << QString::toStdString(temp);
    }
    */


  return a.exec();



}
