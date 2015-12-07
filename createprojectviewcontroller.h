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

    static CreateProjectViewController * getInstance();
    int setView(CreateProjectView *view);

private:
    CreateProjectViewController();
    CreateProjectView *createProjectsView;

    Database *database;
    static CreateProjectViewController *instance;


};

#endif // CREATEPROJECTVIEWCONTROLLER_H
