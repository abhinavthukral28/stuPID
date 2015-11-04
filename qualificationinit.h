#ifndef QUALIFICATIONINIT_H
#define QUALIFICATIONINIT_H
#include "student.h"
#include <QDialog>
class QualificationInitController;
namespace Ui {
class qualificationinit;
}

class QualificationInit : public QDialog
{
    Q_OBJECT

public:
    explicit QualificationInit(Student &student);
    ~QualificationInit();



private:
    Ui::qualificationinit *ui;
    QualificationInitController *controller;
    Student newStudent;
};

#endif // QUALIFICATIONINIT_H
