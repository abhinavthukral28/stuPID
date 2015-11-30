#include "createprojectviewcontroller.h"
#include "createprojectview.h"
#include "Database.h"
#include "project.h"
#include "manageprojectsview.h"
#include <QObject>
#include <QDebug>

CreateProjectViewController::CreateProjectViewController(CreateProjectView *view): QObject(),
  createProjectsView(view),
  database(Database::getInstance())
{


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

   Project* project = new Project (createProjectsView->getProjectTitle());

   project->setDescription(createProjectsView->getProjectDescription());
   project->setTeamMin(createProjectsView->getProjectTeamMin());
   project->setTeamMax(createProjectsView->getProjectTeamMax());

   if(createProjectsView->aTitle.isEmpty())
   {
       return 2;//project name

   }

   if(project->getMaxTeamSize() < project->getMinTeamSize() ||
           createProjectsView->aMax.isEmpty() || createProjectsView->aMin.isEmpty())
   {
      return 3; //invalid team size
   }
   else{
    return database->createProject(*project);

   }


return 1;
 }

int CreateProjectViewController::goToManageProjectView()
{
     createProjectsView->close();
     ManageProjectsView manageProjectView;
     manageProjectView.exec();

     return 0;
}

int CreateProjectViewController::error(int type)
{
    if(type == 0)//all correct
    {
        return err = 0;
    }
    if(type == 1)//team size error
    {
        return err = 1;
    }
    if(type == 2)//project name
    {
        return err = 2;
    }
}
