#include "session.h"

Student Session::user;
int Session::setStudent(const Student &userParam)
{
    Session::user = userParam;
}

const Student Session::getStudent(){
    return Session::user;
}
