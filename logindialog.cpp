#include "logindialog.h"
#include "ui_logindialog.h"
//#include <QString>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
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
    if(ui->userNamelineEdit->text() == tr("11") &&
                   ui->passwroldlineEdit->text() == tr("11"))
            {
               accept();
            } else {
               QMessageBox::warning(this, tr("Waring"),
                                     tr("user name or password error!"),
                                     QMessageBox::Yes);
            }
}
