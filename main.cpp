#include <QApplication> 
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "user.h"
#include "student.h"
#include "studentprojectregisterview.h"
#include "editqualificationsview.h"
#include "project.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    LoginDialog view;
    view.show();

//    Database* database = Database::getInstance();

<<<<<<< HEAD
    QString usernameOne = "studentOne";
    QString usernameTwo = "studentTwo";
    QString projectTitleOne = "projectOne";
    QString projectTitleTwo = "projectTwo";
    int tempID = -1;
=======
//    int projectID;
//    QString projectTitle = "ImAProject";
//    QString username = "ImAStudent";
//    QList<Student*> registeredStudents;
//    int ID = -1;
//    Project* project = new Project(ID,projectTitle);
//    Student* student = new Student (ID,username);
//    database->createStudent(*student);
>>>>>>> 2372888d47e8a7b10a06062ec45bc9c3fd78bd54

    Student* studentOne = new Student(tempID,usernameOne);
    Student* studentTwo = new Student(tempID,usernameTwo);

<<<<<<< HEAD
    Project* projectOne = new Project(tempID,projectTitleOne);
    Project* projectTwo = new Project(tempID,projectTitleTwo);
=======
//    project ->registerStudent(*student);
//    projectID = database->createProject(*project);
>>>>>>> 2372888d47e8a7b10a06062ec45bc9c3fd78bd54

    projectOne->registerStudent(*studentOne);
    projectTwo->registerStudent(*studentTwo);


//    database->createStudent(*studentOne);
//    database->createStudent(*studentTwo);

<<<<<<< HEAD
    database->createProject(*projectOne);
    database->createProject(*projectTwo);

    QList<Project*>* allProjects = database->getAllProjects();
    QList<Project*>* studentOneProjects = database->getProjectsByStudent(studentOne->getID());
    QList<Project*>* studentTwoProjects = database->getProjectsByStudent(studentTwo->getID());

    std::cout << "Printing all projects" << std::endl;
    for (int i = 0; i < allProjects->count();i++)
    {
        std::cout << allProjects->at(i)->getTitle().toStdString() << std::endl;
    }

    std::cout << "Printing student one projects" << std::endl;
    if (studentOneProjects != NULL)
    {
        for (int i = 0; i < studentOneProjects->count();i++)
        {
            std::cout << studentOneProjects->at(i)->getTitle().toStdString() << std::endl;
        }
    }

    std::cout << "Printing student two projects" << std::endl;
    if (studentTwoProjects != NULL)
    {
        for (int i = 0; i < studentTwoProjects->count();i++)
        {
            std::cout << studentTwoProjects->at(i)->getTitle().toStdString() << std::endl;
        }
    }
    return a.exec();
=======
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
>>>>>>> 2372888d47e8a7b10a06062ec45bc9c3fd78bd54


}
