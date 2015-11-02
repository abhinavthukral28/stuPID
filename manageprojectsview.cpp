#include "manageprojectsview.h"
#include "ui_manageprojectsview.h"

#include "manageprojectscontroller.h"

ManageProjectsView::ManageProjectsView(QWidget *parent) :
<<<<<<< HEAD
    QMainWindow(parent),
    ui(new Ui::ManageProjectsView),
     manageProjectsController(new ManageProjectsController(this))
=======
    QDialog(parent),
    ui(new Ui::ManageProjectsView)
>>>>>>> 1b5a4786bd4cd220050c18087b420e5b0e7c4f05
{


    ui->setupUi(this);

     QStringList projectTitles;

    for (int i = 0; i < 50;i++)
    {
        projectTitles << QString("Project %1").arg(i);
    }


    ui->projectsList->addItems(projectTitles);
    ui->projectName->setText("Project Name");
    ui->projectDescription->setText("Project Description");
    ui->viewTextBrowser->setText("view students or view details or view results");

}

ManageProjectsView::~ManageProjectsView()
{
    delete ui;
}

void ManageProjectsView::on_projectsList_itemClicked(QListWidgetItem *item)
{
    item->setText("Hi");
}
