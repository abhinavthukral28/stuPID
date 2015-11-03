#ifndef STUDENTREGISTER_H
#define STUDENTREGISTER_H
#include "studentregistercontroller.h"

#include <QDialog>

namespace Ui {
class StudentRegister;
}

class StudentRegister : public QDialog
{
    Q_OBJECT

public:
    explicit StudentRegister(QWidget *parent = 0);
    ~StudentRegister();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StudentRegister *ui;
    StudentRegisterController *controller;

};

#endif // STUDENTREGISTER_H
