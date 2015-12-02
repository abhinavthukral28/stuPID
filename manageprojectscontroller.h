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
    ManageProjectsController(ManageProjectsView *view);
    int init();
    int updateSelectedProject(const int& index);
    int updateStudentList();
    int goToCreateProjectView();
    int updateDetailedView();
    int makeTeams();


 private slots:

private:
    ManageProjectsView *manageProjectsView;

    QList<Project*> allProjects;
    Project *selectedProject;
    QList<Student*> studentsByProjects;
    Database *database;

};

#endif // MANAGEPROJECTSCONTROLLER_H
