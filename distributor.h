#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <QPair>
#include <QList>
#include <QMap>
class Team;


class Distributor
{
private:
    const QMap< int,QList < QPair<int,int> > >& pci;
    int calculateTeamWeight(Team team);
    int assignStudentToTeam(int studentID, QList<Team*> teams);
public:
    Distributor(const QMap< int,QList< QPair<int,int> > >& pciParam);
    const QList<Team*>& distributeTeams(const int minSize,const int maxSize);
};

#endif // DISTRIBUTOR_H
