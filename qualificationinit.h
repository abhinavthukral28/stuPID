#ifndef QUALIFICATIONINIT_H
#define QUALIFICATIONINIT_H
#include "student.h"
#include <QDialog>
class QualificationInitController;
class QString;
namespace Ui {
class qualificationinit;
}

class QualificationInit : public QDialog
{
    Q_OBJECT

public:
    explicit QualificationInit(Student &student);
    ~QualificationInit();



private slots:
    void on_NextButton_clicked();

private:
    Ui::qualificationinit *ui;
    QualificationInitController *controller;
    Student newStudent;
    QList<QString> keyList,q,e;
    int activeIndex;
};

#endif // QUALIFICATIONINIT_H
