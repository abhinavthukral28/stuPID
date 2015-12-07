#include "editprojectcontroller.h"
#include "createprojectviewcontroller.h"
#include "createprojectview.h"
#include "Database.h"
#include "project.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include <QObject>
#include <QDebug>

EditProjectController *EditProjectController::instance=0;
EditProjectController::EditProjectController():QObject(),
    database(Database::getInstance())
{

}

int EditProjectController::saveProject(){
/*
   Project* project = new Project (editProjectView->getProjectTitle());

   project->setDescription(editProjectView->getProjectDescription());
   project->setTeamMin(editProjectView->getProjectTeamMin());
   project->setTeamMax(editProjectView->getProjectTeamMax());

   if(editProjectView->aTitle.isEmpty())
   {
       return 2;//project name

   }

   if(project->getMaxTeamSize() < project->getMinTeamSize() ||
           editProjectView->aMax.isEmpty() || createProjectsView->aMin.isEmpty() ||
           editProjectView->aMax.toInt() == 0 || createProjectsView->aMin.toInt() < 2)
   {
      return 3; //invalid team size
   }
   else{
    if(database->createProject(*project))
    {
        return 1;
    }
    else return 0;

   }

*/

 }

int EditProjectController::goToManageProjectView()
{
     //editProjectView->close();
     ManageProjectsView manageProjectView;
     manageProjectView.exec();

     return 0;
}

int EditProjectController::goToLoginDialog(){
    //editProjectView->close();
    LoginDialog login;
    login.exec();

}

int EditProjectController::error(int type)
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

int EditProjectController::setView(EditProjectView *view){
    editProjectView=view;
}

EditProjectController* EditProjectController::getInstance(){

    if(!EditProjectController::instance){

        EditProjectController::instance = new EditProjectController();
    }
    return EditProjectController::instance;

}
