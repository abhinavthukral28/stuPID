#include <QApplication> 
#include <iostream>
#include "logindialog.h"
#include "Database.h"
#include "user.h"
#include "student.h"
#include "studentprojectview.h"
#include "editqualificationsview.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

   LoginDialog d;
   d.show();
    return a.exec();


}
