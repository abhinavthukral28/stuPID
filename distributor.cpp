#include "distributor.h"
#include "team.h"
#include <QDebug>
Distributor::Distributor(QMap< int,QList< QPair<int,int> >* >& pciParam) : pci(pciParam)
{

}

const QList<Team*>& Distributor::distributeTeams(const int minSize,const int maxSize){

    qDebug () << " STARTING DISTRIBUTOR";

    QList<int> remainingStudents = pci.keys();

    int numTeams = pci.keys().count()/minSize;


      QList<Team*> teams = createTopRowTeams(numTeams,remainingStudents);

     addOutliers(teams,minSize,maxSize);
     for (int i = 0; i < teams.count(); i++)
     {
         qDebug() <<"Team " << (i+1);

         for (int j = 0; j < teams.at(i)->getTeamMembers().count(); j++)
         {
             qDebug () << teams.at(i)->getTeamMembers().at(j);
         }


     }

     for (int i = 0; i < pci.keys().count(); i++)
     {
        qDebug() << pci.keys().at(i);
     }


     return teams;
 }


int Distributor::calculateTeamWeight(const Team& team,const int& id)
{
    QList<int> teamMembers = team.getTeamMembers();
    int total = team.getPci();
    for(int i=0; i<teamMembers.count();i++){
       QList<QPair<int,int> >* values = pci.value(id);
       for(int j; j<values->count(); j++){
           if(values->at(j).first == teamMembers.at(i)){
               total += values->at(j).second;
           }
        }

    }
    return total;
}

int Distributor::assignStudentToTeam(int studentID, QList<Team*> teams)
{
    return -1;
}

QList<Team*>& Distributor::createTopRowTeams(int numTeams,QList<int>& remainingStudents)
{

     QList< Team* >* topRow = new QList< Team* >;
     QList< int > keys = sortKeys(pci.keys());

     for (int i = 0; i < keys.count();i++)
     {
         if (numTeams == 0)
             return *topRow;
         int idOne = keys.at(i);
         if (pci.contains(keys.at(i)))
         {
             int otherID = pci.value(idOne)->at(0).first;
             qDebug() << "this one " << idOne;
             qDebug() << "other one " << pci.value(idOne)->at(0).first;
             int idTwo = pci.value(pci.value(idOne)->at(0).first)->at(0).first;
             if (idOne == idTwo)
             {
                 qDebug() << "Student with ID " << idOne << "and " << pci.value(idOne)->at(0).first << "top row match";
                 qDebug() << "The PCI between them is " << pci.value(idOne)->at(0).second;

                 Team* team = new Team();
                 team->addStudent(idOne);
                 team->addStudent(pci.value(idOne)->at(0).first);
                 team->setPci(pci.value(idOne)->at(0).second);
                 topRow->append(team);
                 numTeams--;
                 qDebug() << "Added student id " << idOne << "and " << pci.value(idOne)->at(0).first << "to a new team";


                 qDebug () << " Removing key " << idOne;
                 qDebug () << " Removing key " << otherID;

                 keys.removeOne(idOne);
                 keys.removeOne(otherID);

                 QMutableMapIterator<int,QList<QPair<int,int > >* > iterator (pci);
                 while (iterator.hasNext()) {
                     iterator.next();
                     if (iterator.key() == idOne || iterator.key() == otherID)
                         iterator.remove();
                 }

                 for (int l = 0; l < pci.keys().count(); l++)
                 {
                    qDebug() << " filtering " << pci.keys().at(l);
                    QList< QPair <int,int> >* matches = pci.value(pci.keys().at(l));
                    QList <int> indexes;
                    for (int k = 0; k < matches->count(); k++)
                    {
                        int id = matches->at(k).first;
                        if (id == idOne || id == otherID)
                        {
                            qDebug () << "Removing top match from " << pci.keys().at(l) << " for id " << id;
                            qDebug () << "Removing at index " << k;
                            indexes << k;
                        }
                    }

                    for (int m = 0; m < indexes.count(); m++)
                    {
                        pci.value(pci.keys().at(l))->removeAt(indexes.at(m) - m);
                    }





                 }


                 for (int l = 0; l < pci.keys().count(); l++)
                 {
                    qDebug () << pci.keys().at(l) << " KEY";
                    QList< QPair <int,int> >* matches = pci.value(pci.keys().at(l));

                    for (int k = 0; k < matches->count(); k++)
                    {
                       qDebug () << matches->at(k);
                    }




                 }


                 qDebug () << !pci.contains(idOne);
                 qDebug () << !pci.contains(otherID);
                 i = -1;
             }
         }
     }


     qDebug () << topRow->count();
     return *topRow;
}

bool Distributor::insert(QList<QPair<int,QPair<int,int> > >& pci,const QPair<int,QPair<int,int> >& pair){
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

const QList<int>& Distributor::sortKeys(QList<int> keys)
{

    QList<int>* sorted = new QList<int>;
    for (int i = 0; i < keys.count();i++)
    {
        bool inserted = false;
        for (int j = 0; j < sorted->count(); j++)
        {
            if (pci.value(sorted->at(j))->at(0).second >= pci.value(keys.at(i))->at(0).second)
            {
                sorted->insert(j,keys.at(i));
                inserted = true;
                break;
            }

            if (j+1 == sorted->count() && !inserted)
            {
                sorted->append(keys.at(i));
                inserted = true;
                break;
            }

        }

        if (!inserted)
        {
            sorted->insert(0,keys.at(i));

        }


    }


    for (int i = 0; i < sorted->count(); i ++)
    {
        qDebug() << sorted->at(i);
    }

    return *sorted;
}


int Distributor::sortTeams(QList<Team*>& teams){

    int team1, team2;
    for (int i = 0; i < (teams.count()-1); i++)
    {
        for(int j = 0; j < (teams.count()-i-1); j++)
        {
             team1 = teams.at(i)->getPci();
             team2 = teams.at(i+1)->getPci();
            if(team1 > team2)
            {
                teams.swap(i,j);

            }
        }

    }
    return 1;
}



int Distributor::addOutliers(QList <Team*>& teams,const int& minSize, const int& maxSize){
    QMutableMapIterator<int,QList<QPair<int,int > >* > iterator (pci);
    sortTeams(teams);
    for (int i = 0; i < teams.count(); i++ )
    {
        int minWeight = -1;
        int minStudentID;
        for (int j = 0; j < pci.keys().count();j++)
        {

           int tempWeight =  calculateTeamWeight(*teams.at(i),pci.keys().at(j));

           if (minWeight == -1)
           {
               minWeight = tempWeight;
               minStudentID = pci.keys().at(j);
           }
           else
           {
               if (tempWeight < minWeight)
               {
                   minWeight = tempWeight;
                   minStudentID = pci.keys().at(j);
               }
           }
        }

        teams.at(i)->addStudent(minStudentID);

        while (iterator.hasNext()) {
            iterator.next();
            if (iterator.key() == minStudentID)
                iterator.remove();
        }

    }
}
