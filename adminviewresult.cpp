#include "adminviewresult.h"
#include "ui_adminviewresult.h"

AdminViewResult::AdminViewResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminViewResult)
{
    ui->setupUi(this);

}

AdminViewResult::~AdminViewResult()
{
    delete ui;
}

void AdminViewResult::on_BackButton_clicked()
{

}
