#include "logincontroller.h"
#include <QString>
#include "studentprojectview.h"
#include <QDebug>
#include "logindialog.h"
LoginController::LoginController( LoginDialog *login):QObject(), loginDialog(login)
{
}


int LoginController::authenticate(QString &userName, QString &password, bool boolStudent)
{

    if(QString("11") == userName && QString("11") == password &&
            boolStudent)
            {
              return 1;
            } else {
               return 0;
            }

}

 int LoginController::goToStudentView(QString &userName){
     //transition view
         transition();
        return 0;
 }

 void LoginController::transition()
 {
        loginDialog->close();
     studentProjectView view;

      view.exec();


 }
