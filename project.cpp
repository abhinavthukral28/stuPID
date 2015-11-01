#include "project.h"
#include "student.h"
#include <QString>


Project::Project(Administrator& admin, QString& title) : owner(admin), projectName(title)
{
}

int Project::registerStudent(Student& student)
{
    if (!registeredStudents.contains(&student))
    {
     registeredStudents << &student;
     return 0;
    }
    return -1;
}

int Project::registerStudents(QList<Student*>* students)
{
   for (int i = 0; i < students->count(); i++)
   {
       registerStudent(*(students->at(i)));
   }
}

int Project::setTeamMax(int& max)
{

}

int Project::setTeamMin(int& min)
{

}

int Project::setDescription(QString& description)
{

}


