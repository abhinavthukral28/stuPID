#ifndef CREATEPROJECTVIEW_H
#define CREATEPROJECTVIEW_H
#include <QObject>
#include "createprojectviewcontroller.h"
#include <QDialog>

namespace Ui {
class CreateProjectView;
}

class CreateProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProjectView(QWidget *parent = 0);
    void getProjectDescription();
    void getProjectTitle();
    void getProjectTeamMin();
    void getProjectTeamMax();

    ~CreateProjectView();

private:
    Ui::CreateProjectView *ui;
    CreateProjectViewController *createProjectViewController;

};

#endif // CREATEPROJECTVIEW_H
