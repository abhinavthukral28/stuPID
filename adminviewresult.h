#ifndef ADMINVIEWRESULT_H
#define ADMINVIEWRESULT_H

#include <QDialog>

namespace Ui {
class AdminViewResult;
}

class AdminViewResult : public QDialog
{
    Q_OBJECT

public:
    explicit AdminViewResult(QWidget *parent = 0);
    ~AdminViewResult();

private:
    Ui::AdminViewResult *ui;
};

#endif // ADMINVIEWRESULT_H
