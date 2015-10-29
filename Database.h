

#ifndef DATABASE_H
#define DATABASE_H


class QString;


class Database{

   public:
    static Database* getInstance();
    ~Database();
    void sayHello();
    void createTables();


   private:
    static Database *instance;
    static const QString DBpath;

    //functions
    int init();
    Database();






};

#endif // DATABASE_H





