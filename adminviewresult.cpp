#include "adminviewresult.h"
#include "ui_adminviewresult.h"
#include "logindialog.h"

AdminViewResult::AdminViewResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminViewResult),
    adminViewResultController(new AdminViewResultController(this))
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
