#include "studentregistercontroller.h"
#include "qualificationinit.h"
#include "studentregister.h"
#include "student.h"
#include "Database.h"
#include "session.h"
#include <QList>

StudentRegisterController::StudentRegisterController(StudentRegister *sRegister):QObject(), studentRegister(sRegister)
{

}

int StudentRegisterController::goToQualificationsView(Student student){

    studentRegister->close();

    Database::getInstance()->createStudent(student);
    Session::setStudent(student);
    QualificationInit qual;
    return qual.exec();


}
