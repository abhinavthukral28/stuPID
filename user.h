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
 QString& username;
public:
    User( QString& username);
};

#endif // USER_H
