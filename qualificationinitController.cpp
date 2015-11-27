#include <QString>
#include "studentprojectregisterview.h"
#include <QDebug>
#include "qualificationinitController.h"
#include <QList>
#include "qualification.h"
#include "Database.h"
#include "studentprojectregisterview.h"
QualificationInitController::QualificationInitController( QualificationInit *qual): QObject(), qualification(qual), database(Database::getInstance())


{
  qList = database->getAllQualifications(-1);

}
void QualificationInitController::setQualificationList()
{
    qualification->getQualificationList(qList);
}

void QualificationInitController::createStudent(Student &student){
    database->createStudent(student);
}
void QualificationInitController::goToStudentProjectRegisterView()
{
    qualification->close();
    studentProjectRegisterView view;
    view.exec();

}
