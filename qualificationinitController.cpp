#include <QString>
#include "studentprojectregisterview.h"
#include <QDebug>
#include "qualificationinitController.h"
#include <QList>
#include "qualification.h"
#include "session.h"
#include "Database.h"
#include "studentprojectregisterview.h"

QualificationInitController *QualificationInitController::instance=0;
QualificationInitController::QualificationInitController(): QObject(), database(Database::getInstance())


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

int QualificationInitController::setView(QualificationInit *view)
{
    qualification = view;
}

QualificationInitController* QualificationInitController::getInstance(){

    if(!QualificationInitController::instance){

        QualificationInitController::instance = new QualificationInitController();
    }
    return QualificationInitController::instance;

}
