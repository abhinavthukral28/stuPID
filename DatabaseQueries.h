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
    const static QString PROJECT_STUDENT_TABLE;
  public:
    const static QString selectAllStudents;
    const static QString insertStudent;
    const static QString selectAllProjects;
    const static QString insertProject;
    const static QString addStudentToProject;

};

//TABLES
const QString DatabaseQueries::STUDENTS_TABLE = "Students";
const QString DatabaseQueries::QUALIFICATIONS_TABLE = "Qualifications";
const QString DatabaseQueries::PROJECTS_TABLE = "Projects";
const QString DatabaseQueries::TEAM_STUDENTS_TABLE = "teamMember";
const QString DatabaseQueries::EXPECTATIONS_TABLE = "Expectations";
const QString DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE = "StudentQualifications";
const QString DatabaseQueries::TEAM_TABLE = "Team";
const QString DatabaseQueries::PROJECT_STUDENT_TABLE = "ProjectStudents";


//QUERIES
//SELECT * FROM Projects JOIN ProjectStudents on Projects.projectID = ProjectStudents.projectID JOIN Students ON Students.studentID = ProjectStudents.studentID ;
const QString DatabaseQueries::selectAllStudents = QString("SELECT * FROM ") + DatabaseQueries::STUDENTS_TABLE;

const QString DatabaseQueries::insertStudent = "INSERT INTO "+DatabaseQueries::STUDENTS_TABLE+" (studentID,studentName)  VALUES (NULL,:username)";

const QString DatabaseQueries::selectAllProjects = QString("SELECT * FROM ") + DatabaseQueries::PROJECTS_TABLE +
        " JOIN " + DatabaseQueries::PROJECT_STUDENT_TABLE + " ON " + DatabaseQueries::PROJECTS_TABLE + ".projectID = " + DatabaseQueries::PROJECT_STUDENT_TABLE + ".projectID JOIN " +
        DatabaseQueries::STUDENTS_TABLE + " ON " + DatabaseQueries::STUDENTS_TABLE+ ".studentID = " + DatabaseQueries::PROJECT_STUDENT_TABLE + ".studentID";

const QString DatabaseQueries::insertProject = "INSERT INTO "+DatabaseQueries::PROJECTS_TABLE+" (projectID,projectName,description,minTeamSize,maxTeamSize)  VALUES (NULL,:projectName,:description,:minTeamSize,:maxTeamSize)";

const QString DatabaseQueries::addStudentToProject = "INSERT INTO " + DatabaseQueries::PROJECT_STUDENT_TABLE + " (projectID,studentID) VALUES (:projectID,:studentID)";
#endif // DATABASEQUERIES_H
