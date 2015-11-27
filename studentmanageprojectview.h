#ifndef STUDENTMANAGEPROJECTVIEW_H
#define STUDENTMANAGEPROJECTVIEW_H
#include "studentmanageprojectcontroller.h"


#include <QDialog>

namespace Ui {
class StudentManageProjectView;
}

class QStringList;
class Project;
class StudentManageProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit StudentManageProjectView(QWidget *parent = 0);
    ~StudentManageProjectView();
    int updateProjectsList(QList<QString> &projectTitles);



private:
    Ui::StudentManageProjectView *ui;
    StudentManageProjectController *studentManageProjectController;

};

#endif // STUDENTMANAGEPROJECTVIEW_H
