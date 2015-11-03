#ifndef SQLEXCEPTION_H
#define SQLEXCEPTION_H

#include <exception>
#include <string>
class SQLException : public std::exception
{
public:
    SQLException(std::string desc);
    virtual const char* what() const throw();

    ~SQLException() throw()
     {
        delete &whatStr;
     }
private:
    std::string whatStr;

};

#endif // SQLEXCEPTION_H
