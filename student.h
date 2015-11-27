#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <QList>
class Qualification;
class Student : public User
{


public:

    Student();
    Student(const int& ID,const QString& username);
    Student(const QString& username);
    Student(const int& ID,const QString& username,const QString& firstName,const QString& lastName);
    QList<Qualification*> getQualifications();
    QList<Qualification*> qualifications;
private:



};

#endif // STUDENT_H
