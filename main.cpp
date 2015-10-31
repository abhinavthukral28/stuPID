#include <QApplication> 
#include <iostream>
#include "logindialog.h"
#include "Database.h"
#include "user.h"
#include "student.h"
int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    //DATABASE INITIALIZATION

    Database* instance = Database::getInstance();




//    LoginDialog dialog;

//    dialog.show();
//    return a.exec();

QString username = "im a student";
Student* user = new Student (username);

QList<Student*> students = instance->getAllStudents();

for (int i = 0; i < students.count();i++)
{

    std::cout << students.at(i)->getUsername().toStdString() << std::endl;
}

std::cout << user->getUsername().toStdString() << std::endl;

return 0;

}
