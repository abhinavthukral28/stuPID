#include "team.h"

Team::Team()
{
}

int Team::addStudent(Student& student)
{
    if (!teamMembers.contains(&student))
    {
     teamMembers << &student;
     return 1;
    }
    return 0;
}


int Team::removeStudent(Student& student){
 return teamMembers.removeOne(&student);
}
