#include "user.h"

#include <QDebug>
User::User(QString& initUsername) : username(initUsername)
{

}

QString User::getUsername() const{
    return username;
}
