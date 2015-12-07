#include "studentprojectregisterviewcontroller.h"
#include "Database.h"
#include "project.h"
#include "session.h"
#include "Database.h"
#include "sqlexception.h"
#include "studentprojectregisterview.h"
#include "studentmanageprojectview.h"
#include "logindialog.h"



studentprojectregisterviewcontroller *studentprojectregisterviewcontroller::instance=0;
studentprojectregisterviewcontroller::studentprojectregisterviewcontroller():QObject(),
   database(Database::getInstance())
{

    allProjects = database->getOpenProjectsByStudent(Session::getStudent().getID());
    selectedProject=NULL;
}

int studentprojectregisterviewcontroller::init()
{
    QList<QString> projectTitles;
    QString tempTitle;

    for(int i=0;i<allProjects.count();i++){
        tempTitle = allProjects.at(i)->getTitle();
        projectTitles << tempTitle;

    }

    stuProRegisterView->updateProjectsList(projectTitles);
    if(allProjects.count() > 0)
    {
      stuProRegisterView->updateDetailedView(*allProjects.at(0));
      if(!allProjects.isEmpty())
        selectedProject = allProjects.at(0);
    }
    return 1;

}

int studentprojectregisterviewcontroller::updateSelectedProject(const int& index)
{

    if (allProjects.count() > 0)
    {
        selectedProject=allProjects.at(index);
        if(selectedProject != NULL){
            stuProRegisterView->updateDetailedView(*selectedProject);
        }
    }
    return 0;
}

int studentprojectregisterviewcontroller::goStudentManageProjectView()
{
    stuProRegisterView->close();
    StudentManageProjectView studentManageProjectView;
    studentManageProjectView.exec();

     return 0;
}

int studentprojectregisterviewcontroller::gotoLoginDialog()
{
    stuProRegisterView->close();
    LoginDialog login;
    login.exec();

     return 0;
}


 int studentprojectregisterviewcontroller::registerToProject(){
    Student student = Session::getStudent();
    if(selectedProject != NULL)
    {
      if( database->addStudentToProject((selectedProject->getID()),student))
      {
          allProjects.removeOne(selectedProject);//
          return 1;
      }else if(allProjects.count() == 0 ){

          return 2;
      }else
      return 0;
    }

 }

 int studentprojectregisterviewcontroller::setView(studentProjectRegisterView *view){

    stuProRegisterView=view;
 }

studentprojectregisterviewcontroller* studentprojectregisterviewcontroller::getInstance(){

     if(!studentprojectregisterviewcontroller::instance){

         studentprojectregisterviewcontroller::instance = new studentprojectregisterviewcontroller();
     }
     return studentprojectregisterviewcontroller::instance;

 }




