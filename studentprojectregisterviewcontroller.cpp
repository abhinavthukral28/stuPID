#include "studentprojectregisterviewcontroller.h"
#include "Database.h"
#include "project.h"
#include "session.h"
#include "Database.h"
#include "sqlexception.h"
#include "studentprojectregisterview.h"
#include "studentmanageprojectview.h"




studentprojectregisterviewcontroller::studentprojectregisterviewcontroller(studentProjectRegisterView *view):QObject(),
   stuProRegisterView(view),
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

 int studentprojectregisterviewcontroller::registerToProject(){
    Student student = Session::getStudent();
    if(selectedProject != NULL)
    {
      if( database->addStudentToProject((selectedProject->getID()),student)){
          allProjects.removeAt(0);
          return 1;
      }
      return 0;
    }
    else return 2;

 }
