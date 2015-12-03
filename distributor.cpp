#include "distributor.h"
#include "team.h"
#include "student.h"

Distributor::Distributor(const QMap< int,QList< QPair<int,int> > >& pciParam) : pci(pciParam)
{

}

const QList<Team*>& Distributor::distributeTeams(const int minSize,const int maxSize){
    QList <Team*>* teams = new QList<Team*>;


    int numTeams = pci.keys().count()/minSize;

    for (int i = 0; i < numTeams; i++){
        //QPair<int,int> pair = pci.value(pci.keys.at(i));
    }

    return *teams;
}


int Distributor::calculateTeamWeight(Team team, int id)
{
    QList<int> teamMembers = team.getTeamMembers();
    int total = team.getPci();
    for(int i=0; i<teamMembers.count();i++){
       QList<QPair<int,int> > values = pci.value(id);
       for(int j; j<values.count(); j++){
           if(values.at(j).first == teamMembers.at(i)){
               total += values.at(j).second;
           }
        }

    }
    //total =(team.getTeamMembers().at(i));
    return -1;
}

int Distributor::assignStudentToTeam(int studentID, QList<Team*> teams)
{
    return -1;
}

