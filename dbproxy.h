#ifndef DBPROXY_H
#define DBPROXY_H

#include "Database.h"

class DBimpl;
class DBproxy : public Database
{
public:
    DBproxy();
    const QList<Student*>& getAllStudents();
    const QList<Project*>& getAllProjects();
    const QList<Qualification*>& getAllQualifications(const int& studentID);

    const Student& getStudentByID(const int& studentID);
 //   const QList<Student*>& getStudentsByProject();
    const QList<Project*>& getProjectsByStudent(const int& studentID);
    const QList<Project*>& getOpenProjectsByStudent(const int& studentID);
    const QList<Team*>& getTeamsbyProjectID (const int& projectID);
    int deleteTeamsByProject(const int& projectID);
    int createStudent(Student& student);
    int createProject(Project& project);
 //   const Project& getProjectByID(const int& projectID);
    int storeTeamsByProject (const QList<Team*>& teams, const int& projectID);
    int addStudentsToProject(const int& projectID, QList<Student*>* students);
    int addStudentToProject(const int& projectID,Student& student);
    int removeStudentFromProject(const int projectID,const Student& student);
    int updateQualification(const int& studentID,const Qualification& qualification);
    int createQualificationEntry(const int& studentID,const Qualification& qualification);
    const Student* authenticate(const QString& username);
private:
    DBimpl* dbimpl;

};

#endif // DBPROXY_H
