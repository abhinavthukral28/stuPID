#include "manageprojectscontroller.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include "Database.h"


ManageProjectsController::ManageProjectsController(ManageProjectsView *view):QObject(),manageProjectsView(view)
{

}

/*LoginController::LoginController( LoginDialog *login):QObject(), loginDialog(login)
{
}
*/

int ManageProjectsController::displayAllProjects(){
  //Database *d;
// QList<Project*>* p= d->getInstance()->getAllProjects();
       return 0;
}


