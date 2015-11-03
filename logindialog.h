#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include "logincontroller.h"
#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();


private slots:
    void on_loginpushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    LoginController *loginController;
};

#endif // LOGINDIALOG_H
