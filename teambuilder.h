#ifndef TEAMBUILDER_H
#define TEAMBUILDER_H

#include <QList>
class PciBuilder;
class Project;
class Distributor;
class Team;

class TeamBuilder
{


public:
    TeamBuilder();
    const QList<Team*>& createTeams(const Project& project);
};

#endif // TEAMBUILDER_H
