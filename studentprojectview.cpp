#include "studentprojectview.h"
#include "ui_studentprojectview.h"

studentProjectView::studentProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentProjectView)
{
    ui->setupUi(this);
}

studentProjectView::~studentProjectView()
{
    delete ui;
}
