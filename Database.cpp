#include "Database.h"
#include "student.h"
#include "DatabaseQueries.h"
#include <QDebug>
#include <QtSql>
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



int Database::init(){


    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

     db.setDatabaseName(Database::DBpath);

     if( !db.open() )
     {
       qDebug() << db.lastError();
       qFatal( "Failed to connect." );
     }

     qDebug( "Connected!" );


     createTables();
     return 0;


}






void Database::createTables(){

    QSqlQuery qry;

    qry.prepare( "CREATE TABLE IF NOT EXISTS Students (studentID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, studentName VARCHAR(30))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table Students created!";



    qry.prepare( "CREATE TABLE IF NOT EXISTS Qualifications(qID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, qualificationValue VARCHAR(30))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table Qualifications created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS Projects(projectID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, admin VARCHAR(30),projectName VARCHAR(30), description VARCHAR(30),minTeamSize int, maxTeamSize int)" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table Project created!";


    qry.prepare( "CREATE TABLE IF NOT EXISTS teamMember(teamID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,student_ID int,FOREIGN KEY(student_ID) REFERENCES Students(studentId))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table teamMember created!";


    qry.prepare( "CREATE TABLE IF NOT EXISTS Expectations(eID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, expectationValue VARCHAR(30))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table Expectations created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS StudentQualifications(studentQualificationID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, ratings VARCHAR(30), student_ID int, e_ID int,FOREIGN KEY(e_ID) REFERENCES Expectations(eId))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table StudentQualifications created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS Team(teamID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,project_ID int, FOREIGN KEY(project_ID) REFERENCES Projects(projectID))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table Teams created!";

}


QList<Student*>* Database::getAllStudents(){

    QSqlQuery query;
    query.prepare(DatabaseQueries::selectAllStudents);
    qDebug() << DatabaseQueries::selectAllStudents;
    if (!query.exec())
    {
      return NULL;
    }
    else
    {
        QList<Student*>* students = new QList<Student*>;
        while (query.next())
        {
        QString username = QString(query.value(0).toString());
        Student* temp = new Student(username);
        students->append(temp);
        }

        return students;
    }


}


int Database::createStudent (Student& student){
    QSqlQuery query;
    query.prepare(DatabaseQueries::insertStudent);
    query.addBindValue(student.getUsername());
    return !query.exec() ? 1 : 0;


}
