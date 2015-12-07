#include "dbproxy.h"
#include "dbimpl.h"
DBproxy::DBproxy()
{
   dbimpl = new DBimpl();

}
const Student& DBproxy::getStudentByID(const int& studentID){

    return dbimpl->getStudentByID(studentID);


}


const QList<Student*>& DBproxy::getAllStudents(){

    return dbimpl->getAllStudents();


}

const QList<Team*>& DBproxy::getTeamsbyProjectID (const int& projectID){

    return dbimpl->getTeamsbyProjectID(projectID);
}



const QList<Project*>& DBproxy::getAllProjects(){

     return dbimpl->getAllProjects();
}



int DBproxy::createStudent (Student& student){

    return dbimpl->createStudent(student);
}


int DBproxy::createProject(Project& project){

    return dbimpl->createProject(project);
}

int DBproxy::addStudentsToProject(const int& projectID, QList<Student*>* students){

    return dbimpl->addStudentsToProject(projectID,students);

}

int DBproxy::removeStudentFromProject(const int projectID,const Student& student){

    return dbimpl->removeStudentFromProject(projectID,student);

}

int DBproxy::updateQualification(const int& studentID,const Qualification& qualification)
{
 return dbimpl->updateQualification(studentID,qualification);
}

int DBproxy::addStudentToProject(const int& projectID,Student& student){

    return dbimpl->addStudentToProject(projectID,student);

}



const QList<Project*>& DBproxy::getProjectsByStudent(const int& studentID)
{

    return dbimpl->getProjectsByStudent(studentID);
}

const QList<Project*>& DBproxy::getOpenProjectsByStudent(const int& studentID){

    return dbimpl->getOpenProjectsByStudent(studentID);
}

const QList<Qualification*>& DBproxy::getAllQualifications(const int& studentID)
{

   return dbimpl->getAllQualifications(studentID);

}


const Student* DBproxy::authenticate(const QString& username){

     return dbimpl->authenticate(username);
}

int DBproxy::createQualificationEntry(const int& studentID, const Qualification& qualification)
{
    return dbimpl->createQualificationEntry(studentID,qualification);
}


int DBproxy::storeTeamsByProject (const QList<Team*>& teams, const int& projectID){
return dbimpl->storeTeamsByProject(teams,projectID);

}

