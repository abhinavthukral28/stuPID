#ifndef PCIBUILDER_H
#define PCIBUILDER_H

#include <QList>
#include <QMap>
#include <QPair>

class Student;
class Qualification;
class PciBuilder
{
   private:
    int calculatePci(const Student& studentOne,const Student& studentTwo);
    bool insert(QList<QPair<int,int> >* pci,const QPair<int,int>&);
public:
    PciBuilder();
    QMap<int, QList< QPair<int,int> >* >& calculatePci(const QList<Student*>&);
    int calculatePci(const Qualification& q1,const Qualification& q2);

};

#endif // PCIBUILDER_H
