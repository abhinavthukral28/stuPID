#ifndef MANAGEPROJECTSVIEW_H
#define MANAGEPROJECTSVIEW_H
#include <QListWidgetItem>
#include <QDialog>

#include "manageprojectscontroller.h"

namespace Ui {
class ManageProjectsView;
}

class QStringList;
class Project;
class ManageProjectsView : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProjectsView(QWidget *parent = 0);
     int updateProjectsList(QList<QString> &projectTitles);
     int updateDetailedView(Project &project);
     //int showListofAllStudents(Students);
    ~ManageProjectsView();



private slots:
     void on_projectsList_clicked(const QModelIndex &index);

private:
    Ui::ManageProjectsView *ui;
    ManageProjectsController *manageProjectsController;
};

#endif // MANAGEPROJECTSVIEW_H
