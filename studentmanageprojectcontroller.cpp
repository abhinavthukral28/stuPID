#include "studentmanageprojectcontroller.h"
#include "studentmanageprojectview.h"
#include "project.h"
#include "Database.h"


StudentManageProjectController::StudentManageProjectController(StudentManageProjectView *view):QObject(),
    studentManageProjectView(view),
    database(Database::getInstance())
{

}
