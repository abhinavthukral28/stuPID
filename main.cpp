#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "createprojectview.h"
#include "logindialog.h"
#include "project.h"
#include "student.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //view.show();
    //LoginDialog view;
    Database::getInstance();
    LoginDialog view;
    view.show();

//    Database* database = Database::getInstance();

//    Student* student = new Student("tester2");
//    database->createStudent(*student);
//    std::cout << "New ID " << student->getID();


  return a.exec();



}
