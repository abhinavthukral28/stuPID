#include "resultbuilder.h"
#define NQ 12


ResultBuilder::ResultBuilder(Team *team):newTeam(team), database(Database::getInstance())
{
    teamMemberIds = team->getTeamMembers();
    teamMembers = new QList<Student>();
    for(int i=0;i<teamMemberIds.count();i++){
        Student student = database->getStudentByID(teamMemberIds.at(i));
        teamMembers->append(student);
    }

}

QString ResultBuilder::getDetailedResults()
{

}

void ResultBuilder::getCompareString()
{
    PciBuilder pci;
    for(int i=0;i<NQ;i++)
    {
        int qPci = 0;
        QString title = teamMembers->at(0).getQualifications().at(i)->getTitle();
        for(int j=0; j<teamMembers->count() - 1;j++){
            Student stu1 = teamMembers->at(j);
            for(int k = j+1;k<teamMembers->count();k++){
                Student stu2 = teamMembers->at(k);
                qPci += pci.calculatePci(*stu1.getQualifications().at(i), *stu2.getQualifications().at(i));

            }
        }
        int averagePci = qPci/teamMembers->count();
        if(averagePci<=4){
            highCompatibility.append(title);
        }
        else if(averagePci<=8){
            mediumCompatibility.append(title);

        }
        else if(averagePci<=12){
            lowCompatibility.append(title);
        }

    }
}
