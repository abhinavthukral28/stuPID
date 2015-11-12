#include "studentmanageprojectview.h"
#include "ui_studentmanageprojectview.h"

StudentManageProjectView::StudentManageProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentManageProjectView)
{
    ui->setupUi(this);
}

StudentManageProjectView::~StudentManageProjectView()
{
    delete ui;
}

void StudentManageProjectView::on_listView_doubleClicked(const QModelIndex &index)
{
    //int index = index.row();

   //studentmanageprojectviewcontroller->updateSelectedProject(index);
}

int StudentManageProjectView::updateProjectsList(QList<QString> &projectTitles){
     QString temp;
     for (int i = 0; i <projectTitles.count();i++)
     {
         temp =projectTitles.at(i);
        ui->projectsList->addItem(temp);
     }
    // manageProjectsController->updateSelectedProject(0);

 }
