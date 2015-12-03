#include "distributor.h"
#include "team.h"
Distributor::Distributor(const QMap< int,QList< QPair<int,int> > >& pciParam) : pci(pciParam)
{

}

 const QList<Team*>& Distributor::distributeTeams(const int minSize,const int maxSize){
     QList <Team*>* teams = new QList<Team*>;


     int numTeams = pci.keys().count()/minSize;

     createTopRowPairs(numTeams);
     return *teams;
 }


int Distributor::calculateTeamWeight(Team team)
{
    QList<int> total;
    QList<Student*> teamMembers = team.getTeamMembers();
        for(int i=0;i<teamMembers.count();i++){
        int a = 0;
        }
        //total =(team.getTeamMembers().at(i));
 return -1;
}

int Distributor::assignStudentToTeam(int studentID, QList<Team*> teams)
{
    return -1;
}

QList< QPair<int,int> > Distributor::createTopRowPairs(int numTeams)
{
     QList< QPair<int,int> > topRow;
     for (int i = 0; i < pci.keys().count(); i++){

         int IDOne = pci.keys().at(i);
         insert(topRow,pci.value(IDOne).at(0));



     }

     for (int i = numTeams; i < topRow.count(); i++)
     {
         topRow.removeAt(i);
     }
     return topRow;
}

bool Distributor::insert(QList<QPair<int,int> >& pci,const QPair<int,int>& pair){
    bool inserted = false;
    for (int i = 0; i < pci.count() && !inserted; i++)
    {
        if (pci.at(i).second > pair.second)
        {
            if (i > 0)
            {
                pci.insert(i-1,pair);
                inserted = true;
            }
            else break;
        }
    }

    if (!inserted)
        pci.insert(0,pair);

    return inserted;
}
