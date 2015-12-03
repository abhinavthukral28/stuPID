#include "project.h"
#include "student.h"
#include <QString>




Project::Project(const int& pID,const QString &title) : projectName(QString::fromStdString(title.toStdString())),ID(pID),teamMax(0),teamMin(0)
{

}

Project::Project(const QString &title) : projectName(QString::fromStdString(title.toStdString())),ID(-1),teamMax(0),teamMin(0)
{

}


Project::Project(const Project &obj){
  projectName = QString::fromStdString(obj.projectName.toStdString());
  teamMax = obj.teamMax;
  teamMin = obj.teamMin;
  description = QString::fromStdString(obj.description.toStdString());
  registeredStudents = obj.registeredStudents;
}

int Project::registerStudent(Student& student)
{
    if (!registeredStudents.contains(&student))
    {
     registeredStudents << &student;
     return 1;
    }
    return 0;
}

int Project::registerStudents(QList<Student*>* students)
{
   for (int i = 0; i < students->count(); i++)
   {
       if (!registerStudent(*(students->at(i))))
       {
           return 0;
       }
       return 1;
   }
}

int Project::unregisterStudent(Student& student){
 return registeredStudents.removeOne(&student);
}

int Project::setTeamMax(const int& max)
{
    teamMax = max;
    return 1;
}

int Project::setTeamMin(const int& min)
{
   if (min > 0)
   {
       teamMin = min;
       return 1;
   }
   else
       return 0;
}

int Project::setDescription(const QString& description)
{
    this->description = QString(description);
    return 1;
}

int Project::setTitle(const QString& title){
    this->projectName = QString(title);
    return 1;
}

int Project::getMinTeamSize() const{
    return teamMin;

}

int Project::getMaxTeamSize() const {
    return teamMax;
}

QString Project::getDescription() const {
    return description;
}

QString Project::getTitle() const{
    return projectName;
}

const int Project::getID() const
{
    return ID;
}

int Project::setID(const int& newID){

    ID = newID;
    return 1;
}

const QList<Student*>& Project::getRegisteredStudents () const{
    return registeredStudents;
}

bool Project::operator==(const Project& other){
    return other.getID() == getID();
}

