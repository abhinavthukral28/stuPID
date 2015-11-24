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
