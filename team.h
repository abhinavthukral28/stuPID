#ifndef TEAM_H
#define TEAM_H

#include <QList>

class Team
{

private :
    QList<int> teamMembers;
    int pci;
    int rank;
    int id;
public:
    Team();
    Team(int id);
    int addStudent(int id);
    int removeStudent(int id);
    const QList<int>& getTeamMembers();
    int getPci();
    int getID();
    int setPci(int newPci);

};

#endif // TEAM_H
