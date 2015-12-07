#include "logincontroller.h"
#include <QString>
#include "studentprojectregisterview.h"
#include "manageprojectsview.h"
#include <QDebug>
#include "logindialog.h"
#include "studentregister.h"
#include "session.h"
#include "Database.h"
#include "studentmanageprojectview.h"
#include "qualificationinit.h"
#include "qualification.h"
LoginController *LoginController::instance = 0;
LoginController::LoginController(): QObject()
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


            if(student->getQualifications().at(0)->getQualificationRating() == 0)
            {
                //goToQualificationsInit();
                return 2;

            }
            //qDebug()<<"student qualifications are"<<student->getQualifications().first();

            return 1;

        }
        return 0;

    }
    else{ 
      return  userName == "admin";

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

int LoginController::goToStudentRegisterView(){
    //transition view
    loginDialog->close();
    StudentRegister rview;
    rview.exec();

    return 0;
}

int LoginController::goToQualificationsInit(){
    //transition view
    loginDialog->close();
     QualificationInit qual;
     qual.exec();

    return 0;
}

void LoginController::transition(bool student)
{

    loginDialog->close();
    if(student){
       StudentManageProjectView sview;
        sview.exec();
    }
    else{
        ManageProjectsView mview;
        mview.exec();
    }

}


LoginController* LoginController::getInstance(){
    if(!LoginController::instance) {
        LoginController::instance = new LoginController();
    }
    return LoginController::instance;

}

int LoginController::setView(LoginDialog*view){
   loginDialog = view;
}
    ;
