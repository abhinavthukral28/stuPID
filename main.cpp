#include <QApplication> 
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    LoginDialog view;
    view.show();

//    Database* database = Database::getInstance();

//    int projectID;
//    QString projectTitle = "ImAProject";
//    QString username = "ImAStudent";
//    QList<Student*> registeredStudents;
//    int ID = -1;
//    Project* project = new Project(ID,projectTitle);
//    Student* student = new Student (ID,username);
//    database->createStudent(*student);


//    project ->registerStudent(*student);
//    projectID = database->createProject(*project);




//    //database->addStudentToProject(projectID,*student);

//     std::cout<< "FETCHING" << std::endl;
//    QList<Project*>* projects = database->getAllProjects();
//    std::cout << projects->count() << std::endl;
//    for (int i = 0; i < projects->count(); i++)
//    {
//        project = projects->at(i);
//        std::cout<< project->getTitle().toStdString() << std::endl;
//        registeredStudents = project->getRegisteredStudents();
//        for (int j = 0; j < registeredStudents.count(); j++)
//        {
//            std::cout<< registeredStudents.at(j)->getUsername().toStdString();
//        }


//    }
  return a.exec();


}
