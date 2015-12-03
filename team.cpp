#include "team.h"

Team::Team()
{
}


int Team::addStudent(int id)
{
    if (!teamMembers.contains(id))
    {
     teamMembers << id;
     return 1;
    }
    return 0;
}

const QList<int>& Team::getTeamMembers()
{
    return teamMembers;
}





int Team::removeStudent(int id){
 return teamMembers.removeOne(id);
}
