#ifndef RESULTBUILDER_H
#define RESULTBUILDER_H
#include "student.h"
#include <QList>
#include <QPair>
#include "team.h"
#include "pcibuilder.h"
#include <QString>
#include <Database.h>




class ResultBuilder
{
public:
    ResultBuilder(Team *team);
    QString getDetailedResults();


private:
    QList<int> teamMemberIds;
    Database* database;
    QList<Student>* teamMembers;
    Team* newTeam;
    QList<QPair<Student, Student> > pairs;
    QString detailedResults;
    PciBuilder pci;
    void getCompareString();

};

#endif // RESULTBUILDER_H
