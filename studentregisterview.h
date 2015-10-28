#ifndef STUDENTREGISTERVIEW_H
#define STUDENTREGISTERVIEW_H

#include <QMainWindow>

namespace Ui {
class StudentRegisterView;
}

class StudentRegisterView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentRegisterView(QWidget *parent = 0);
    ~StudentRegisterView();

private:
    Ui::StudentRegisterView *ui;
};

#endif // STUDENTREGISTERVIEW_H
