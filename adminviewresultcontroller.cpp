#include "adminviewresultcontroller.h"
#include "adminviewresult.h"
AdminViewResultController* AdminViewResultController::instance=0;
AdminViewResultController::AdminViewResultController():QObject(),
    database(Database::getInstance())
{

}
QList<Team*> AdminViewResultController::getTeams(){
    return database->getTeamsbyProjectID(projectId);

}
Student AdminViewResultController::getStudent(int id){
    return database->getStudentByID(id);
}
void AdminViewResultController::init(int id){
    projectId = id;
    adminViewResult = new AdminViewResult(this);
    adminViewResult->exec();

}
AdminViewResultController* AdminViewResultController::getInstance(){
    if(!AdminViewResultController::instance) {
        AdminViewResultController::instance = new AdminViewResultController();
    }
    return AdminViewResultController::instance;

}

