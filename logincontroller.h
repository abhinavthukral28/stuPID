#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include<QObject>
class QString;
class LoginDialog;
class LoginController:public QObject
{
    Q_OBJECT
public:
    LoginController(LoginDialog *login);
    int authenticate(QString &userName, QString &password, bool boolStudent);
    int goToStudentView(QString &userName);
    int goToAdminView(QString &userName);
    int goToStudentRegisterView();


 private slots:
    void transition(bool student);

 private:
    LoginDialog *loginDialog;
};

#endif // LOGINTCONTROLLER_H
