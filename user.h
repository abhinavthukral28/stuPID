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
    User(QString &username,int& ID);
    User(QString &username,int&ID, QString &firstName, QString &lastName);
public:
    QString getUsername() const;
    QString setFirstName(QString& firstName);
    QString setLastName(QString& lastName);
    QString getFirstName() const;
    QString getLastName () const;
    int getID() const;
    bool operator==(const User& other);
};

#endif // USER_H
