#ifndef MANAGEPROJECTSCONTROLLER_H
#define MANAGEPROJECTSCONTROLLER_H
#include<QObject>


class QString;
class ManageProjectsView;
class ManageProjectsController:public QObject
{
public:
    ManageProjectsController(ManageProjectsView *view);
    int displayAllProjects();


 private slots:
   // void transition();

private:
   //LoginDialog *loginDialog;
    ManageProjectsView *manageProjectsView;
};

#endif // MANAGEPROJECTSCONTROLLER_H
