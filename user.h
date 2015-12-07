#ifndef USER_H
#define USER_H

#include <QString>



/**
 * @brief The User class
 */

class User
{

    friend class DBimpl;
 QString username;
 QString firstName;
 QString lastName;
 int ID;
protected:
    User(const QString &username,const int&ID,const QString &fName,const QString &lName);
   int setID(const int& newID);
public:
    QString getUsername() const;
    int setFirstName(const QString& firstName);
    int setLastName(const QString& lastName);
    QString getFirstName() const;
    QString getLastName () const;
    int getID() const;
    bool operator==(const User& other);

};

#endif // USER_H
