#ifndef RESULTBUILDER_H
#define RESULTBUILDER_H
#include "student.h"
#include <QList>
#include <QPair>
#include "team.h"
#include "pcibuilder.h"
#include <QString>



class ResultBuilder
{
public:
    ResultBuilder();
    QString getDetailedResults();

private:
    QList<Student> temaMembers;
    Team newTeam;
    QList<QPair<Student, Student> > pairs;
    QString detailedResults;
    PciBuilder pci;

};

#endif // RESULTBUILDER_H
