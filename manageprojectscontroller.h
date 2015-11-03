#ifndef MANAGEPROJECTSCONTROLLER_H
#define MANAGEPROJECTSCONTROLLER_H
#include<QObject>

class Project;
class QString;
class ManageProjectsView;
class Database;
class Student;
class ManageProjectsController:public QObject
{
public:
    ManageProjectsController(ManageProjectsView *view);
    int init();
    int updateSelectedProject(const int& index);
    //int showStudentsbyProject(const int&




 private slots:

private:
    ManageProjectsView *manageProjectsView;
    QList<Project*> allProjects;
    QList<Student*> studentsByProjects;
    Database *database;

};

#endif // MANAGEPROJECTSCONTROLLER_H
