#ifndef STUDENTREGISTER_H
#define STUDENTREGISTER_H

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

private:
    Ui::StudentRegister *ui;
};

#endif // STUDENTREGISTER_H
