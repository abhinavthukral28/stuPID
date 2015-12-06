#include "adminviewresultcontroller.h"
#include "adminviewresult.h"

AdminViewResultController::AdminViewResultController(int id):QObject(),
    projectId(id),
    database(Database::getInstance())
{
    adminViewResult = new AdminViewResult(this);
    adminViewResult->exec();

}
QList<Team*> AdminViewResultController::getTeams(){
    return database->getTeamsbyProjectID(projectId);

}
QString AdminViewResultController::getDetailResults(Team *team){
    ResultBuilder result(team);
    return result.getDetailedResults();
}

