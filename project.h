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
    Project(const int& pID,const QString& title);
    Project(const QString& title);
    Project(const Project &obj);
    int registerStudent(Student& student);
    int registerStudents(QList<Student*>* students);
    int setTeamMax(int& max);
    int setTeamMin(int& min);
    int setDescription(QString& description);
    int setTitle (QString& title);
    int getMinTeamSize();
    int getMaxTeamSize();
    int getID() const;
    int setID(int& newID);
    QString getDescription();
    QString getTitle() const;
    QList<Student*> getRegisteredStudents() const;

};

#endif // PROJECT_H
