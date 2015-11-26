#ifndef PCIBUILDER_H
#define PCIBUILDER_H

#include <QList>
#include <QMap>

class Student;
class PciBuilder
{
   private:
    int calculatePci(Student studentOne, Student studentTwo);
public:
    PciBuilder();
    QMap<int, QMap<int,int> >& calculatePci(const QList<Student*>&);

};

#endif // PCIBUILDER_H
