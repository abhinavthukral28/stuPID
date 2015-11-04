#include "user.h"

#include <QDebug>
User::User(const QString& initUsername,const int& userID) : username(initUsername),ID(userID)
{

}

QString User::getUsername() const{
    return username;
}

int User::setFirstName(QString& firstName){
    this->firstName = firstName;
}

int User::setLastName(QString& lastName) {
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

int User::setID(int& newID){

    ID = newID;
    return 1;
}

bool User::operator==(const User& other){
    return other.getID() == getID();
}
