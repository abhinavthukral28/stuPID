#include "pcibuilder.h"
#include "student.h"
#include "qualification.h"
#include <stdlib.h>
#include <QDebug>
PciBuilder::PciBuilder()
{

}

QMap<int, QList< QPair<int,int> >* >& PciBuilder::calculatePci(const QList<Student*>& studentList)
{

    //student id -> student id -> pci
    QMap<int, QList < QPair<int,int> >* >* pci = new QMap<int, QList < QPair<int,int> >* >;
    for (int i = 0; i < studentList.count(); i++)
    {


        Student* thisOne = studentList.at(i);
        qDebug () << "Measuring student..." << thisOne->getID();
        QList< QPair<int,int> >* val = new QList< QPair<int,int> >();
        int tempResult;
        for (int j = 0; j < studentList.count(); j++)
        {   
            if (j != i) {
                Student* otherOne = studentList.at(j);
                qDebug () << "Measuring with " << otherOne->getID();
                QPair<int,int> pair;
                //results processing master list
                tempResult = calculatePci(*thisOne,*otherOne);
                qDebug () << "Got pci -> " << tempResult;
                pair.first = otherOne->getID() ;
                pair.second = tempResult;
                qDebug () << "Storing pair as " << pair.first << " as other student id and " << pair.second << " as pci";
                insert(val,pair);
                 qDebug () << "Inserted! Current list: ";

                 for (int k = 0; k < val->count(); k++)
                 {
                     qDebug() << val->at(k).first << " key, " << val->at(k).second << " pci";
                 }


            }
        }
        qDebug () << "Final list stored for student " << thisOne->getID();
        for (int k = 0; k < val->count(); k++)
        {
            qDebug() << val->at(k).first << " key, " << val->at(k).second << " pci";
        }

        pci->insert(thisOne->getID(),val);

    }
    qDebug () <<"total number of students"<< pci->keys().count();

    for (int i = 0; i < pci->keys().count(); i++)
    {
        QList< QPair<int,int> >* pair = pci->value(pci->keys().at(i));
        qDebug() <<"count of students measured with "<< pair->count();
        qDebug () <<"This student ID "<< pci->keys().at(i);
        for (int j = 0; j < pair->count(); j++){
            qDebug() <<"Other student ID"<< pair->at(j).first;
            qDebug() <<"Pci"<< pair->at(j).second;
        }
    }
    return *pci;
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
//    results processing...
    return total;


}

int PciBuilder::calculatePci(const Qualification& q1, const Qualification& q2)
{
   return abs(q2.getExpectationRating() - q1.getQualificationRating())
           + abs(q1.getExpectationRating() - q2.getQualificationRating())
           + 2* abs(q1.getExpectationRating()- q2.getExpectationRating());
}


bool PciBuilder::insert(QList<QPair<int,int> >* pci,const QPair<int,int>& pair){
    qDebug() << "Trying to insert pair with pci of " << pair.second;
    bool inserted = false;
    for (int i = 0; i < pci->count() && !inserted; i++)
    {
        qDebug () << "Current pci in list " << pci->at(i).second;
        if (pci->at(i).second >= pair.second)
        {
            qDebug () << "Found a pci greater than or equal to " << pair.second;
            qDebug () << "That pci is " << pci->at(i).second;

            if (i > 0)
            {
                qDebug () << " index is greater than 0; " << i;
                qDebug () << " inserting at " << (i-1);
                pci->insert(i,pair);
                inserted = true;
            }
            else break;
        }

        if (i+1 == pci->count() && !inserted)
        {

            qDebug () << " inserting pair at end ";
            pci->append(pair);
            inserted = true;
        }
    }

    if (!inserted)
    {
        qDebug () << " Inserted at index 0";
        pci->insert(0,pair);
    }

    return inserted;
}


