#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LoginDialog view;
    view.show();

  return a.exec();



}
