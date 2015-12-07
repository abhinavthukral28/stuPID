#include "pcibuilder.h"
#include "distributor.h"
#include "teambuilder.h"
#include "project.h"
#include "resultbuilder.h"
#include <qdebug.h>
TeamBuilder::TeamBuilder()
{

}

const QList<Team*>& TeamBuilder::createTeams(const Project& project){
    PciBuilder* builder = new PciBuilder;
    QMap<int, QList < QPair<int,int> >* >& pci = builder->calculatePci(project.getRegisteredStudents());

    Distributor* distributor = new Distributor (pci);


   QList<Team*> list = distributor->distributeTeams(project.getMinTeamSize(),project.getMaxTeamSize());

   delete builder;
   delete distributor;
   delete &pci;

   ResultBuilder rBuilder;
   for (int i = 0; i < list.count();i++)
   {
      list.at(i)->setResultDisplay(rBuilder.getDetailedResults(list.at(i)));

      qDebug() << "RESULT " << list.at(i)->getResultDisplay();
   }
   return list;
}



