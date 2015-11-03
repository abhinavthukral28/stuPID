#include "project.h"
#include "student.h"
#include <QString>




Project::Project(int& pID, QString &title) : projectName(QString::fromStdString(title.toStdString())),ID(pID),teamMax(0),teamMin(0)
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
       registerStudent(*(students->at(i)));
   }
}

int Project::setTeamMax(int& max)
{
    teamMax = max;
    return 1;
}

int Project::setTeamMin(int& min)
{
   if (min > 0)
   {
       teamMin = min;
       return 1;
   }
   else
       return 0;
}

int Project::setDescription(QString& description)
{
    this->description = QString(description);
}

int Project::setTitle(QString& title){
    this->projectName = QString(title);
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

QString Project::getTitle() const{
    return projectName;
}

int Project::getID() const
{
    return ID;
}

int Project::setID(int& newID){

    ID = newID;
    return 1;
}

QList<Student*> Project::getRegisteredStudents () const{
    return registeredStudents;
}
