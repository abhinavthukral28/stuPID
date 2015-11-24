#ifndef STUDENTMANAGEPROJECTVIEW_H
#define STUDENTMANAGEPROJECTVIEW_H

#include <QDialog>

namespace Ui {
class StudentManageProjectView;
}

class StudentManageProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit StudentManageProjectView(QWidget *parent = 0);
    ~StudentManageProjectView();

private:
    Ui::StudentManageProjectView *ui;
};

#endif // STUDENTMANAGEPROJECTVIEW_H
