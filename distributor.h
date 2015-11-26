#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <QList>
#include <QMap>
class Team;


class Distributor
{
private:
    const QMap< int,QMap<int,int> >& pci;
    int calculateTeamWeight(Team team);
    int assignStudentToTeam(int studentID, QList<Team*> teams);
public:
    Distributor(const QMap< int,QMap<int,int> >& pciParam);
    const QList<Team*>& distributeTeams(int minSize, int maxSize);
};

#endif // DISTRIBUTOR_H
