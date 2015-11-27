#include "adminviewdetial.h"
#include "ui_adminviewdetial.h"

AdminViewDetial::AdminViewDetial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminViewDetial)
{
    ui->setupUi(this);
}

AdminViewDetial::~AdminViewDetial()
{
    delete ui;
}

void AdminViewDetial::on_BackButton_clicked()
{

}
