#include "user.h"

#include <QDebug>
User::User(const QString& initUsername,const int& userID,const QString &fName,const QString& lName) : firstName(fName),lastName(lName),username(initUsername),ID(userID)
{

}

QString User::getUsername() const{
    return username;
}

int User::setFirstName(const QString& firstName){
    this->firstName = firstName;
}

int User::setLastName(const QString& lastName) {
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


int User::setID(const int& newID){

    ID = newID;
    return 1;
}

bool User::operator==(const User& other){
    return other.getID() == getID();
}
