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
    int calculateTeamWeight(const Team& team,const int& id);
    int assignStudentToTeam(int studentID, QList<Team*> teams);
    QList< Team* >& createTopRowTeams(int numteams,QList<int>& remainingStudents);
    bool insert(QList<QPair<int,QPair<int,int> > >& pci,const QPair<int,QPair<int,int> >& pair);
    int addOutliers(QList <Team*>& teams,const int& minSize, const int& maxSize);
    const QList<int>& sortKeys(QList<int> keys);
    int sortTeams(QList<Team*>& team);
public:
    Distributor(QMap< int,QList< QPair<int,int> >* >& pciParam);
    const QList<Team*>& distributeTeams(const int minSize,const int maxSize);

};

#endif // DISTRIBUTOR_H
