#include "studentprojectview.h"
#include "ui_studentprojectview.h"
#include <QDebug>
#include <QListWidgetItem>
studentProjectView::studentProjectView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentProjectView)
{   
    ui->setupUi(this);
    for(int i=1; i<=20; i++)
    {
        ui->listWidget->addItem("Project "+ QString::number(i));
       // ui->textBrowser->setText("Hello");
    }
}

studentProjectView::~studentProjectView()
{
    delete ui;
}

void studentProjectView::on_registerButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setTextColor(Qt::red);

}

void studentProjectView::on_listWidget_doubleClicked(const QModelIndex &index)
{
     //  QModelIndex i = ui->listWidget->currentIndex();
      //  qDebug()<<index;
      //tatic int i=1;
      // ui->textBrowser->setText("Hello I am project "+ QString::number(i));
      // i++;
}

void studentProjectView::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->textBrowser->setText(item->text());

}
