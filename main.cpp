#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "createprojectview.h"
#include "logindialog.h"
#include "project.h"
#include <QDebug>
#include "team.h"
#include "resultbuilder.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Database::getInstance();
    LoginDialog view;
    view.show();

    Team *team = new Team();
    team->addStudent(1);
    team->addStudent(2);
    team->addStudent(3);
    ResultBuilder *result = new ResultBuilder(team);
    QString str = result->getDetailedResults();
    qDebug() << str;

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
