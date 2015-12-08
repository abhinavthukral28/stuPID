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
    Student getStudent(int id);
    QList<Team*> getTeams();
    void init(int id);
    static AdminViewResultController* getInstance();
private:
    AdminViewResultController();
    AdminViewResult *adminViewResult;
    Database* database;
    int projectId;
    static AdminViewResultController *instance;
};

#endif // ADMINVIEWRESULTCONTROLLER_H
