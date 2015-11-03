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



int Database::insertValuesintoQualifications(){
    QSqlQuery qry;

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (1,'Core GPA','What is your core GPA?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (2,'Git Version Control','How familiar are you with the GIT?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (3, 'Object Oriented Programming', 'How familiar are you with object-oriented Programming?')");

    qry.prepare("INSERT INTO Qualifications (qtle,qid,qtiualificationValue) VALUES (4, 'Systems Programming', 'How familiar are you with systems programming?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (5, 'Web Development', 'How much experience do you have in Web Development?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (6, 'UX Design','How much experience do you have in UX Design? ')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (7, 'Punctuality', 'How punctual are you?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (8, 'Night Owl', 'How much of a night owl are you?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (9, 'Documentation', ' How much experience do you have in documentation?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (10, 'Leadership Skills', ' How would you rate your leadership skills?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (11, 'Locally or Remotely ', ' Do you prefer to work locally or remotely?')");

    qry.prepare("INSERT INTO Qualifications (qid,qtitle,qualificationValue) VALUES (12, 'Communication Skills', ' How would you rate you communication skills?')");

    return 0;
}

int Database::insertValuesintoExpectations(){

    QSqlQuery qry;

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (1, 'Core GPA', 'What Core GPA do you expect from your team mates?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (2, 'Git Version Control','How familiar do you want your team mates to know Git?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (3, 'Object Oriented Programming', 'How familiar do you want your team mates to know Object Oriented Programming?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (4, 'Systems Programming','How familiar do you want your team mates to know Systems Programming?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (5, 'Web Development', 'How much experience do you expect your team mates to have in Web Development?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (6, 'UX Design', 'How much experience do you want your team mates to have in UX Design?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (7, 'Punctuality', 'How punctual do you want your team mates to be?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (8, 'Night Owl', 'How much of a night owl do you want your team mates to be?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (9, 'Documentation ', 'How much experience in documentation do you want your team mates to have?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (10, 'Leadership Skills', 'How much experience do you want your team mates to have in leadership?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (11, 'Locally or Remotely ', 'Do you want your team mates to work locally or remotely?')");

    qry.prepare("INSERT INTO Expectations (eID,etitle,expectationValue) VALUES (12, 'Communication Skills', 'How important is it for your teams to have communication skills?')");

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



    qry.prepare( "CREATE TABLE IF NOT EXISTS Qualifications(qID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, qtitle VARCHAR(30),qualificationValue VARCHAR(60))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table Qualifications created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS Projects(projectID INTEGER PRIMARY KEY, admin VARCHAR(30),projectName VARCHAR(30) UNIQUE, description VARCHAR(30),minTeamSize INTEGER, maxTeamSize INTEGER)" );
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

    qry.prepare( "CREATE TABLE IF NOT EXISTS TeamMember(teamID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,studentID int,FOREIGN KEY(studentID) REFERENCES Students(studentId))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table teamMember created!";





    qry.prepare( "CREATE TABLE IF NOT EXISTS Expectations(eID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,etitle VARCHAR(30),expectationValue VARCHAR(30))" );
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


const QList<Project*>& Database::getAllProjects(){

    QSqlQuery query;
    query.prepare(DatabaseQueries::selectAllProjects);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

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

        return *projects;
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

                if (tempProject != NULL)
                {
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
            }

            return projects;
        }
    }
    else return NULL;
}



