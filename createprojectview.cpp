#include "createprojectview.h"
#include "ui_createprojectview.h"
#include "createprojectviewcontroller.h"
#include <QDebug>

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
     QString desc = ui->projectDescriptionTextFeild->toPlainText();
     return desc;

 }

const QString CreateProjectView::getProjectTitle(){
    QString title =ui->projectNameTextFeild->text();

    return title;
}

const int& CreateProjectView::getProjectTeamMin(){
    int b =ui->minTeamSizeTextFeild->text().toInt();
    int& ref3=b;

   // createProjectViewController->setNewProjectTeamMin(b);
    return ref3;
}



const int& CreateProjectView::getProjectTeamMax()
{
    int x =ui->maxTeamSizeTextFeild->text().toInt();
    int &ref4=x;
    //createProjectViewController->setNewProjectTeamMax(x);
    return ref4;
}


void CreateProjectView::on_buttonBox_clicked(QAbstractButton *button)
{
    createProjectViewController->saveProject();
}
