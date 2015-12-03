#ifndef TEAM_H
#define TEAM_H

#include <QList>

class Student;
class Team
{

private :
    QList<Student*> teamMembers;
    int pci;
    int rank;
public:
    Team();
    int addStudent(Student& student);
    int removeStudent(Student& student);
    const QList<Student*>& getTeamMembers();

};

#endif // TEAM_H
