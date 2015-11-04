#include "manageprojectsview.h"
#include "ui_manageprojectsview.h"
#include "project.h"
#include "manageprojectscontroller.h"
#include "student.h"

ManageProjectsView::ManageProjectsView(QWidget *parent) :QDialog(parent),
    ui(new Ui::ManageProjectsView),
    manageProjectsController(new ManageProjectsController(this))

{
    ui->setupUi(this);

    manageProjectsController->init();

    ui->projectName->setText("Project Name");
    ui->projectDescription->setText("Project Description");
    ui->viewTextBrowser->setText("view students or view details or view results");

}


 int ManageProjectsView::updateProjectsList(QList<QString> &projectTitles){
     QString temp;
     for (int i = 0; i <projectTitles.count();i++)
     {
         temp =projectTitles.at(i);
        ui->projectsList->addItem(temp);
     }
    // manageProjectsController->updateSelectedProject(0);

 }


ManageProjectsView::~ManageProjectsView()
{
    delete ui;
}




int ManageProjectsView::updateDetailedView(Project &project)
{
  ui->projectName->setText(project.getTitle());
  ui->projectDescription->setText(project.getDescription());
  QString a= "hello";
   QString temp;

  for(int i=0; i<project.getRegisteredStudents().count();i++)
  {

      temp += project.getRegisteredStudents().at(i)->getUsername() + "  ";

      ui->viewTextBrowser->setText(temp);

  }
}


void ManageProjectsView::on_projectsList_clicked(const QModelIndex &index)
{


    int indexVal = index.row();

   manageProjectsController->updateSelectedProject(indexVal);


}

int ManageProjectsView::setStudentList(Project &project){
QString temp;
    for(int i=0; i<project.getRegisteredStudents().count();i++)
    {
        temp += project.getRegisteredStudents().at(i)->getUsername() + " ";
        ui->viewTextBrowser->setText(temp);


    }

}



void ManageProjectsView::on_ViewStudentButton_clicked()
{
    //int indexVal = index.row();

    manageProjectsController->updateStudentList();




}


void ManageProjectsView::on_viewDetailButton_clicked()
{
    ui->viewTextBrowser->setText("coming soon");
}

void ManageProjectsView::on_viewResultButton_clicked()
{
    ui->viewTextBrowser->setText("coming soon");
}
