#include "manageprojectsview.h"
#include "ui_manageprojectsview.h"

ManageProjectsView::ManageProjectsView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageProjectsView)
{
    ui->setupUi(this);

     QStringList projectTitles;

    for (int i = 0; i < 50;i++)
    {
        projectTitles << QString("Project %1").arg(i);
    }


    ui->projectsList->addItems(projectTitles);

}

ManageProjectsView::~ManageProjectsView()
{
    delete ui;
}

void ManageProjectsView::on_projectsList_itemClicked(QListWidgetItem *item)
{
    item->setText("Hi");
}
