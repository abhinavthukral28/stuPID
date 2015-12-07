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
    int goToManageProjectView();
    int err;
    int error(int type);

   int saveProject();
   int goToLoginDialog();
private:
    CreateProjectView *createProjectsView;
    Database *database;



};

#endif // CREATEPROJECTVIEWCONTROLLER_H
