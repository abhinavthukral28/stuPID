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
    int results;


public:
    Project(const int& pID,const QString& title);
    Project(const QString& title);
    Project(const Project &obj);
    int registerStudent(Student& student);
    int registerStudents(QList<Student*>* students);
    int unregisterStudent(Student& student);
    int setTeamMax(const int& max);
    int setTeamMin(const int& min);
    int setDescription(const QString& description);
    int setTitle (const QString& title);
    int getMinTeamSize() const;
    int getMaxTeamSize() const;
    int getID() const;
    int setID(const int& newID);
    QString getDescription() const;
    QString getTitle() const;
    const QList<Student*>& getRegisteredStudents() const;
    bool operator==(const Project& other);
    int resultsAreAvailable() const;
    int setResultsAvailable(int available);

};

#endif // PROJECT_H
