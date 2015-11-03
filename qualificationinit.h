#ifndef QUALIFICATIONINIT_H
#define QUALIFICATIONINIT_H

#include <QDialog>
class QualificationInitController;
namespace Ui {
class qualificationinit;
}

class QualificationInit : public QDialog
{
    Q_OBJECT

public:
    explicit QualificationInit(QWidget *parent = 0);
    ~QualificationInit();



private:
    Ui::qualificationinit *ui;
    QualificationInitController *controller;
};

#endif // QUALIFICATIONINIT_H
