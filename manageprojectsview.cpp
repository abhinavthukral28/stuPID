#include "manageprojectsview.h"
#include "ui_manageprojectsview.h"
#include "project.h"
#include "manageprojectscontroller.h"
#include "student.h"
#include <QDialog>


ManageProjectsView::ManageProjectsView(QWidget *parent) :QDialog(parent),
    ui(new Ui::ManageProjectsView),
    manageProjectsController(ManageProjectsController::getInstance())

{
    manageProjectsController->setView(this);
    ui->setupUi(this);


    ui->projectName->setText("Project Name");
    ui->projectDescription->setText("Project Description");
    ui->viewTextBrowser->setText("view students or view details or view results");
    QPixmap  pixmap ;
    int w = ui->image->width();
    int h = ui->image->height();
    pixmap.load(":/images/carleton.jpeg");
    ui->image->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));

    if(manageProjectsController->init())
    {
        ui->projectsList->setCurrentRow(0);

    }

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
    QString title="Title: "+project.getTitle();
    QString description="Description: " +project.getDescription();
  ui->projectName->setText(title);
  ui->projectDescription->setText(description);
  //QString a= "hello";
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

int ManageProjectsView::setDetailedView(Project &project)
{
    QString num1;
    num1.setNum(project.getMinTeamSize());
    QString num2;
    num2.setNum(project.getMaxTeamSize());
    QString tempsStorage= "Minimum Team Size: "+ num1 + "\nMaximum Team Size: " + num2;
    ui->viewTextBrowser->setText(tempsStorage);

}



void ManageProjectsView::on_ViewStudentButton_clicked()
{
    //int indexVal = index.row();

    manageProjectsController->updateStudentList();




}


void ManageProjectsView::on_viewDetailButton_clicked()
{
   manageProjectsController->updateDetailedView();
}

void ManageProjectsView::on_viewResultButton_clicked()
{
    ui->viewTextBrowser->setText("coming soon");
}

void ManageProjectsView::on_createProjectButton_clicked()
{
    manageProjectsController->goToCreateProjectView();
}

void ManageProjectsView::on_makeTeamsButton_clicked()
{

    manageProjectsController->makeTeams();
    QMessageBox::information(this, tr("Team Builder"),
                         tr("Teams Created!"),
                         QMessageBox::Ok);

}

void ManageProjectsView::on_pushButton_clicked()
{
    manageProjectsController->goToLoginDialog();
}
