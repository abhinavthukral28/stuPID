#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include <vector>

class Project;
class Administrator : public User
{

std::vector<Project*> projects;
public:
    Administrator(int& ID, QString& username);
    int addProject (Project& project);

};

#endif // ADMINISTRATOR_H
