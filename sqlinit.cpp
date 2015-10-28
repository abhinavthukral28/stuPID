
#include <QApplication>
#include <QtSql>
#include <QtDebug>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);


 QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

  db.setDatabaseName( "/home/admin/testdatabase.db" );

  if( !db.open() )
  {
    qDebug() << db.lastError();
    qFatal( "Failed to connect." );
  }

  qDebug( "Connected!" );


  QSqlQuery qry;

  qry.prepare( "SELECT * FROM Students" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
      qDebug( "Selected!" );

      QSqlRecord rec = qry.record();

      int cols = rec.count();

      for( int c=0; c<cols; c++ )
        qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

      for( int r=0; qry.next(); r++ )
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
    }


    qry.prepare( "CREATE TABLE IF NOT EXISTS Students (studentID INTEGER UNIQUE PRIMARY KEY, studentName VARCHAR(30))" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table created!";



    qry.prepare( "CREATE TABLE IF NOT EXISTS Projects (admin VARCHAR(30),projectID INTEGER UNIQUE PRIMARY KEY, projectName VARCHAR(30),description VARCHAR(30),minTeamSize int NOT NULL,maxTeamSize int NOT NULL)" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug() << "Table created!";

    qry.prepare("CREATE TABLE IF NOT EXISTS Qualifications(qID INTEGER UNIQUE PRIMARY KEY)")





/*

    qry.prepare( "INSERT INTO Students (studentID,studentName) VALUES (1, 'Allan')" );
     if( !qry.exec() )
       qDebug() << qry.lastError();
     else
       qDebug( "Inserted!" );

     qry.prepare( "INSERT INTO Students (studentID,studentName) VALUES (2, 'Fan')" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug( "Inserted!" );

        */








 return app.exec();
}
