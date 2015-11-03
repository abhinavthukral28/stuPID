#ifndef QUALIFICATIONINITCONTROLLER_H
#define QUALIFICATIONINITCONTROLLER_H
#include<QObject>
#include "qualificationinit.h"
class QString;
class qualificationinit;
class qualificationinitController:public QObject
{
    Q_OBJECT
public:
    qualificationinitController(qualificationinit *qual);


    qualificationinit *qualification;
};

#endif // LOGINTCONTROLLER_H
