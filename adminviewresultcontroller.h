#ifndef ADMINVIEWRESULTCONTROLLER_H
#define ADMINVIEWRESULTCONTROLLER_H
#include <QObject>



class AdminViewResult;
class AdminViewResultController:public QObject
{
public:
    AdminViewResultController(AdminViewResult *view );
    int getTeamID();
private:
    AdminViewResult *adminViewResult;
};

#endif // ADMINVIEWRESULTCONTROLLER_H
