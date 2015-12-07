#include <QString>
#include "studentprojectregisterview.h"
#include <QDebug>
#include "editqualificationscontroller.h"
#include <QList>
#include "qualification.h"
#include "Database.h"
#include "session.h"

EditQualificationsController *EditQualificationsController::instance=0;
EditQualificationsController::EditQualificationsController(): QObject(), database(Database::getInstance())


{
  qList = database->getAllQualifications(-1);
  stu = Session::getStudent();


}
Student EditQualificationsController::getStudent()
{
    return stu;
}

void EditQualificationsController::updateQualifications(Student &student){
    for (int i = 0; i < student.getQualifications().count(); i++)
     database->updateQualification(student.getID(),*student.getQualifications().at(i));
}

int EditQualificationsController::setView(EditQualificationsView *view){
    editQualificationsView=view;
}

EditQualificationsController* EditQualificationsController::getInstance(){

    if(!EditQualificationsController::instance){

        EditQualificationsController::instance = new EditQualificationsController();
    }
    return EditQualificationsController::instance;

}
