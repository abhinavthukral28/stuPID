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
    studentProjectRegisterViewController->init();
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
    QListWidgetItem *item = ui->projectsList->currentItem();

    int index = item->listWidget()->currentIndex().row();

    //item->setTextColor(Qt::red);

    if (!studentProjectRegisterViewController->registerToProject())
    {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Already registered!"),
                             QMessageBox::Yes);
    }else {
        QMessageBox::information(this, tr("Success"),
                             tr("Successfully registered!"),
                             QMessageBox::Yes);

    }//do whatever

}

void studentProjectRegisterView::on_projectsList_doubleClicked(const QModelIndex &index)
{
    int indexVal = index.row();
    studentProjectRegisterViewController->updateSelectedProject(indexVal);
}



void studentProjectRegisterView::on_manageProjectButton_clicked()
{
    studentProjectRegisterViewController->goStudentManageProjectView();
}
