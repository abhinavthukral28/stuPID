#include "qualificationinit.h"
#include "ui_qualificationinit.h"
#include "qualificationinitController.h"
#include "student.h"
#include <QDebug>
QualificationInit::QualificationInit(Student &student) :
    QDialog(),
    ui(new Ui::qualificationinit),
    controller(new QualificationInitController(this)),
    newStudent(student)


{
    ui->setupUi(this);
    keyList.append("Git");
    keyList.append("OO");
    keyList.append("GPA");
    keyList.append("WD");

    e.append("How much your partner gits");
    q.append("Do you do object oriented pogramming?");
    e.append("How much your partner knows");
    q.append("What's you CGPA");
    e.append("Parner's expected CGPA");
    q.append("Do you know web dev");
    e.append("How much does your partner know");
    activeIndex = 0;
    ui->keyLabel->setText(keyList.at(0));
    ui->NumberLabel->setText("1");
    ui->QuesTopLabel->setText(q.at(0));
    ui->QuesDownLabel->setText(e.at(0));
}

QualificationInit::~QualificationInit()
{
    delete ui;
}




void QualificationInit::on_NextButton_clicked()
{

    activeIndex += 1;
    if(activeIndex >= keyList.length()){

    }
    else{
        qDebug() << activeIndex;

        ui->keyLabel->setText(keyList.at(activeIndex));
        ui->NumberLabel->setText(QString::number(activeIndex));
        ui->QuesTopLabel->setText(q.at(activeIndex));
        ui->QuesDownLabel->setText(e.at(activeIndex));
    }
}
