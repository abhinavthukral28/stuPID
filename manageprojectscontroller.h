#ifndef MANAGEPROJECTSCONTROLLER_H
#define MANAGEPROJECTSCONTROLLER_H
#include<QObject>

class QString;
class ManageProjectsView;
class ManageProjectsController:public QObject
{
public:
    ManageProjectsController(ManageProjectsView *view);
    int init();
    int updateSelectedProject(const int& index);



 private slots:

private:
    ManageProjectsView *manageProjectsView;
};

#endif // MANAGEPROJECTSCONTROLLER_H
