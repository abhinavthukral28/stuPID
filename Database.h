

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
class DBproxy;
class QSqlQuery;
class QString;
class Student;
class Project;
class User;
class Team;
class SQLException;
class Qualification;
class Database{

   public:
    static Database* getInstance();

    virtual const QList<Student*>& getAllStudents() = 0;
    virtual const QList<Project*>& getAllProjects() = 0;
    virtual const QList<Qualification*>& getAllQualifications(const int& studentID) = 0;

    virtual const Student& getStudentByID(const int& studentID) = 0;
//    virtual const QList<Student*>& getStudentsByProject() = 0;
    virtual const QList<Project*>& getProjectsByStudent(const int& studentID) =  0;
    virtual const QList<Project*>& getOpenProjectsByStudent(const int& studentID) = 0;
    virtual const QList<Team*>& getTeamsbyProjectID (const int& projectID) = 0;
    virtual int createStudent(Student& student) = 0;
    virtual int createProject(Project& project) = 0;
  //  virtual const Project& getProjectByID(const int& projectID) = 0;
    virtual int storeTeamsByProject (const QList<Team*>& teams, const int& projectID) = 0;
    virtual int addStudentsToProject(const int& projectID, QList<Student*>* students) = 0;
    virtual int addStudentToProject(const int& projectID,Student& student) = 0;
    virtual int removeStudentFromProject(const int projectID,const Student& student) = 0;
    virtual int updateQualification(const int& studentID,const Qualification& qualification) = 0;
    virtual int createQualificationEntry(const int& studentID,const Qualification& qualification) = 0;
    virtual const Student* authenticate(const QString& username) = 0;
   private:
    static Database *instance;







};

#endif // DATABASE_H





