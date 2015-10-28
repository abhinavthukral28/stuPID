#ifndef QUALIFICATIONINIT_H
#define QUALIFICATIONINIT_H

#include <QDialog>

namespace Ui {
class qualificationinit;
}

class qualificationinit : public QDialog
{
    Q_OBJECT

public:
    explicit qualificationinit(QWidget *parent = 0);
    ~qualificationinit();



private:
    Ui::qualificationinit *ui;
};

#endif // QUALIFICATIONINIT_H
