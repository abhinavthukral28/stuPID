#include "editprojectcontroller.h"
#include "createprojectviewcontroller.h"
#include "createprojectview.h"
#include "Database.h"
#include "project.h"
#include "manageprojectscontroller.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include <QObject>
#include <QDebug>

EditProjectController *EditProjectController::instance=0;
EditProjectController::EditProjectController():QObject(),
    database(Database::getInstance()),oldProject(Project(""))
{

}

int EditProjectController::saveProject(){

   oldProject.setTitle(editProject->getProjectTitle());

   oldProject.setDescription(editProject->getProjectDescription());
   oldProject.setTeamMin(editProject->getProjectTeamMin());
   oldProject.setTeamMax(editProject->getProjectTeamMax());

   qDebug()<<"Hello";

   database->updateProject(oldProject);

   qDebug()<<"It Updated"+oldProject.getTitle();



  // database->updateProject(oldProject);

   if(editProject->aTitle.isEmpty())
   {
       qDebug()<<"title is empty";

       return 2;//project name

   }

   if(oldProject.getMaxTeamSize() < oldProject.getMinTeamSize() ||
           editProject->aMax.isEmpty() || editProject->aMin.isEmpty() ||
           editProject->aMax.toInt() == 0 || editProject->aMin.toInt() < 2)
   {
       qDebug()<<"oh no";

      return 3; //invalid team size
   }
   else{
    if(database->updateProject(oldProject))
    {
        return 1;
        qDebug()<<"it updated!";
    }

    else{
        qDebug()<<"it aint updating yoo";
        return 0;
    }


   }



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
    editProject=view;

}


int EditProjectController::initValues(Project *project){
oldProject=Project(*project);
 editProject->updateView(project);
}

EditProjectController* EditProjectController::getInstance(){

    if(!EditProjectController::instance){

        EditProjectController::instance = new EditProjectController();
    }
    return EditProjectController::instance;

}
