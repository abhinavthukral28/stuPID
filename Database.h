#ifndef DATABASE_H
#define DATABASE_H


class Database{

   public:
    static Database* getInstance();
    ~Database();
    void sayHello();

   private:
    static Database *instance;
    int init();

    Database();






};

#endif // DATABASE_H





