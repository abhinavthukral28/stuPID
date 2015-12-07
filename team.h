#ifndef TEAM_H
#define TEAM_H

#include <QList>
#include <QString>
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
    const QList<int>& getTeamMembers() const;
    int getPci() const;
    int getID();
    int setPci(int newPci);
    QString getResultDisplay();

};

#endif // TEAM_H
