

#include "student.h"
#include "qualification.h"
Student::Student(const int& ID,const QString& username) : User(username,ID)
{
}


Student::Student(const QString& username) : User(username,-1)
{
}

