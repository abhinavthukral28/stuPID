#include "createprojectview.h"
#include "ui_createprojectview.h"
#include "createprojectviewcontroller.h"
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

 void CreateProjectView::getProjectDescription()
 {
 QString s =ui->projectDescriptionTextFeild->toPlainText();
 createProjectViewController->setNewProjectDescription(s);
 }

void CreateProjectView::getProjectTitle(){
    QString a =ui->projectNameTextFeild->text();
    createProjectViewController->setNewProjectTitle(a);
}

void CreateProjectView::getProjectTeamMin(){
    int b =ui->minTeamSizeTextFeild->text().toInt();
    createProjectViewController->setNewProjectTeamMin(b);
}



void CreateProjectView::getProjectTeamMax(){
    int x =ui->maxTeamSizeTextFeild->text().toInt();
    createProjectViewController->setNewProjectTeamMax(x);

}

