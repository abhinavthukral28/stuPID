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
    int init();
    int updateSelectedProject(const int& index);
    int goStudentManageProjectView();
    int gotoLoginDialog();
    int registerToProject();
    static studentprojectregisterviewcontroller* getInstance();
    int setView(studentProjectRegisterView *view);
private:
    studentprojectregisterviewcontroller();
    studentProjectRegisterView *stuProRegisterView;

    QList<Project*> allProjects;
    Project *selectedProject;
    Database *database;
    static studentprojectregisterviewcontroller *instance;
};

#endif // STUDENTPROJECTREGISTERVIEWCONTROLLER_H
