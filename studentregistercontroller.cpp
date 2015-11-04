#include "studentregistercontroller.h"
#include "qualificationinit.h"
#include "studentregister.h"
#include "student.h"
#include <QList>

StudentRegisterController::StudentRegisterController(StudentRegister *sRegister):QObject(), studentRegister(sRegister)
{

}

int StudentRegisterController::goToQualificationsView(Student student){
    QList<QString> keyList,q,e;
    keyList[0] = "Git";
    keyList[1] = "OO";
    keyList[2] = "GPA";
    keyList[3] = "WD";
    keyList[4] = "LS";
    q[0] = "Do you git bro?";
    e[0] = "How much your partner gits";
    q[1] = "Do you do object oriented pogramming?";
    e[1] = "How much your partner knows";
    q[2] = "What's you CGPA";
    e[2] = "Parner's expected CGPA";
    q[3] = "Do you know web dev";
    e[3] = "How much does your partner know";

    studentRegister->close();
    QualificationInit qual(student);
    return qual.exec();


}
