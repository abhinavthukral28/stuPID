#ifndef MANAGEPROJECTSVIEW_H
#define MANAGEPROJECTSVIEW_H
#include <QListWidgetItem>
#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include "manageprojectscontroller.h"
#include "team.h"

namespace Ui {
class ManageProjectsView;
}

class QMessageLogContext;
class QStringList;
class Project;
class ManageProjectsView : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProjectsView(QWidget *parent = 0);
     int updateProjectsList(QList<QString> &projectTitles);
     int updateDetailedView(Project &project);
     int setStudentList(Project &project);
     int setDetailedView(Project &project);

     //int showListofAllStudents(Students);
    ~ManageProjectsView();
     void setprojectIndex(int x);
     void getprojectIndex(int x);
     void updateSummaryResults(QList<Team*> teams);



private slots:
     void on_projectsList_clicked(const QModelIndex &index);

     void on_ViewStudentButton_clicked();


     void on_viewDetailButton_clicked();

     void on_viewResultButton_clicked();

     void on_createProjectButton_clicked();

     void on_makeTeamsButton_clicked();

     void on_pushButton_clicked();


     void on_detailedResult_clicked();

     void on_editProject_clicked();

private:
    Ui::ManageProjectsView *ui;
    ManageProjectsController *manageProjectsController;
    int projectIndex;


};

#endif // MANAGEPROJECTSVIEW_H
