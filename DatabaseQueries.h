#ifndef DATABASEQUERIES
#define DATABASEQUERIES

class DatabaseQueries{
private:
    const QString STUDENTS_TABLE = "Students";
    const QString QUALIFICATIONS_TABLE = "Qualifications";
    const QString PROJECTS_TABLE = "Projects";
    const QString TEAM_STUDENTS_TABLE = "teamMember";
    const QString EXPECTATIONS_TABLE = "Expectations";
    const QString STUDENT_QUALIFICATIONS_TABLE = "StudentQualifications";
    const QString TEAM_TABLE = "Team";
  public:
    const QString selectAllStudents = "SELECT * FROM " << STUDENTS_TABLE;



};

#endif // DATABASEQUERIES_H
