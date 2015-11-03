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
 }


ManageProjectsView::~ManageProjectsView()
{
    delete ui;
}




int ManageProjectsView::updateDetailedView(Project &project)
{
  ui->projectName->setText(project.getTitle());
  ui->projectDescription->setText(project.getDescription());
  for(int i=0; i<project.getRegisteredStudents().count();i++)
  {
      //QList<Students>* temp =project.getRegisteredStudents();
      ui->viewTextBrowser->setText(project.getRegisteredStudents(i));

  }
}


void ManageProjectsView::on_projectsList_clicked(const QModelIndex &index)
{
    int indexVal = index.row();

   manageProjectsController->updateSelectedProject(indexVal);


}
