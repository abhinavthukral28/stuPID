#include "resultbuilder.h"
#define NQ 12


ResultBuilder::ResultBuilder():database(Database::getInstance())
{

}

QString ResultBuilder::getDetailedResults(Team *team)
{
    this->getCompareString(team);
    if(highCompatibility.count()<=0){
        highCompatibility.append("None");
    }
    QString hCompString = highCompatibility.join('_');

    if(mediumCompatibility.count()<=0){
        mediumCompatibility.append("None");
    }
    QString mCompString = mediumCompatibility.join('_');

    if(lowCompatibility.count()<=0){
        lowCompatibility.append("None");
    }
    QString lCompString = lowCompatibility.join('_');

    QStringList list;

    list.append(hCompString);
    list.append(mCompString);
    list.append(lCompString);
    QString final = list.join('/');
    return final;



}

void ResultBuilder::getCompareString(Team *team)
{
    highCompatibility.clear();
    mediumCompatibility.clear();
    lowCompatibility.clear();
    QList<int> teamMemberIds = team->getTeamMembers();
    QList<Student>* teamMembers = new QList<Student>();
    for(int i=0;i<teamMemberIds.count();i++){
        Student student = database->getStudentByID(teamMemberIds.at(i));
        teamMembers->append(student);
    }
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

        if(qPci<=(teamMembers->count() * 4)){
            highCompatibility.append(title);
        }
        else if(qPci<=(teamMembers->count() * 8)){
            mediumCompatibility.append(title);

        }
        else if(qPci<(teamMembers->count() * 15)){
            lowCompatibility.append(title);
        }

    }
}
