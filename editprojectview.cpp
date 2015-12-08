#include "editprojectview.h"
#include "ui_editprojectview.h"
#include "editprojectcontroller.h"
#include "project.h"
#include "Database.h"
#include "logindialog.h"
#include "QDebug"
#include "manageprojectsview.h"

EditProjectView::EditProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProjectView),
    editProjectController(EditProjectController::getInstance()),
    database(Database::getInstance())
{
    editProjectController->setView(this);
    ui->setupUi(this);
}

EditProjectView::~EditProjectView()
{
    delete ui;
}



const QString EditProjectView::getProjectDescription()
 {
     aDescription = ui->projectDescriptionTextFeild->toPlainText();
     QString desc = ui->projectDescriptionTextFeild->toPlainText();
     return desc;

 }

const QString EditProjectView::getProjectTitle(){
    aTitle = ui->projectNameTextFeild->text();
    //vinisha
    QString title =ui->projectNameTextFeild->text();
    return title;
}

const int& EditProjectView::getProjectTeamMin(){

    aMin = ui->minTeamSizeTextFeild->text();
    int b =aMin.toInt();
    int& ref3=b;
    return ref3;

}



const int& EditProjectView::getProjectTeamMax()
{
    aMax = ui->maxTeamSizeTextFeild->text();
    int x = aMax.toInt();
    int &ref4=x;
    return ref4;
}

int EditProjectView::updateView(Project *project){
    editProjectController->initValues(project);
 ui->projectNameTextFeild->setText(project->getTitle());
 ui->projectDescriptionTextFeild->setText(project->getDescription());

 QString num1;
 num1.setNum(project->getMinTeamSize());
 QString num2;
 num2.setNum(project->getMaxTeamSize());
 ui->maxTeamSizeTextFeild->setText(num2);
 ui->minTeamSizeTextFeild->setText(num1);

}

void EditProjectView::on_pushButton_2_clicked()
{
    if(editProjectController->saveProject())
    {
        this->close();
        ManageProjectsView view;
        view.exec();
    }
   qDebug()<< "it clicked";

}


void EditProjectView::on_pushButton_3_clicked()
{
    this->close();
    ManageProjectsView view;
    view.exec();
}


