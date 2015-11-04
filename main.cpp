#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include <QDebug>
#include "project.h"
#include "student.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    Database* database = Database::getInstance();
   // int tempID = -1;
    QString title = "imastudent";
    QString projectTitle = "imaProject";
    Project* project = new Project(projectTitle);
    Student* tempStudent = new Student(title);
    database->addStudentToProject(5,*tempStudent);

    //database->createProject(*project);



 //  database->createStudent(*tempStudent);
   // database->

    //ManageProjectsView view;
 //  view.show();
    LoginDialog view;
    view.show();


   QList<Student*> students = database->getAllStudents();


    for (int i = 0; i < students.count(); i++)
    {
        qDebug() << "this is fucked";
        QString temp = students.at(i)->getUsername();
        qDebug() << (temp);
    }

  return a.exec();



}
