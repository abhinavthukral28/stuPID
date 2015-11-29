#include "studentmanageprojectview.h"
#include "ui_studentmanageprojectview.h"
#include "project.h"
#include "student.h"
#include <QDebug>
#include "studentmanageprojectcontroller.h"
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
//  QString a= "hello";

/*
  for(int i=0; i<project.getRegisteredStudents().count();i++)
  {

      temp += project.getRegisteredStudents().at(i)->getUsername() + "  ";

      ui->viewTextBrowser->setText(temp);

  }
  */
}


void StudentManageProjectView::on_listWidget_clicked(const QModelIndex &index)
{
    int indexValue= index.row();
    studentManageProjectController->updateSelectedProject(indexValue);

}
