#include "studentprojectregisterview.h"
#include "ui_studentprojectregisterview.h"
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>
#include "session.h"
#include "project.h"
#include "studentprojectregisterviewcontroller.h"

studentProjectRegisterView::studentProjectRegisterView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentProjectView),
    studentProjectRegisterViewController(new studentprojectregisterviewcontroller(this))
{   
    ui->setupUi(this);
    if(studentProjectRegisterViewController->init())
    {
        ui->projectsList->setCurrentRow(0);
    }
}

studentProjectRegisterView::~studentProjectRegisterView()
{
    delete ui;
}

int studentProjectRegisterView::updateProjectsList(QList<QString> &projectTitles)
{
    QString temp;
    for (int i = 0; i <projectTitles.count();i++)
    {
       temp =projectTitles.at(i);
       ui->projectsList->addItem(temp);
    }
    return 0;
}

int studentProjectRegisterView::updateDetailedView(Project &project)
{
    ui->projectName->setText(project.getTitle());
    ui->projectDescription->setText(project.getDescription());

    return 0;
}

void studentProjectRegisterView::on_registerButton_clicked()
{

    switch(studentProjectRegisterViewController->registerToProject()){
        case 0:
            QMessageBox::warning(this, tr("Warning"),
                                 tr("Already registered!"),
                                 QMessageBox::Yes);
            break;
        case 1:
            QMessageBox::information(this, tr("Success"),
                                 tr("Successfully registered!"),
                                 QMessageBox::Yes);
            break;

        case 2:
            QMessageBox::warning(this, tr("Warning"),
                                 tr("Select a project!"),
                                 QMessageBox::Yes);
            break;

    }


}


void studentProjectRegisterView::on_manageProjectButton_clicked()
{
    studentProjectRegisterViewController->goStudentManageProjectView();
}

void studentProjectRegisterView::on_projectsList_clicked(const QModelIndex &index)
{
    int indexVal = index.row();
    studentProjectRegisterViewController->updateSelectedProject(indexVal);
}
