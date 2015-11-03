#include "studentregistercontroller.h"
#include "qualificationinit.h"
#include "studentregister.h"
StudentRegisterController::StudentRegisterController(StudentRegister *sRegister):QObject(), studentRegister(sRegister)
{

}

int StudentRegisterController::goToQualificationsView(){
    studentRegister->close();
    qualificationinit qual;
    return qual.exec();


}
