#ifndef MANAGEPROJECTSCONTROLLER_H
#define MANAGEPROJECTSCONTROLLER_H
#include<QObject>

class Project;
class QString;
class ManageProjectsView;
class Database;
class ManageProjectsController:public QObject
{
public:
    ManageProjectsController(ManageProjectsView *view);
   // int init();
    int updateSelectedProject(const int& index);



 private slots:

private:
    ManageProjectsView *manageProjectsView;
    QList<Project*> allProjects;
    Database *database;


};

#endif // MANAGEPROJECTSCONTROLLER_H
