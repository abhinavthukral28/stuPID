#ifndef PCIBUILDER_H
#define PCIBUILDER_H

#include <QList>
#include <QMap>

class Student;
class Qualification;
class PciBuilder
{
   private:
    int calculatePci(const Student& studentOne,const Student& studentTwo);
    int calculatePci(const Qualification& q1,const Qualification& q2);
public:
    PciBuilder();
    QMap<int, QMap<int,int> >& calculatePci(const QList<Student*>&);

};

#endif // PCIBUILDER_H
