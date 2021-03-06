#include "dbimpl.h"
#include "student.h"
#include "project.h"
#include "DatabaseQueries.h"
#include "sqlexception.h"
#include "qualification.h"
#include <QDebug>
#include <QtSql>
#include "team.h"


const QString DBimpl::DBpath="./testdatabase.db";

DBimpl::DBimpl(){
    if(init())
    {
        qDebug("Something bad happened");
    }
    else {
        qDebug("It worked!");
    }
}


int DBimpl::init(){


    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

    db.setDatabaseName(DBimpl::DBpath);

    if(!db.open())
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    qDebug( "Connected!" );


    createTables();
    return 0;


}

int DBimpl::insertStudents()
{

    QSqlQuery qry;

    qry.prepare("SELECT * FROM Students");
    if (!qry.exec())
        throw generateException(qry);
    else{
        if (!qry.next())
        {
            int num_students = 25;
            QString usernamePrefix = "Student";
            Student* tempStudent;
            Qualification* qual;
            QList<Qualification*> qualList;
            for (int i = 0; i < num_students;i++)
            {
                tempStudent = new Student(-1,usernamePrefix+(65+i));

                createStudent(*tempStudent);

                qualList = getAllQualifications(tempStudent->getID());

                for (int i = 0;i < qualList.count();i++)
                {
                    qual = qualList.at(i);

                    qual->setExpectationRating(1 + (std::rand() % (int)(5- 1 + 1)));
                    qual->setQualificationRating(1 + (std::rand() % (int)(5 - 1 + 1)));

                    createQualificationEntry(tempStudent->getID(),*qualList.at(i));


                }





            }
        }
    }
    return 1;
}

