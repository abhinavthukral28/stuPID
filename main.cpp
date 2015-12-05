#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "createprojectview.h"
#include "logindialog.h"
#include "project.h"
#include "student.h"
#include <QDebug>
#include "team.h"
#include "resultbuilder.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Database::getInstance();
    LoginDialog view;
    view.show();


  return a.exec();



}
