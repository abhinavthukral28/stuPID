

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
class QSqlQuery;
class QString;
class Student;
class Project;
class SQLException;
class Qualification;
class Database{

   public:
    static Database* getInstance();

    const QList<Student*>& getAllStudents();
    const QList<Project*>& getAllProjects();
    const QList<Qualification*>& getAllQualifications(const int& studentID);
    const QList<Student*>& getStudentsByProject();
    const QList<Project*>& getProjectsByStudent(const int& studentID);
    int createStudent(Student& student);
    int createProject(Project& project);
    int addStudentsToProject(const int& projectID, QList<Student*>* students);
    int addStudentToProject(const int& projectID,Student& student);


   private:
    static Database *instance;
    static const QString DBpath;
    static SQLException generateException(QSqlQuery query);
    static SQLException generateCustomSQLException(const char* input);

    //functions
    void createTables();
    int insertValuesintoQualifications();
    int insertValuesintoExpectations();
    int init();
    Database();






};

#endif // DATABASE_H





