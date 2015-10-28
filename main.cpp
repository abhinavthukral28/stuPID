#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "studentregister.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    w.show();

    StudentRegister r;
    r.show();

    return a.exec();
}
