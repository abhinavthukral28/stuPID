#include "studentregister.h"
#include "ui_studentregister.h"
#include "studentregistercontroller.h"
#include "student.h"
#include <QMessageBox>

StudentRegister::StudentRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentRegister),
    controller(new StudentRegisterController(this))
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
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
    if(userName.isEmpty() || firstName.isEmpty() || lastName.isEmpty())
    {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Please enter all the information!"),
                             QMessageBox::Yes);
    }else{
        Student *student = new Student(userName);
        student->setFirstName(firstName);
        student->setLastName(lastName);
        controller->goToQualificationsView(*student);
    }

    
}
