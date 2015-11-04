#include "qualificationinit.h"
#include "ui_qualificationinit.h"
#include "qualificationinitController.h"
#include "student.h"
#include <QDebug>
#include "qualification.h"
QualificationInit::QualificationInit(Student &student) :
    QDialog(),
    ui(new Ui::qualificationinit),
    controller(new QualificationInitController(this)),
    newStudent(student)


{
    ui->setupUi(this);
    controller->setQualificationList();
    activeIndex = 0;

    //    keyList.append("Git");
    //    keyList.append("OO");
    //    keyList.append("GPA");
    //    keyList.append("WD");
    //    q.append("How musch do you git");
    //    e.append("How much your partner gits");
    //    q.append("Do you do object oriented pogramming?");
    //    e.append("How much your partner knows");
    //    q.append("What's you CGPA");
    //    e.append("Parner's expected CGPA");
    //    q.append("Do you know web dev");
    //    e.append("How much does your partner know");
    ui->keyLabel->setText(qualificationList.at(0)->getTitle());
    ui->NumberLabel->setText("1");
    ui->QuesTopLabel->setText(qualificationList.at(0)->getQualificationDisplay());
    ui->QuesDownLabel->setText(qualificationList.at(0)->getExpectationDisplay());

    ui->qualificationButtonGroup->setId(ui->qB1, 1);
    ui->qualificationButtonGroup->setId(ui->qB2, 2);
    ui->qualificationButtonGroup->setId(ui->qB3, 3);
    ui->qualificationButtonGroup->setId(ui->qB4, 4);
    ui->qualificationButtonGroup->setId(ui->qB5, 5);
    ui->expectationButtonGroup->setId(ui->eB1, 1);
    ui->expectationButtonGroup->setId(ui->eB2, 2);
    ui->expectationButtonGroup->setId(ui->eB3, 3);
    ui->expectationButtonGroup->setId(ui->eB4, 4);
    ui->expectationButtonGroup->setId(ui->eB5, 5);
}

QualificationInit::~QualificationInit()
{
    delete ui;
}

void QualificationInit::getQualificationList(const QList<Qualification*>& qList){
    qualificationList = qList;
}


void QualificationInit::on_NextButton_clicked()
{

    activeIndex += 1;
    if(activeIndex >= qualificationList.count()){

    }
    else{
        if(activeIndex == qualificationList.count() - 1){
            ui->NextButton->setText("Submit");
        }

        qDebug() << activeIndex;
        qDebug() << ui->qualificationButtonGroup->checkedId();
        qDebug() << ui->expectationButtonGroup->checkedId();

//        ui->keyLabel->setText(qualificationList.at(activeIndex)->getTitle());
//        ui->NumberLabel->setText(QString::number(activeIndex + 1));
//        ui->QuesTopLabel->setText(qualificationList.at(activeIndex)->getQualificationDisplay());
//        ui->QuesDownLabel->setText(qualificationList.at(activeIndex)->getExpectationDisplay());
    }
}
