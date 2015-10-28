#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "Database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    w.show();

    //DATABASE INITIALIZATION

    Database *instance = Database::getInstance();

    instance->sayHello();
    instance->createTables();









    return a.exec();


}
