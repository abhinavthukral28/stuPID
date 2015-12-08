#ifndef EDITPROJECTVIEW_H
#define EDITPROJECTVIEW_H

#include <QDialog>
#include "editprojectcontroller.h"
#include "manageprojectscontroller.h"
namespace Ui {
class EditProjectView;
}

class EditProjectController;
class Project;
class Database;
class ManageProjectController;
class EditProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit EditProjectView(QWidget *parent = 0);
    const QString getProjectDescription();
    const QString getProjectTitle();
    const int& getProjectTeamMin();
    const int& getProjectTeamMax();
    int updateView(Project *project);

    QString aTitle, aMin, aMax, aDescription;

    ~EditProjectView();

private slots:



    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::EditProjectView *ui;
    EditProjectController *editProjectController;
    Database *database;
    ManageProjectsController manageProjects;
    Project *project;
};

#endif // EDITPROJECTVIEW_H



