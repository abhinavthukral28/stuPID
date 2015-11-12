#ifndef CREATEPROJECTVIEWCONTROLLER_H
#define CREATEPROJECTVIEWCONTROLLER_H
#include <QObject>

class QString;
class CreateProjectView;
class Project;
class Database;
class CreateProjectViewController:public QObject
{
public:
    CreateProjectViewController(CreateProjectView *view);

   int saveProject();
private:
    CreateProjectView *createProjectsView;
    Database *database;
    Project *newproject;


};

#endif // CREATEPROJECTVIEWCONTROLLER_H
