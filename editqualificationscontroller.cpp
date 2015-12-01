#include <QString>
#include "studentprojectregisterview.h"
#include <QDebug>
#include "EditQualificationsController.h"
#include <QList>
#include "qualification.h"
#include "Database.h"
#include "session.h"

EditQualificationsController::EditQualificationsController( EditQualificationsView *qual): QObject(), editQualificationsView(qual), database(Database::getInstance())


{
  qList = database->getAllQualifications(-1);
  stu = Session::getStudent();


}
Student EditQualificationsController::getStudent()
{
    return stu;
}

void EditQualificationsController::createStudent(Student &student){
    database->createStudent(student);
}
