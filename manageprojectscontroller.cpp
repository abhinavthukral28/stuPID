#include "manageprojectscontroller.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include "project.h"
#include "Database.h"
#include <QDebug>
#include "team.h"
#include "createprojectview.h"
#include "student.h"
#include "teambuilder.h"
#include "adminviewresultcontroller.h"


ManageProjectsController *ManageProjectsController::instance = 0;
ManageProjectsController::ManageProjectsController():QObject(),
        database(Database::getInstance())

{


}






int ManageProjectsController::init(){

    allProjects = database->getAllProjects();
    selectedProject=0;

    QList<QString> projectTitles;
    QString tempTitle;

    for(int i=0;i<allProjects.count();i++){
        tempTitle = allProjects.at(i)->getTitle();
        projectTitles << tempTitle;

    }

    manageProjectsView->updateProjectsList(projectTitles);
    if(allProjects.count() > 0)
    {
        manageProjectsView->updateDetailedView(*allProjects.at(0));

        selectedProject = allProjects.at(0);
    }
    return 1;
}


int ManageProjectsController::updateSelectedProject(const int& index){
    selectedProject=allProjects.at(index);
    if(selectedProject != NULL){
        manageProjectsView->updateDetailedView(*selectedProject);

    }
    return 0;
}

int ManageProjectsController::updateStudentList(){
    if(selectedProject != NULL){
        manageProjectsView->setStudentList(*selectedProject);
    }
    return 0;
}

int ManageProjectsController::updateDetailedView(){
    if(selectedProject != NULL){
        manageProjectsView->setDetailedView(*selectedProject);
    }
    return 0;
}

int ManageProjectsController::goToCreateProjectView()
{
    manageProjectsView->close();
    CreateProjectView createProjectView;
    createProjectView.exec();

    return 0;

}

int ManageProjectsController::goToLoginDialog(){
    manageProjectsView->close();
    LoginDialog logindialog;
    return logindialog.exec();

}

int ManageProjectsController::makeTeams()
{
    qDebug() << "SENDING PROJECT WITH ID " << selectedProject->getID();
    if (selectedProject != NULL)
    {
        TeamBuilder* builder = new TeamBuilder;
        builder->createTeams(*selectedProject);
        delete builder;

        return 1;
    }
}
void ManageProjectsController::showDetailedResults(){
    AdminViewResultController* resultController = AdminViewResultController::getInstance();
    resultController->init(selectedProject->getID());
}
int ManageProjectsController::setView(ManageProjectsView*view){
    manageProjectsView = view;
}

ManageProjectsController* ManageProjectsController::getInstance(){
    if(!ManageProjectsController::instance) {
        ManageProjectsController::instance = new ManageProjectsController();
    }
    return ManageProjectsController::instance;
}
void ManageProjectsController::updateSummaryResults(){
    manageProjectsView->updateSummaryResults(database->getTeamsbyProjectID(selectedProject->getID()));
}
Student ManageProjectsController::getStudent(int id){
    return database->getStudentByID(id);
}
