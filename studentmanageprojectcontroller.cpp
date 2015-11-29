#include "studentmanageprojectcontroller.h"
#include "studentmanageprojectview.h"
#include "project.h"
#include "Database.h"
#include <QDebug>


StudentManageProjectController::StudentManageProjectController(StudentManageProjectView *view):QObject(),
    studentManageProjectView(view),
    database(Database::getInstance())
{
    allProjects = database->getAllProjects();

}

int StudentManageProjectController::init(){

    QList<QString> projectTitles;
    QString tempTitle;

    for(int i=0;i<allProjects.count();i++){
        tempTitle = allProjects.at(i)->getTitle();
        projectTitles << tempTitle;

    }

    studentManageProjectView->updateProjectsList(projectTitles);
    /*
    if(allProjects.count() > 0)
    manageProjectsView->updateDetailedView(*allProjects.at(0));
    return 1;
    */
}


int StudentManageProjectController::updateSelectedProject(const int& index){
    selectedProject=allProjects.at(index);
    if(selectedProject != NULL){
    studentManageProjectView->updateDetailedView(*selectedProject);
    }
    return 0;
}