int DBimpl::insertValuesintoQualifications(){
    QSqlQuery qry;

    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (1,'Core GPA','What is your core GPA?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (2,'Git Version Control','How familiar are you with the GIT?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (3, 'Object Oriented Programming', 'How familiar are you with object-oriented Programming?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (4, 'Systems Programming', 'How familiar are you with systems programming?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (5, 'Web Development', 'How much experience do you have in Web Development?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (6, 'UX Design','How much experience do you have in UX Design? ')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (7, 'Punctuality', 'How punctual are you?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (8, 'Night Owl', 'How much of a night owl are you?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (9, 'Documentation', ' How much experience do you have in documentation?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (10, 'Leadership Skills', ' How would you rate your leadership skills?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (11, 'Locally or Remotely ', ' Do you prefer to work locally or remotely?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Qualifications (qid,qtitle,qualificationValue) VALUES (12, 'Communication Skills', ' How would you rate you communication skills?')");
    if (!qry.exec()) throw generateException(qry);
    return 1;
}

int DBimpl::insertValuesintoExpectations(){

    QSqlQuery qry;

    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (1, 'Core GPA', 'What Core GPA do you expect from your team mates?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (2, 'Git Version Control','How familiar do you want your team mates to know Git?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (3, 'Object Oriented Programming', 'How familiar do you want your team mates to know Object Oriented Programming?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (4, 'Systems Programming','How familiar do you want your team mates to know Systems Programming?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (5, 'Web Development', 'How much experience do you expect your team mates to have in Web Development?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (6, 'UX Design', 'How much experience do you want your team mates to have in UX Design?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (7, 'Punctuality', 'How punctual do you want your team mates to be?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (8, 'Night Owl', 'How much of a night owl do you want your team mates to be?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (9, 'Documentation ', 'How much experience in documentation do you want your team mates to have?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (10, 'Leadership Skills', 'How much experience do you want your team mates to have in leadership?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (11, 'Locally or Remotely ', 'Do you want your team mates to work locally or remotely?')");
    if (!qry.exec()) throw generateException(qry);
    qry.prepare("INSERT OR IGNORE INTO Expectations (eID,etitle,expectationValue) VALUES (12, 'Communication Skills', 'How important is it for your teams to have communication skills?')");
    if (!qry.exec()) throw generateException(qry);
    return 1;
}


const Student& DBimpl::getStudentByID(const int& studentID){

    QSqlQuery query;
    query.prepare(DatabaseQueries::getStudentByID);
    query.bindValue(":studentID",studentID);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        throw generateException(query);
    }
    else
    {
        QString tempUsername;
        int tempID;
        Student* tempStudent = new Student;

        if (query.next())
        {
            //first column is 0
            tempID = query.value(0).toInt();

            tempUsername = QString(query.value(1).toString());

            tempStudent = new Student(tempID,tempUsername);
            qDebug()<< "getAllQualifications"<<getAllQualifications(tempID);
            tempStudent->setQualifications(getAllQualifications(tempID));

        }

        return *tempStudent;
    }



}




void DBimpl::createTables(){

    QSqlQuery qry;




    qry.prepare( "CREATE TABLE IF NOT EXISTS Qualifications(qID INTEGER PRIMARY KEY, qtitle VARCHAR(30),qualificationValue VARCHAR(60))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {   try{
            insertValuesintoQualifications();
        }catch(SQLException e)
        {
            qDebug() << "FAILED TO INIT QUALIFICATIONS";
            qDebug() << e.what();
        }

        qDebug() << "Table Qualifications created!";
    }

    qry.prepare( "CREATE TABLE IF NOT EXISTS Projects(projectID INTEGER PRIMARY KEY, results INTEGER,projectName VARCHAR(30) UNIQUE, description VARCHAR(30),minTeamSize INTEGER, maxTeamSize INTEGER)" );
    if( !qry.exec() )
    {
        qDebug() << qry.lastQuery();
        qDebug() << qry.lastError();
    }
    else
        qDebug() << "Table Project created!";


    qry.prepare( "CREATE TABLE IF NOT EXISTS ProjectStudents (projectID INTEGER NOT NULL, studentID INTEGER NOT NULL,PRIMARY KEY(projectID,studentID),FOREIGN KEY(projectID) REFERENCES Projects(projectID),FOREIGN KEY(studentID) REFERENCES Students(studentID))" );
    if( !qry.exec() )
    {
        qDebug() <<qry.lastQuery();
        qDebug() << qry.lastError();
    }
    else
        qDebug() << "Table ProjectStudents!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS TeamMember(teamID INTEGER ,studentID int,FOREIGN KEY(studentID) REFERENCES Students(studentID), FOREIGN KEY(teamID) REFERENCES Team(teamID) on delete cascade on update cascade, PRIMARY KEY (teamID, studentID))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table teamMember created!";





    qry.prepare( "CREATE TABLE IF NOT EXISTS Expectations(eID INTEGER PRIMARY KEY ,etitle VARCHAR(30),expectationValue VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {
        try{
            insertValuesintoExpectations();
        }catch(SQLException e)
        {
            qDebug() << "FAILED TO INIT EXPECTATIONS";
        }

        qDebug() << "Table Expectations created!";
    }

    qry.prepare( "CREATE TABLE IF NOT EXISTS StudentQualifications(studentQualificationID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, qualificationRating INTEGER, expectationRating INTEGER, studentID int, eID int,FOREIGN KEY(eID) REFERENCES Expectations(eId))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table StudentQualifications created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS Team(teamID INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,projectID int, result TEXT, FOREIGN KEY(projectID) REFERENCES Projects(projectID))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table Teams created!";


    qry.prepare( "CREATE TABLE IF NOT EXISTS Students (studentID INTEGER PRIMARY KEY, studentName VARCHAR(30) UNIQUE,firstName VARCHAR(30), lastName VARCHAR(30))" );
    if( !qry.exec() )
    {
        qDebug() <<qry.lastQuery();
        qDebug() << qry.lastError();
    }
    else
    {
        insertStudents();
        randomProjects();
        qDebug() << "Table Students created!";
    }

}


const QList<Student*>& DBimpl::getAllStudents(){

    QSqlQuery query;
    query.prepare(DatabaseQueries::selectAllStudents);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        throw generateException(query);
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
            qDebug()<< "getAllQualifications"<<getAllQualifications(tempID);
            tempStudent->setQualifications(getAllQualifications(tempID));
            students->append(tempStudent);
        }

        return *students;
    }


}

const QList<Team*>& DBimpl::getTeamsbyProjectID (const int& projectID){

    QSqlQuery query;
    query.prepare(DatabaseQueries::getTeamsByProject);

    query.bindValue(":projectID",projectID);


    if (!query.exec())
    {
        throw generateException(query);
    }
    else
    {
        QList<Team*>* teams = new QList<Team*> ();
        int teamID = -1;
        int tempID;
        int tempStudentID;


        while (query.next())
        {

            tempID = query.value(1).toInt();


            if (teamID != tempID)
            {

                teamID = tempID;
                Team* team = new Team(teamID);
                teams->append(team);
                qDebug () << query.value(2).toString();
                team->setResultDisplay(query.value(2).toString());
            }

            tempStudentID = query.value(0).toInt();
            teams->last()->addStudent(tempStudentID);


        }

        return *teams;
    }
}



const QList<Project*>& DBimpl::getAllProjects(){

    QSqlQuery query;
    query.prepare(DatabaseQueries::selectAllProjects);

    if (!query.exec())
    {
        throw generateException(query);
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
            qDebug () << "DB " << query.value(1).toInt();


            if (tempProject->getID() != tempID)
            {
                tempTitle = QString(query.value(2).toString());
                tempProject = new Project(tempID,tempTitle);
                 tempProject->setResultsAvailable(query.value(1).toInt());
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
            tempStudent->setQualifications(getAllQualifications(tempStudentID));


        }

        return *projects;
    }

}



int DBimpl::createStudent (Student& student){
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
        for (int i = 0;i < student.getQualifications().count();i++)
        {
            createQualificationEntry(student.getID(),*student.getQualifications().at(i));
        }

        return lastID;
    }

}


int DBimpl::createProject(Project& project){
    QSqlQuery query;
    query.prepare(DatabaseQueries::insertProject);
    query.bindValue(":projectName",project.getTitle());
    query.bindValue(":description",project.getDescription());
    query.bindValue(":minTeamSize",project.getMinTeamSize());
    query.bindValue(":maxTeamSize",project.getMaxTeamSize());
    query.bindValue(":results",0);
    if(!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return 0;
    }
    else {

        int lastID = query.lastInsertId().toInt();
        QList<Student*> students = project.getRegisteredStudents();

        addStudentsToProject(lastID,&students);
        project.setID(lastID);
        return lastID;
    }

}

int DBimpl::addStudentsToProject(const int& projectID, QList<Student*>* students){
    if (projectID > 0)
    {
        int tempInt;
        QSqlQuery query;
        QVariantList projectIDList;
        QVariantList studentIDList;
        query.prepare(DatabaseQueries::addStudentToProject);

        for (int i = 0; i< students->count();i++)
        {
            tempInt = students->at(i)->getID();
            if (tempInt > 0)
            {
                projectIDList << projectID;
                studentIDList << tempInt ;
            }
            else return 0;
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

int DBimpl::removeStudentFromProject(const int projectID,const Student& student){

    QSqlQuery query;

    query.prepare(DatabaseQueries::removeStudentFromProject);

    query.bindValue(":studentID",student.getID());
    query.bindValue(":projectID",projectID);

    if(!query.exec())
    {
        throw generateException(query);
        return 0;
    }
    else
    {
        return 1;
    }


}

int DBimpl::updateQualification(const int& studentID,const Qualification& qualification)
{
    QSqlQuery query;

    query.prepare(DatabaseQueries::updateQualificationByStudent);

    query.bindValue(":qualificationRating",qualification.getQualificationRating());
    query.bindValue(":expectationRating",qualification.getExpectationRating());
    query.bindValue(":studentID",studentID);
    query.bindValue(":displayID",qualification.getDisplayID());

    if(!query.exec())
    {
        throw generateException(query);
        return 0;
    }
    else
    {
        return 1;
    }
}




const QList<Project*>& DBimpl::getProjectsByStudent(const int& studentID)
{
    if (studentID > 0)
    {
        QSqlQuery query;

        query.prepare(DatabaseQueries::getProjectsByStudent);
        query.bindValue(":studentID",studentID);

        if(!query.exec())
        {
            throw generateException(query);
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
                tempProject->setResultsAvailable(query.value(1).toInt());
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
                    QList<Qualification*> temp = getAllQualifications(tempID);


                    tempStudent->qualifications = temp;
                    tempProject->registerStudent(*tempStudent);

                }
            }

            return *projects;
        }
    }
    throw generateCustomSQLException("INVALID INPUT FOR STUDENT ID -> " + studentID);

}

const QList<Project*>& DBimpl::getOpenProjectsByStudent(const int& studentID){
    if (studentID > 0)
    {
        QSqlQuery query;

        query.prepare(DatabaseQueries::getAvailableProjects);
        query.bindValue(":studentID",studentID);

        if(!query.exec())
        {
            throw generateException(query);
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
                tempProject->setResultsAvailable(query.value(1).toInt());
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
                     tempStudent->qualifications = getAllQualifications(tempStudentID);
                    tempProject->registerStudent(*tempStudent);

                }
            }

            return *projects;
        }
    }
    throw generateCustomSQLException("INVALID INPUT FOR STUDENT ID -> " + studentID);

}

const QList<Qualification*>& DBimpl::getAllQualifications(const int& studentID)
{

    QSqlQuery query;
    query.prepare(DatabaseQueries::getQualificationsByStudent);
    query.bindValue(":studentID",studentID);

    if (!query.exec())
    {
        throw generateException(query);
    }
    else
    {
        QList<Qualification*>* qualifications = new QList<Qualification*>;
        Qualification* tempQualification;
        int displayID;
        QString title ;
        QString expectationValue;
        QString qualificationValue;
        int qualificationID ;
        int qualificationRating;
        int expectationRating;
        while (query.next())
        {

            displayID = query.value(0).toInt();
            title = query.value(1).toString();
            expectationValue = QString(query.value(2).toString());
            qualificationValue = QString(query.value(5).toString());
            qualificationID = query.value(6).toInt();
            qualificationRating = query.value(7).toInt();
            expectationRating = query.value(8).toInt();


            tempQualification = new Qualification(displayID,qualificationID,title,expectationValue,
                                                  qualificationValue,qualificationRating,expectationRating);
            qualifications->append(tempQualification);
        }

        return *qualifications;
    }
}


const Student* DBimpl::authenticate(const QString& username){

    QSqlQuery query;

    query.prepare("SELECT * from Students where studentName = :username");

    query.bindValue(":username",username);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        throw generateException(query);
    }
    else
    {
        QString tempUsername;
        int tempID;
        Student* tempStudent = 0;

       if (query.next())
        {
            //first column is 0
            tempID = query.value(0).toInt();
            tempUsername = QString(query.value(1).toString());
            tempStudent = new Student(tempID,tempUsername);
             QList<Qualification*> temp = getAllQualifications(tempID);
             tempStudent->qualifications = temp;
             return tempStudent;

        }
       else return 0;


    }
}

int DBimpl::createQualificationEntry(const int& studentID, const Qualification& qualification)
{
    QSqlQuery query;

    query.prepare(DatabaseQueries::createQualificationByStudent);

    query.bindValue(":eID",qualification.getDisplayID());
    query.bindValue(":expectationRating",qualification.getExpectationRating());
    query.bindValue(":qualificationRating",qualification.getQualificationRating());
    query.bindValue(":qualificationID",qualification.getQualificationID());
    query.bindValue(":studentID",studentID);



    if (!query.exec())
    {
        throw generateException(query);
        return 1;
    }else
    {
        return 0;
    }
}


int DBimpl::storeTeamsByProject (const QList<Team*>& teams, const int& projectID){

    if (projectID > 0)
    {
        int tempInt;
        QSqlQuery query;
        QVariantList studentIDList;
        QVariantList teamIDList;


        query.prepare(DatabaseQueries::storeTeamsByProject);

        for (int i = 0; i< teams.count();i++)
        {
            tempInt = createTeam(projectID,teams.at(i)->getResultDisplay());


            if (tempInt > 0)
            {
                for (int j = 0; j < teams.at(i)->getTeamMembers().count();j++)
                {
                    studentIDList << teams.at(i)->getTeamMembers().at(j);
                    teamIDList << tempInt ;
                }


            }
            else return 0;
        }

        query.bindValue(":studentID",studentIDList);
        query.bindValue(":teamID",teamIDList);

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

 int DBimpl::createTeam(const int& projectID,const QString& resultDisplay)
 {
     QSqlQuery query;

     query.prepare(DatabaseQueries::createTeamByProject);

     query.bindValue(":projectID",projectID);
     query.bindValue(":results",resultDisplay);


     if(!query.exec())
     {
         qDebug() << query.lastError();
         qDebug() << query.lastQuery();
         return 0;
     }
     else{
         markResults(projectID,1);
         return query.lastInsertId().toInt();
     }
 }

 int DBimpl::addStudentToProject(const int& projectID,Student& student){

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
     else return 0;


 }

 int DBimpl::deleteTeamsByProject(const int& projectID){
     QSqlQuery query;

     query.prepare(DatabaseQueries::deleteTeamByProject);

     query.bindValue(":projectID",projectID);



     if(!query.exec())
     {
         qDebug() << query.lastError();
         qDebug() << query.lastQuery();
         return 0;
     }
     else {
         markResults(projectID,0);
         return 1;
     }



 }

 int DBimpl::markResults(const int& projectID,const int& results){

     QSqlQuery query;

     query.prepare(DatabaseQueries::markResults);

     query.bindValue(":projectID",projectID);
     query.bindValue(":results",results);


     if(!query.exec())
     {
         qDebug() << query.lastError();
         qDebug() << query.lastQuery();
         return 0;
     }
     else {
         return 1;
     }

 }

 int DBimpl::updateProject(const Project& project)
 {
    QSqlQuery query;

    query.prepare(DatabaseQueries::updateProject);

    query.bindValue(":projectName",project.getTitle());
    query.bindValue(":description",project.getDescription());
    query.bindValue(":minTeamSize",project.getMinTeamSize());
    query.bindValue(":maxTeamSize",project.getMaxTeamSize());
    query.bindValue(":projectID", project.getID());

    if(!query.exec())
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return 0;
    }
    else {
        return 1;
    }
 }

 int DBimpl::randomProjects(){
     Project* projectOne = new Project("Project One");
     projectOne->setTeamMax(4);
     projectOne->setTeamMin(3);


     Project* projectTwo = new Project ("Project Two");
     projectTwo->setTeamMax(3);
     projectTwo->setTeamMin(2);
     createProject(*projectOne);
     createProject(*projectTwo);


     QList<Student*> students = getAllStudents();

     QList <Student*> studentsOne;
     QList <Student*> studentsTwo;
     int insertCount = 0;
     while (students.count() != 0)
     {
         int index = std::rand() % students.count();
         if (insertCount < 13)
         {
              studentsOne << students.at(index);
              students.removeAt(index);
         }
         else{
             studentsTwo << students.at(index);
             students.removeAt(index);
         }
         insertCount++;

     }


          addStudentsToProject(projectOne->getID(),&studentsOne);
          addStudentsToProject(projectTwo->getID(),&studentsTwo);
 }

SQLException DBimpl::generateException(QSqlQuery query)
{
    return *(new SQLException(query.lastError().text().toStdString() + "\n"  + query.lastQuery().toStdString() + "\n"));
}

SQLException DBimpl::generateCustomSQLException(const char* input)
{
    return  *(new SQLException(input));
}



