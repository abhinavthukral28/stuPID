#ifndef STUDENTPROJECTREGISTERVIEWCONTROLLER_H
#define STUDENTPROJECTREGISTERVIEWCONTROLLER_H
#include<QObject>

class Project;
class QString;
class studentProjectRegisterView;
class Database;
class StudentManageProjectView;

class studentprojectregisterviewcontroller: public QObject
{
public:
    studentprojectregisterviewcontroller(studentProjectRegisterView *view);
    int init();
    int updateSelectedProject(const int& index);
    int goStudentManageProjectView();
    int registerToProject();
private:
    studentProjectRegisterView *stuProRegisterView;
    QList<Project*> allProjects;
    Project *selectedProject;
    Database *database;
};

#endif // STUDENTPROJECTREGISTERVIEWCONTROLLER_H
