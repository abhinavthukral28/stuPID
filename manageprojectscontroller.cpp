#include "manageprojectscontroller.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include "project.h"
#include "Database.h"


ManageProjectsController::ManageProjectsController(ManageProjectsView *view):QObject(),manageProjectsView(view)
{

}

/*LoginController::LoginController( LoginDialog *login):QObject(), loginDialog(login)
{
}
*/

int ManageProjectsController::init(){
  Database* database = Database::getInstance();
  QList<Project*>* allProjects;// = database->getAllProjects();
  QStringList projectTitles;

       for(int i=0;i<allProjects->count();i++){
           projectTitles<<allProjects->at(i)->getTitle();
       }


    manageProjectsView->updateProjectsList(projectTitles);
    return 1;
}

int ManageProjectsController::updateSelectedProject(const int& index){
    return 0;
}


