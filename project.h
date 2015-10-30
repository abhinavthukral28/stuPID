#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include "student.h"
class Administrator;
class QString;
class Project
{

Administrator& owner;
QString& projectName;
std::vector<Student> registeredStudents;

public:
    Project(Administrator& admin,QString& title);
    int registerStudent(Student& student);
};

#endif // PROJECT_H
