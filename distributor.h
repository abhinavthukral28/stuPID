#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <QPair>
#include <QList>
#include <QMap>
class Team;


class Distributor
{
private:
    QMap< int,QList < QPair<int,int> >* >& pci;
    int calculateTeamWeight(Team team, int id);
    int assignStudentToTeam(int studentID, QList<Team*> teams);
    const QList< Team* >& createTopRowTeams(int numteams,QList<int>& remainingStudents);
    bool insert(QList<QPair<int,QPair<int,int> > >& pci,const QPair<int,QPair<int,int> >& pair);
public:
    Distributor(QMap< int,QList< QPair<int,int> >* >& pciParam);
    const QList<Team*>& distributeTeams(const int minSize,const int maxSize);
    const QList<int>& sortKeys(QList<int> keys);
};

#endif // DISTRIBUTOR_H
