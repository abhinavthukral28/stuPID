#include <QtSql>
#include <QtDebug>
#include<QString>

#ifndef DATABASE_H
#define DATABASE_H




class Database{

   public:
    static Database* getInstance();
    ~Database();
    void sayHello();

   private:
    static Database *instance;
    static const QString DBpath;

    //functions
    int init();
    Database();






};

#endif // DATABASE_H





