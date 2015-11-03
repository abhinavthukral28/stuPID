#include "createprojectview.h"
#include "ui_createprojectview.h"

CreateProjectView::CreateProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProjectView)
{
    ui->setupUi(this);
}

CreateProjectView::~CreateProjectView()
{
    delete ui;
}
