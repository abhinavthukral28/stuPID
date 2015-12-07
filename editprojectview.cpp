#include "editprojectview.h"
#include "ui_editprojectview.h"
#include "editprojectcontroller.h"

EditProjectView::EditProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProjectView),
    editProjectController(EditProjectController::getInstance())
{
    editProjectController->setView(this);
    ui->setupUi(this);
}

EditProjectView::~EditProjectView()
{
    delete ui;
}

void EditProjectView::on_buttonBox_accepted()
{

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

void EditProjectView::accept(){

}
    ;


