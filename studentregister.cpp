#include "studentregister.h"
#include "ui_studentregister.h"
#include "studentregistercontroller.h"
#include "student.h"

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
    

    QString userName = ui->userName->text();
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    Student *student = new Student(userName);
    student->setFirstName(firstName);
    student->setLastName(lastName);
    controller->goToQualificationsView(*student);

    
}
