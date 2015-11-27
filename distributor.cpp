#include "distributor.h"
#include "team.h"

Distributor::Distributor(const QMap< int,QMap<int,int> >& pciParam) : pci(pciParam)
{

}

 const QList<Team*>& Distributor::distributeTeams(int minSize, int maxSize){
     QList <Team*>* teams = new QList<Team*>;
     return *teams;
 }


int Distributor::calculateTeamWeight(Team team)
{
 return -1;
}

int Distributor::assignStudentToTeam(int studentID, QList<Team*> teams)
{
    return -1;
}

