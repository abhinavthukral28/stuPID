#ifndef ADMINVIEWRESULT_H
#define ADMINVIEWRESULT_H
#include <QObject>
#include <QDialog>
#include "adminviewresultcontroller.h"

namespace Ui {
class AdminViewResult;
}

class AdminViewResult : public QDialog
{
    Q_OBJECT

public:
    explicit AdminViewResult(QWidget *parent = 0);
    ~AdminViewResult();

private slots:
    void on_BackButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::AdminViewResult *ui;
    AdminViewResultController *adminViewResultController;
};

#endif // ADMINVIEWRESULT_H
