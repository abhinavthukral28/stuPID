#include "studentmanageprojectview.h"
#include "ui_studentmanageprojectview.h"
#include "project.h"
#include "student.h"
#include <QDebug>
#include "studentmanageprojectcontroller.h"
#include "studentregistercontroller.h"
#include "editqualificationsview.h"
StudentManageProjectView::StudentManageProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentManageProjectView),
    studentManageProjectController(new StudentManageProjectController(this))
{
    ui->setupUi(this);

    if(studentManageProjectController->init())
    {
       ui->listWidget->setCurrentRow(0);
    }
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
  ui->ProjectTitle->setText(project.getTitle());
}


void StudentManageProjectView::on_listWidget_clicked(const QModelIndex &index)
{
    int indexValue= index.row();
    studentManageProjectController->updateSelectedProject(indexValue);

}

void StudentManageProjectView::on_dropProject_clicked()
{
    int index = ui->listWidget->currentIndex().row();
   if(studentManageProjectController->unregisterFromProject()){

       delete ui->listWidget->takeItem(index);
       ui->listWidget->setCurrentRow(0);
       studentManageProjectController->updateSelectedProject(0);
       if(ui->listWidget->count()==0)
       {
           ui->ProjectTitle->setText("Project Title");
           ui->descriptionView->clear();
       }
   }

}
void StudentManageProjectView::on_RegisterNewProject_clicked()
{
    studentManageProjectController->goStudentRegisterProjectView();
}

void StudentManageProjectView::on_editProfile_clicked()
{

    this->close();
    EditQualificationsView view;
    view.exec();


}
