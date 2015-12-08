#ifndef DBIMPL_H
#define DBIMPL_H

#include "Database.h"

class QSqlQuery;
class QString;
class Student;
class Project;
class User;
class Team;
class SQLException;
class Qualification;
class DBimpl : public Database
{
public:
    DBimpl();
    const QList<Student*>& getAllStudents();
    const QList<Project*>& getAllProjects();
    const QList<Qualification*>& getAllQualifications(const int& studentID);

    const Student& getStudentByID(const int& studentID);
    const QList<Project*>& getProjectsByStudent(const int& studentID);
    const QList<Project*>& getOpenProjectsByStudent(const int& studentID);
    const QList<Team*>& getTeamsbyProjectID (const int& projectID);
    int createStudent(Student& student);
    int createProject(Project& project);
    int deleteTeamsByProject(const int& projectID);
    int updateProject(const Project& project);
    int storeTeamsByProject (const QList<Team*>& teams, const int& projectID);
    int addStudentsToProject(const int& projectID, QList<Student*>* students);
    int addStudentToProject(const int& projectID,Student& student);
    int removeStudentFromProject(const int projectID,const Student& student);
    int updateQualification(const int& studentID,const Qualification& qualification);
    int createQualificationEntry(const int& studentID,const Qualification& qualification);
    const Student* authenticate(const QString& username);
private:
 static const QString DBpath;
 static SQLException generateException(QSqlQuery query);
 static SQLException generateCustomSQLException(const char* input);
 //functions
 void createTables();
 int markResults(const int& projectID,const int& results);
 int insertValuesintoQualifications();
 int insertValuesintoExpectations();
 int createTeam(const int& projectID, const QString& result);
 int insertStudents();
 int init();
};

#endif // DBIMPL_H
