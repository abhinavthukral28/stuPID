#ifndef STUDENTMANAGEPROJECTVIEW_H
#define STUDENTMANAGEPROJECTVIEW_H
#include "studentmanageprojectcontroller.h"


#include <QDialog>

namespace Ui {
class StudentManageProjectView;
}

class QStringList;
class Project;
class studentprojectregisterviewcontroller;
class StudentManageProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit StudentManageProjectView(QWidget *parent = 0);
    ~StudentManageProjectView();
    int updateProjectsList(QList<QString> &projectTitles);
    int updateDetailedView(Project &project); // you pass in a projec to display


private slots:
    void on_listWidget_clicked(const QModelIndex &index);

    void on_dropProject_clicked();
    void on_RegisterNewProject_clicked();

private:
    Ui::StudentManageProjectView *ui;
    StudentManageProjectController *studentManageProjectController;
    studentprojectregisterviewcontroller *studentProjectRegisterViewcontroller;
};


#endif // STUDENTMANAGEPROJECTVIEW_H
