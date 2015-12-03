#ifndef TEAM_H
#define TEAM_H

#include <QList>

class Team
{

private :
    QList<int> teamMembers;
    int pci;
    int rank;
public:
    Team();
    int addStudent(int id);
    int removeStudent(int id);
    const QList<int>& getTeamMembers();

};

#endif // TEAM_H
