#include "qualificationinit.h"
#include "ui_qualificationinit.h"
#include "qualificationinitController.h"
#include "student.h"
#include "session.h"
#include <QDebug>
#include "qualification.h"
QualificationInit::QualificationInit() :
        QDialog(),
        ui(new Ui::qualificationinit),
        controller(QualificationInitController::getInstance()),
        newStudent(Session::getStudent())


{
    controller->setView(this);
    ui->setupUi(this);
    controller->setQualificationList();
    activeIndex = 0;
    //Inistialization
    ui->keyLabel->setText(qualificationList.at(0)->getTitle());
    ui->NumberLabel->setText("1");
    ui->QuesTopLabel->setText(qualificationList.at(0)->getQualificationDisplay());
    ui->QuesDownLabel->setText(qualificationList.at(0)->getExpectationDisplay());
    //Setting the radio buttons
    ui->qualificationButtonGroup->setId(ui->qB1, 1);
    ui->qualificationButtonGroup->setId(ui->qB2, 2);
    ui->qualificationButtonGroup->setId(ui->qB3, 3);
    ui->qualificationButtonGroup->setId(ui->qB4, 4);
    ui->qualificationButtonGroup->setId(ui->qB5, 5);
    //Setting expectation radio buttons
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
    //saving the qualification values
    qualificationList.at(activeIndex)->setQualificationRating(ui->qualificationButtonGroup->checkedId());
    qualificationList.at(activeIndex)->setExpectationRating(ui->expectationButtonGroup->checkedId());

    activeIndex += 1;
    if(activeIndex >= qualificationList.count()){
        newStudent.qualifications = qualificationList;
        controller->createStudent(newStudent);
        controller->goToStudentProjectRegisterView();

    }
    else{
        //Change the button to submit on the last question
        if(activeIndex == qualificationList.count() - 1){
            ui->NextButton->setText("Submit");
        }
        //Change the question to the next one
        ui->keyLabel->setText(qualificationList.at(activeIndex)->getTitle());
        ui->NumberLabel->setText(QString::number(activeIndex + 1));
        ui->QuesTopLabel->setText(qualificationList.at(activeIndex)->getQualificationDisplay());
        ui->QuesDownLabel->setText(qualificationList.at(activeIndex)->getExpectationDisplay());
    }
}
