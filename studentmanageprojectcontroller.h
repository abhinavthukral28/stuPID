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
    StudentManageProjectController(StudentManageProjectView *view);
    int init();
private:
    StudentManageProjectView *studentManageProjectView;
    Project *selectedProject;
    QList<Project*> allProjects;
    QList<Student*> studentsByProjects;
    Database *database;

};

#endif // STUDENTMANAGEPROJECTCONTROLLER_H