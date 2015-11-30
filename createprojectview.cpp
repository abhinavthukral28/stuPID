#include "createprojectview.h"
#include "ui_createprojectview.h"
#include "createprojectviewcontroller.h"
#include <QDebug>
#include <QMessageBox>

CreateProjectView::CreateProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProjectView),
    createProjectViewController(new CreateProjectViewController(this))
{
    ui->setupUi(this);
}

CreateProjectView::~CreateProjectView()
{
    delete ui;
}

const QString CreateProjectView::getProjectDescription()
 {
     aDescription = ui->projectDescriptionTextFeild->toPlainText();
     //vinisha
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
   // createProjectViewController->setNewProjectTeamMin(b);
    return ref3;
    /*
    int b =ui->minTeamSizeTextFeild->text().toInt();
    int& ref3=b;
   // createProjectViewController->setNewProjectTeamMin(b);
    return ref3;
    */

}



const int& CreateProjectView::getProjectTeamMax()
{
    aMax = ui->maxTeamSizeTextFeild->text();
    int x = aMax.toInt();
    int &ref4=x;
    //createProjectViewController->setNewProjectTeamMax(x);
    return ref4;
    //vinisha
    /*
    int x =ui->maxTeamSizeTextFeild->text().toInt();
    int &ref4=x;
    //createProjectViewController->setNewProjectTeamMax(x);
    return ref4;
    */
}




void CreateProjectView::on_buttonBox_accepted()
{
    switch(createProjectViewController->saveProject())
    {
        case 0:
        {
           //createProjectViewController->saveProject();
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
                                 tr("Please enter correct infromation!"),
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
