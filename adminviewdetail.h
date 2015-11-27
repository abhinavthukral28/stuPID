#ifndef ADMINVIEWDETAIL_H
#define ADMINVIEWDETAIL_H

#include <QMainWindow>

namespace Ui {
class AdminViewDetail;
}

class AdminViewDetail : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminViewDetail(QWidget *parent = 0);
    ~AdminViewDetail();

private:
    Ui::AdminViewDetail *ui;
};

#endif // ADMINVIEWDETAIL_H
