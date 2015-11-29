#include "studentmanageprojectview.h"
#include "ui_studentmanageprojectview.h"
#include "project.h"
#include "student.h"
#include <QDebug>
#include "studentmanageprojectcontroller.h"
#include "studentregistercontroller.h"

StudentManageProjectView::StudentManageProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentManageProjectView),
    studentManageProjectController(new StudentManageProjectController(this))
{
    ui->setupUi(this);

    studentManageProjectController->init();
}

StudentManageProjectView::~StudentManageProjectView()
{
    delete ui;
}

int StudentManageProjectView::updateProjectsList(QList<QString> &projectTitles){
    QString temp;
    for (int i = 0; i <projectTitles.count();i++)
    {
        temp =projectTitles.at(i);
        qDebug() << temp + "THIS";

        ui->listWidget->addItem(temp);
    }
    return 1;
   //manageProjectsController->updateSelectedProject(0);

}

int StudentManageProjectView::updateDetailedView(Project &project)

{
  QString num1;
  num1.setNum(project.getMinTeamSize());
  QString num2;
  num2.setNum(project.getMaxTeamSize());
  QString tempsStorage= "Description:"+ project.getDescription() + "\nMinimum Team Size: "+ num1 + "\nMaximum Team Size: " + num2;
  ui->descriptionView->setText(tempsStorage);

}


void StudentManageProjectView::on_listWidget_clicked(const QModelIndex &index)
{
    int indexValue= index.row();
    studentManageProjectController->updateSelectedProject(indexValue);

}

void StudentManageProjectView::on_dropProject_clicked()
{
   //studentManageProjectController-
}
void StudentManageProjectView::on_RegisterNewProject_clicked()
{
    studentManageProjectController->goStudentRegisterProjectView();
}
