

#ifndef DATABASE_H
#define DATABASE_H


class QString;


class Database{

   public:
    static Database* getInstance();
    ~Database();
    void sayHello();



   private:
    static Database *instance;
    static const QString DBpath;

    //functions
    void createTables();
    int init();
    Database();






};

#endif // DATABASE_H





