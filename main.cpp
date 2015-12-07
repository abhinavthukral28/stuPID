#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "createprojectview.h"
#include "logindialog.h"
#include "project.h"
#include "student.h"
#include <QDebug>
#include "team.h"
#include "teambuilder.h"
#include "resultbuilder.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Database* database = Database::getInstance();
//    database->getTeamsbyProjectID(1);
//    TeamBuilder builder;
//    QList<Team*> teams = builder.createTeams(*database->getAllProjects().at(0));
//    database->storeTeamsByProject(teams,1);

    LoginDialog view;
    view.show();


  return a.exec();



}
