#include "editqualificationsview.h"
#include "ui_editqualificationsview.h"
#include "session.h"

EditQualificationsView::EditQualificationsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editQualificationsView),
    controller(new EditQualificationsController(this))
{
    ui->setupUi(this);
    stu = controller->getStudent();
    qualificationList = stu.getQualifications();

    for(int i=0; i< qualificationList.count(); i++)
    {
        ui->listWidget->addItem(qualificationList[i]->getTitle());
    }
}

EditQualificationsView::~EditQualificationsView()
{
    delete ui;
}

void EditQualificationsView::updatePanel(int index){

}

void EditQualificationsView::on_listWidget_clicked(const QModelIndex &index)
{
    int i = index.row();
    updatePanel(i);

}

void EditQualificationsView::on_NextButton_2_clicked()
{
    controller->goToManageProject();
}
