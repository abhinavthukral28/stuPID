#include "team.h"

Team::Team(int idParam): id(idParam)
{
    pci = -1;
}

Team::Team()
{
   id = -1;
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



int Team::getID()
{
    return id;
}

int Team::removeStudent(int id){
    return teamMembers.removeOne(id);
}

int Team::getPci(){
    return pci;
}

int Team::setPci(int newPci){
    if(pci >= 0){
        pci = newPci;
        return 1;
    }
    return 0;
}
