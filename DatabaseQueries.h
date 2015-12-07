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
    const static QString getProjectsByStudent;
    const static QString getQualificationsByStudent;
    const static QString updateQualificationByStudent;
    const static QString createQualificationByStudent;
    const static QString removeStudentFromProject;
    const static QString getAvailableProjects;
    const static QString getStudentByID;
    const static QString getTeamsByProject;
    const static QString createTeamByProject;
    const static QString storeTeamsByProject;
    const static QString getProjectByID;

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
        " LEFT JOIN " + DatabaseQueries::PROJECT_STUDENT_TABLE + " ON " + DatabaseQueries::PROJECTS_TABLE + ".projectID = " + DatabaseQueries::PROJECT_STUDENT_TABLE + ".projectID LEFT JOIN " +
        DatabaseQueries::STUDENTS_TABLE + " ON " + DatabaseQueries::STUDENTS_TABLE+ ".studentID = " + DatabaseQueries::PROJECT_STUDENT_TABLE + ".studentID";

const QString DatabaseQueries::insertProject = "INSERT INTO "+DatabaseQueries::PROJECTS_TABLE+" (projectID,projectName,description,minTeamSize,maxTeamSize)  VALUES (null,:projectName,:description,:minTeamSize,:maxTeamSize)";

const QString DatabaseQueries::addStudentToProject = "INSERT INTO " + DatabaseQueries::PROJECT_STUDENT_TABLE + " (projectID,studentID) VALUES (:projectID,:studentID)";


const QString DatabaseQueries::removeStudentFromProject = "DELETE FROM ProjectStudents where studentID=:studentID AND projectID=:projectID";

//SELECT Projects.* FROM Students JOIN ProjectStudents on Students.studentID = ProjectStudents.studentID JOIN Projects ON Projects.projectID = ProjectStudents.projectID where Students.studentID = ?;

const QString DatabaseQueries::getProjectsByStudent =  QString("SELECT * FROM ") + DatabaseQueries::PROJECTS_TABLE +
        " JOIN " + DatabaseQueries::PROJECT_STUDENT_TABLE + " ON " + DatabaseQueries::PROJECTS_TABLE + ".projectID = " + DatabaseQueries::PROJECT_STUDENT_TABLE + ".projectID JOIN " +
        DatabaseQueries::STUDENTS_TABLE + " ON " + DatabaseQueries::STUDENTS_TABLE+ ".studentID = " + DatabaseQueries::PROJECT_STUDENT_TABLE + ".studentID WHERE "+DatabaseQueries::STUDENTS_TABLE+".studentID = :studentID";



const QString DatabaseQueries::getAvailableProjects =  "SELECT * FROM Projects WHERE  projectID NOT IN (SELECT projectID FROM ProjectStudents where studentID = :studentID)";


const QString DatabaseQueries::getQualificationsByStudent = QString("SELECT * FROM ")+DatabaseQueries::EXPECTATIONS_TABLE+" JOIN "
        +DatabaseQueries::QUALIFICATIONS_TABLE+" ON "+DatabaseQueries::EXPECTATIONS_TABLE+".eID = "+DatabaseQueries::QUALIFICATIONS_TABLE+".qID LEFT JOIN "+
        DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE+" on "+DatabaseQueries::EXPECTATIONS_TABLE+".eID = "+DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE+".eID and "+ DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE+".studentID = :studentID";


const QString DatabaseQueries::updateQualificationByStudent = QString("UPDATE ")+DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE+" SET qualificationRating = :qualificationRating, expectationRating = :expectationRating where studentID = :studentID and eID = :displayID";

const QString DatabaseQueries::getStudentByID = "Select * from Students where studentID = :studentID";

const QString DatabaseQueries::getTeamsByProject =  "SELECT Students.studentID, Team.teamID FROM (Team join TeamMember as teamJoin on Team.teamID = teamJoin.teamID join Students on teamJoin.studentID = Students.studentID) where projectID = :projectID";


const QString DatabaseQueries::createQualificationByStudent = QString("INSERT INTO ")+DatabaseQueries::STUDENT_QUALIFICATIONS_TABLE+" (studentQualificationID,qualificationRating,expectationRating,studentID,eID) VALUES(NULL,:qualificationRating,:expectationRating,:studentID,:eID)";



const QString DatabaseQueries::createTeamByProject = "INSERT INTO Team (teamID, projectID,result) VALUES (NULL, :projectID,:result)";

const QString DatabaseQueries::getProjectByID = "Select * from Projects where projectID = :project";


const QString DatabaseQueries::storeTeamsByProject ="INSERT INTO TeamMember (teamID,studentID) VALUES (:teamID,:studentID)";
#endif // DATABASEQUERIES_H
