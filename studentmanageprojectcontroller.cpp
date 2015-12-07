#include "studentmanageprojectcontroller.h"
#include "studentmanageprojectview.h"
#include "project.h"
#include "session.h"
#include "logindialog.h"
#include "Database.h"
#include <QDebug>
#include "studentprojectregisterview.h"

StudentManageProjectController *StudentManageProjectController::instance=0;
StudentManageProjectController::StudentManageProjectController():QObject(),
    database(Database::getInstance())
{


}

int StudentManageProjectController::init(){

    allProjects = database->getProjectsByStudent(Session::getStudent().getID());
    QList<QString> projectTitles;
    QString tempTitle;

    for(int i=0;i<allProjects.count();i++){
        tempTitle = allProjects.at(i)->getTitle();
        projectTitles << tempTitle;

    }

    studentManageProjectView->updateProjectsList(projectTitles);

    if(allProjects.count() > 0)
    {
        studentManageProjectView->updateDetailedView(*allProjects.at(0));
        selectedProject = allProjects.at(0);
    }
    return 1;

}


int StudentManageProjectController::updateSelectedProject(const int& index){
    if (allProjects.count() > 0)
    {
        selectedProject=allProjects.at(index);
        if(selectedProject != NULL){
            studentManageProjectView->updateDetailedView(*selectedProject);
             return 1;
        }
                else return 0;
    }
    return 0;
}

int StudentManageProjectController::goStudentRegisterProjectView()
{
    studentManageProjectView->close();
    studentProjectRegisterView studentrojectRegisterView;
    studentrojectRegisterView.exec();

    return 0;

}

int StudentManageProjectController::gotoLoginDialog(){
    studentManageProjectView->close();
    LoginDialog login;
    login.exec();
}

int StudentManageProjectController::unregisterFromProject(){
    if(database->removeStudentFromProject(selectedProject->getID(),Session::getStudent()))
    {

        allProjects.removeOne(selectedProject);
        return 1;

    }
    else return 0;


}

int StudentManageProjectController::setView(StudentManageProjectView *view)
{
    studentManageProjectView = view;
}

StudentManageProjectController* StudentManageProjectController::getInstance(){

    if(!StudentManageProjectController::instance){

        StudentManageProjectController::instance = new StudentManageProjectController();
    }
    return StudentManageProjectController::instance;

}

