#ifndef ADMINVIEWRESULTCONTROLLER_H
#define ADMINVIEWRESULTCONTROLLER_H
#include <QObject>
#include "team.h"
#include "Database.h"
#include <QList>
#include <QStringList>
#include "adminviewresult.h"

class AdminViewResult;
class AdminViewResultController:public QObject
{
public:
    AdminViewResultController(int id);
private:
    AdminViewResult *adminViewResult;
    QList<Team*> getTeams();
    Database* database;
    int projectId;
};

#endif // ADMINVIEWRESULTCONTROLLER_H
