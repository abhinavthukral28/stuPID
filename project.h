#ifndef PROJECT_H
#define PROJECT_H

#include <QList>
#include "administrator.h"
class Student;
class QString;
class Project
{

//    Administrator owner;
    int ID;
    QString projectName;
    QList<Student*> registeredStudents;
    int teamMax;
    int teamMin;
    QString description;


public:
    Project(int& pID,QString& title);
    int registerStudent(Student& student);
    int registerStudents(QList<Student*>* students);
    int setTeamMax(int& max);
    int setTeamMin(int& min);
    int setDescription(QString& description);

    int getMinTeamSize();
    int getMaxTeamSize();
    int getID();
    int setID(int& newID);
    QString getDescription();
    QString getTitle();
    QList<Student*> getRegisteredStudents();

};

#endif // PROJECT_H
