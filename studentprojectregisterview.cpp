#include "studentprojectregisterview.h"
#include "ui_studentprojectregisterview.h"
#include <QDebug>
#include <QListWidgetItem>
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
    item->setTextColor(Qt::red);

}

void studentProjectRegisterView::on_projectsList_doubleClicked(const QModelIndex &index)
{
    ui->projectsList->currentIndex();
    ui->projectDescription->setText("Hello I am project "+ index.data(Qt::DisplayRole).toString());

}



void studentProjectRegisterView::on_manageProjectButton_clicked()
{
    studentProjectRegisterViewController->goStudentManageProjectView();
}
