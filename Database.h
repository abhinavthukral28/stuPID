

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
class QString;
class Student;


class Database{

   public:
    static Database* getInstance();

    QList<Student*> getAllStudents();


   private:
    static Database *instance;
    static const QString DBpath;

    //functions
    void createTables();
    int init();
    Database();






};

#endif // DATABASE_H





