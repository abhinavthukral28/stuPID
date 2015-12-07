#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include<QObject>
class QString;
class LoginDialog;
class LoginController:public QObject
{
    Q_OBJECT
public:
    int authenticate(QString &userName, QString &password, bool boolStudent);
    int goToQualificationsInit();
    int goToStudentView(QString &userName);
    int goToAdminView(QString &userName);
    int goToStudentRegisterView();
    static LoginController* getInstance();
    int setView(LoginDialog* view);



 private slots:
    void transition(bool student);

 private:
    LoginDialog *loginDialog;
    LoginController();
    static LoginController *instance;
};

#endif // LOGINTCONTROLLER_H
