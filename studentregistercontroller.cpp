#include "studentregistercontroller.h"
#include "qualificationinit.h"
#include "studentregister.h"
#include "student.h"
#include "Database.h"
#include "session.h"
#include <QList>
StudentRegisterController *StudentRegisterController::instance=0;
StudentRegisterController::StudentRegisterController():QObject()
{

}

int StudentRegisterController::goToQualificationsView(Student student){

    studentRegister->close();

    Database::getInstance()->createStudent(student);
    Session::setStudent(student);
    QualificationInit qual;
    return qual.exec();


}

int StudentRegisterController::setView(StudentRegister *view)
{
    studentRegister = view;
}

StudentRegisterController* StudentRegisterController::getInstance(){

    if(!StudentRegisterController::instance){

        StudentRegisterController::instance = new StudentRegisterController();
    }
    return StudentRegisterController::instance;

}
