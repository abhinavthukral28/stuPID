#include "pcibuilder.h"
#include "distributor.h"
#include "teambuilder.h"
#include "project.h"
TeamBuilder::TeamBuilder()
{

}

const QList<Team*>& TeamBuilder::createTeams(const Project& project){
    PciBuilder builder;
    QMap<int, QList < QPair<int,int> >* >& pci = builder.calculatePci(project.getRegisteredStudents());

//    Distributor* distributor = new Distributor (pci);
//    QList<Team*> list = distributor->distributeTeams(project.getMinTeamSize(),project.getMaxTeamSize());
//     return list;
}



