#include "editqualificationsview.h"
#include "ui_editqualificationsview.h"
#include "session.h"
#include "studentmanageprojectview.h"
EditQualificationsView::EditQualificationsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editQualificationsView),
    controller(new EditQualificationsController(this))
{
    ui->setupUi(this);
    stu = controller->getStudent();
    qualificationList = stu.getQualifications();

    for(int i=0; i< qualificationList.count(); i++)
    {
        ui->listWidget->addItem(qualificationList[i]->getTitle());
    }

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
    ui->listWidget->setCurrentRow(0);
    this->updatePanel(0);
}

EditQualificationsView::~EditQualificationsView()
{
    delete ui;
}

void EditQualificationsView::updatePanel(int index){
    ui->QuesTopLabel->setText(qualificationList.at(index)->getQualificationDisplay());
    ui->QuesDownLabel->setText(qualificationList.at(index)->getExpectationDisplay());

    switch(qualificationList.at(index)->getQualificationRating()){
    case 1:
        ui->qB1->setChecked(true);
        break;
    case 2:
        ui->qB2->setChecked(true);
        break;
    case 3:
        ui->qB3->setChecked(true);
        break;
    case 4:
        ui->qB4->setChecked(true);
        break;
    case 5:
        ui->qB5->setChecked(true);
        break;
    default:
        break;
    }
    switch(qualificationList.at(index)->getExpectationRating()){
    case 1:
        ui->eB1->setChecked(true);
        break;
    case 2:
        ui->eB2->setChecked(true);
        break;
    case 3:
        ui->eB3->setChecked(true);
        break;
    case 4:
        ui->eB4->setChecked(true);
        break;
    case 5:
        ui->eB5->setChecked(true);
        break;
    default:
        break;
    }
    previousIndex = index;



}

void EditQualificationsView::on_listWidget_clicked(const QModelIndex &index)
{
    qualificationList.at(previousIndex)->setQualificationRating(ui->qualificationButtonGroup->checkedId());
    qualificationList.at(previousIndex)->setExpectationRating(ui->expectationButtonGroup->checkedId());

    int i = index.row();
    updatePanel(i);

}


void EditQualificationsView::on_NextButton_clicked()
{
    qualificationList.at(previousIndex)->setQualificationRating(ui->qualificationButtonGroup->checkedId());
    qualificationList.at(previousIndex)->setExpectationRating(ui->expectationButtonGroup->checkedId());

    controller->updateQualifications(stu);
    this->on_NextButton_2_clicked();
}

void EditQualificationsView::on_NextButton_2_clicked()
{
    this->close();
    StudentManageProjectView view;
    view.exec();

}
