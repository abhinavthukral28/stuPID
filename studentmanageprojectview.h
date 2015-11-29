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
    int updateDetailedView(Project &project); // you pass in a projec to display


private slots:
    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::StudentManageProjectView *ui;
    StudentManageProjectController *studentManageProjectController;

};


#endif // STUDENTMANAGEPROJECTVIEW_H
