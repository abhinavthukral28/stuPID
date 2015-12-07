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
     Student getStudent();
     void updateQualifications(Student &student);


     static EditQualificationsController* getInstance();
     int setView(EditQualificationsView *view);

 private:
     EditQualificationsController();
     EditQualificationsView *editQualificationsView;
     static EditQualificationsController *instance;

     Database *database;
     QList<Qualification*> qList;
     Student stu;
};

#endif // LOGINTCONTROLLER_H
