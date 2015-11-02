#include "project.h"
#include "student.h"
#include <QString>




Project::Project(int& pID, QString &title) : projectName(title),ID(pID)
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
    teamMax = max;
    return 0;
}

int Project::setTeamMin(int& min)
{
   if (min > 0)
   {
       teamMin = min;
       return 0;
   }
   else
       return -1;
}

int Project::setDescription(QString& description)
{
    this->description = description;
}


int Project::getMinTeamSize(){
    return teamMin;
}

int Project::getMaxTeamSize(){
    return teamMax;
}

QString Project::getDescription(){
    return description;
}

QString Project::getTitle(){
    return projectName;
}
