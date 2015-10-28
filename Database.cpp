#include "Database.h"


const QString Database::DBpath="./testdatabase.db";

Database* Database::instance=0;

Database::Database(){
   if(init())
   {
       qDebug("Something bad happened");
   }
   else {
       qDebug("It worked!");
   }


}

Database* Database::getInstance(){
    if(!Database::instance) {
       Database::instance = new Database();
    }
    return Database::instance;

}
void Database::sayHello(){

    qDebug("hello");
}


int Database::init(){


    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

     db.setDatabaseName(Database::DBpath);

     if( !db.open() )
     {
       qDebug() << db.lastError();
       qFatal( "Failed to connect." );
     }

     qDebug( "Connected!" );

     return 0;


}
