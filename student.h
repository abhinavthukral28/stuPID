#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <QList>
class Qualification;
class Student : public User
{


public:

    Student(const int& ID,const QString& username);
    Student(const QString& username);
    Student(const int& ID,const QString& username,const QString& firstName,const QString& lastName);

private:
    QList<Qualification*> qualifications;



};

#endif // STUDENT_H
