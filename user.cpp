#include "user.h"

#include <QDebug>
User::User(QString& initUsername,int& userID) : username(initUsername),ID(userID)
{

}

QString User::getUsername() const{
    return username;
}

QString User::setFirstName(QString& firstName){
    this->firstName = firstName;
}
QString User::setLastName(QString& lastName) {
    this->lastName = lastName;
}
QString User::getFirstName() const{
    return firstName;
}
QString User::getLastName () const{
    return lastName;
}
int User::getID() const{
    return ID;
}

bool User::operator==(const User& other){
    return other.getID() == getID();
}
