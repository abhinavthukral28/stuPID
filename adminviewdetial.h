#ifndef ADMINVIEWDETIAL_H
#define ADMINVIEWDETIAL_H

#include <QDialog>

namespace Ui {
class AdminViewDetial;
}

class AdminViewDetial : public QDialog
{
    Q_OBJECT

public:
    explicit AdminViewDetial(QWidget *parent = 0);
    ~AdminViewDetial();

private slots:
    void on_BackButton_clicked();

private:
    Ui::AdminViewDetial *ui;
};

#endif // ADMINVIEWDETIAL_H
