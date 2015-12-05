#include "resultbuilder.h"

ResultBuilder::ResultBuilder(Team *team):newTeam(team), database(Database::getInstance())
{
    teamMemberIds = team->getTeamMembers();
    teamMembers = new QList<Student>();
    for(int i=0;i<teamMemberIds.count();i++){
        Student student = database->getStudentByID(teamMemberIds.at(i));
        teamMembers->append(student);
    }

}

QString ResultBuilder::getDetailedResults()
{

}

void ResultBuilder::getCompareString()
{

}
