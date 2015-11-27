#include "adminviewdetail.h"
#include "ui_adminviewdetail.h"

AdminViewDetail::AdminViewDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminViewDetail)
{
    ui->setupUi(this);
}

AdminViewDetail::~AdminViewDetail()
{
    delete ui;
}
