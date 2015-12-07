#include "Database.h"
#include "dbproxy.h"



Database* Database::instance=0;


Database* Database::getInstance(){
    if(!Database::instance) {
        Database::instance = new DBproxy();
    }
    return Database::instance;

}



