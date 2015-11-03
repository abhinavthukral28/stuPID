#include "Database.h"
#include "student.h"
#include "project.h"
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

    qry.prepare( "CREATE TABLE IF NOT EXISTS Students (studentID INTEGER PRIMARY KEY, studentName VARCHAR(30) UNIQUE)" );
    if( !qry.exec() )
    {
        qDebug() <<qry.lastQuery();
        qDebug() << qry.lastError();
    }
    else
        qDebug() << "Table Students created!";



    qry.prepare( "CREATE TABLE IF NOT EXISTS Qualifications(qID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, qualificationValue VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table Qualifications created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS Projects(projectID INTEGER PRIMARY KEY, admin VARCHAR(30),projectName VARCHAR(30) UNIQUE, description VARCHAR(30),minTeamSize int, maxTeamSize int)" );
    if( !qry.exec() )
    {
        qDebug() << qry.lastQuery();
        qDebug() << qry.lastError();
    }
    else
        qDebug() << "Table Project created!";


    qry.prepare( "CREATE TABLE IF NOT EXISTS ProjectStudents (projectID INTEGER , studentID VARCHAR(30),PRIMARY KEY(projectID,studentID))" );
    if( !qry.exec() )
    {
        qDebug() <<qry.lastQuery();
        qDebug() << qry.lastError();
    }
    else
        qDebug() << "Table ProjectStudents!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS teamMember(teamID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,studentID int,FOREIGN KEY(studentID) REFERENCES Students(studentId))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table teamMember created!";





    qry.prepare( "CREATE TABLE IF NOT EXISTS Expectations(eID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, expectationValue VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table Expectations created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS StudentQualifications(studentQualificationID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, ratings VARCHAR(30), studentID int, eID int,FOREIGN KEY(eID) REFERENCES Expectations(eId))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table StudentQualifications created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS Team(teamID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,projectID int, FOREIGN KEY(projectID) REFERENCES Projects(projectID))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table Teams created!";

}


QList<Student*>* Database::getAllStudents(){

    QSqlQuery query;
    query.prepare(DatabaseQueries::selectAllStudents);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return NULL;
    }
    else
    {
        QString tempUsername;
        int tempID;
        Student* tempStudent;
        QList<Student*>* students = new QList<Student*>;
        while (query.next())
        {
            //first column is 0
            tempID = query.value(0).toInt();
            tempUsername = QString(query.value(1).toString());

            tempStudent = new Student(tempID,tempUsername);
            students->append(tempStudent);
        }

        return students;
    }


}


QList<Project*>* Database::getAllProjects(){

    QSqlQuery query;
    query.prepare(DatabaseQueries::selectAllProjects);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return NULL;
    }
    else
    {

        QList<Project*>* projects = new QList<Project*>;
        Student* tempStudent;
        QString tempDescription;
        QString tempTitle = "";
        QString tempUsername;
        int tempTeamMin;
        int tempTeamMax;
        int tempID = -1;
        Project* tempProject  = new Project(tempID,tempTitle);
        int tempStudentID;


        while (query.next())
        {

            tempID = query.value(0).toInt();


            if (tempProject->getID() != tempID)
            {
                tempTitle = QString(query.value(2).toString());
                tempProject = new Project(tempID,tempTitle);

                tempDescription = QString(query.value(3).toString());
                tempTeamMin = query.value(4).toInt();
                tempTeamMax = query.value(5).toInt();

                tempProject->setDescription(tempDescription);
                tempProject->setTeamMax(tempTeamMax);
                tempProject->setTeamMin(tempTeamMin);

                projects->append(tempProject);
            }

            tempStudentID = query.value(8).toInt();
            tempUsername = query.value(9).toString();
            tempStudent = new Student(tempStudentID,tempUsername);
            tempProject->registerStudent(*tempStudent);


        }

        return projects;
    }

}



