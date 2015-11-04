    #include "administrator.h"

Administrator::Administrator(int& ID, QString& username) : User(username,ID)
{
}

int Administrator::addProject (Project& project)
{

    return 1;
}
