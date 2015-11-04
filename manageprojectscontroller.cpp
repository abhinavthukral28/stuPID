#include "manageprojectscontroller.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include "project.h"
#include "Database.h"



ManageProjectsController::ManageProjectsController(ManageProjectsView *view):QObject(),
    manageProjectsView(view),
    database(Database::getInstance())

{
    allProjects = database->getAllProjects();
    selectedProject=0;

}






int ManageProjectsController::init(){

    QList<QString> projectTitles;
    QString tempTitle;

    for(int i=0;i<allProjects.count();i++){
        tempTitle = allProjects.at(i)->getTitle();
        projectTitles << tempTitle;

    }

    manageProjectsView->updateProjectsList(projectTitles);
    if(allProjects.count() > 0)
    manageProjectsView->updateDetailedView(*allProjects.at(0));
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


