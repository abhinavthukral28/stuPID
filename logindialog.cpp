#include "logindialog.h"
#include "ui_logindialog.h"
//#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "studentprojectview.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    loginController(new LoginController(this))
{

    ui->setupUi(this);
    ui->passwroldlineEdit->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginpushButton_clicked()
{
    QString userName = ui->userNamelineEdit->text();
    QString password = ui->passwroldlineEdit->text();
    bool isStudent = ui->studentradioButton->isChecked();
    qDebug() << isStudent;
    if(loginController->authenticate(userName, password, isStudent))
    {
        //do other stuff if u want in the dialog
       if(isStudent){
    qDebug() << "Go to this place";
        loginController->goToStudentView(userName);

        //studentProjectView ;
       }
       else{
           loginController->goToAdminView(userName);
           //Manage Projects View
       }
    }
    else {
        QMessageBox::warning(this, tr("Waring"),
                             tr("user name or password error!"),
                             QMessageBox::Yes);
    }
}
