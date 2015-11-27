#ifndef SESSION_H
#define SESSION_H

#include "student.h"
class Session
{
friend class LoginController;
protected:
       static int setStudent(const Student& user);
private:
    static Student user;
public:

    static const Student getStudent();
};

#endif // SESSION_H
