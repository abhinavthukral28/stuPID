#include "distributor.h"
#include "team.h"
#include <QDebug>
#include "Database.h"
#include <cmath>
#include "project.h"
#include <QMessageBox>
#include "resultbuilder.h"
Distributor::Distributor(QMap< int,QList< QPair<int,int> >* >& pciParam,Project& projectParam) : pci(pciParam),project(projectParam)
{

}

const QList<Team*>& Distributor::distributeTeams(const int minSize,int maxSize){

    qDebug () << " STARTING DISTRIBUTOR";


    int numTeams;

    if (pci.keys().count() % minSize == 0)
    {
        numTeams = floor(pci.keys().count()/(float)minSize);
    }
    else
    {
       numTeams =  ceil(pci.keys().count()/(float)maxSize);
    }






      QList<Team*> teams = createTopRowTeams(numTeams);


      qDebug() << "Starting pairs";
       for (int i = 0; i < teams.count(); i++)
       {
           qDebug () << "Team " << teams.at(i)->getID();

           for (int j = 0; j < teams.at(i)->getTeamMembers().count(); j++)
           {
              qDebug() <<   teams.at(i)->getTeamMembers().at(j) ;
           }

           qDebug () << "PCI " << teams.at(i)->getPci();
       }




     addOutliers(teams,minSize,maxSize);

     qDebug() << "Final teams";
       for (int i = 0; i < teams.count(); i++)
       {
           qDebug () << "Team " << teams.at(i)->getID();

           for (int j = 0; j < teams.at(i)->getTeamMembers().count(); j++)
           {
              qDebug() <<   teams.at(i)->getTeamMembers().at(j) ;
           }

           qDebug () << "PCI " << teams.at(i)->getPci();
       }


           ResultBuilder* rBuilder = new ResultBuilder;
           for (int i = 0; i < teams.count();i++)
           {
              teams.at(i)->setResultDisplay(rBuilder->getDetailedResults(teams.at(i)));

              qDebug() << "RESULT " << teams.at(i)->getResultDisplay();
           }

           if (teams.count() > 0)
           {
               Database::getInstance()->deleteTeamsByProject(project.getID());
               int returnval = Database::getInstance()->storeTeamsByProject(teams,project.getID());
              // return returnval;
           }
           //else return 0;


     return teams;
 }


int Distributor::calculateTeamWeight(const Team& team,const int& id)
{
    QList<int> teamMembers = team.getTeamMembers();
    int total = team.getPci();
    for(int i=0; i<teamMembers.count();i++){
       QList<QPair<int,int> >* values = pci.value(id);


       for(int j=0; j<values->count(); j++){

           if(values->at(j).first == teamMembers.at(i)){
               total += values->at(j).second;
          //     qDebug()<<"values->at(j).second"<<values->at(j).second;
           }
        }

    }
    return total;
}



QList<Team*>& Distributor::createTopRowTeams(int numTeams)
{

     QList< Team* >* topRow = new QList< Team* >;
     QList< int >* keys = sortKeys(pci.keys());

     for (int i = 0; i < keys->count();i++)
     {
         if (numTeams == 0)
             return *topRow;
         int idOne = keys->at(i);

         qDebug () << "first id is " << idOne;
         if (pci.contains(keys->at(i)))
         {
             int otherID;
             int pciVal;
             int idTwo;

             for (int j = 0; j <pci.value(idOne)->count(); j++ )
             {
                if (pci.contains(pci.value(idOne)->at(j).first))
                {

                    otherID = pci.value(idOne)->at(j).first;
                    qDebug () << "other student id set to " << otherID;
                    for (int t = 0; t < pci.value(pci.value(idOne)->at(j).first)->count();t++ )
                    {
                        if (pci.contains(pci.value(pci.value(idOne)->at(j).first)->at(t).first))
                        {
                          idTwo = pci.value(pci.value(idOne)->at(j).first)->at(t).first;
                          pciVal = pci.value(pci.value(idOne)->at(j).first)->at(t).second;
                          qDebug () << "eligible id found " << idTwo;
                          qDebug () << "pci is " <<pciVal;
                        }
                        break;
                    }
                    break;
                }
             }


             {
                 qDebug() << "Student with ID " << idOne << "and " << otherID << "top row match";

                 Team* team = new Team();
                 team->addStudent(idOne);
                 team->addStudent(otherID);
                 team->setPci(pciVal);
                 topRow->append(team);
                 numTeams--;
                 qDebug() << "Added student id " << idOne << "and " << otherID << "to a new team";


                 qDebug () << " Removing key " << idOne;
                 qDebug () << " Removing key " << otherID;

                 keys->removeOne(idOne);
                 keys->removeOne(otherID);



                 QMutableMapIterator<int,QList<QPair<int,int > >* > iterator (pci);
                 while (iterator.hasNext()) {
                     iterator.next();

                     if (iterator.key() == idOne || iterator.key() == otherID)
                         iterator.remove();
                 }


                 i = -1;
             }
         }
     }



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

QList<int>* Distributor::sortKeys(QList<int> keys)
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




    return sorted;
}


int Distributor::sortTeams(QList<Team*>& teams){


    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < teams.count() -1; i++){
            if (teams.at(i)->getPci() < teams.at(i+1)->getPci())
            {
                teams.swap(i,i+1);
                swapped = true;
            }
        }
    }
    return 1;
}



int Distributor::addOutliers(QList <Team*>& teams,const int& minSize,  int& maxSize){

    sortTeams(teams);

    while (pci.keys().count() != 0)
    {
    for (int i = 0; i < teams.count(); i++ )
    {
        int minWeight = -1;
        int minStudentID = -1;
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

        qDebug () << "Current team size " << teams.at(i)->getTeamMembers().count();
    if (minStudentID != -1)
    {
         if (teams.at(i)->getTeamMembers().count() != maxSize)
         {
            teams.at(i)->addStudent(minStudentID);
            teams.at(i)->setPci(minWeight);

            QMutableMapIterator<int,QList<QPair<int,int > >* > iterator (pci);

            while (iterator.hasNext()) {
                iterator.next();
                if (iterator.key() == minStudentID)
                    iterator.remove();
            }
         }
         else {
             int increaseNum = ceil(pci.keys().count()/teams.count());

             QString display = QString("Would you like to increase the maximum team size by ") + QString::number(increaseNum) + " to continue team building?";
             QMessageBox msgBox;
             msgBox.setWindowTitle("Invalid params");
             msgBox.setText(display);
             msgBox.setStandardButtons(QMessageBox::Yes);
             msgBox.addButton(QMessageBox::No);
             msgBox.setDefaultButton(QMessageBox::No);
              if (msgBox.exec() == QMessageBox::Yes) {
                maxSize +=increaseNum;
                 //return 0;

              } else {
               return 1;
              }
         }
    }
    else{
        break;
    }


    }
    }



    return 1;
}
