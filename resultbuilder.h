#ifndef RESULTBUILDER_H
#define RESULTBUILDER_H
#include "student.h"
#include <QList>
#include <QPair>
#include "team.h"
#include "pcibuilder.h"
#include <QString>
#include "Database.h"
#include "qualification.h"



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
    QString detailedResults;
    PciBuilder* pci;
    QList<QString> highCompatibility;
    QList<QString> mediumCompatibility;
    QList<QString> lowCompatibility;
    void getCompareString();

};

#endif // RESULTBUILDER_H
