#include "editqualificationsview.h"
#include "ui_editqualificationsview.h"

editQualificationsView::editQualificationsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editQualificationsView)
{
    ui->setupUi(this);
    for(int i=1; i<=20; i++)
    {
        ui->listWidget->addItem("Qualification "+ QString::number(i));
        ui->textBrowser->setText("Hello");
    }
}

editQualificationsView::~editQualificationsView()
{
    delete ui;
}

void editQualificationsView::on_listWidget_clicked(const QModelIndex &index)
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setTextColor(Qt::red);

}
