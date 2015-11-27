#include "studentmanageprojectview.h"
#include "ui_studentmanageprojectview.h"
#include "project.h"
#include "student.h"
#include <QDebug>
#include "studentmanageprojectcontroller.h"
StudentManageProjectView::StudentManageProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentManageProjectView),
    studentManageProjectController(new StudentManageProjectController(this))
{
    ui->setupUi(this);

    studentManageProjectController->init();
}

StudentManageProjectView::~StudentManageProjectView()
{
    delete ui;
}

int StudentManageProjectView::updateProjectsList(QList<QString> &projectTitles){
    QString temp;
    for (int i = 0; i <projectTitles.count();i++)
    {
        temp =projectTitles.at(i);
        qDebug() << temp + "THIS";

        ui->listWidget->addItem(temp);
    }
    return 1;
   // manageProjectsController->updateSelectedProject(0);

}
