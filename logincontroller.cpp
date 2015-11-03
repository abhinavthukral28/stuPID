#include "logincontroller.h"
#include <QString>
#include "studentprojectview.h"
#include "manageprojectsview.h"
#include <QDebug>
#include "logindialog.h"
LoginController::LoginController( LoginDialog *login): QObject(), loginDialog(login)
{

}


int LoginController::authenticate(QString &userName, QString &password, bool boolStudent)
{

    if(QString("11") == userName)
    {
        return 1;
    } else {
        return 0;
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
void LoginController::transition(bool student)
{

    loginDialog->close();
    if(student){
        qDebug() << "got Here Now";
        studentProjectView sview;
        sview.exec();
    }
    else{
        qDebug() << "got Here";
        ManageProjectsView mview;
        mview.exec();
    }


}
