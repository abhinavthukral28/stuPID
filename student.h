#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class Student : public User
{
public:
    Student(QString& username);
};

#endif // STUDENT_H
