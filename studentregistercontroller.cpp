#include "studentregistercontroller.h"
#include "qualificationinit.h"
#include "studentregister.h"
#include "student.h"
#include <QList>

StudentRegisterController::StudentRegisterController(StudentRegister *sRegister):QObject(), studentRegister(sRegister)
{

}

int StudentRegisterController::goToQualificationsView(Student student){

    studentRegister->close();
    QualificationInit qual(student);
    return qual.exec();


}
