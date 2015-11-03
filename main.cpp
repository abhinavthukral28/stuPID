#include <QApplication> 
#include <iostream>
#include "logindialog.h"
#include "Database.h"
#include "user.h"
#include "student.h"
#include "studentprojectview.h"
#include "editqualificationsview.h"
#include "project.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Database* database = Database::getInstance();

    QString usernameOne = "studentOne";
    QString usernameTwo = "studentTwo";
    QString projectTitleOne = "projectOne";
    QString projectTitleTwo = "projectTwo";
    int tempID = -1;

    Student* studentOne = new Student(tempID,usernameOne);
    Student* studentTwo = new Student(tempID,usernameTwo);

    Project* projectOne = new Project(tempID,projectTitleOne);
    Project* projectTwo = new Project(tempID,projectTitleTwo);

    projectOne->registerStudent(*studentOne);
    projectTwo->registerStudent(*studentTwo);


//    database->createStudent(*studentOne);
//    database->createStudent(*studentTwo);

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


}
