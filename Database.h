

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
    //QList<Student*>* getStudentsByProject();
    QList<Project*>* getProjectsByStudent(const int& studentID);



    int createStudent(Student& student);
    int createProject(Project& project);
    int addStudentsToProject(const int& projectID, QList<Student*>* students);
    int addStudentToProject(const int& projectID,Student& student);
    int insertValuesintoQualifications();
    int insertValuesintoExpectations();

   private:
    static Database *instance;
    static const QString DBpath;
    static SQLException generateException(QSqlQuery query);
    //functions
    void createTables();
    int init();
    Database();






};

#endif // DATABASE_H





