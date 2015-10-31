#include "project.h"

Project::Project(Administrator& admin, QString& title) : owner(admin), projectName(title)
{
}

int Project::registerStudent(Student& student)
{
    return 1;
}