int Database::createStudent (Student& student){
    QSqlQuery query;
    query.prepare(DatabaseQueries::insertStudent);
    query.bindValue(":username",student.getUsername());
    if(!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return 0;
    }
    else {
        int lastID = query.lastInsertId().toInt();
        student.setID(lastID);
        return lastID;
    }

}

/**
 * @brief Database::createProject
 *
 * This function currently does not register students in the Project object.
 * Please add the registered students to the database.
 *
 * @param project
 * @return
 */
int Database::createProject (Project& project){
    QSqlQuery query;
    query.prepare(DatabaseQueries::insertProject);
    query.bindValue(":projectName",project.getTitle());
    query.bindValue(":description",project.getDescription());
    query.bindValue(":minTeamSize",project.getMinTeamSize());
    query.bindValue(":maxTeamSize",project.getMaxTeamSize());
    if(!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return 0;
    }
    else {

        int lastID = query.lastInsertId().toInt();
        QList<Student*> students = project.getRegisteredStudents();
        //RISKY CALL, STUDENTS MAY NOT EXIST
        addStudentsToProject(lastID,&students);
        project.setID(lastID);
        return lastID;
    }

}

int Database::addStudentsToProject(int& projectID, QList<Student*>* students){
    if (projectID > 0)
    {
        QSqlQuery query;
        QVariantList projectIDList;
        QVariantList studentIDList;
        query.prepare(DatabaseQueries::addStudentToProject);

        for (int i = 0; i< students->count();i++)
        {
            projectIDList << projectID;
            studentIDList << students->at(i)->getID();
        }

        query.bindValue(":projectID",projectIDList);
        query.bindValue(":studentID",studentIDList);

        if(!query.execBatch())
        {
            qDebug() << query.lastError();
            qDebug() << query.lastQuery();
            return 0;
        }
        else return query.lastInsertId().toInt();
    }
    else return 0;

}

int Database::addStudentToProject(int& projectID,Student& student){

    if (projectID > 0)
    {
        QSqlQuery query;

        query.prepare(DatabaseQueries::addStudentToProject);
        query.bindValue(":projectID",projectID);
        query.bindValue(":studentID",student.getID());

        if(!query.exec())
        {
            qDebug() << query.lastError();
            qDebug() << query.lastQuery();
            return 0;
        }
        else {
            return query.lastInsertId().toInt();
        }
    }
    else return NULL;


}

QList<Project*>* Database::getProjectsByStudent(const int& studentID)
{
    if (studentID > 0)
    {
        QSqlQuery query;

        query.prepare(DatabaseQueries::getProjectsByStudent);
        query.bindValue(":studentID",studentID);

        if(!query.exec())
        {
            qDebug() << query.lastError();
            qDebug() << query.lastQuery();
            return NULL;
        }
        else {
            QList<Project*>* projects = new QList<Project*>;

            Student* tempStudent;
            QString tempDescription;
            QString tempTitle = "";
            QString tempUsername;
            int tempTeamMin;
            int tempTeamMax;
            int tempID = -1;
            Project* tempProject = new Project(tempID,tempTitle);
            int tempStudentID;


            while (query.next())
            {

                tempID = query.value(0).toInt();


                if (tempProject->getID() != tempID)
                {
                    tempTitle = QString(query.value(2).toString());
                    tempProject = new Project(tempID,tempTitle);

                    tempDescription = QString(query.value(3).toString());
                    tempTeamMin = query.value(4).toInt();
                    tempTeamMax = query.value(5).toInt();

                    tempProject->setDescription(tempDescription);
                    tempProject->setTeamMax(tempTeamMax);
                    tempProject->setTeamMin(tempTeamMin);

                    projects->append(tempProject);
                }

                tempStudentID = query.value(8).toInt();
                tempUsername = query.value(9).toString();
                tempStudent = new Student(tempStudentID,tempUsername);
                tempProject->registerStudent(*tempStudent);


            }

            return projects;
        }
    }
    else return NULL;
}



