#include <QApplication> 
#include "logindialog.h"
#include "Database.h"
#include "user.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    //DATABASE INITIALIZATION

    Database *instance = Database::getInstance();

    instance->sayHello();


//    LoginDialog dialog;

//    dialog.show();
//    return a.exec();

QString username = "hi";
User* user = new User (username);

return 0;

}
