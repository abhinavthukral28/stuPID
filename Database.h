

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
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

    const QList<Student*>& getAllStudents();
    const QList<Project*>& getAllProjects();
    const QList<Qualification*>& getAllQualifications(const int& studentID);

    const Student& getStudentByID(const int& studentID);
    const QList<Student*>& getStudentsByProject();
    const QList<Project*>& getProjectsByStudent(const int& studentID);
    const QList<Project*>& getOpenProjectsByStudent(const int& studentID);
    const QList<Team*>& getTeamsbyProjectID (const int& projectID);
    int createStudent(Student& student);
    int createProject(Project& project);

    int storeTeamsByProject (const QList<Team*>& teams, const int& projectID);
    int addStudentsToProject(const int& projectID, QList<Student*>* students);
    int addStudentToProject(const int& projectID,Student& student);
    int removeStudentFromProject(const int projectID,const Student& student);
    int updateQualification(const int& studentID,const Qualification& qualification);
    int createQualificationEntry(const int& studentID,const Qualification& qualification);
    const Student* authenticate(const QString& username);
   private:
    static Database *instance;
    static const QString DBpath;
    static SQLException generateException(QSqlQuery query);
    static SQLException generateCustomSQLException(const char* input);

    //functions
    void createTables();
    int insertValuesintoQualifications();
    int insertValuesintoExpectations();
    int createTeam(const int& projectID);
    int insertStudents();
    int init();
    Database();






};

#endif // DATABASE_H





