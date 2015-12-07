#ifndef EDITPROJECTCONTROLLER_H
#define EDITPROJECTCONTROLLER_H
#include <QObject>

class QString;
class EditProjectView;
class Project;
class Database;

class EditProjectController:public QObject
{
public:
    int goToManageProjectView();
    int err;
    int error(int type);
    int saveProject();
    int goToLoginDialog();

    static EditProjectController * getInstance();
    int setView(EditProjectView *view);

private:
    EditProjectController();
    EditProjectView *editProjectView;

    Database *database;
    static EditProjectController *instance;
};

#endif // EDITPROJECTCONTROLLER_H
