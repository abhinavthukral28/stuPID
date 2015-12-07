#ifndef MANAGEPROJECTSCONTROLLER_H
#define MANAGEPROJECTSCONTROLLER_H
#include<QObject>

class Project;
class QString;
class ManageProjectsView;
class Database;
class Student;
class CreateProjectView;
class ManageProjectsController:public QObject
{
public:
    int init();
    int updateSelectedProject(const int& index);
    int updateStudentList();
    int goToCreateProjectView();
    int goToLoginDialog();
    int updateDetailedView();
    int makeTeams();
    static ManageProjectsController * getInstance();
    int setView(ManageProjectsView *view);
    void showDetailedResults();


 private slots:

private:
    ManageProjectsController();
    ManageProjectsView *manageProjectsView;

    QList<Project*> allProjects;
    Project *selectedProject;
    QList<Student*> studentsByProjects;
    Database *database;
    static ManageProjectsController *instance;

};

#endif // MANAGEPROJECTSCONTROLLER_H
