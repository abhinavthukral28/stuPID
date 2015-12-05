
#include <QDebug>
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

Student::Student() : User("username",-1,"","")
{
}


const QList<Qualification*> Student::getQualifications() const{
    //qDebug()<< "This is qualification1" << qualifications.first();
    return qualifications;
}

int Student::setQualifications(QList<Qualification*> qualif)
{
    qualifications = qualif;
    return 1;

}

