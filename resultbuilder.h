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
#include <QStringList>



class ResultBuilder
{
public:
    ResultBuilder();
    QString getDetailedResults(Team *team);


private:
    Database* database;
    QStringList highCompatibility;
    QStringList mediumCompatibility;
    QStringList lowCompatibility;
    void getCompareString(Team *team);

};

#endif // RESULTBUILDER_H
