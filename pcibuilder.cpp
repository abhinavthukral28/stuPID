#include "pcibuilder.h"
#include "student.h"
#include "qualification.h"
#include <stdlib.h>
PciBuilder::PciBuilder()
{

}

QMap<int, QMap<int,int> >& PciBuilder::calculatePci(const QList<Student*>& studentList)
{

    //student id -> student id -> pci
     const QMap<int, QMap<int,int> > pci;
    for (int i = 0; i < studentList.count(); i++)
    {


        Student* thisOne = studentList.at(i);

        int tempResult;
        for (int j = 0; j < studentList.count(); j++)
        {
            Student* otherOne = studentList.at(j);
            if (j != i) {
                //results processing master list
                tempResult = calculatePci(*thisOne,*otherOne);

            }



        }


//        Collections.sort(results);
//        for (Result result : results)
//        {
//            System.out.println ("ID: " +result.one.id + " ID:" + result.two.id);
//            System.out.println (result.score);
//        }

//        System.out.println();
//        System.out.println();

//        results.clear();
    }
}


int PciBuilder::calculatePci(const Student& studentOne,const Student& studentTwo){

//get the qualification 
    
   const QList<Qualification*> personOneQuals = studentOne.getQualifications();
   const QList<Qualification*> personTwoQuals = studentTwo.getQualifications();
    int total= 0;
   for (int i = 0; i < personOneQuals.size();i++)
    {
      total+=calculatePci(*personOneQuals.at(i),*personTwoQuals.at(i));
    }
    //results processing...
    return total;


}

int PciBuilder::calculatePci(const Qualification& q1, const Qualification& q2)
{
   return abs(q2.getExpectationRating() - q1.getQualificationRating())
           - abs(q1.getExpectationRating() - q2.getQualificationRating())
           + 2* abs(q1.getExpectationRating()- q2.getExpectationRating());
}


