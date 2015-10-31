#ifndef DATABASEQUERIES
#define DATABASEQUERIES

#include<QString>

class DatabaseQueries{
private:
    const static QString STUDENTS_TABLE;
    const static QString QUALIFICATIONS_TABLE;
    const static QString PROJECTS_TABLE;
    const static QString TEAM_STUDENTS_TABLE;
    const static QString EXPECTATIONS_TABLE;
    const static QString STUDENT_QUALIFICATIONS_TABLE;
    const static QString TEAM_TABLE;
  public:
    const static QString selectAllStudents;
    const static QString insertStudent;



};

//TABLES
const QString DatabaseQueries::STUDENTS_TABLE = "Students";
const QString DatabaseQueries::QUALIFICATIONS_TABLE = "Qualifications";
const QString DatabaseQueries::PROJECTS_TABLE = "Projects";
const QString DatabaseQueries::TEAM_STUDENTS_TABLE = "teamMember";
const QString DatabaseQueries::EXPECTATIONS_TABLE = "Expectations";
const QString DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE = "StudentQualifications";
const QString DatabaseQueries::TEAM_TABLE = "Team";

//QUERIES
const QString DatabaseQueries::selectAllStudents = QString("SELECT * FROM ") + DatabaseQueries::STUDENTS_TABLE;
const QString DatabaseQueries::insertStudent = "INSERT INTO (studentID,studentName) " + DatabaseQueries::STUDENTS_TABLE + " VALUES (NULL,?)";

#endif // DATABASEQUERIES_H
