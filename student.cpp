

#include "student.h"
#include "qualification.h"
Student::Student(const int& ID,const QString& username) : User(username,ID,"","")
{
}

Student::Student(const int& ID,const QString& username,const QString& firstName,const QString& lastName) : User(username,ID,firstName,lastName)
{

}

Student::Student(const QString& username) : User(username,-1,"","")
{
}

QList<Student*> Student::getQualifications() const{
    return qualifications;
}

