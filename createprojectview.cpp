#include "createprojectview.h"
#include "ui_createprojectview.h"
#include "createprojectviewcontroller.h"
#include <QDebug>
#include <QMessageBox>

CreateProjectView::CreateProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProjectView),
    createProjectViewController(CreateProjectViewController::getInstance())
{

    createProjectViewController->setView(this);
    ui->setupUi(this);
}

CreateProjectView::~CreateProjectView()
{
    delete ui;
}

const QString CreateProjectView::getProjectDescription()
 {
     aDescription = ui->projectDescriptionTextFeild->toPlainText();
     QString desc = ui->projectDescriptionTextFeild->toPlainText();
     return desc;

 }

const QString CreateProjectView::getProjectTitle(){
    aTitle = ui->projectNameTextFeild->text();
    //vinisha
    QString title =ui->projectNameTextFeild->text();
    return title;
}

const int& CreateProjectView::getProjectTeamMin(){

    aMin = ui->minTeamSizeTextFeild->text();
    int b =aMin.toInt();
    int& ref3=b;
    return ref3;

}



const int& CreateProjectView::getProjectTeamMax()
{
    aMax = ui->maxTeamSizeTextFeild->text();
    int x = aMax.toInt();
    int &ref4=x;
    return ref4;
}




void CreateProjectView::on_buttonBox_accepted()
{
    switch(createProjectViewController->saveProject())
    {
        case 1:
        {
           createProjectViewController->goToManageProjectView();
           break;
        }

        case 3:
        {

            QMessageBox::warning(this, tr("Warning"),
                                 tr("Wrong team size!"),
                                 QMessageBox::Ok);
            break;
        }

        case 2:
        {

            QMessageBox::warning(this, tr("Warning"),
                                 tr("Please enter Project Name!"),
                                 QMessageBox::Ok);
            break;
         }
        default:
         {
            QMessageBox::warning(this, tr("Warning"),
                                 tr("Project already exist!"),
                                 QMessageBox::Ok);
            break;
        }
    }

}

void CreateProjectView::accept()
{

}

void CreateProjectView::on_buttonBox_rejected()
{
    createProjectViewController->goToManageProjectView();
}

void CreateProjectView::on_pushButton_clicked()
{
    createProjectViewController->goToLoginDialog();
}
