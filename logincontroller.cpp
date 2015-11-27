#include "logincontroller.h"
#include <QString>
#include "studentprojectregisterview.h"
#include "manageprojectsview.h"
#include <QDebug>
#include "logindialog.h"
#include "studentregister.h"
#include "session.h"
#include "Database.h"
LoginController::LoginController( LoginDialog *login): QObject(), loginDialog(login)
{

}


int LoginController::authenticate(QString &userName, QString &password, bool boolStudent)
{

    if (boolStudent)
    {
        const Student* student =  Database::getInstance()->authenticate(userName);
        if (student != 0)
        {
            Session::setStudent(*student);
            return 1;
        }
        return 0;

    }
    else{
       return userName == "admin";
    }

}

int LoginController::goToStudentView(QString &userName){
    //transition view
    transition(true);
    return 0;
}

int LoginController::goToAdminView(QString &userName){
    //transition view
    transition(false);
    return 0;
}
int LoginController::goToStudentManageProjectsView(){
    //transition view
    loginDialog->close();
    ManageProjectsView rview;
    rview.exec();

    return 0;
}
void LoginController::transition(bool student)
{

    loginDialog->close();
    if(student){
        studentProjectRegisterView sview;
        sview.exec();
    }
    else{
        ManageProjectsView mview;
        mview.exec();
    }


}
