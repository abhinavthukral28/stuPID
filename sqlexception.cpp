#include "sqlexception.h"

SQLException::SQLException(std::string desc) : exception(),whatStr(desc)
{
}


const char* SQLException::what() const throw()
{
    return whatStr.c_str();
}



