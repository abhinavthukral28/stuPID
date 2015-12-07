#ifndef STUDENTMANAGEPROJECTCONTROLLER_H
#define STUDENTMANAGEPROJECTCONTROLLER_H
#include <QObject>

class Project;
class QString;
class Student;
class StudentManageProjectView;
class Database;
class StudentManageProjectController:public QObject
{
public:
    int init();
    int updateSelectedProject(const int& index);
    int goStudentRegisterProjectView();
    int gotoLoginDialog();
    int unregisterFromProject();
    static StudentManageProjectController* getInstance();
    int setView(StudentManageProjectView *view);
private:
    StudentManageProjectController();
    StudentManageProjectView *studentManageProjectView;

    Project *selectedProject;
    QList<Project*> allProjects;
    QList<Student*> studentsByProjects;
    Database *database;
    static StudentManageProjectController *instance;



};

#endif // STUDENTMANAGEPROJECTCONTROLLER_H
