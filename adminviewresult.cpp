#include "adminviewresult.h"
#include "ui_adminviewresult.h"
#include "logindialog.h"

AdminViewResult::AdminViewResult(AdminViewResultController *newController) :
    QDialog(),
    ui(new Ui::AdminViewResult),
    adminViewResultController(newController)
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

void AdminViewResult::on_pushButton_clicked()
{

}
