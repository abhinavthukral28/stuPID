#ifndef USER_H
#define USER_H

#include <QString>
/**
 * @brief The User class
 */
class User
{
 QString username;
 QString firstName;
 QString lastName;
 int ID;
protected:
    User(const QString &username,const int&ID,const QString &fName,const QString &lName);
public:
    QString getUsername() const;
    int setFirstName(QString& firstName);
    int setLastName(QString& lastName);
    QString getFirstName() const;
    QString getLastName () const;
    int getID() const;
    int setID(int& newID);
    bool operator==(const User& other);
};

#endif // USER_H
