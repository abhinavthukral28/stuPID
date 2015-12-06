#ifndef ADMINVIEWRESULTCONTROLLER_H
#define ADMINVIEWRESULTCONTROLLER_H
#include <QObject>
#include "team.h"
#include "Database.h"
#include <QList>
#include <QStringList>
#include "adminviewresult.h"
#include "resultbuilder.h"

class AdminViewResult;
class AdminViewResultController: public QObject
{
public:
    AdminViewResultController(int id);
    QString getDetailResults(Team *team);
    QList<Team*> getTeams();
private:
    AdminViewResult *adminViewResult;
    Database* database;
    int projectId;
};

#endif // ADMINVIEWRESULTCONTROLLER_H
