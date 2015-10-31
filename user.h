#ifndef USER_H
#define USER_H

#include <QString>
/**
 * @brief The User class
 *
 *  We can add in some contact info or things if required.
 */
class User
{
 QString username;
 QString firstName;
 QString lastName;
protected:
    User(QString &username);
    User(QString &username, QString &firstName, QString &lastName);
public:
    QString getUsername() const;
    QString setFirstName(QString& firstName) const;
    QString setLastName(QString& lastName) const;
};

#endif // USER_H
