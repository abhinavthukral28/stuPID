#include "pcibuilder.h"
#include "student.h"
#include "qualification.h"
#include <stdlib.h>
#include<qdebug.h>
PciBuilder::PciBuilder()
{

}

QMap<int, QList< QPair<int,int> > >& PciBuilder::calculatePci(const QList<Student*>& studentList)
{

    //student id -> student id -> pci
    QMap<int, QList < QPair<int,int> > > pci;
    for (int i = 0; i < studentList.count(); i++)
    {


        Student* thisOne = studentList.at(i);

        int tempResult;
        for (int j = 0; j < studentList.count(); j++)
        {
            Student* otherOne = studentList.at(j);
            if (j != i) {
                QPair<int,int> pair;
                //results processing master list
                tempResult = calculatePci(*thisOne,*otherOne);

                pair.first = j ;
                pair.second = tempResult;
                QList< QPair<int,int> >* val = &pci.value(i);
                insert(val,pair);
                pci.insert(i,val);


            }



        }


    }
    return pci;
}


int PciBuilder::calculatePci(const Student& studentOne,const Student& studentTwo){

//get the qualification 
    
   const QList<Qualification*> personOneQuals = studentOne.getQualifications();
   const QList<Qualification*> personTwoQuals = studentTwo.getQualifications();
    int total= 0;

    for (int i = 0; i < personOneQuals.size();i++)
    {
//       qDebug << "Title: " + personOneQuals.at(i)->getTitle();
//       qDebug << "Student UserName:" + studentOne.getUsername();
//       qDebug << "q1 = " + personOneQuals.at(i)->getQualificationRating();
//       qDebug << "e1 = " + personOneQuals.at(i)->getQualificationRating();
       total+=calculatePci(*personOneQuals.at(i),*personTwoQuals.at(i));

    }
//    results processing...
    return total;


}

int PciBuilder::calculatePci(const Qualification& q1, const Qualification& q2)
{
   return abs(q2.getExpectationRating() - q1.getQualificationRating())
           - abs(q1.getExpectationRating() - q2.getQualificationRating())
           + 2* abs(q1.getExpectationRating()- q2.getExpectationRating());
}


bool PciBuilder::insert(QList<QPair<int,int> >& pci,const QPair<int,int>& pair){
    bool inserted = false;
    for (int i = 0; i < pci.count() && !inserted; i++)
    {
        if (pci.at(i).second > pair.second)
        {
            if (i > 0)
            {
                pci.insert(i-1,pair);
                inserted = true;
            }
            else break;
        }
    }

    if (!inserted)
        pci.insert(0,pair);

    return inserted;
}


