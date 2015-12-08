#ifndef EDITPROJECTCONTROLLER_H
#define EDITPROJECTCONTROLLER_H
#include <QObject>
#include "editprojectview.h"
#include "manageprojectscontroller.h"
#include "project.h"

class QString;
class EditProjectView;
class Database;

class EditProjectController:public QObject
{
public:
    int goToManageProjectView();
    int err;
    int error(int type);
    int saveProject();
    int goToLoginDialog();
    int initValues(Project *project);

    static EditProjectController * getInstance();
    int setView(EditProjectView *view);

private:
    EditProjectController();
    EditProjectView *editProject;
    Project oldProject;
    Database *database;
    static EditProjectController *instance;

    //ManageProjects
    ManageProjectsController *m;
};

#endif // EDITPROJECTCONTROLLER_H
