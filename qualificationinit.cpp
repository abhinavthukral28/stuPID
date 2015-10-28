#include "qualificationinit.h"
#include "ui_qualificationinit.h"

qualificationinit::qualificationinit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qualificationinit)
{
    ui->setupUi(this);
    ui->NameLabel->setText("Git");
    ui->NumberLabel->setText("1/20");
    ui->QuesTopLabel->setText("Do you even Git bro?");
    ui->QuesDownLabel->setText("How much can the other do?");
}

qualificationinit::~qualificationinit()
{
    delete ui;
}



