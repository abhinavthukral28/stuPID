#ifndef QUALIFICATIONINITCONTROLLER_H
#define QUALIFICATIONINITCONTROLLER_H
#include<QObject>
#include "qualificationinit.h"
#include<QList>
class QString;
class QualificationInit;
class Qualification;
class Database;
class QualificationInitController:public QObject

{
    Q_OBJECT
public:
    void setQualificationList();
    void createStudent(Student &student);
    void goToStudentProjectRegisterView();
    static QualificationInitController* getInstance();
    int setView(QualificationInit *view);

private:
    QualificationInit *qualification;
    QualificationInitController();

    Database *database;
    QList<Qualification*> qList;
    static QualificationInitController *instance;

};

#endif // LOGINTCONTROLLER_H
