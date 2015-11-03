#include "manageprojectscontroller.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include "project.h"
#include "Database.h"



ManageProjectsController::ManageProjectsController(ManageProjectsView *view):QObject(),
    manageProjectsView(view),
    database(Database::getInstance())

{
    //Database* database = Database::getInstance();
    allProjects = database->getAllProjects();


}



/*LoginController::LoginController( LoginDialog *login):QObject(), loginDialog(login)
{
}
*/


int ManageProjectsController::init(){


    QList<QString> projectTitles;
    QString tempTitle;

    for(int i=0;i<allProjects.count();i++){
        tempTitle = allProjects.at(i)->getTitle();
        projectTitles << tempTitle;

    }


    manageProjectsView->updateProjectsList(projectTitles);
    return 1;
}


int ManageProjectsController::updateSelectedProject(const int& index){

    manageProjectsView->updateDetailedView(*(allProjects.at(index)));
    return 0;
}


