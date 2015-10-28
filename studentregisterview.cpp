#include "studentregisterview.h"
#include "ui_studentregisterview.h"

StudentRegisterView::StudentRegisterView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentRegisterView)
{
    ui->setupUi(this);
}

StudentRegisterView::~StudentRegisterView()
{
    delete ui;
}
