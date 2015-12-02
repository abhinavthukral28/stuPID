#ifndef QUALIFICATIONINITCONTROLLER_H
#define QUALIFICATIONINITCONTROLLER_H
#include<QObject>
#include "editqualificationsview.h"
#include<QList>
#include"student.h"
class QString;
class EditQualificationsView;
class Qualification;
class Database;
class EditQualificationsController:public QObject

{
    Q_OBJECT
public:
    EditQualificationsController(EditQualificationsView *qual);


     EditQualificationsView *editQualificationsView;
     Student getStudent();
     void updateQualifications(Student &student);

 private:
     Database *database;
     QList<Qualification*> qList;
     Student stu;
};

#endif // LOGINTCONTROLLER_H
