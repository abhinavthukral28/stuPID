#ifndef QUALIFICATIONINITCONTROLLER_H
#define QUALIFICATIONINITCONTROLLER_H
#include<QObject>
#include "qualificationinit.h"
class QString;
class QualificationInit;
class QualificationInitController:public QObject
{
    Q_OBJECT
public:
    QualificationInitController(QualificationInit *qual);


    QualificationInit *qualification;
};

#endif // LOGINTCONTROLLER_H
