#ifndef STUDENTREGISTER_H
#define STUDENTREGISTER_H

#include <QMainWindow>

namespace Ui {
class StudentRegister;
}

class StudentRegister : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentRegister(QWidget *parent = 0);
    ~StudentRegister();

private:
    Ui::StudentRegister *ui;
};

#endif // STUDENTREGISTER_H
