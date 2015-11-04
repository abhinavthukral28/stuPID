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
    QualificationInitController(QualificationInit *qual);


    QualificationInit *qualification;
     void setQualificationList();

 private:
     Database *database;
     QList<Qualification*> qList;
};

#endif // LOGINTCONTROLLER_H
