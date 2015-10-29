#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"

class Administrator : public User
{
public:
    Administrator(QString& username);
};

#endif // ADMINISTRATOR_H
