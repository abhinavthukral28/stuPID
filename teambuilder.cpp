#include "pcibuilder.h"
#include "distributor.h"
#include "teambuilder.h"
#include "project.h"
#include "resultbuilder.h"
#include <QMessageBox>
#include "Database.h"
#include <qdebug.h>
#include <cmath>
TeamBuilder::TeamBuilder()
{

}

const QList<Team*>& TeamBuilder::createTeams(Project& project){

    if (prefilter(project))
    {
        QList<Team*> list;
        return list;
    }


    PciBuilder* builder = new PciBuilder;

    QMap<int, QList < QPair<int,int> >* >& pci = builder->calculatePci(project.getRegisteredStudents());


    Distributor* distributor = new Distributor (pci,project);

  QList<Team*> list = distributor->distributeTeams(project.getMinTeamSize(),project.getMaxTeamSize());


  delete builder;
   delete distributor;
   delete &pci;


   return list;
}

 int TeamBuilder::prefilter (Project& project){

    if (project.getRegisteredStudents().count() < project.getMinTeamSize())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Team builder");
        msgBox.setText("Not enough students registered.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return 1;

    }else{
        return 0;
//        int outlierCountMin = (floor(project.getRegisteredStudents().count()/project.getMinTeamSize())) * project.getMaxTeamSize();
//        int outlierCountMax = (floor(project.getRegisteredStudents().count()/project.getMaxTeamSize())) * project.getMaxTeamSize();
        
//        if (outlierCountMin >= project.getRegisteredStudents().count() || outlierCountMax >= project.getRegisteredStudents().count())
//            return 0;
//        else
//        {
//            int increaseNum = (project.getRegisteredStudents().count() - outlierCountMin)/floor(project.getRegisteredStudents().count()/project.getMinTeamSize());

//            QString display = QString("Would you like to increase the minimum team size by ") + QString::number(increaseNum) + " to continue team building?";
//            QMessageBox msgBox;
//            msgBox.setWindowTitle("Invalid params");
//            msgBox.setText(display);
//            msgBox.setStandardButtons(QMessageBox::Yes);
//            msgBox.addButton(QMessageBox::No);
//            msgBox.setDefaultButton(QMessageBox::No);
//             if (msgBox.exec() == QMessageBox::Yes) {
//               project.setTeamMin(project.getMinTeamSize()+increaseNum);
//               return 0;

//             } else {
//              return 1;
//             }
//        }
            
    }
   



 }



