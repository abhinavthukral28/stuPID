#include "mainwindow.h"
#include <QApplication>
#include "editqualificationsview.h"
#include "qualificationinit.h"
#include "logindialog.h"
#include "Database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
   // w.show();

   // editQualificationsView w;
    //w.show();

    qualificationinit w;
    w.show();

    //DATABASE INITIALIZATION

    Database *instance = Database::getInstance();

    instance->sayHello();









    return a.exec();


}
