#ifndef ADMINVIEWRESULT_H
#define ADMINVIEWRESULT_H
#include <QObject>
#include <QDialog>
#include "adminviewresultcontroller.h"
#include "team.h"
class AdminViewResultController;
namespace Ui {
class AdminViewResult;
}

class AdminViewResult : public QDialog
{
    Q_OBJECT

public:
    explicit AdminViewResult(AdminViewResultController *controller);
    ~AdminViewResult();

private slots:
    void on_BackButton_clicked();

    void on_pushButton_clicked();

    void on_listWidget_clicked(const QModelIndex &index);
    void updatePanel(int i);

private:
    Ui::AdminViewResult *ui;
    AdminViewResultController *adminViewResultController;
    QList<Team*> teams;
};

#endif // ADMINVIEWRESULT_H
