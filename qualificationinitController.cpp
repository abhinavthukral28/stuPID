#include <QString>
#include "studentprojectregisterview.h"
#include <QDebug>
#include "qualificationinitController.h"
#include <QList>
#include "qualification.h"
#include "session.h"
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
    for (int i = 0; i < student.getQualifications().count(); i++)
     database->createQualificationEntry(student.getID(),*student.getQualifications().at(i));
}
void QualificationInitController::goToStudentProjectRegisterView()
{

    qualification->close();
    studentProjectRegisterView view;
    view.exec();

}
