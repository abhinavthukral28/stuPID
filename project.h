#ifndef PROJECT_H
#define PROJECT_H

#include <QList>
#include "administrator.h"
class Student;
class QString;
class Project
{

    Administrator owner;
    QString projectName;
    QList<Student*> registeredStudents;
    int teamMax;
    int teamMin;
    QString description;


public:
    Project(Administrator& admin,QString& title);
    int registerStudent(Student& student);
    int registerStudents(QList<Student*>* students);
    int setTeamMax(int& max);
    int setTeamMin(int& min);
    int setDescription(QString& description);

};

#endif // PROJECT_H
