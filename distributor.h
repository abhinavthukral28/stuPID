#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <QPair>
#include <QList>
#include <QMap>
#include "project.h"
class Team;
class Project;


class Distributor
{
private:
    QMap< int,QList < QPair<int,int> >* >& pci;
    int calculateTeamWeight(const Team& team,const int& id);
    QList< Team* >& createTopRowTeams(int numteams);
    bool insert(QList<QPair<int,QPair<int,int> > >& pci,const QPair<int,QPair<int,int> >& pair);
    int addOutliers(QList <Team*>& teams,const int& minSize, int& maxSize);
    QList<int>* sortKeys(QList<int> keys);
    int sortTeams(QList<Team*>& team);
    Project project;
public:
    Distributor(QMap< int,QList< QPair<int,int> >* >& pciParam,Project& projectParam);
    const QList<Team*>& distributeTeams(const int minSize,const int maxSize);

};

#endif // DISTRIBUTOR_H
