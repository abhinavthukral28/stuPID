#ifndef QUALIFICATIONINIT_H
#define QUALIFICATIONINIT_H
#include "student.h"
#include <QDialog>
class QualificationInitController;
class Qualification;
class QString;
namespace Ui {
class qualificationinit;
}

class QualificationInit : public QDialog
{
    Q_OBJECT

public:
    explicit QualificationInit();
    ~QualificationInit();
    void getQualificationList(const QList<Qualification*>& qList);



private slots:
    void on_NextButton_clicked();

private:
    Ui::qualificationinit *ui;
    QualificationInitController *controller;
    Student newStudent;
    QList<QString> keyList,q,e;
    QList<Qualification*> qualificationList;
    int activeIndex;
};

#endif // QUALIFICATIONINIT_H
