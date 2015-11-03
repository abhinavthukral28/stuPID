#include "studentregister.h"
#include "ui_studentregister.h"
#include "studentregistercontroller.h"

StudentRegister::StudentRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentRegister),
    controller(new StudentRegisterController(this))
{
    ui->setupUi(this);
}

StudentRegister::~StudentRegister()
{
    delete ui;
}

void StudentRegister::on_pushButton_clicked()
{
    controller->goToQualificationsView();
}
