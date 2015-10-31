#include <QApplication> 
#include <iostream>
#include "logindialog.h"
#include "Database.h"
#include "user.h"
#include "student.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
   // MainWindow w;
   // w.show();

   // editQualificationsView w;
    //w.show();

    //qualificationinit w;
   // w.show();

//    QApplication a(argc, argv);
//    //DATABASE INITIALIZATION


    Database* instance = Database::getInstance();




//    LoginDialog dialog;

//    dialog.show();
//    return a.exec();

QString username = "im a student";
//Student* user = new Student (username);

Student* temp = new Student(username);
if (instance->createStudent(*temp))
{

QList<Student*>* students = instance->getAllStudents();

for (int i = 0; i < students->count();i++)
{

    std::cout << students->at(i)->getUsername().toStdString() << std::endl;
}

}
else std::cout << "ERROR IN INSERTION";
//std::cout << user->getUsername().toStdString() << std::endl;

return 0;

}
