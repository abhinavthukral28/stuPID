

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
class QString;
class Student;
class Project;
class Team;
class Database{

   public:
    static Database* getInstance();

    QList<Student*>* getAllStudents();
    QList<Project*>* getAllProjects();
   // QList<Student*>* getStudentsByProject();


    int createStudent(Student& student);
    int createProject(Project& project);

   private:
    static Database *instance;
    static const QString DBpath;

    int addStudentsToProject(int& projectID, QList<Student*>* students);
    //functions
    void createTables();
    int init();
    Database();






};

#endif // DATABASE_H





