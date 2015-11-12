#include "createprojectviewcontroller.h"
#include "createprojectview.h"
#include "Database.h"
#include "project.h"
#include <QObject>
#include <QDebug>

CreateProjectViewController::CreateProjectViewController(CreateProjectView *view): QObject(),
  createProjectsView(view),
  database(Database::getInstance())
{
  //projectList = database->getAllProjects();
    newproject=new Project("Empty");
}
/**
    int CreateProjectViewController::setNewProjectDescription(QString& description){
    qDebug() << "this is description" + description;
    newproject->setDescription(description);
    return 0;
 }

   int CreateProjectViewController::setNewProjectTeamMin(int& min){
    newproject->setTeamMin(min);
    return 0;
 }

  int CreateProjectViewController::setNewProjectTeamMax(int& max) {
    newproject->setTeamMax(max);
   return 0;
  }

   int CreateProjectViewController::setNewProjectTitle(QString &title){
    newproject->setTitle(title);
    return 0;
 }
   ***/

int CreateProjectViewController::saveProject(){
   //const QString& a= createProjectsView->getProjectDescription();
   //const QString& b= createProjectsView->getProjectTitle();
   //const int& c=createProjectsView->getProjectTeamMin();
  // const int& d=createProjectsView->getProjectTeamMax();

   newproject->setDescription(createProjectsView->getProjectDescription());
   newproject->setTitle(createProjectsView->getProjectTitle());
   newproject->setTeamMin(createProjectsView->getProjectTeamMin());
   newproject->setTeamMax(createProjectsView->getProjectTeamMax());



    database->createProject(*newproject);
qDebug()<<"YAYAYAAYAYAYAYA";

return 1;
 }

