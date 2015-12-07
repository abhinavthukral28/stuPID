#include "editprojectview.h"
#include "ui_editprojectview.h"

EditProjectView::EditProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProjectView)
{
    ui->setupUi(this);
}

EditProjectView::~EditProjectView()
{
    delete ui;
}

void EditProjectView::on_buttonBox_accepted()
{

}
