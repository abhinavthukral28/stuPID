#include "studentprojectregisterview.h"
#include "ui_studentprojectregisterview.h"
#include <QDebug>
#include <QListWidgetItem>
studentProjectRegisterView::studentProjectRegisterView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentProjectView)
{   
    ui->setupUi(this);
    for(int i=1; i<=20; i++)
    {
        ui->listWidget->addItem("Project "+ QString::number(i));

    }
}

studentProjectRegisterView::~studentProjectRegisterView()
{
    delete ui;
}

void studentProjectRegisterView::on_registerButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setTextColor(Qt::red);

}

void studentProjectRegisterView::on_listWidget_doubleClicked(const QModelIndex &index)
{
     //  QModelIndex i = ui->listWidget->currentIndex();
      //  qDebug()<<index;
      //tatic int i=1;
      // ui->textBrowser->setText("Hello I am project "+ QString::number(i));
      // i++;

}

void studentProjectRegisterView::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}
