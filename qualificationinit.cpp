#include "qualificationinit.h"
#include "ui_qualificationinit.h"
#include "qualificationinitController.h"

QualificationInit::QualificationInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qualificationinit),
    controller(new QualificationInitController(this))


{
    ui->setupUi(this);
    ui->NameLabel->setText("Git");
    ui->NumberLabel->setText("1/20");
    ui->QuesTopLabel->setText("Do you even Git bro?");
    ui->QuesDownLabel->setText("How much can the other do?");
}

QualificationInit::~QualificationInit()
{
    delete ui;
}



